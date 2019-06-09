#include <iostream>
#include <Init.h>
#include <Window.h>
#include <Event.h>
#include <Renderer.h>
#include <Sprite.h>

int     main()
{
    vra::Init(SDL_INIT_VIDEO, IMG_INIT_PNG);
    vra::Window     window{"VikTek2d Main Test Program",
                           100, 100, 800, 600,
                           SDL_WINDOW_SHOWN};
    vra::Renderer   renderer{window, true, 0};
    vra::Event      event{};
    vt2::Sprite     sprite{renderer, "./floss.png", 100, 300, 500, 500};
    bool            loop{true};

    renderer.setDrawBlendMode(SDL_BLENDMODE_BLEND);
    while (loop)
    {
        sprite.flip(vt2::FLIP_HORIZONTAL);
        renderer.setDrawColor(50, 50, 50, 255);
        renderer.clear();
        event.update();
        if (event.isKeyPressed(SDL_SCANCODE_ESCAPE) ||
            event.getEvent().type == SDL_QUIT)
        {
            loop = false;
        }
        sprite.rotate(0.5);
        sprite.move(sprite.getPosition().getX() > 800 ? -800 : 1, 0);
        sprite.draw(&renderer);
        renderer.setDrawColor(255, 0, 0, 255);
        renderer.drawPoint(vra::Point{400, 300});
        renderer.draw();
    }
    std::cout << "Hello World !" << std::endl;
    return (1);
}
