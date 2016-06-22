#include "GUI.hh"
#include "GCommunicator.hh"

int main(int ac, char **av)
{
    if (ac == 3)
    {        
        GUI gui;
        GCommunicator communicator(std::string(av[1]), atoi(av[2]), &gui);
        gui.launch();
    }
    else
        std::cout << "Usage : ./zappy_Gclient [server address] [port]" << std::endl;
    return (0);
}