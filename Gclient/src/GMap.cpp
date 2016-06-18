#include "GMap.hh"

GMap::GMap(ISceneManager *smgr, Board *board, std::map<RESSOURCES, IMesh *> const &ressourcesMeshes, std::array<IMesh *, 8> const &playersMeshes) : _ressourcesMeshes(ressourcesMeshes), _playersMeshes(playersMeshes)
{
    this->_board = board;
    this->_smgr = smgr;
}

GMap::~GMap()
{
}

void   GMap::initGMap()
{
    std::vector<std::vector<Board *> >::iterator    j = this->_board->getUnderSquares()->begin();
    std::vector<Board *>::iterator  i;

    while (j != this->_board->getUnderSquares()->end())
    {
        i = j->begin();
        while (i != j->end())
        {
            this->initPlayerNode(*i);
            this->initRessourcesNodes(*i);
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
    meshRescale = 10.0f / ((this->_playersMeshes[0]->getBoundingBox().getExtent().X + this->_playersMeshes[0]->getBoundingBox().getExtent().Y + this->_playersMeshes[0]->getBoundingBox().getExtent().Z) / 3.0f);
    IMeshSceneNode *newNode = this->_smgr->addMeshSceneNode(this->_playersMeshes[0], curBoard->getBoardRootNode(), -1, vector3df(0.0f, meshRepos, 0.0f), vector3df(0.0f, 0.0f, 0.0f), vector3df(meshRescale, meshRescale, meshRescale));
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
        meshRescale = 10.0f / ((this->_ressourcesMeshes[(RESSOURCES)i]->getBoundingBox().getExtent().X + this->_ressourcesMeshes[(RESSOURCES)i]->getBoundingBox().getExtent().Y + this->_ressourcesMeshes[(RESSOURCES)i]->getBoundingBox().getExtent().Z) / 3.0f);
        IMeshSceneNode *newNode = this->_smgr->addMeshSceneNode(this->_ressourcesMeshes[(RESSOURCES)i], curBoard->getBoardRootNode(), -1, randomResPos(curBoard, this->_ressourcesMeshes[(RESSOURCES)i]), vector3df(0.0f, 0.0f, 0.0f), vector3df(meshRescale, meshRescale, meshRescale));
        newNode->setMaterialFlag(EMF_WIREFRAME, false);
        newNode->setMaterialFlag(EMF_LIGHTING, false);
        newNode->setMaterialType(EMT_SOLID);
        newNode->setVisible(false);
        ressourcesNodes[(RESSOURCES)i] = newNode;
        i++;
    }
    curBoard->setRessourcesNodes(ressourcesNodes);
}

vector3df   GMap::randomResPos(Board *curBoard, IMesh *res)
{
    vector3df   repos;
    unsigned int    i = 0;
    std::map<RESSOURCES, IMeshSceneNode *>  *ressourcesNodes = curBoard->getRessourcesNodes();

    srand(time(NULL));
    repos.Y = 1.0f / res->getBoundingBox().getExtent().Y;
    repos.X = rand() % (int)curBoard->getSquareSize();
    repos.Y = rand() % (int)curBoard->getSquareSize();
    while (i < RES_SIZE)
    {
        if (((*ressourcesNodes)[(RESSOURCES)i]->getPosition().X == repos.X) && 
            ((*ressourcesNodes)[(RESSOURCES)i]->getPosition().Y == repos.Y))
            repos = randomResPos(curBoard, res);
        i++;
    }
}

void   GMap::refreshGMapRes()
{
    
}

void   GMap::refreshGMapPlayers(std::vector<GPlayer *> const &players)
{
    std::vector<GPlayer *>::const_iterator   it = players.begin();
    std::vector<std::vector<Board *> >    underSquares = *this->_board->getUnderSquares();
    clearAllPlayers();
    while (it != players.end())
    {
        underSquares[(*it)->getX()][(*it)->getY()]->setCurPlayerMesh(this->_playersMeshes[(*it)->getLvl()]);
        underSquares[(*it)->getX()][(*it)->getY()]->getPlayerNode()->setVisible(true);
        ++it;
    }
}

void   GMap::clearAllRessources()
{
    
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