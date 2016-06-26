#ifndef GPLAYER_HH_
# define GPLAYER_HH_

#include "irrlicht.h"
#include "common.h"
#include "Board.hh"

class   GPlayer
{
    IMesh   *_mesh;
    int     _x;
    int     _y;
    Direction    _direction;
    int     _id;
    int     _lvl;
    IAnimatedMeshSceneNode  *_sceneNode;
  public:
    GPlayer(t_player const &newPlayer, IMesh *mesh);
    ~GPlayer();
    int     getX();
    int     getY();
    Direction    getDirection();
    int     getId();
    int     getLvl();
    void    setX(int newX);
    void    setY(int newY);
    void    setDirection(Direction newDirection);
    void    setMesh(IMesh *newMesh);
    void    setLvl(int lvl);
    IAnimatedMeshSceneNode    *getSceneNode();
    void  setSceneNode(IAnimatedMeshSceneNode *newNode);
};

#endif