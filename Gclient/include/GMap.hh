#ifndef GMAP_HH_
# define GMAP_HH_

#include <array>
#include <cstdlib>
#include <ctime>
#include "Board.hh"
#include "GPlayer.hh"

class   GMap
{
    ISceneManager   *_smgr;
    Board   *_board;
    std::map<RESSOURCES, IMesh *> _ressourcesMeshes; 
    std::array<IMesh *, 8> _playersMeshes;
    t_square                **_map;
   public:
     GMap(ISceneManager *smgr, Board *board, std::map<RESSOURCES, IMesh *> const &ressourcesMeshes, std::array<IMesh *, 8> const &playersMeshes);
     ~GMap();
     void   initGMap();
     void   initPlayerNode(Board *curBoard);
     void   initRessourcesNodes(Board *curBoard);
     vector3df  randomResPos(Board *curBoard, IMesh *res);
     void   refreshGMapRes();
     void   refreshGMapPlayers(std::vector<GPlayer *> const &players);
     void   clearAllRessources();
     void   clearAllPlayers();
     void   setMap(t_square **map);
};

#endif