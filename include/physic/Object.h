#ifndef PHYSIC_OBJECT_H_
#define PHYSIC_OBJECT_H_

#include <Point.h>

namespace vt2
{

class Object
{
 private:
    vra::Point  m_position;

 public:
    const vra::Point &getPosition() const;
    Object  &setX(const int &x);
    Object  &setY(const int &y);
};

}   //  namespace vt2

#endif  //  PHYSIC_OBJECT_H_
