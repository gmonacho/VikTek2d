#include "CircleObject.h"

namespace vt2
{

CircleObject::CircleObject(const int &mass, const vra::Circle &hitbox) :
                           m_mass(mass), m_hitbox(hitbox) {}


const vra::Circle   &CircleObject::getHitBox() const
{
    return (m_hitbox);
}

}   //  namespace vt2
