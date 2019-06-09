#include <Camera.h>
#include <Point.h>

namespace vt2
{

Camera::Camera(const int &x, const int &y, const float &zoom) :
               m_x(x),
               m_y(y),
               m_zoom(zoom) {}

vra::Point  Camera::getPosition() const
{
    return (vra::Point{m_x, m_y});
}

Camera      &Camera::move(const int &dx, const int &dy)
{
    m_x += dx;
    m_y += dy;
}

const float &Camera::getZoom() const
{
    return (m_zoom);
}

Camera      &Camera::setZoom(const float &zoom)
{
    if (zoom > 0)
    {
        m_zoom = zoom;
    }
}

const float &Camera::getAngle() const
{
    return (m_angle);
}

Camera      &Camera::rotate(const float &angle)
{
    m_angle += angle;
}

}   //  namespace vt2
