#ifndef BOARD_HH_
#define BOARD_HH_

#include "irrlicht.h"
#include <vector>
#include <string>

using namespace irr;
using namespace core;
using namespace scene;

class   Board
{
    IMeshSceneNode      *_squareNode;
    video::SMaterial    _material;
    IMesh               *_square;
    u32                 _nbSquareSize;
    std::vector<std::vector<Board *> > _underSquares;
    video::ITexture     *_texture;
    f32                 _squareSize;
    IMeshSceneNode      *_blockNode;

    void    init();
public:
    IMesh         *curBlockMesh;

    Board(ISceneNode *parent, ISceneManager *smgr, s32 id, const vector3df &position, const vector3df &rotation, const vector3df &scale, u32 nbSquareSize, video::ITexture *texture);
    ~Board();
    IMeshSceneNode  *getSquareNode();
    IMesh       *getSquare();
    u32         getNbSquareSize();
    std::vector<std::vector<Board *> > *getUnderSquares();
    void        setMaterialFlag(video::E_MATERIAL_FLAG flag, bool newvalue);
    void        setMaterialTexture(u32 textureLayer, video::ITexture *texture);
    void        setPosition (const core::vector3df &newpos);
    void        setScale(const core::vector3df &scale);
    void        setVisible (bool isVisible);
    void        remove();
    const core::vector3df   &getPosition() const;
    core::vector3df         getPositionUpperLeft() const;
    const core::vector3df   &getScale() const;
    ISceneManager   *getSceneManager(void) const;
    video::ITexture *getTexture();
    void            setBlockNode(IMeshSceneNode *newBlockNode);
    IMeshSceneNode  *getBlockNode();
    f32             getSquareSize();
};

#endif