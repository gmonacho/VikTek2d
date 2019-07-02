#ifndef GRAPHIC_GRAPHICOBJECT_H_
#define GRAPHIC_GRAPHICOBJECT_H_

#include <Renderer.h>
#include <Texture.h>
#include <Rect.h>

namespace vt2
{

class GraphicObject
{
 private:
    vra::Renderer                   *m_renderer;
    vra::Rect                       m_rect;
    float                           m_angle;
    SDL_RendererFlip                m_flip;
    vra::Point                      m_center;
    bool                            m_hidden;

 public:
    virtual GraphicObject           &setRenderer(vra::Renderer *renderer);
    virtual vra::Renderer           *getRenderer() const;

    virtual void                    draw() const = 0;

    virtual GraphicObject           &move(const int &dx, const int &dy);

    virtual GraphicObject           &setPosition(const int &x, const int &y);
    virtual vra::Point              getPosition() const;

    virtual GraphicObject           &setWidth(const int &width);
    virtual GraphicObject           &setHeight(const int &height);
    virtual vra::Point              getSize() const;

    virtual GraphicObject           &rotate(const float &angle);
    virtual const float             &getAngle() const;

    virtual GraphicObject           &setFlip(const SDL_RendererFlip &sdlFlip);
    virtual const SDL_RendererFlip  &getFlip() const;

    virtual GraphicObject           &setCenter(const int &x, const int &y);
    virtual const vra::Point        &getCenter() const;

    virtual GraphicObject           &hide();
    virtual GraphicObject           &show();
    virtual const bool              &isHidden() const;
};

}   //  namespace vt2

#endif  //  GRAPHIC_GRAPHICOBJECT_H_
