#include <iostream>
#include <Init.h>
#include <Window.h>
#include <Event.h>
#include <Renderer.h>
#include <Sprite.h>
#include <Text.h>
#include <Exception.h>
#include <Texture.h>
#include "Camera.h"
#include "vikString.h"
#include "Scene.h"

int     main()
{
    vra::Init(SDL_INIT_VIDEO, IMG_INIT_PNG);
    vra::Window     window{"VikTek2d Main Test Program",
                           100, 100, 800, 600,
                           SDL_WINDOW_SHOWN};
    vra::Renderer   renderer{window, true, 0};
    vra::Event      event{};
    vt2::Camera     camera{0, 0, 1};
    vra::Texture    texture{&renderer, "./floss.png"};
    vra::Texture    texture2{&renderer, "./png_des.png"};
    vt2::Sprite     sprite1{&texture, 400, 300, 200, 300};
    vt2::Sprite     sprite2{&texture2, 400, 300, 200, 300};
    vt2::Scene      scene{&renderer, 2, 400, 300, 800, 600};
    bool            loop{true};

    renderer.setDrawBlendMode(SDL_BLENDMODE_BLEND);
    scene.addSprite(&sprite1, 1, "sprite1");
    scene.addSprite(&sprite2, 0, "sprite2");
    scene.moveSprite("sprite1", 100, 0);
    // scene.removeSprite("sprite2");
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
        if (event.isKeyPressed(SDL_SCANCODE_D))
            scene.move(1, 0);
        if (event.isKeyPressed(SDL_SCANCODE_A))
            scene.move(-1, 0);
        if (event.isKeyPressed(SDL_SCANCODE_S))
            scene.move(0, 1);
        if (event.isKeyPressed(SDL_SCANCODE_W))
            scene.move(0, -1);
        if (event.isKeyPressed(SDL_SCANCODE_Q))
            scene.rotate(-1);
        if (event.isKeyPressed(SDL_SCANCODE_E))
            scene.rotate(1);
        scene.draw();
        renderer.setDrawColor(255, 0, 0, 255);
        renderer.draw();
    }
    std::cout << "Hello World !" << std::endl;
    return (1);
}
