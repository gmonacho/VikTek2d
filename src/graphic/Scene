#include "Scene.h"

namespace vt2
{


Scene          &Scene::updateRendererSprite()
{
    m_texture = vra::Texture{m_renderer,
                             SDL_PIXELFORMAT_RGBA32,
                             SDL_TEXTUREACCESS_TARGET,
                             m_rendererSprite.getSize().getX(),
                             m_rendererSprite.getSize().getY()};

    m_renderer->setTarget(&m_texture);
    m_renderer->setDrawColor(0, 0, 0, 255);
    m_renderer->clear();
    for (auto &ground : m_sprites)
    {
        for (auto &[key, sprite] : ground)
        {
            sprite.draw(m_renderer);
        }
    }
    m_renderer->setTarget(nullptr);
    m_rendererSprite.setTexture(&m_texture);
    return (*this);
}

Scene::Scene(vra::Renderer *renderer,
             const int &groundNumber,
             const int &x,
             const int &y,
             const int &w,
             const int &h) :
             m_renderer(renderer),
             m_texture(vra::Texture{renderer,
                             SDL_PIXELFORMAT_RGBA32,
                             SDL_TEXTUREACCESS_TARGET,
                             w,
                             h}),
             m_rendererSprite(Sprite{&m_texture, x, y, w, h})
{
    m_sprites.resize(groundNumber);
}

Scene   &Scene::draw()
{
    m_rendererSprite.draw(m_renderer);
    return (*this);
}

Scene   &Scene::move(const int &dx, const int &dy)
{
    m_rendererSprite.move(dx, dy);
    return (*this);
}

Scene   &Scene::setPosition(const int &x, const int &y)
{
    m_rendererSprite.setPosition(x, y);
    return (*this);
}

Scene   &Scene::rotate(const float &angle)
{
    m_rendererSprite.rotate(angle);
    return (*this);
}

Scene   &Scene::setCenter(const int &x, const int &y)
{
    m_rendererSprite.setCenter(vra::Point{x, y});
    return (*this);
}

Scene   &Scene::setWidth(const int &width)
{
    m_rendererSprite.setWidth(width);
    return (*this);
}

Scene   &Scene::setHeight(const int &height)
{
    m_rendererSprite.setHeight(height);
    return (*this);
}

Scene   &Scene::setFlip(const SDL_RendererFlip &sdlFlip)
{
    m_rendererSprite.setFlip(sdlFlip);
    return (*this);
}

Scene   &Scene::hide()
{
    m_rendererSprite.hide();
    return (*this);
}

Scene   &Scene::show()
{
    m_rendererSprite.show();
    return (*this);
}

Scene   &Scene::addSprite(vra::Texture *texture,
                          const int &x,
                          const int &y,
                          const int &w,
                          const int &h,
                          const int &i_ground,
                          const std::string &key)
{
    // m_sprites[(i_ground > m_sprites.size() - 1)
    //           ? m_sprites.size() - 1 : i_ground
    //          ][key] = Sprite{texture, x, y, w, h};
    m_sprites[i_ground].insert(std::make_pair(key,
                                              Sprite{texture, x, y, w, h}));
    updateRendererSprite();
    return (*this);
}

Scene   &Scene::removeSprite(const std::string &key)
{
    for (auto &ground : m_sprites)
    {
        if (ground.find(key) != ground.end())
            ground.erase(key);
    }
    updateRendererSprite();
    return (*this);
}

const Sprite  &Scene::getSprite(const std::string &key)
{
    for (auto &ground : m_sprites)
    {
        if (ground.find(key) != ground.end())
            return (ground.find(key)->second);
    }
}

Scene   &Scene::setSpriteTexture(const std::string &key,
                                 vra::Texture *texture)
{
    for (auto &ground : m_sprites)
    {
        if (ground.find(key) != ground.end())
            ground.find(key)->second.setTexture(texture);
    }
    updateRendererSprite();
    return (*this);
}


Scene   &Scene::moveSprite(const std::string &key,
                           const int &dx,
                           const int &dy)
{
    for (auto &ground : m_sprites)
    {
        if (ground.find(key) != ground.end())
            ground.find(key)->second.move(dx, dy);
    }
    updateRendererSprite();
    return (*this);
}


Scene   &Scene::setSpritePosition(const std::string &key,
                                   const int &x,
                                   const int &y)
{
    for (auto &ground : m_sprites)
    {
        if (ground.find(key) != ground.end())
            ground.find(key)->second.setPosition(x, y);
    }
    updateRendererSprite();
    return (*this);
}

Scene   &Scene::setSpriteWidth(const std::string &key,
                               const int &width)
{
    for (auto &ground : m_sprites)
    {
        if (ground.find(key) != ground.end())
            ground.find(key)->second.setWidth(width);
    }
    updateRendererSprite();
    return (*this);
}


Scene   &Scene::setSpriteHeight(const std::string &key,
                                const int &height)
{
    for (auto &ground : m_sprites)
    {
        if (ground.find(key) != ground.end())
            ground.find(key)->second.setHeight(height);
    }
    updateRendererSprite();
    return (*this);
}


Scene   &Scene::rotateSprite(const std::string &key,
                              const float &angle)
{
    for (auto &ground : m_sprites)
    {
        if (ground.find(key) != ground.end())
            ground.find(key)->second.rotate(angle);
    }
    updateRendererSprite();
    return (*this);
}


Scene   &Scene::setSpriteFlip(const std::string &key,
                              const SDL_RendererFlip &sdlFlip)
{
    for (auto &ground : m_sprites)
    {
        if (ground.find(key) != ground.end())
            ground.find(key)->second.setFlip(sdlFlip);
    }
    updateRendererSprite();
    return (*this);
}


Scene   &Scene::setSpriteCenter(const std::string &key,
                                const vra::Point &center)
{
    for (auto &ground : m_sprites)
    {
        if (ground.find(key) != ground.end())
            ground.find(key)->second.setCenter(center);
    }
    updateRendererSprite();
    return (*this);
}


Scene   &Scene::hideSprite(const std::string &key)
{
        for (auto &ground : m_sprites)
    {
        if (ground.find(key) != ground.end())
            ground.find(key)->second.hide();
    }
    updateRendererSprite();
    return (*this);
}

Scene   &Scene::showSprite(const std::string &key)
{
        for (auto &ground : m_sprites)
    {
        if (ground.find(key) != ground.end())
            ground.find(key)->second.show();
    }
    updateRendererSprite();
    return (*this);
}

}   //  namespace vt2
