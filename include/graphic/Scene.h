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
    std::vector<std::map<std::string, Sprite*>>    m_sprites;
// std::vector<std::map<std::string, Animation*>>  m_animations;

    vra::Renderer *m_renderer;


 public:
    explicit Scene(vra::Renderer *renderer, const int &groundNumber);
    ~Scene() = default;
    Scene   &addSprite(Sprite *sprite,
                       const int &i_ground,
                       const std::string &key);
    Scene   &draw();
    Sprite  *getSprite(const std::string &key);
    Scene   &removeSprite(const std::string &key);
};

}   //  namespace vt2

#endif  //  GRAPHIC_SCENE_H_
