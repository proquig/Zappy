#ifndef GCOMMUNICATOR_HH_
# define GCOMMUNICATOR_HH_

#include "GUI.hh"

class   GCommunicator
{
    GUI *_gui;
    boost::asio::io_service _ios;
    
    boost::asio::ip::tcp::socket    *_socket;
    public:
    GCommunicator(std::string const &address, int port, GUI *gui);
    ~GCommunicator();
    void handleCommunications();
};

#endif