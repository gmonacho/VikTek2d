#include "Object.h"

namespace vt2
{

const vra::Point    &Object::getPosition() const
{
    return (m_position);
}

Object  &Object::setX(const int &x)
{
    m_position.setX(x);
}

Object  &Object::setY(const int &y)
{
    m_position.setY(y);
}

}   //  namespace vt2
