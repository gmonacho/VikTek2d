#include "TileObject.h"

namespace vt2
{

TileObject::TileObject(const int &mass, const vra::Rect &hitbox) :
           m_mass(mass),
           m_hitbox(hitbox) {}


const vra::Rect  &TileObject::getHitbox() const
{
    return (m_hitbox);
}

}   //  namespace vt2
