#include <Text.h>
#include <iostream>
#include <Font.h>
#include <Renderer.h>
#include <Exception.h>

namespace vt2
{

Text    &Text::updateTabTexture(const vra::Renderer &renderer)
{
    m_tabTexture[0] = m_font->renderText(renderer, m_text, m_color);
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
           m_text(text),
           m_x(x),
           m_y(y),
           m_w(w),
           m_h(h),
           m_color(color),
           m_font(font),
           m_alignment(TEXT_AL_LEFT)
{
    int     i{0};
    int     pos{0};

    while (text[i] == '\n' && i < text.size())
        i++;
    pos = i;
    while (i < text.size())
    {
        if (text[i] == '\n' && i != 0 && text[i - 1] != '\n')
        {
            m_tabTexture.push_back(m_font->renderText(renderer,
                                   text.substr(pos, i - pos),
                                   color));
            while (text[i + 1] == '\n' && i < text.size() - 1)
                i++;
            pos = i + 1;
        }
        i++;
    }
    if (i != 0 && text[i - 1] != '\n')
    {
        m_tabTexture.push_back(m_font->renderText(renderer,
                               text.substr(pos, i - pos),
                               color));
    }
    if (m_tabTexture.empty())
        throw(std::bad_alloc());    //  pas de texte valide
    alignLeft();
}

Text    &Text::draw(vra::Renderer *renderer)
{
    int         i{0};

    if (renderer)
    {
        i = 0;
        while (i < m_tabTexture.size())
        {
            renderer->drawTexture(m_tabTexture[i], nullptr, &m_tabRect[i]);
            i++;
        }
    }
}

Text    &Text::setText(const vra::Renderer &renderer,
                       const std::string &text)
{
    if (m_text != text)
    {
        m_text = text;
        updateTabTexture(renderer);
    }
}

Text    &Text::setAlign(const Uint8 alignment)
{
    switch(alignment)
    {
        case(TEXT_AL_LEFT) :
            alignLeft();
        case(TEXT_AL_RIGHT) :
            alignRight();
        case(TEXT_AL_MIDDLE) :
            alignMiddle();
    }

}

const std::string   &Text::getText() const
{
    return (m_text);
}

}   //  namespace vt2
