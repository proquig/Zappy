#ifndef GCOMMUNICATOR_HH_
# define GCOMMUNICATOR_HH_

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "GUI.hh"
#include "SocketBuf.hpp"
#include "Tool.hh"



class   GCommunicator
{   
    typedef void (GCommunicator::*f)(std::string&);
   
    GUI             *_gui;
    Socket          _socket;
    fd_set          _readf;
    struct timeval  _tv;
    std::map<std::string, f>   _func_ptrs;
    public:
    GCommunicator(std::string const &address, int port, GUI *gui);
    ~GCommunicator();
    void    handleCommunications();
    void    fbienvenue(std::string &line);
    void    mszf(std::string &line);
    void    sgtf(std::string &line);
    void    bctf(std::string &line);
    void    tnaf(std::string &line);
    void    pnwf(std::string &line);
    void    pdif(std::string &line);
    void    segf(std::string &line);
    void    ppof(std::string &line);
};

#endif