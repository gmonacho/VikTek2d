#include "Scene.h"
#include "Sprite.h"
#include <iostream>

namespace vt2
{


Scene          &Scene::updateScene()
{
    m_texture = vra::Texture{m_renderer,
                             SDL_PIXELFORMAT_RGBA32,
                             SDL_TEXTUREACCESS_TARGET,
                             m_rect.getW(),
                             m_rect.getH()};

    m_renderer->setTarget(&m_texture);
    m_renderer->setDrawColor(0, 0, 0, 255);
    m_renderer->clear();
    for (auto &ground : m_grounds)
    {
        for (Sprite *sprite : ground)
        {
            sprite->draw();
        }
    }
    m_renderer->setTarget(nullptr);
    return (*this);
}

Scene::Scene(vra::Renderer *renderer,
             const int &groundNumber,
             const int &x,
             const int &y,
             const int &w,
             const int &h) :
             m_renderer(renderer),
             m_rect{x, y, w, h},
             m_angle(0),
             m_flip(SDL_FLIP_NONE),
             m_center(w / 2, h / 2),
             m_hidden(false),
             m_texture(vra::Texture{renderer,
                             SDL_PIXELFORMAT_RGBA32,
                             SDL_TEXTUREACCESS_TARGET,
                             w,
                             h})
{
    m_grounds.resize(groundNumber);
}

void    Scene::draw()
{
    vra::Rect   rect;

    if (m_hidden == false)
    {
        this->updateScene();
        rect = m_rect - m_center;
        m_texture.setCenter(m_center.getX(), m_center.getY());
        m_texture.rotate(m_angle);
        m_texture.setFlip(m_flip);
        m_renderer->drawTexture(m_texture, nullptr, &rect);
        m_texture.rotate(-m_angle);
    }
}

Scene       &Scene::addSprite(Sprite *sprite, const int &groundIndex)
{
    if (groundIndex < m_grounds.size())
        m_grounds[groundIndex].push_front(sprite);
    return (*this);
}

}   //  namespace vt2
