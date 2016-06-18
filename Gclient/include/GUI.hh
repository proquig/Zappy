#ifndef GUI_HH_
# define GUI_HH_

#include <iostream>
#include <map>
#include <array>
#include <iterator>
#include "Board.hh"
#include "GPlayer.hh"
#include "GMap.hh"
#include "irrlicht.h"
#include "common.h"
#include "driverChoice.h"

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
    std::map<RESSOURCES, IMesh *>   _ressourcesMeshes;
    std::array<IMesh *, 8>        _playersMeshes;
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
    std::map<RESSOURCES, IMesh *>  const &getRessourcesMeshes();
    std::array<IMesh *, 8>  const &getPlayersMeshes();
    ITexture    *getTextures();
    Board       *getBoard();
    void        initMap(int sizeX, int sizeY);
    void        refreshMap(t_square const &toRefresh);
    void        refreshGame();
    void        addPlayer(t_player const &newPlayer);
};

#endif