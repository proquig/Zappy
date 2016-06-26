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
      std::array<IAnimatedMesh *, 8> _playersMeshes;
      t_square                **_map;
   public:
      GMap(ISceneManager *smgr, Board *board, std::map<RESSOURCES, IMesh *> const &ressourcesMeshes, std::array<IAnimatedMesh *, 8> const &playersMeshes, IMesh *eggMesh);
      ~GMap();
      void   initGMap(IMesh *eggMesh);
      void   initPlayerNode(Board *curBoard);
      void   initRessourcesNodes(Board *curBoard);
      void   initEggNode(Board *curBoard, IMesh *eggMesh);
      vector3df  randomResPos(Board *curBoard, IMesh *res);
      void   refreshGMapRes();
      void   refreshGMapPlayers(std::vector<GPlayer *> const &players);
      void   clearAllRessources();
      void   clearAllPlayers();
      void   setMap(t_square **map);
      void        popEgg(int id, int x, int y);
      void        eraseEgg(int id);
};

#endif