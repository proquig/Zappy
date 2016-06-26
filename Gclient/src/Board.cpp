#include "Board.hh"

Board::Board(ISceneNode *parent, ISceneManager *smgr, s32 id, const vector3df &position, const vector3df &rotation, const vector3df &scale, u32 nbSquareSizeX, u32 nbSquareSizeY, ITexture *texture)
{
    this->_material.Wireframe = false;
    this->_material.Lighting = false;
    this->_square = smgr->getGeometryCreator()->createPlaneMesh(dimension2d<f32>(scale.X, scale.Z), dimension2du(1, 1), &this->_material);
    this->_boardRootNode = smgr->addMeshSceneNode(this->_square, parent, id, position, rotation, vector3df(1.0f, 1.0f, 1.0f));
    this->_nbSquareSizeX = nbSquareSizeX;
    this->_nbSquareSizeY = nbSquareSizeY;
    this->_squareSizeX = scale.X;
    this->_squareSizeY = scale.Z;
    this->_texture = texture;
    if (nbSquareSizeX == 0 || nbSquareSizeY == 0)
        this->_boardRootNode->setMaterialTexture(0, texture);
    this->_playerNode = nullptr;
    init();
}

Board::~Board()
{
    
}
#include <iostream>
void    Board::init()
{
    if (this->_nbSquareSizeX != 0 && this->_nbSquareSizeY != 0)
    {
        f32 underSquareSizeX =  this->_squareSizeX / this->_nbSquareSizeX;
        f32 underSquareSizeY =  this->_squareSizeY / this->_nbSquareSizeY;
   
        f32  x;
        f32  z = (this->_squareSizeY / 2) - (underSquareSizeY / 2);
        u32  j = 0;
        u32  i;
        s32  underSquareId = 2;
        while (j < this->_nbSquareSizeY)
        {
            i = 0;
            x = - ((this->_squareSizeX / 2) - (underSquareSizeX / 2));
            std::vector<Board *> line;
            while (i < this->_nbSquareSizeX)
            {
                Board *newBoard = new Board(this->_boardRootNode, this->getSceneManager(), underSquareId, vector3df(x, 0.1f, z), vector3df(0.0f, 0.0f, 0.0f), vector3df(underSquareSizeX, 0.0f, underSquareSizeY), 0, 0, this->_texture);
                line.push_back(newBoard);
                x += underSquareSizeX;
                i++;
                underSquareId++;
            }
            this->_underSquares.push_back(line);
            j++;
            z -= underSquareSizeY;
        }
    }
}

IMeshSceneNode  *Board::getBoardRootNode()
{
    return (this->_boardRootNode);
}

IMesh       *Board::getSquare()
{
    return (this->_square);
}

u32         Board::getNbSquareSizeX()
{
    return (this->_nbSquareSizeX);
}

u32         Board::getNbSquareSizeY()
{
    return (this->_nbSquareSizeY);
}

std::vector<std::vector<Board *> > *Board::getUnderSquares()
{
    return (&this->_underSquares);
}

void        Board::setMaterialFlag(E_MATERIAL_FLAG flag, bool newvalue)
{
    this->_boardRootNode->setMaterialFlag(flag, newvalue);
}

void        Board::setMaterialTexture(u32 textureLayer, ITexture *texture)
{
    this->_boardRootNode->setMaterialTexture(textureLayer, texture);
}

void        Board::setPosition (const vector3df &newpos)
{
    this->_boardRootNode->setPosition(newpos);
}

void        Board::setScale(const vector3df &scale)
{
    this->_boardRootNode->setScale(scale);
}

void        Board::setVisible (bool isVisible)
{
    this->_boardRootNode->setVisible(isVisible);
}

void        Board::remove()
{
    this->_boardRootNode->remove();
}

const vector3df &Board::getPosition() const
{
    return (this->_boardRootNode->getPosition());
}

vector3df Board::getPositionUpperLeft() const
{
    return (this->getPosition() - (this->getScale() / 2));
}

const vector3df &Board::getScale() const
{
    return (this->_boardRootNode->getScale());
}

ISceneManager   *Board::getSceneManager(void) const
{
    return (this->_boardRootNode->getSceneManager());
}

ITexture *Board::getTexture()
{
    return (this->_texture);
}

void            Board::setPlayerNode(IAnimatedMeshSceneNode *newPlayerNode)
{
    if (this->_playerNode != nullptr)
          this->_playerNode->remove();
    this->_playerNode = newPlayerNode;
}

IAnimatedMeshSceneNode  *Board::getPlayerNode()
{
    return (this->_playerNode);
}

f32             Board::getSquareSizeX()
{
    return (this->_squareSizeX);
}

f32             Board::getSquareSizeY()
{
    return (this->_squareSizeY);
}

IMesh   *Board::getCurPlayerMesh()
{
    return (this->_playerNode->getMesh());
}

void    Board::setCurPlayerMesh(IAnimatedMesh *newCurModelMesh)
{
    this->_playerNode->setMesh(newCurModelMesh);
}

std::map<RESSOURCES, IMeshSceneNode *>  *Board::getRessourcesNodes()
{
    return (&this->_ressourcesNodes);
}

void    Board::setRessourcesNodes(std::map<RESSOURCES, IMeshSceneNode *>  const &ressourcesNodes)
{
    this->_ressourcesNodes = ressourcesNodes;
}

Egg     *Board::getEgg()
{
    return (this->_egg);
}

void    Board::setEgg(Egg *egg)
{
    this->_egg = egg;
}