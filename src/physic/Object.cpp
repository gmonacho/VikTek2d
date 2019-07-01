#include "Object.h"

namespace vt2
{

void    Object::setXVelocity(const int &xVelocity)
{
    m_velocity.setX(xVelocity);
}

void    Object::setYVelocity(const int &yVelocity)
{
    m_velocity.setY(yVelocity);
}

const vra::Point    &Object::getVelocity() const
{
    return (m_velocity);
}

void    Object::move()
{
    m_hitbox += m_velocity;
}

void    Object::setMass(const int &mass)
{
    m_mass = (mass < 0) ? 0 : mass;
}

const int   &Object::getMass() const
{
    return (m_mass);
}

}   //  namespace vt2
