#ifndef EGG_HH_
# define EGG_HH_

#include "irrlicht.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace gui;

class   Egg
{
    int             _id;
    IMeshSceneNode  *_node;

    void    _init(ISceneManager *smgr, IMeshSceneNode *parent, IMesh *eggMesh);
public:  
    Egg(ISceneManager *smgr, IMeshSceneNode *parent, IMesh *eggMesh);
    ~Egg();
    int             getId();
    void            setId(int id);
    IMeshSceneNode  *getNode();
    void            setVisible(bool visibility);
};

#endif