#ifndef PHYSIC_OBJECT_H_
#define PHYSIC_OBJECT_H_

#include <Point.h>

namespace vt2
{

class Object
{
 private:
    int         m_mass;
    vra::Point  m_hitbox;
    vra::Point  m_velocity;

 public:
    void                setXVelocity(const int &xVelocity);
    void                setYVelocity(const int &yVelocity);
    const vra::Point    &getVelocity() const;
    void                move();

    void                setMass(const int &mass);
    const int           &getMass() const;
};

}   //  namespace vt2

#endif  //  PHYSIC_OBJECT_H_
