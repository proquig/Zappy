#ifndef GCOMMUNICATOR_HH_
# define GCOMMUNICATOR_HH_

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "GUI.hh"
#include "SocketBuf.hpp"
#include "Tool.hh"
#include <thread>


class   GCommunicator
{   
    typedef void (GCommunicator::*f)(std::string&);
   
    GUI             *_gui;
    Socket          _socket;
    std::map<std::string, f>   _func_ptrs;
    std::thread     *_gui_thread;
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
    void    picf(std::string &line);
    void    enwf(std::string &line);
    void    ehtf(std::string &line);
    void    ebof(std::string &line);
    void    pgtf(std::string &line);
};

#endif