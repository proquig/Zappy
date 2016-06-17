#include "GUI.hh"

GUI::GUI()
{
  IrrlichtDevice *nulldevice = createDevice(EDT_NULL);
  this->_deskres = nulldevice->getVideoModeList()->getDesktopResolution();
  nulldevice->drop();

  this->_driverType = driverChoiceConsole();
  if (this->_driverType == video::EDT_COUNT || this->_driverType == video::EDT_NULL)
  {
    std::cout << "This driver is not available" << std::endl;
    exit(EXIT_SUCCESS);
  }

  if (!(this->_device = createDevice(this->_driverType, this->_deskres, 32, false, false, false, 0)))
    exit(EXIT_FAILURE);
  this->_driver = _device->getVideoDriver();
  this->_smgr = _device->getSceneManager();
  this->_env = _device->getGUIEnvironment();
  _device->getCursorControl()->setVisible(false); 
}

GUI::~GUI()
{
    for (int i = 0; i < this->_sizeY; ++i)
        delete[] this->map[i];
    delete[] this->_map;
}

void    GUI::launch()
{
    if (loadMeshesAndTextures() == false)
    {
        std::cerr << "Error: 3D model or texture has not been loaded" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->_gameBoard = new Board(/* ... */);
    handleCommunications();
}

void    GUI::handleCommunications()
{
    
}

bool    GUI::loadMeshesAndTextures()
{
    return (false);
}

IrrlichtDevice  *GUI::getDevice()
{
    return (this->_device);    
}

IVideoDriver    *GUI::getDriver()
{
    return (this->_driver);
}

ISceneManager   *GUI::getSmgr()
{
    return (this->_smgr);
}

IGUIEnvironment *GUI::getEnv()
{
    return (this->_env);
}

std::map<models, IMesh *>  const &GUI::getMeshes()
{
    return (this->_meshes);
}

ITexture    *GUI::getTextures()
{
    return (this->_textures);
}

Board       *GUI::getBoard()
{
    return (this->_gameBoard);
}

void    GUI::initMap(int sizeX, int sizeY)
{
    this->_map = new t_square*[sizeY];
    for (int i = 0; i < sizeY; ++i)
        this->_map[i] = new t_square[sizeX];
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;
}

void    GUI::refreshMap(t_square const &toRefresh)
{
    static int  x = 0;
    static int  y = 0;
    
    //
    //modifications de la map
    //
    if (x == this->sizeX - 1)
    {
        x = 0;
        y++;
    }
    if (y == this->sizeY - 1)
        y = 0;
}

void    GUI::refreshGame()
{
    this->_gMap->setMap(this->_map);
    this->_gMap->setPlayers(this->_players);
    this->_gMap->dispMeshesOnBoard();
}

void    GUI::addPlayer(t_player const &newPlayer)
{
    GPlayer *playerToAdd = new(newPlayer, this->_meshes[PLAYER1]);
    this->_players.push_back(playerToAdd);
}