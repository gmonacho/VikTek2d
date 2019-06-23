#include "Scene.h"
// #include <Sprite.h>
// #include <Animation.h>

namespace vt2
{



Scene::Scene(const int &groundNumber)
{
    m_sprites.resize(groundNumber);
}

Scene   &Scene::draw() const
{
    for (const auto &ground : m_sprites)
    {
        for (const auto &graphicObj : ground)
        {
            graphicObj.draw();
        }
    }
}

}   //  namespace vt2
