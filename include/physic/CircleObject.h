#ifndef PHYSIC_CIRCLEOBJECT_H_
#define PHYSIC_CIRCLEOBJECT_H_

#include "Object.h"
#include "Circle.h"

namespace vt2
{

class CircleObject : public Object
{
 private:
    int           m_mass;
    vra::Circle   m_hitbox;
    vra::Point    m_velocity;

 public:
    CircleObject(const int &mass, const vra::Circle &hitbox);
    ~CircleObject() = default;

    const vra::Circle   &getHitBox() const;
};

}   //  namespace vt2

#endif  //  PHYSIC_CIRCLEOBJECT_H_
