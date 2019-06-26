#include <Sprite.h>
#include <Rect.h>
#include <Renderer.h>
#include <Camera.h>

namespace vt2
{

Sprite::Sprite(vra::Texture *texture,
               const int &x,
               const int &y,
               const int &w,
               const int &h) :
               m_x(x),
               m_y(y),
               m_w(w),
               m_h(h),
               m_angle(0),
               m_flip(SDL_FLIP_NONE),
               m_center(vra::Point{m_w / 2, m_h / 2}),
               m_hidden(false),
               m_texture(texture) {}

Sprite              &Sprite::draw(vra::Renderer *renderer)
{
    if (m_hidden == false)
    {
        vra::Rect   rect{m_x - m_center.getX(),
                         m_y - m_center.getY(),
                         m_w,
                         m_h};
        m_texture->setCenter(m_center);
        m_texture->rotate(m_angle);
        m_texture->setFlip(m_flip);
        renderer->drawTexture(*m_texture, nullptr, &rect);
        m_texture->rotate(-m_angle);
    }
    return (*this);
}

Sprite              &Sprite::move(const int &dx, const int &dy)
{
    m_x += dx;
    m_y += dy;
    return (*this);
}

vra::Point          Sprite::getPosition() const
{
    return (vra::Point{m_x, m_y});
}

Sprite              &Sprite::setPosition(const int &x, const int &y)
{
    m_x = x;
    m_y = y;
    return (*this);
}

vra::Point          Sprite::getSize()
{
    return (vra::Point{m_w, m_h});
}

Sprite              &Sprite::setWitdh(const int &width)
{
    if (width >= 0)
        m_w = width;
}

Sprite              &Sprite::setHeight(const int &height)
{
    if (height >= 0)
        m_h = height;
}

Sprite              &Sprite::rotate(const float &angle)
{
    m_angle += angle;
    return (*this);
}

Sprite      &Sprite::setFlip(const SDL_RendererFlip &sdlFlip)
{
    m_flip = sdlFlip;
    return (*this);
}

const float     &Sprite::getAngle() const
{
    return (m_angle);
}

const vra::Point    &Sprite::getCenter() const
{
    return (m_center);
}

Sprite              &Sprite::setCenter(const vra::Point &center)
{
    m_center = center;
    return (*this);
}

Sprite              &Sprite::hide()
{
    m_hidden = true;
}

Sprite              &Sprite::show()
{
    m_hidden = false;
}

}   //  namespace vt2
