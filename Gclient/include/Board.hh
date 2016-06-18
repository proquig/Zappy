#ifndef BOARD_HH_
#define BOARD_HH_

#include <map>
#include <vector>
#include <string>
#include "irrlicht.h"
#include "common.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

class   Board
{
    IMeshSceneNode      *_boardRootNode;
    SMaterial    _material;
    IMesh               *_square;
    u32                 _nbSquareSize;
    std::vector<std::vector<Board *> > _underSquares;
    ITexture     *_texture;
    f32                 _squareSize;
    IMeshSceneNode      *_playerNode;
    std::map<RESSOURCES, IMeshSceneNode *>  _ressourcesNodes;

    void    init();
public:
    Board(ISceneNode *parent, ISceneManager *smgr, s32 id, const vector3df &position, const vector3df &rotation, const vector3df &scale, u32 nbSquareSize, ITexture *texture);
    ~Board();
    IMeshSceneNode  *getBoardRootNode();
    IMesh       *getSquare();
    u32         getNbSquareSize();
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
    void            setPlayerNode(IMeshSceneNode *newPlayerNode);
    IMeshSceneNode  *getPlayerNode();
    f32             getSquareSize();
    IMesh           *getCurPlayerMesh();
    void            setCurPlayerMesh(IMesh *newCurModelMesh);
    std::map<RESSOURCES, IMeshSceneNode *>  *getRessourcesNodes();
    void    setRessourcesNodes(std::map<RESSOURCES, IMeshSceneNode *>  const &resourcesNodes);
};

#endif