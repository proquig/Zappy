#ifndef GUI_HH_
# define GUI_HH_

#include <iostream>
#include <map>
#include <iterator>
#include "Board.hh"
#include "GPlayer.hh"
#include "GMap.hh"
#include "irrlicht.h"
#include "driverChoice.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace gui;

enum    models
{
  PLAYER1,
  PLAYER2,
  EGG,
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME,
  FOOD1,
  FOOD2
};

class GUI
{
    dimension2d<u32>    _deskres;
    IrrlichtDevice      *_device;
    IVideoDriver        *_driver;
    ISceneManager       *_smgr;
    IGUIEnvironment     *_env;
    std::map<models, IMesh *>   _meshes;
    ITexture            *_textures;
    Board               *_gameBoard;
    E_DRIVER_TYPE       _driverType;
    GMap                *_gMap;
    t_square            **_map;
    std::vector<GPlayer *> _players;
    int                 _sizeX;
    int                 _sizeY;
public:
    GUI();
    ~GUI();
    void    launch();
    void    handleCommunications();
    bool    loadMeshesAndTextures();
    IrrlichtDevice  *getDevice();
    IVideoDriver    *getDriver();
    ISceneManager   *getSmgr();
    IGUIEnvironment *getEnv();
    std::map<models, IMesh *>  const &getMeshes();
    ITexture    *getTextures();
    Board       *getBoard();
    void        initMap(int sizeX, int sizeY);
    void        refreshMap();
    void        refreshGame();
    void        addPlayer(t_player const &newPlayer);
};

#endif