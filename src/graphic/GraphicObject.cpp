#include "GraphicObject.h"

namespace vt2
{

GraphicObject   &GraphicObject::setRenderer(vra::Renderer *renderer)
{
    m_renderer = renderer;
    return (*this);
}

vra::Renderer   *GraphicObject::getRenderer() const
{
    return (m_renderer);
}

GraphicObject   &GraphicObject::move(const int &dx,
                                     const int &dy)
{
    m_rect.move(dx, dy);
    return (*this);
}

GraphicObject   &GraphicObject::setPosition(const int &x,
                                            const int &y)
{
    m_rect.setSdlRect(SDL_Rect{x, y, m_rect.getW(), m_rect.getH()});
    return (*this);
}

vra::Point      GraphicObject::getPosition() const
{
    return (vra::Point{m_rect.getX(), m_rect.getY()});
}

GraphicObject   &GraphicObject::setWidth(const int &width)
{
    m_rect.setSdlRect(SDL_Rect{m_rect.getX(),
                               m_rect.getY(),
                               width,
                               m_rect.getH()});
    return (*this);
}

GraphicObject   &GraphicObject::setHeight(const int &height)
{
    m_rect.setSdlRect(SDL_Rect{m_rect.getX(),
                               m_rect.getY(),
                               m_rect.getW(),
                               height});
    return (*this);
}

vra::Point      GraphicObject::getSize() const
{
    return (vra::Point{m_rect.getW(), m_rect.getH()});
}

GraphicObject   &GraphicObject::rotate(const float &angle)
{
    m_angle += angle;
    if (m_angle >= 360)
        m_angle = m_angle / 360 * 360;
    return (*this);
}

const float     &GraphicObject::getAngle() const
{
    return (m_angle);
}

GraphicObject   &GraphicObject::setFlip(const SDL_RendererFlip &sdlFlip)
{
    m_flip = sdlFlip;
    return (*this);
}

const SDL_RendererFlip  &GraphicObject::getFlip() const
{
    return (m_flip);
}

GraphicObject   &GraphicObject::setCenter(const int &x,
                                          const int &y)
{
    m_center.setX(x).setY(y);
    return (*this);
}

const vra::Point    &GraphicObject::getCenter() const
{
    return (m_center);
}

GraphicObject   &GraphicObject::hide()
{
    m_hidden = true;
    return (*this);
}

GraphicObject   &GraphicObject::show()
{
    m_hidden = false;
    return (*this);
}

const bool      &GraphicObject::isHidden() const
{
    return (m_hidden);
}

}   //  namespace vt2
