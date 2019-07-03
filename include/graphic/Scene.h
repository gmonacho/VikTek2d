#ifndef GRAPHIC_SCENE_H_
#define GRAPHIC_SCENE_H_

#include <vector>
#include <forward_list>
#include <string>
#include <Renderer.h>
#include <Texture.h>
#include "GraphicObject.h"

namespace vt2
{
class Sprite;

class Scene : public GraphicObject
{
 private:

    vra::Renderer                               *m_renderer;
    vra::Rect                                   m_rect;
    float                                       m_angle;
    SDL_RendererFlip                            m_flip;
    vra::Point                                  m_center;
    bool                                        m_hidden;
    vra::Texture                                m_texture;
    std::vector<std::forward_list <Sprite*>>    m_grounds;

    Scene          &updateScene();

 public:
    Scene(vra::Renderer *renderer,
          const int &groundNumber,
          const int &x,
          const int &y,
          const int &w,
          const int &h);

    virtual ~Scene() = default;

    void            draw() override;

    Scene           &addSprite(Sprite *sprite, const int &groundIndex);

};

}   //  namespace vt2
#endif  //  GRAPHIC_SCENE_H_
