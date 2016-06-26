#include "GMap.hh"
#include <iostream>

GMap::GMap(ISceneManager *smgr, Board *board, std::map<RESSOURCES, IMesh *> const &ressourcesMeshes, std::array<IAnimatedMesh *, 8> const &playersMeshes, IMesh *eggMesh) : _ressourcesMeshes(ressourcesMeshes), _playersMeshes(playersMeshes)
{
    this->_board = board;
    this->_smgr = smgr;
    this->initGMap(eggMesh);
}

GMap::~GMap()
{
}

void   GMap::initGMap(IMesh *eggMesh)
{
    std::vector<std::vector<Board *> >::iterator    j = this->_board->getUnderSquares()->begin();
    std::vector<Board *>::iterator  i;

    srand(time(NULL));
    while (j != this->_board->getUnderSquares()->end())
    {
        i = j->begin();
        while (i != j->end())
        {
            this->initPlayerNode(*i);
            this->initRessourcesNodes(*i);
            this->initEggNode(*i, eggMesh);
            ++i;
        }
        ++j;
    }
}

void    GMap::initPlayerNode(Board *curBoard)
{
    f32 meshRepos;
    f32 meshRescale;
    
    meshRepos = 1.0f / this->_playersMeshes[0]->getBoundingBox().getExtent().Y;
    meshRescale = 15.0f / ((this->_playersMeshes[0]->getBoundingBox().getExtent().X + this->_playersMeshes[0]->getBoundingBox().getExtent().Y + this->_playersMeshes[0]->getBoundingBox().getExtent().Z) / 3.0f);
    IAnimatedMeshSceneNode *newNode = this->_smgr->addAnimatedMeshSceneNode(this->_playersMeshes[0], curBoard->getBoardRootNode(), -1, vector3df(0.0f, meshRepos, 0.0f), vector3df(0.0f, 0.0f, 0.0f), vector3df(meshRescale, meshRescale, meshRescale));
    newNode->setMaterialFlag(EMF_WIREFRAME, false);
    newNode->setMaterialFlag(EMF_LIGHTING, false);
    newNode->setMaterialType(EMT_SOLID);
    newNode->setVisible(false);
    curBoard->setPlayerNode(newNode);
}

void    GMap::initRessourcesNodes(Board *curBoard)
{
    std::map<RESSOURCES, IMeshSceneNode *>  ressourcesNodes;
    unsigned int i = 0;
    f32 meshRescale;

    while (i < RES_SIZE)
    {
        if (i == 0)
            meshRescale = 4.0f / ((this->_ressourcesMeshes[(RESSOURCES)i]->getBoundingBox().getExtent().X + this->_ressourcesMeshes[(RESSOURCES)i]->getBoundingBox().getExtent().Y + this->_ressourcesMeshes[(RESSOURCES)i]->getBoundingBox().getExtent().Z) / 3.0f);
        else
            meshRescale = 3.0f / ((this->_ressourcesMeshes[(RESSOURCES)i]->getBoundingBox().getExtent().X + this->_ressourcesMeshes[(RESSOURCES)i]->getBoundingBox().getExtent().Y + this->_ressourcesMeshes[(RESSOURCES)i]->getBoundingBox().getExtent().Z) / 3.0f);
        IMeshSceneNode *newNode = this->_smgr->addMeshSceneNode(this->_ressourcesMeshes[(RESSOURCES)i], curBoard->getBoardRootNode(), -1, randomResPos(curBoard, this->_ressourcesMeshes[(RESSOURCES)i]), vector3df(-60.0f, -135.0f, -5.0f), vector3df(meshRescale, meshRescale, meshRescale));
        newNode->setMaterialFlag(EMF_WIREFRAME, false);
        newNode->setMaterialFlag(EMF_LIGHTING, false);
        newNode->setMaterialType(EMT_SOLID);
        newNode->setVisible(false);
        ressourcesNodes[(RESSOURCES)i] = newNode;
        curBoard->setRessourcesNodes(ressourcesNodes);
        i++;
    }
}

void    GMap::initEggNode(Board *curBoard, IMesh *eggMesh)
{
    curBoard->setEgg(new Egg(this->_smgr, curBoard->getBoardRootNode(), eggMesh));
}

vector3df   GMap::randomResPos(Board *curBoard, IMesh *res)
{
    vector3df   repos;
    std::map<RESSOURCES, IMeshSceneNode *>::iterator it = curBoard->getRessourcesNodes()->begin();
    
    if (res == this->_ressourcesMeshes[FOOD])
        repos.Y = -1.0f / res->getBoundingBox().getExtent().Y;
    else
        repos.Y = 9.0f / res->getBoundingBox().getExtent().Y;
    repos.X = (rand() % (int)curBoard->getSquareSizeX()) - ((int)curBoard->getSquareSizeX() / 2);
    repos.Z = (rand() % (int)curBoard->getSquareSizeY()) - ((int)curBoard->getSquareSizeY() / 2);
    if (repos.X < 0)
        repos.X++;
    else if (repos.X > 0)
        repos.X--;
    if (repos.Z < 0)
        repos.Z++;
    else if (repos.Z > 0)
        repos.Z--;
    if (repos.X > 0 || repos.Z > 0)
        repos = randomResPos(curBoard, res);
    while (it != curBoard->getRessourcesNodes()->end())
    {
       if (((it->second->getPosition().X == repos.X) || (it->second->getPosition().X == repos.X + 2) || (it->second->getPosition().X == repos.X - 2)) && 
            ((it->second->getPosition().Y == repos.Y) || (it->second->getPosition().Y == repos.Y + 2) || (it->second->getPosition().Y == repos.Y - 2)))
            repos = randomResPos(curBoard, res);
       ++it;
    }
    return (repos);
}

void   GMap::refreshGMapRes()
{
    unsigned int i;
    unsigned int j;
    int k;
    std::map<RESSOURCES, IMeshSceneNode *>  *ressourcesNodes;
    std::vector<std::vector<Board *> > *underSquares = this->_board->getUnderSquares();

    j = 0;
    while (j < this->_board->getNbSquareSizeY())
    {
        i = 0;
        while (i < this->_board->getNbSquareSizeX())
        {
            k = 0;
            while ((RESSOURCES)k < RES_SIZE)
            {
                ressourcesNodes = (*underSquares)[j][i]->getRessourcesNodes();
                if (this->_map[j][i].res.res[(RESSOURCES)k] > 0)
                    ressourcesNodes->at((RESSOURCES)k)->setVisible(true);
                else
                    ressourcesNodes->at((RESSOURCES)k)->setVisible(false);                    
                k++;
            }
            i++;
        }
        j++;
    }
}

void   GMap::refreshGMapPlayers(std::vector<GPlayer *> const &players)
{
    std::vector<GPlayer *>::const_iterator   it = players.begin();
    std::vector<std::vector<Board *> >    *underSquares = this->_board->getUnderSquares();
    clearAllPlayers();

    while (it != players.end())
    {
        (*underSquares)[(*it)->getY()][(*it)->getX()]->setCurPlayerMesh(this->_playersMeshes[(*it)->getLvl()]);
        (*it)->setSceneNode((*underSquares)[(*it)->getY()][(*it)->getX()]->getPlayerNode());
        (*underSquares)[(*it)->getY()][(*it)->getX()]->getPlayerNode()->setVisible(true);
        (*underSquares)[(*it)->getY()][(*it)->getX()]->getPlayerNode()->setMaterialFlag(EMF_LIGHTING, false);
        (*underSquares)[(*it)->getY()][(*it)->getX()]->getPlayerNode()->setRotation(vector3df(0.0f, 0.0f, 0.0f));
        if ((*it)->getDirection() == UP)
            (*underSquares)[(*it)->getY()][(*it)->getX()]->getPlayerNode()->setRotation(vector3df(0.0f, 180.0f, 0.0f));
        else if ((*it)->getDirection() == RIGHT)
            (*underSquares)[(*it)->getY()][(*it)->getX()]->getPlayerNode()->setRotation(vector3df(0.0f, -90.0f, 0.0f));
        else if ((*it)->getDirection() == LEFT)
            (*underSquares)[(*it)->getY()][(*it)->getX()]->getPlayerNode()->setRotation(vector3df(0.0f, 90.0f, 0.0f));
        ++it;
    }
}

void   GMap::clearAllRessources()
{
    std::vector<std::vector<Board *> >::iterator    j = this->_board->getUnderSquares()->begin();
    std::vector<Board *>::iterator  i;
    std::map<RESSOURCES, IMeshSceneNode *>::iterator it;

    while (j != this->_board->getUnderSquares()->end())
    {
        i = j->begin();
        while (i != j->end())
        {
            it = (*i)->getRessourcesNodes()->begin();
            while (it != (*i)->getRessourcesNodes()->end())
            {
                it->second->setVisible(false);
                ++it;
            }
            ++i;
        }
        ++j;
    }
}

void   GMap::clearAllPlayers()
{
    std::vector<std::vector<Board *> >::iterator    j = this->_board->getUnderSquares()->begin();
    std::vector<Board *>::iterator  i;

    while (j != this->_board->getUnderSquares()->end())
    {
        i = j->begin();
        while (i != j->end())
        {
            (*i)->getPlayerNode()->setVisible(false);
            ++i;
        }
        ++j;
    }
}

void    GMap::setMap(t_square **map)
{
    this->_map = map;
}

void    GMap::popEgg(int id, int x, int y)
{
    std::vector<std::vector<Board *> >    *underSquares = this->_board->getUnderSquares();

    (*underSquares)[y][x]->getEgg()->setId(id);
    (*underSquares)[y][x]->getEgg()->setVisible(true);
}

void    GMap::eraseEgg(int id)
{
    std::vector<std::vector<Board *> >::iterator    j = this->_board->getUnderSquares()->begin();
    std::vector<Board *>::iterator  i;

    while (j != this->_board->getUnderSquares()->end())
    {
        i = j->begin();
        while (i != j->end())
        {
            if ((*i)->getEgg()->getId() == id)
                (*i)->getEgg()->setVisible(false);
            ++i;
        }
        ++j;
    }
}