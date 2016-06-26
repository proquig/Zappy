#include "GPlayer.hh"

GPlayer::GPlayer(t_player const &newPlayer, IMesh *mesh)
{
   this->_x = newPlayer.x;
   this->_y = newPlayer.y;
   this->_direction = newPlayer.dir;
   this->_id = newPlayer.fd;
   this->_lvl = newPlayer.lvl;
   this->_mesh = mesh;
}

GPlayer::~GPlayer()
{
}

int     GPlayer::getX()
{
    return (this->_x);
}

int     GPlayer::getY()
{
    return (this->_y);
}

Direction   GPlayer::getDirection()
{
    return (this->_direction);
}

int     GPlayer::getId()
{
    return (this->_id);
}

int     GPlayer::getLvl()
{
    return (this->_lvl);
}

void    GPlayer::setX(int newX)
{
    this->_x = newX;
}

void    GPlayer::setY(int newY)
{
    this->_y = newY;
}

void    GPlayer::setDirection(Direction newDirection)
{
    this->_direction = newDirection;
}

void    GPlayer::setMesh(IMesh *newMesh)
{
    this->_mesh = newMesh;
}

void    GPlayer::setLvl(int lvl)
{
    this->_lvl = lvl;
}

IAnimatedMeshSceneNode    *GPlayer::getSceneNode()
{
    return (this->_sceneNode);
}

void  GPlayer::setSceneNode(IAnimatedMeshSceneNode *newNode)
{
    this->_sceneNode = newNode;
}