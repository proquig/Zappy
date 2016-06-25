#include "Egg.hh"

Egg::Egg(ISceneManager *smgr, IMeshSceneNode *parent, IMesh *eggMesh)
{
    this->_id = -1;
    this->_init(smgr, parent, eggMesh);
}

Egg::~Egg()
{
    
}
#include <iostream>
void    Egg::_init(ISceneManager *smgr, IMeshSceneNode *parent, IMesh *eggMesh)
{
    vector3df   meshRepos = vector3df((parent->getBoundingBox().getExtent().X / 2) - (eggMesh->getBoundingBox().getExtent().X * 4), 1.0f / eggMesh->getBoundingBox().getExtent().Y, (parent->getBoundingBox().getExtent().Z / 2) - (eggMesh->getBoundingBox().getExtent().Z * 4));
    f32 meshRescale = 6.0f / ((eggMesh->getBoundingBox().getExtent().X + eggMesh->getBoundingBox().getExtent().Y + eggMesh->getBoundingBox().getExtent().Z) / 3.0f);
    this->_node = smgr->addMeshSceneNode(eggMesh, parent, -1, meshRepos, vector3df(0.0f, 0.0f, 0.0f), vector3df(meshRescale, meshRescale, meshRescale));
    this->_node->setMaterialFlag(EMF_WIREFRAME, false);
    this->_node->setMaterialFlag(EMF_LIGHTING, false);
    this->_node->setMaterialType(EMT_SOLID);
    this->_node->setVisible(false);
}

int     Egg::getId()
{
    return (this->_id);
}

void    Egg::setId(int id)
{
    this->_id = id;
}

IMeshSceneNode  *Egg::getNode()
{
    return (this->_node);
}

void    Egg::setVisible(bool visibility)
{
    this->_node->setVisible(visibility);
}