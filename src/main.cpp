#include <iostream>
#include <Init.h>
#include <Window.h>
#include <Event.h>
#include <Renderer.h>
#include "Scene.h"

int     main()
{
    vra::Init(SDL_INIT_VIDEO, IMG_INIT_PNG);
    vra::Window     window{"VikTek2d Main Test Program",
                           100, 100, 800, 600,
                           SDL_WINDOW_SHOWN};
    vra::Renderer   renderer{window, true, 0};
    vra::Event      event{};
    vt2d::Scene     scene{renderer, vra::Rect{0, 0, 800, 600}};
    bool            loop{true};

    while (loop)
    {
        renderer.setDrawColor(50, 50, 50, 255);
        renderer.clear();
        event.waitEvent();
        if (event.isKeyPressed(SDL_SCANCODE_ESCAPE) ||
            event.getEvent().type == SDL_QUIT)
        {
            loop = false;
        }
        renderer.draw();
    }
    std::cout << "Hello World !" << std::endl;
    return (1);
}