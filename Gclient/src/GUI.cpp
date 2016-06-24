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
}

GUI::~GUI()
{
/*
    for (int i = 0; i < this->_sizeY; ++i)
        delete[] this->_map[i];
   delete[] this->_map;
*/
}

void    GUI::launch()
{
    int lastFPS = -1;
    int FPS;

  if (!(this->_device = createDevice(this->_driverType, this->_deskres, 32, false, false, false, 0)))
    exit(EXIT_FAILURE);
  this->_driver = _device->getVideoDriver();
  this->_smgr = _device->getSceneManager();
  this->_env = _device->getGUIEnvironment();
  this->_device->getCursorControl()->setVisible(false);

  sleep(1);
 
    if (loadMeshesAndTextures() == false)
    {
        std::cerr << "Error: 3D model or texture has not been loaded" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->_smgr->addCameraSceneNode(this->_smgr->getRootSceneNode(), core::vector3df(this->_sizeX * 10, (float)((float)this->_sizeY * 10) * ((float)this->_sizeX / 10), (float)this->_sizeY * 0.66f), core::vector3df(this->_sizeX * 10, 0, (float)((float)this->_sizeY * 10) - ((float)this->_sizeY * 0.66f)));
    //this->_smgr->addCameraSceneNodeMaya(this->_smgr->getRootSceneNode());

    this->_gameBoard = new Board(this->_smgr->getRootSceneNode(), this->_smgr, 1, vector3df(10 * this->_sizeX, 0.0f, 10 * this->_sizeY), vector3df(0.0f, 0.0f, 0.0f), vector3df(20 * this->_sizeX, 0.0f, 20 * this->_sizeY), this->_sizeX, this->_sizeY, this->_floor);
    this->_gMap = new GMap(this->_smgr, this->_gameBoard, this->_ressourcesMeshes, this->_playersMeshes);

    while (this->_device->run())
    {
        if (this->_device->isWindowActive())
        {
            FPS = this->_driver->getFPS();
            this->_driver->beginScene(true, true, irr::video::SColor(255,200,200,200));
            this->_smgr->drawAll();
            this->_env->drawAll();
            this->refreshGame();
            this->_driver->endScene();
            if (lastFPS != FPS)
            {
              stringw str = L"Zappy [";
              str += this->_driver->getName();
              str += "] FPS:";
              str += FPS;
              this->_device->setWindowCaption(str.c_str());
              lastFPS = FPS;
            }
        }
    }
}

bool    GUI::loadMeshesAndTextures()
{
    if ((this->_floor = this->_driver->getTexture("modelsAndTextures/Floor/grass2.jpg")) == nullptr)
        return (false);
    this->_ressourcesMeshes.insert(std::pair<RESSOURCES, IMesh*>(FOOD, this->_smgr->getMesh("modelsAndTextures/Pizza/pizza.obj")));
    this->_ressourcesMeshes.insert(std::pair<RESSOURCES, IMesh*>(LINEMATE, this->_smgr->getMesh("modelsAndTextures/Gems/diamond_gray.obj")));
    this->_ressourcesMeshes.insert(std::pair<RESSOURCES, IMesh*>(DERAUMERE, this->_smgr->getMesh("modelsAndTextures/Gems/diamond_green.obj")));
    this->_ressourcesMeshes.insert(std::pair<RESSOURCES, IMesh*>(SIBUR, this->_smgr->getMesh("modelsAndTextures/Gems/diamond_orange.obj")));
    this->_ressourcesMeshes.insert(std::pair<RESSOURCES, IMesh*>(MENDIANE, this->_smgr->getMesh("modelsAndTextures/Gems/large_diamond_yellow.obj")));
    this->_ressourcesMeshes.insert(std::pair<RESSOURCES, IMesh*>(PHIRAS, this->_smgr->getMesh("modelsAndTextures/Gems/large_diamond_blue.obj")));
    this->_ressourcesMeshes.insert(std::pair<RESSOURCES, IMesh*>(THYSTAME, this->_smgr->getMesh("modelsAndTextures/Gems/large_diamond_blue.obj")));
    this->_playersMeshes[0] = this->_smgr->getMesh("modelsAndTextures/Players/Level1/Brendan/Brendan_ColladaMax.DAE");
    this->_playersMeshes[1] = this->_playersMeshes[0];
    this->_playersMeshes[2] = this->_playersMeshes[0];
    this->_playersMeshes[3] = this->_playersMeshes[0];
    this->_playersMeshes[4] = this->_playersMeshes[0];
    this->_playersMeshes[5] = this->_playersMeshes[0];
    this->_playersMeshes[6] = this->_playersMeshes[0];
    this->_playersMeshes[7] = this->_playersMeshes[0];
    
    std::map<RESSOURCES, IMesh *>::iterator it = this->_ressourcesMeshes.begin();
    while (it != this->_ressourcesMeshes.end())
    {
        if (it->second == nullptr)
            return (false);
        ++it;
    }
    return (true);
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

std::map<RESSOURCES, IMesh *>  const &GUI::getRessourcesMeshes()
{
    return (this->_ressourcesMeshes);
}

std::array<IMesh *, 8>  const &GUI::getPlayersMeshes()
{
    return (this->_playersMeshes);
}

ITexture    *GUI::getTextures()
{
    return (this->_textures);
}

Board       *GUI::getBoard()
{
    return (this->_gameBoard);
}

void    GUI::initMap()
{
    int i = 0;
    this->_map = new t_square*[this->_sizeY + 2];
    for (int i = 0; i < this->_sizeY + 2; ++i)
        this->_map[i] = new t_square[this->_sizeX + 2];
/*    while (i < this->_sizeY + 2)
    {
        this->_map[i] = new t_square[this->_sizeX + 2];
        i++;
    }*/
}

void    GUI::refreshMap(t_square const &toRefresh)
{
    static int  x = 0;
    static int  y = 0;
    
    //
    //modifications de la map
    //
    if (x == this->_sizeX - 1)
    {
        x = 0;
        y++;
    }
    if (y == this->_sizeY - 1)
        y = 0;
}

void    GUI::refreshGame()
{
    this->_gMap->setMap(this->_map);
    this->_mutexes[0].lock();
    this->_gMap->refreshGMapPlayers(this->_players);
    this->_mutexes[0].unlock();
    this->_mutexes[1].lock();
    this->_gMap->refreshGMapRes();
    this->_mutexes[1].unlock();
}

void    GUI::addPlayer(t_player const &newPlayer)
{
    this->_mutexes[0].lock();
    GPlayer *playerToAdd = new GPlayer(newPlayer, this->_playersMeshes[0]);
    this->_players.push_back(playerToAdd);
    this->_mutexes[0].unlock();
}

void    GUI::removePlayer(int id)
{
    this->_mutexes[0].lock();
    std::vector<GPlayer *>::iterator    it = this->_players.begin();

    while (it != this->_players.end())
    {
        if ((*it)->getId() == id)
            this->_players.erase(it);
        ++it;
    }
    this->_mutexes[0].unlock();
}

void    GUI::setSizeX(int sizeX)
{
    this->_sizeX = sizeX;
}

void    GUI::setSizeY(int sizeY)
{
    this->_sizeY = sizeY;
}

t_square    **GUI::getMap()
{
    return (this->_map);
}

GPlayer     *GUI::getPlayer(int id)
{
    std::vector<GPlayer *>::iterator    it = this->_players.begin();

    while (it != this->_players.end())
    {
        if ((*it)->getId() == id)
            return (*it);
        ++it;
    }
    return (nullptr);
}

Mutex   *GUI::getMutexes()
{
    return (this->_mutexes);
}