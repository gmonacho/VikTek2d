#ifndef GRAPHIC_CAMERA_H_
#define GRAPHIC_CAMERA_H_

#include <Point.h>

namespace vt2
{

class Camera
{
 private:
    int         m_x, m_y;
    float       m_zoom;
    float       m_angle;

 public:

     /**
      * @brief  Construct Camera from given position and zoom values
      * @note   
      * @param  &x: x Camera's position
      * @param  &y: y Camera's position
      * @param  &zoom: Camera's zoom, 1 mean no zoom, normal view
      * @retval None
      */
    explicit    Camera(const int &x, const int &y, const float &zoom);

     /**
      * @brief  defautl destructor
      * @note   
      * @retval None
      */
    virtual     ~Camera() = default;

     /**
      * @brief  get the Camera's position
      * @note   
      * @retval vra::Point{x, y}
      */
    vra::Point  getPosition() const;

     /**
      * @brief  move the camera
      * @note   
      * @param  &dx: x distance
      * @param  &dy: y distance
      * @retval 
      */
    Camera      &move(const int &dx, const int &dy);

     /**
      * @brief  get the Camera's zoom
      * @note   
      * @retval the Camera's zoom
      */
    const float &getZoom() const;

     /**
      * @brief  set the Camera's zoom
      * @note   if zoom value is negative it did nothing
      * @param  &zoom: new zoom value
      * @retval the Camera's reference
      */
    Camera      &setZoom(const float &zoom);

     /**
      * @brief  get the camera's angle rotation
      * @note   
      * @retval the camera's angle rotation
      */
    const float &getAngle() const;

     /**
      * @brief  rotate the camera in degree
      * @note   
      * @param  &angle: rotation in degree
      * @retval the Camera's reference
      */
    Camera      &rotate(const float &angle);
};

}   //  namespace vt2

#endif  //  GRAPHIC_CAMERA_H_
