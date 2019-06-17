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
    Text(const vra::Renderer &renderer,
         const std::string &text,
         vra::Font *font,
         const int &x,
         const int &y,
         const int &w,
         const int &h,
         const SDL_Color &color);

    ~Text() = default;  //  pour le moment

    Text    &draw(vra::Renderer *renderer);

    Text    &setText(const vra::Renderer &renderer,
                     const std::string &text);

    const std::vector<std::string>   &getText() const;

    Text          &setAlign(const Uint8 alignment);

    const Uint8   &getAlign() const;

    Text    &setColor(const vra::Renderer &renderer,
                            const SDL_Color &color);

    const SDL_Color  &getColor() const;
};

enum  e_alignment {TEXT_AL_LEFT, TEXT_AL_MIDDLE, TEXT_AL_RIGHT};

}   //  namespace vt2


#endif  //  GRAPHIC_TEXT_H_
