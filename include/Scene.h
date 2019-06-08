#include <Renderer.h>
#include <Rect.h>

namespace vt2d
{
    class Scene
    {
    private:
        vra::Renderer       &m_rend;
        vra::Rect           m_frame;

    public:
        explicit    Scene(vra::Renderer &renderer, vra::Rect frame);
        virtual     ~Scene();
    };
}