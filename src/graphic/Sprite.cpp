#include <Sprite.h>
#include <Rect.h>
#include <Renderer.h>
#include <Camera.h>

namespace vt2
{

Sprite::Sprite(const vra::Renderer &renderer,
               const std::string &filepath,
               const int &x,
               const int &y,
               const int &w,
               const int &h) :
               m_x(x),
               m_y(y),
               m_w(w),
               m_h(h),
               m_hidden(false)
{
    m_texture = vra::Texture{renderer, filepath};
}

Sprite              &Sprite::draw(vra::Renderer *renderer)
{
    if (m_hidden == false)
    {
        vra::Rect   rect{m_x - m_texture.getCenter().getX(),
                         m_y - m_texture.getCenter().getY(),
                         m_w,
                         m_h};
        renderer->drawTexture(m_texture, nullptr, &rect);
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

Sprite              &Sprite::rotate(const double &angle)
{
    m_texture.rotate(angle);
    return (*this);
}

Sprite              &Sprite::flip(const Uint8 &way)
{
    if (way & FLIP_HORIZONTAL)
    {
        if (!(m_texture.getFlip() & SDL_FLIP_HORIZONTAL))
        {
            m_texture.setFlip(static_cast<SDL_RendererFlip>
                             (m_texture.getFlip() |
                              SDL_FLIP_HORIZONTAL));
        }
        else
        {
            m_texture.setFlip(static_cast<SDL_RendererFlip>
                             (m_texture.getFlip() - SDL_FLIP_HORIZONTAL));
        }
    }
}

const double        &Sprite::getAngle() const
{
    return (m_texture.getAngle());
}

const vra::Point    &Sprite::getCenter() const
{
    return (m_texture.getCenter());
}

Sprite              &Sprite::setCenter(const vra::Point &center)
{
    m_texture.setCenter(center);
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
