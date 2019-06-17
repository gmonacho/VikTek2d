#ifndef GRAPHIC_TEXT_H_
#define GRAPHIC_TEXT_H_

#include <string>
#include <vector>
#include <Font.h>
#include <Renderer.h>
#include <Sprite.h>

namespace vt2
{

class Text
{
 private:
    vra::Font                   *m_font;
    std::vector<std::string>     m_tabText;
    std::vector<vra::Texture>    m_tabTexture;
    std::vector<vra::Rect>       m_tabRect;
    SDL_Color                    m_color;
    Uint8                        m_alignment;
    int                          m_x, m_y, m_w, m_h;

    Text    &updateTabTexture(const vra::Renderer &renderer);
    Text    &alignLeft();
    Text    &alignRight();
    Text    &alignMiddle();

 public:
     /**
      * @brief  Construct an object Text from the given string.
      * @note   
      * @param  &renderer: vra::Renderer
      * @param  &text: each '\n' will return to the line
      * @param  *font: font wich will render the text
      * @param  &x: x text's position
      * @param  &y: y text's position
      * @param  &w: text's width
      * @param  &h: text's height
      * @param  &color: font color
      * @retval 
      */
    Text(const vra::Renderer &renderer,
         const std::string &text,
         vra::Font *font,
         const int &x,
         const int &y,
         const int &w,
         const int &h,
         const SDL_Color &color);

    ~Text() = default;

     /**
      * @brief  draw the text's object
      * @note   
      * @param  *renderer: 
      * @retval the text's reference
      */
    Text    &draw(vra::Renderer *renderer);

     /**
      * @brief  set the text's Font
      * @note   
      * @param  &renderer: 
      * @param  *font: 
      * @retval the text's reference
      */
    Text    &setFont(const vra::Renderer &renderer,
                     vra::Font *font);

     /**
      * @brief  get the text's font
      * @note   
      * @retval the text's font
      */
    vra::Font *getFont() const;

     /**
      * @brief  set the text value
      * @note   
      * @param  &renderer: 
      * @param  &text: each '\n' will return to the line
      * @retval the text value
      */
    Text    &setText(const vra::Renderer &renderer,
                     const std::string &text);

     /**
      * @brief  get the text's value
      * @note   each line is stocked in a raw
      * @retval a vector filled with the text's lines
      */
    const std::vector<std::string>   &getText() const;

     /**
      * @brief  set text's alignment
      * @note   
      * @param  alignment: TEXT_AL_LEFT, TEXT_AL_MIDDLE, TEXT_AL_RIGHT
      * @retval the text's reference
      */
    Text          &setAlign(const Uint8 alignment);

     /**
      * @brief  get text's alignment
      * @note   TEXT_AL_LEFT, TEXT_AL_MIDDLE, TEXT_AL_RIGHT
      * @retval the text's reference
      */
    const Uint8   &getAlign() const;

     /**
      * @brief  set the text's color
      * @note   
      * @param  &renderer: 
      * @param  &color: SDL_Color
      * @retval the text's reference
      */
    Text    &setColor(const vra::Renderer &renderer,
                            const SDL_Color &color);

     /**
      * @brief  get the text's color
      * @note   
      * @retval the text's color
      */
    const SDL_Color  &getColor() const;
};

enum  e_alignment {TEXT_AL_LEFT, TEXT_AL_MIDDLE, TEXT_AL_RIGHT};

}   //  namespace vt2


#endif  //  GRAPHIC_TEXT_H_
