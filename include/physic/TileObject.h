#ifndef PHYSIC_TILEOBJECT_H_
#define PHYSIC_TILEOBJECT_H_

#include "Object.h"
#include "Rect.h"

namespace vt2
{

class TileObject : public Object
{
 private:
    int         m_mass;
    vra::Rect   m_hitbox;
    vra::Point  m_velocity;

 public:
    TileObject(const int &mass, const vra::Rect &hitbox);
    ~TileObject() = default;

    const vra::Rect  &getHitbox() const;
};

}   //  namespace vt2

#endif  //  PHYSIC_TILEOBJECT_H_
