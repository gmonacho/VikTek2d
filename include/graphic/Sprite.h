
#ifndef GRAPHIC_SPRITE_H_
#define GRAPHIC_SPRITE_H_

#include <string>
#include <Texture.h>
#include <Rect.h>
#include <Camera.h>

namespace vt2
{

class Sprite
{
 private:
    vra::Texture  *m_texture;
    int           m_x, m_y, m_w, m_h;
    bool          m_hidden;

 public:
    Sprite(vra::Texture *texture,
           const int &x,
           const int &y,
           const int &w,
           const int &h);

    virtual             ~Sprite() = default;

   /**
    * @brief  draw the sprite
    * @note 
    * @param  *renderer: renderer where the sprite will be draw
    * @retval the sprite reference
    */
    Sprite              &draw(vra::Renderer *renderer) const;

    /**
     * @brief  move the sprite
     * @note   
     * @param  &dx: x distance
     * @param  &dy: y distance
     * @retval the sprite reference
     */
    Sprite              &move(const int &dx, const int &dy);

    /**
     * @brief  get the sprite's position
     * @note   
     * @retval vra::Point position{x, y}
     */
    vra::Point          getPosition() const;

     /**
      * @brief  set the sprite's position
      * @note   
      * @param  &x: x sprite's position
      * @param  &y: y sprite's position
      * @retval 
      */
    Sprite              &setPosition(const int &x, const int &y);

    /**
     * @brief  get the sprite's size
     * @note   
     * @retval the sprite's size
     */
    vra::Point          getSize();

     /**
      * @brief  set the sprite's width
      * @note   only if new width >= 0
      * @param  &width: new width
      * @retval the sprite reference
      */
    Sprite              &setWitdh(const int &width);

     /**
      * @brief  set the sprite's height
      * @note   only if new height >= 0
      * @param  &height: new height
      * @retval the sprite reference
      */
    Sprite              &setHeight(const int &height);

    /**
     * @brief  rotate the sprite
     * @note   
     * @param  angle: angle in degree
     * @retval None
     */
    Sprite              &rotate(const float &angle);

   /**
    * @brief  flip the sprite horizontaly or verticaly
    * @note   
    * @param  &sdlFlip: 
    *                   FLIP_HORIZONTAL
    *                   FLIP_VERTICAL
    * @retval the sprite's reference
    */
    Sprite              &flip(const Uint8 &way);

    /**
     * @brief  get sprite's angle rotation
     * @note   
     * @retval sprite's angle rotation
     */
    const float        &getAngle() const;

    /**
     * @brief  get sprite's center position
     * @note   
     * @retval sprite's center position
     */
    const vra::Point    &getCenter() const;

    /**
     * @brief  set sprite's center position
     * @note   
     * @retval sprite's center position
     */
    Sprite              &setCenter(const vra::Point &center);

     /**
      * @brief  hide the sprite
      * @note   
      * @retval sprite's reference
      */
    Sprite              &hide();

     /**
      * @brief  show the sprite
      * @note   
      * @retval sprite's reference
      */
    Sprite              &show();
};

enum e_flip
{
  FLIP_HORIZONTAL = 0b01,
  FLIP_VERTOCAL = 0b10
};

}   //  namespace vt2

#endif  //  GRAPHIC_SPRITE_H_
