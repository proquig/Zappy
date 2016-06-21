#include "GUI.hh"

int main(int ac, char **av)
{
    if (ac == 3)
    {        
        GUI gui(std::string(av[1]), atoi(av[2]));
        gui.launch();
    }
    else
        std::cout << "Usage : ./zappy_Gclient [server address] [port]" << std::endl;
    return (0);
}