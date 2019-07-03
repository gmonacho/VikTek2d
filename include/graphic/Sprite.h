#ifndef GRAPHIC_SPRITE_H_
#define GRAPHIC_SPRITE_H_

#include <string>
#include <Texture.h>
#include <Rect.h>
#include "GraphicObject.h"

namespace vt2
{

class Sprite : public GraphicObject
{
 private:
    vra::Renderer       *m_renderer;
    vra::Texture        *m_texture;
    vra::Rect           m_rect;
    float               m_angle;
    SDL_RendererFlip    m_flip;
    vra::Point          m_center;
    bool                m_hidden;

 public:
    Sprite(vra::Renderer *renderer,
           vra::Texture *texture,
           const int &x,
           const int &y,
           const int &w,
           const int &h);

    virtual             ~Sprite() = default;

    void                draw() override;

    Sprite              &setTexture(vra::Texture *texture);

    vra::Texture        *getTexture();
};

}   //  namespace vt2

#endif  //  GRAPHIC_SPRITE_H_
