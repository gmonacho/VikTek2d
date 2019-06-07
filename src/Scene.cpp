#include "Scene.h"

namespace vt2d
{
    Scene::Scene(vra::Renderer &renderer, vra::Rect frame) : m_rend(renderer), m_frame(frame)
    {
    }

    Scene::~Scene()
    {
    }
}