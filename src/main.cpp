#include <iostream>
#include <Init.h>
#include <Window.h>
#include <Event.h>
#include <Renderer.h>
#include <Sprite.h>
#include <Camera.h>
#include <Text.h>
#include <Exception.h>
#include <Texture.h>
#include "vikString.h"

int     main()
{
    vra::Init(SDL_INIT_VIDEO, IMG_INIT_PNG);
    vra::Window     window{"VikTek2d Main Test Program",
                           100, 100, 800, 600,
                           SDL_WINDOW_SHOWN};
    vra::Renderer   renderer{window, true, 0};
    vra::Event      event{};
    vt2::Camera     camera{0, 0, 1};
    vra::Texture    texture{renderer, "./floss.png"};
    // vt2::Sprite     frame{renderer, "./rectangle.png", 0, 0, 800, 600};
    vt2::Sprite     sprite{&texture, 300, 200, 200, 300};
    vra::Font       font{"./font/OpenSans-Bold.ttf", 100};
    vra::Font       ifont{"./font/OpenSans-Italic.ttf", 100};
    vt2::Text       text{renderer,
                         "retour\na\nla\nligne",
                         &font,
                         50, 50, 150, 150,
                         (SDL_Color){255, 255, 255, 255}};
    std::vector<std::string>    splitTab;
    bool            loop{true};

    renderer.setDrawBlendMode(SDL_BLENDMODE_BLEND);
    text.setAlign(vt2::TEXT_AL_RIGHT);
    text.setColor(renderer, (SDL_Color){200, 200, 200, 255});
    while (loop)
    {
        renderer.setDrawColor(50, 50, 50, 255);
        renderer.clear();
        event.update();
        if (event.isKeyPressed(SDL_SCANCODE_ESCAPE) ||
            event.getEvent().type == SDL_QUIT)
        {
            loop = false;
        }
        // sprite.rotate(0.5);
        // sprite.move(sprite.getPosition().getX() > 800 ? -800 : 1, 0);
        // camera.move(camera.getPosition().getX() > 400 ? -400 : 1, 0);
        // frame.draw(&renderer);
        sprite.draw(&renderer);
        text.draw(&renderer);
        renderer.setDrawColor(255, 0, 0, 255);
        renderer.drawPoint(vra::Point{400, 300});
        renderer.draw();
    }
    std::cout << "Hello World !" << std::endl;
    return (1);
}
