#include "GCommunicator.hh"

GCommunicator::GCommunicator(std::string const &address, int port, GUI *gui)
{
    struct sockaddr_in sin;

    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    if (address == "localhost")
        sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    else
        sin.sin_addr.s_addr = inet_addr(address.c_str());
    this->_gui = gui;
    this->_socket.setFdSocket(socket(PF_INET, SOCK_STREAM, 0));
    if (this->_socket.getFdSocket() == -1)
    {
        std::cerr << "Problem occured while creating socket" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->_tv.tv_sec = 1;
    this->_tv.tv_usec = 0;
    if (connect(this->_socket.getFdSocket(), (struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
        std::cerr << "Problem occured while connection to the server, please retry later" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->_socket.initFileFd();
/*    while (1)
    {
        FD_ZERO(&this->_readf);
        FD_SET(this->_socket._fd_socket, &this->_readf);
        if (select(this->_socket._fd_socket + 1, &this->_readf, NULL, NULL, &this->_tv) == -1)
            perror("select");
        if (FD_ISSET(this->_socket._fd_socket, &this->_readf))
        {*/

/*        }
    }*/
    this->_func_ptrs.insert(std::pair<std::string, f>("BIENVENUE", &GCommunicator::fbienvenue));
    this->_func_ptrs.insert(std::pair<std::string, f>("msz", &GCommunicator::mszf));
    this->_func_ptrs.insert(std::pair<std::string, f>("sgt", &GCommunicator::sgtf));
    this->_func_ptrs.insert(std::pair<std::string, f>("bct", &GCommunicator::bctf));
    this->_func_ptrs.insert(std::pair<std::string, f>("tna", &GCommunicator::tnaf));
    this->_func_ptrs.insert(std::pair<std::string, f>("pnw", &GCommunicator::pnwf));
    this->_func_ptrs.insert(std::pair<std::string, f>("pdi", &GCommunicator::pdif));
    this->_func_ptrs.insert(std::pair<std::string, f>("seg", &GCommunicator::segf));
    this->_func_ptrs.insert(std::pair<std::string, f>("ppo", &GCommunicator::ppof));
    this->_func_ptrs.insert(std::pair<std::string, f>("plv", &GCommunicator::sgtf));
    this->_func_ptrs.insert(std::pair<std::string, f>("pin", &GCommunicator::sgtf));
    this->_func_ptrs.insert(std::pair<std::string, f>("pex", &GCommunicator::sgtf));
    this->_func_ptrs.insert(std::pair<std::string, f>("pbc", &GCommunicator::sgtf));
    this->_func_ptrs.insert(std::pair<std::string, f>("pic", &GCommunicator::picf));
    this->_func_ptrs.insert(std::pair<std::string, f>("pie", &GCommunicator::sgtf));
    this->_func_ptrs.insert(std::pair<std::string, f>("pfk", &GCommunicator::sgtf));
    this->_func_ptrs.insert(std::pair<std::string, f>("pdr", &GCommunicator::sgtf));
    this->_func_ptrs.insert(std::pair<std::string, f>("pgt", &GCommunicator::sgtf));
    this->_func_ptrs.insert(std::pair<std::string, f>("enw", &GCommunicator::sgtf));
    this->_func_ptrs.insert(std::pair<std::string, f>("eht", &GCommunicator::sgtf));
    this->_func_ptrs.insert(std::pair<std::string, f>("ebo", &GCommunicator::sgtf));
    this->_func_ptrs.insert(std::pair<std::string, f>("edi", &GCommunicator::sgtf));
    this->_func_ptrs.insert(std::pair<std::string, f>("smg", &GCommunicator::sgtf));
    this->_func_ptrs.insert(std::pair<std::string, f>("suc", &GCommunicator::sgtf));
    this->_func_ptrs.insert(std::pair<std::string, f>("sbp", &GCommunicator::sgtf));
}

GCommunicator::~GCommunicator()
{
    
}

void    GCommunicator::handleCommunications()
{
    std::string line;
    std::string tmp;

    while (!((line = this->_socket.read()).empty()))
    {
        std::cout << line;
        line.resize(line.length() - 1);
        tmp = line.substr(0, line.find_first_of(' '));
        line = line.substr(line.find_first_of(' ') + 1, line.length());
        (this->*_func_ptrs[tmp])(line);
        line.clear();
        tmp.clear();
    }
}

void    GCommunicator::fbienvenue(std::string &line)
{
    this->_socket.my_write("GRAPHIC\n");
}

void    GCommunicator::mszf(std::string &line)
{
    this->_gui->setSizeX(std::stoi(line.substr(0, line.find(' '))));
    this->_gui->setSizeY(std::stoi(line.substr(line.find(' ') + 1, line.length())));
    this->_gui->initMap();
}

void    GCommunicator::sgtf(std::string &line)
{
    
}

void    GCommunicator::bctf(std::string &line)
{
    std::vector<std::string>    words = Tool::strToWordVector(line, ' ');

    this->_gui->getMap()[std::stoi(words[0])][std::stoi(words[1])].res.res[FOOD] = std::stoi(words[2]);
    this->_gui->getMap()[std::stoi(words[0])][std::stoi(words[1])].res.res[LINEMATE] = std::stoi(words[3]);
    this->_gui->getMap()[std::stoi(words[0])][std::stoi(words[1])].res.res[DERAUMERE] = std::stoi(words[4]);
    this->_gui->getMap()[std::stoi(words[0])][std::stoi(words[1])].res.res[SIBUR] = std::stoi(words[5]);
    this->_gui->getMap()[std::stoi(words[0])][std::stoi(words[1])].res.res[MENDIANE] = std::stoi(words[6]);
    this->_gui->getMap()[std::stoi(words[0])][std::stoi(words[1])].res.res[PHIRAS] = std::stoi(words[7]);
    this->_gui->getMap()[std::stoi(words[0])][std::stoi(words[1])].res.res[THYSTAME] = std::stoi(words[8]);
}

void    GCommunicator::tnaf(std::string &line)
{
    
}

void    GCommunicator::pnwf(std::string &line)
{
    t_player    newPlayer;
    std::vector<std::string>    words = Tool::strToWordVector(line, ' ');

    newPlayer.fd = std::stoi(words[0]);
    newPlayer.x = std::stoi(words[1]);
    newPlayer.y = std::stoi(words[2]);
    if (std::stoi(words[3]) == 1)
        newPlayer.dir = RIGHT;
    else if (std::stoi(words[3]) == 3)
        newPlayer.dir = LEFT;
    else
        newPlayer.dir = (Direction)std::stoi(words[3]);
    newPlayer.lvl = std::stoi(words[4]);
    this->_gui->addPlayer(newPlayer);
}

void    GCommunicator::pdif(std::string &line)
{
    this->_gui->removePlayer(std::stoi(line));
}

void    GCommunicator::segf(std::string &line)
{
    std::cout << "team '" << line << "' win the game !" << std::endl;
    exit(EXIT_SUCCESS);
}

void    GCommunicator::ppof(std::string &line)
{
    this->_gui->getMutexes()[0].lock();
    std::vector<std::string>    words = Tool::strToWordVector(line, ' ');
    GPlayer *curPlayer = this->_gui->getPlayer(std::stoi(words[0]));

    curPlayer->setX(std::stoi(words[1]));
    curPlayer->setY(std::stoi(words[2]));
    if (std::stoi(words[3]) == 1)
        curPlayer->setDirection(RIGHT);
    else if (std::stoi(words[3]) == 3)
        curPlayer->setDirection(LEFT);
    else
        curPlayer->setDirection((Direction)std::stoi(words[3]));
    this->_gui->getMutexes()[0].unlock();
}

void    GCommunicator::picf(std::string &line)
{
    this->_gui->getMutexes()[0].lock();
    std::vector<std::string>    words = Tool::strToWordVector(line, ' ');
    std::vector<std::string>::iterator  it = words.begin();
    GPlayer *curPlayer;

    it += 3;
    while (it != words.end())
    {
        curPlayer = this->_gui->getPlayer(std::stoi(*it));
        curPlayer->setLvl(std::stoi(words[2]));
        ++it;
    }    
    this->_gui->getMutexes()[0].unlock();
}