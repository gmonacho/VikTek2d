#include <Text.h>
#include <iostream>
#include <Font.h>
#include <Renderer.h>
#include <Exception.h>
#include "vikString.h"

namespace vt2
{

Text    &Text::updateTabTexture(const vra::Renderer &renderer)
{
    for (int i{0}; i < m_tabText.size(); i++)
    {
        if (i < m_tabTexture.size())
            m_tabTexture[i] = m_font->renderText(renderer,
                                            m_tabText[i],
                                            m_color);
        else
            m_tabTexture.push_back(m_font->renderText(renderer,
                                m_tabText[i],
                                m_color));
    }
    if (m_tabTexture.empty())
        throw(std::logic_error("text rendering failed"));
    Text::setAlign(m_alignment);
    return (*this);
}

Text    &Text::alignLeft()
{
    int         i{0};
    vra::Rect   lineRect;
    int         lineHeight;
    int         lineWidth;
    int         maxWidth{0};

    while (i < m_tabTexture.size())
    {
        if (m_tabTexture[i].getSdlRect().w > maxWidth)
            maxWidth = m_tabTexture[i].getSdlRect().w;
        i++;
    }
    lineHeight = m_h / m_tabTexture.size();
    i = 0;
    while (i < m_tabTexture.size())
    {
        lineRect.setSdlRect((SDL_Rect){0,
                            i * lineHeight,
                            static_cast<int>(m_w *
                                    (m_tabTexture[i].getSdlRect().w
                                        / static_cast<float>(maxWidth))),
                            lineHeight});
        if (m_tabRect.size() <= i)
            m_tabRect.push_back(lineRect);
        else
            m_tabRect[i] = lineRect;
        i++;
    }
    return (*this);
}


Text    &Text::alignRight()
{
    int         i{0};
    vra::Rect   lineRect;
    int         lineHeight;
    int         lineWidth;
    int         maxWidth{0};
    int         w;

    while (i < m_tabTexture.size())
    {
        if (m_tabTexture[i].getSdlRect().w > maxWidth)
            maxWidth = m_tabTexture[i].getSdlRect().w;
        i++;
    }
    lineHeight = m_h / m_tabTexture.size();
    i = 0;
    while (i < m_tabTexture.size())
    {
        w = static_cast<int>(m_w * (m_tabTexture[i].getSdlRect().w
                                    / static_cast<float>(maxWidth)));
        lineRect.setSdlRect((SDL_Rect){m_x + m_w - w,
                            i * lineHeight,
                            w,
                            lineHeight});
        if (m_tabRect.size() <= i)
            m_tabRect.push_back(lineRect);
        else
            m_tabRect[i] = lineRect;
        i++;
    }
    return (*this);
}

Text    &Text::alignMiddle()
{
    int         i{0};
    vra::Rect   lineRect;
    int         lineHeight;
    int         lineWidth;
    int         maxWidth{0};
    int         w;

    while (i < m_tabTexture.size())
    {
        if (m_tabTexture[i].getSdlRect().w > maxWidth)
            maxWidth = m_tabTexture[i].getSdlRect().w;
        i++;
    }
    lineHeight = m_h / m_tabTexture.size();
    i = 0;
    while (i < m_tabTexture.size())
    {
        w = static_cast<int>(m_w * (m_tabTexture[i].getSdlRect().w
                                    / static_cast<float>(maxWidth)));
        lineRect.setSdlRect((SDL_Rect){m_x + m_w / 2 - w / 2,
                            i * lineHeight,
                            w,
                            lineHeight});
        if (m_tabRect.size() <= i)
            m_tabRect.push_back(lineRect);
        else
            m_tabRect[i] = lineRect;
        i++;
    }
    return (*this);
}

Text::Text(const vra::Renderer &renderer,
           const std::string &text,
           vra::Font *font,
           const int &x,
           const int &y,
           const int &w,
           const int &h,
           const SDL_Color &color) :
           m_x(x),
           m_y(y),
           m_w(w),
           m_h(h),
           m_color(color),
           m_font(font),
           m_alignment(TEXT_AL_LEFT)
{
    if ((m_tabText = vik::strSplit(text, '\n')).empty())
        throw(std::logic_error("invalid text"));
    for (int i{0}; i < m_tabText.size(); i++)
    {
        m_tabTexture.push_back(m_font->renderText(renderer,
                               m_tabText[i],
                               color));
    }
    if (m_tabTexture.empty())
        throw(std::logic_error("text rendering failed"));
    Text::alignLeft();
}

Text    &Text::draw(vra::Renderer *renderer)
{
    if (renderer)
    {
        for (int i{0}; i < m_tabTexture.size(); i++)
            renderer->drawTexture(m_tabTexture[i], nullptr, &m_tabRect[i]);
    }
}

Text    &Text::setFont(const vra::Renderer &renderer, vra::Font *font)
{
    m_font = font;
    Text::updateTabTexture(renderer);
}

vra::Font *Text::getFont() const
{
    return (m_font);
}

Text    &Text::setText(const vra::Renderer &renderer,
                       const std::string &text)
{
    if ((m_tabText = vik::strSplit(text, '\n')).empty())
        throw(std::logic_error("invalid text"));
    Text::updateTabTexture(renderer);
    return (*this);
}

const std::vector<std::string>   &Text::getText() const
{
    return (m_tabText);
}

Text    &Text::setAlign(const Uint8 alignment)
{
    // switch (alignment) ca marche pas why?
    // {
    //     case(TEXT_AL_LEFT) :
    //         Text::alignLeft();
    //     case(TEXT_AL_RIGHT) :
    //         Text::alignRight();
    //     case(TEXT_AL_MIDDLE) :
    //         Text::alignMiddle();
    // }
    if (alignment == TEXT_AL_LEFT)
        Text::alignLeft();
    else if (alignment == TEXT_AL_MIDDLE)
        Text::alignMiddle();
    else if (alignment == TEXT_AL_RIGHT)
        Text::alignRight();
    m_alignment = alignment;
}

const Uint8   &Text::getAlign() const
{
    return (m_alignment);
}

Text    &Text::setColor(const vra::Renderer &renderer, const SDL_Color &color)
{
    m_color = color;
    Text::updateTabTexture(renderer);
}

const SDL_Color  &Text::getColor() const
{
    return (m_color);
}

}   //  namespace vt2
