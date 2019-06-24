#include "Scene.h"
// #include <Sprite.h>
// #include <Animation.h>

namespace vt2
{



Scene::Scene(vra::Renderer *renderer,
             const int &groundNumber) :
             m_renderer(renderer)
{
    m_sprites.resize(groundNumber);
}

Scene   &Scene::addSprite(Sprite *sprite,
                          const int &i_ground,
                          const std::string &key)
{
    m_sprites[(i_ground > m_sprites.size() - 1)
              ? m_sprites.size() - 1 : i_ground
             ][key] = sprite;
    return (*this);
}

Scene   &Scene::draw()
{
    for (int i_ground{0}; i_ground < m_sprites.size(); i_ground++)
    {
        for (const auto &[key, sprite] : m_sprites[i_ground])
        {
            sprite->draw(m_renderer);
        }
    }
    return (*this);
}

Sprite  *Scene::getSprite(const std::string &key)
{
    for (auto &ground : m_sprites)
    {
        if (ground.find(key) != ground.end())
            return (ground[key]);
    }
    return (nullptr);
}

Scene   &Scene::removeSprite(const std::string &key)
{
    for (auto &ground : m_sprites)
    {
        if (ground.find(key) != ground.end())
            ground.erase(key);
    }
}

}   //  namespace vt2
