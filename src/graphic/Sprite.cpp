#include <Renderer.h>
#include "Sprite.h"

namespace vt2
{

Sprite::Sprite(vra::Renderer *renderer,
               vra::Texture *texture,
               const int &x,
               const int &y,
               const int &w,
               const int &h) :
               m_renderer(renderer),
               m_texture(texture),
               m_rect(vra::Rect{x, y, w, h}),
               m_angle(0),
               m_flip(SDL_FLIP_NONE),
               m_center(vra::Point{w / 2, h / 2}),
               m_hidden(false) {}

void              Sprite::draw() const
{
    vra::Rect   rect;

    if (m_hidden == false)
    {
        rect = m_rect - m_center;
        m_texture->setCenter(m_center.getX(), m_center.getY());
        m_texture->rotate(m_angle);
        m_texture->setFlip(m_flip);
        m_renderer->drawTexture(*m_texture, nullptr, &rect);
        m_texture->rotate(-m_angle);
    }
}


Sprite          &Sprite::setTexture(vra::Texture *texture)
{
    if (texture != nullptr)
        m_texture = texture;
}

vra::Texture    *Sprite::getTexture()
{
    return (m_texture);
}

}   //  namespace vt2
