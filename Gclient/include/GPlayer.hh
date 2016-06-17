#ifndef GPLAYER_HH_
# define GPLAYER_HH_

#include "irrlicht.h"

class   GPlayer
{
    IMesh   *_mesh;
    int     _x;
    int     _y;
    Direction    _direction;
    int     _id;
  public:
    GPlayer(t_player const &newPlayer, IMesh *mesh);
    ~GPlayer();
    int     getX();
    int     getY();
    enum    getDirection();
    int     getId();
    void    setX(int newX);
    void    setY(int newY);
    void    setDirection(Direction newDirection);
    void    setMesh(IMesh *newMesh);
};

#endif