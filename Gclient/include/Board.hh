#ifndef BOARD_HH_
#define BOARD_HH_

#include <map>
#include <vector>
#include <string>
#include "irrlicht.h"
#include "common.h"
#include "Egg.hh"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

class   Board
{
    IMeshSceneNode      *_boardRootNode;
    SMaterial    _material;
    IMesh               *_square;
    u32                 _nbSquareSizeX;
    u32                 _nbSquareSizeY;
    std::vector<std::vector<Board *> > _underSquares;
    ITexture     *_texture;
    f32                 _squareSizeX;
    f32                 _squareSizeY;
    IAnimatedMeshSceneNode      *_playerNode;
    std::map<RESSOURCES, IMeshSceneNode *>  _ressourcesNodes;
    Egg                 *_egg;

    void    init();
public:
    Board(ISceneNode *parent, ISceneManager *smgr, s32 id, const vector3df &position, const vector3df &rotation, const vector3df &scale, u32 nbSquareSizeX, u32 nbSquareSizeY, ITexture *texture);
    ~Board();
    IMeshSceneNode  *getBoardRootNode();
    IMesh       *getSquare();
    u32         getNbSquareSizeX();
    u32         getNbSquareSizeY();
    std::vector<std::vector<Board *> > *getUnderSquares();
    void        setMaterialFlag(E_MATERIAL_FLAG flag, bool newvalue);
    void        setMaterialTexture(u32 textureLayer, ITexture *texture);
    void        setPosition (const vector3df &newpos);
    void        setScale(const vector3df &scale);
    void        setVisible (bool isVisible);
    void        remove();
    const vector3df   &getPosition() const;
    vector3df   getPositionUpperLeft() const;
    const vector3df   &getScale() const;
    ISceneManager   *getSceneManager(void) const;
    video::ITexture *getTexture();
    void            setPlayerNode(IAnimatedMeshSceneNode *newPlayerNode);
    IAnimatedMeshSceneNode  *getPlayerNode();
    f32             getSquareSizeX();
    f32             getSquareSizeY();
    IMesh           *getCurPlayerMesh();
    void            setCurPlayerMesh(IAnimatedMesh *newCurModelMesh);
    std::map<RESSOURCES, IMeshSceneNode *>  *getRessourcesNodes();
    void    setRessourcesNodes(std::map<RESSOURCES, IMeshSceneNode *>  const &resourcesNodes);
    Egg     *getEgg();
    void    setEgg(Egg *egg);
};

#endif