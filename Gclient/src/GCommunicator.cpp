#include "GCommunicator.hh"

GCommunicator::GCommunicator(std::string const &address, int port, GUI *gui)
{
    this->_gui = gui;
    boost::asio::ip::tcp::endpoint ep;
    if (address == "localhost")
        ep = boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), port);
    else
	    ep = boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(address), port);
     this->_socket = new boost::asio::ip::tcp::socket(this->_ios);
     std::cout << "Establishing connection to the server..." << std::endl;
     try
     {
        this->_socket->connect(ep);
     }
     catch(boost::system::system_error &e)
     {
      e.what();
         exit(EXIT_FAILURE);
     }
}

GCommunicator::~GCommunicator()
{
    
}

void    GCommunicator::handleCommunications()
{
    
}