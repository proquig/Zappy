#include "Board.hh"

Board::Board(ISceneNode *parent, ISceneManager *smgr, s32 id, const vector3df &position, const vector3df &rotation, const vector3df &scale, u32 nbSquareSize, video::ITexture *texture)
{
    this->_material.Wireframe = false;
    this->_material.Lighting = false;
    this->_square = smgr->getGeometryCreator()->createPlaneMesh(dimension2d<f32>(scale.X, scale.Z), dimension2du(1, 1), &this->_material);
    this->_squareNode = smgr->addMeshSceneNode(this->_square, parent, id, position, rotation, vector3df(1.0f, 1.0f, 1.0f));
    this->_nbSquareSize = nbSquareSize;
    this->_squareSize = scale.X;
    this->_texture = texture;
    if (nbSquareSize == 0)
        this->_squareNode->setMaterialTexture(0, texture);
    this->_blockNode = nullptr;
    this->curBlockMesh = nullptr;
    init();
}

Board::~Board()
{
    
}

void    Board::init()
{
    if (this->_nbSquareSize != 0)
    {
        f32 underSquareSize =  this->_squareSize / this->_nbSquareSize;
   
        f32  x;
        f32  z = (this->_squareSize / 2) - (underSquareSize / 2);
        u32  j = 0;
        u32  i;
        s32  underSquareId = 2;
        while (j < this->_nbSquareSize)
        {
            i = 0;
            x = - ((this->_squareSize / 2) - (underSquareSize / 2));
            std::vector<Board *> line;
            while (i < this->_nbSquareSize)
            {
                Board *newBoard = new Board(this->_squareNode, this->getSceneManager(), underSquareId, vector3df(x, 0.1f, z), vector3df(0.0f, 0.0f, 0.0f), vector3df(underSquareSize, 0.0f, underSquareSize), 0, this->_texture);
                line.push_back(newBoard);
                x += underSquareSize;
                i++;
                underSquareId++;
            }
            this->_underSquares.push_back(line);
            j++;
            z -= underSquareSize;
        }
    }
}

IMeshSceneNode  *Board::getSquareNode()
{
    return (this->_squareNode);
}

IMesh       *Board::getSquare()
{
    return (this->_square);
}

u32         Board::getNbSquareSize()
{
    return (this->_nbSquareSize);
}

std::vector<std::vector<Board *> > *Board::getUnderSquares()
{
    return (&this->_underSquares);
}

void        Board::setMaterialFlag(video::E_MATERIAL_FLAG flag, bool newvalue)
{
    this->_squareNode->setMaterialFlag(flag, newvalue);
}

void        Board::setMaterialTexture(u32 textureLayer, video::ITexture *texture)
{
    this->_squareNode->setMaterialTexture(textureLayer, texture);
}

void        Board::setPosition (const core::vector3df &newpos)
{
    this->_squareNode->setPosition(newpos);
}

void        Board::setScale(const core::vector3df &scale)
{
    this->_squareNode->setScale(scale);
}

void        Board::setVisible (bool isVisible)
{
    this->_squareNode->setVisible(isVisible);
}

void        Board::remove()
{
    this->_squareNode->remove();
}

const core::vector3df &Board::getPosition() const
{
    return (this->_squareNode->getPosition());
}

core::vector3df Board::getPositionUpperLeft() const
{
    return (this->getPosition() - (this->getScale() / 2));
}

const core::vector3df &Board::getScale() const
{
    return (this->_squareNode->getScale());
}

ISceneManager   *Board::getSceneManager(void) const
{
    return (this->_squareNode->getSceneManager());
}

video::ITexture *Board::getTexture()
{
    return (this->_texture);
}

void            Board::setBlockNode(IMeshSceneNode *newBlockNode)
{
    if (this->_blockNode != nullptr)
          this->_blockNode->remove();
    this->_blockNode = newBlockNode;
}

IMeshSceneNode  *Board::getBlockNode()
{
    return (this->_blockNode);
}

f32             Board::getSquareSize()
{
    return (this->_squareSize);
}