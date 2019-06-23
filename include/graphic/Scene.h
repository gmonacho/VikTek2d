#ifndef GRAPHIC_SCENE_H_
#define GRAPHIC_SCENE_H_

#include <vector>
#include <map>
#include <string>
#include "Sprite.h"

namespace vt2
{

class Scene
{
 private:
    std::vector<std::map<std::string, Sprite>>     m_sprites;

 public:
    explicit Scene(const int &groundNumber);
    Scene   &addGraphicObject(Sprite graphicObj, const int &groundTier);
    Scene   &draw() const;
};

}   //  namespace vt2

#endif  //  GRAPHIC_SCENE_H_
