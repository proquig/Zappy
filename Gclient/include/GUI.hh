#ifndef GUI_HH_
# define GUI_HH_

#include <iostream>
#include <map>
#include <array>
#include <iterator>
#include <unistd.h>
#include <pthread.h>
#include "Board.hh"
#include "GPlayer.hh"
#include "GMap.hh"
#include "irrlicht.h"
#include "common.h"
#include "driverChoice.h"
#include "Mutex.hh"
#include "EventReceiver.hh"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace gui;

class GUI
{
    dimension2d<u32>    _deskres;
    IrrlichtDevice      *_device;
    IVideoDriver        *_driver;
    ISceneManager       *_smgr;
    IGUIEnvironment     *_env;
    ITexture            *_floor;
    std::map<RESSOURCES, IMesh *>   _ressourcesMeshes;
    std::array<IAnimatedMesh *, 8>        _playersMeshes;
    ITexture            *_textures;
    Board               *_gameBoard;
    E_DRIVER_TYPE       _driverType;
    GMap                *_gMap;
    t_square            **_map;
    std::vector<GPlayer *> _players;
    int                 _sizeX;
    int                 _sizeY;
    Mutex               _mutex;
    ITexture            *_background;
    
public:
    GUI();
    ~GUI();
    void    launch();
    bool    loadMeshesAndTextures();
    IrrlichtDevice  *getDevice();
    IVideoDriver    *getDriver();
    ISceneManager   *getSmgr();
    IGUIEnvironment *getEnv();
    std::map<RESSOURCES, IMesh *>  const &getRessourcesMeshes();
    std::array<IAnimatedMesh *, 8>  const &getPlayersMeshes();
    ITexture    *getTextures();
    Board       *getBoard();
    void        initMap();
    void        refreshGame();
    void        addPlayer(t_player const &newPlayer);
    void        setSizeX(int sizeX);
    void        setSizeY(int sizeY);
    t_square    **getMap();
    void        removePlayer(int id);
    GPlayer     *getPlayer(int id);
    Mutex       &getMutex();
    GMap        *getGMap();
    void        dispBackground();
    void        dropAnimation(int id);
};

#endif