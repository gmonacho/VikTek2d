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
    vra::Texture    texture{renderer, "./floss.png"};
    vra::Texture    texture2{renderer, "./png_des.png"};
    vt2::Sprite     sprite1{&texture, 400, 300, 200, 300};
    vt2::Sprite     sprite2{&texture, 400, 300, 200, 300};
    vt2::Scene      scene{&renderer, 2};
    bool            loop{true};

    renderer.setDrawBlendMode(SDL_BLENDMODE_BLEND);
    scene.addSprite(&sprite1, 1, "sprite1");
    scene.addSprite(&sprite2, 0, "sprite2");
    scene.getSprite("sprite1")->rotate(90);
    scene.getSprite("sprite2")->move(100, 0).setFlip(SDL_FLIP_VERTICAL);
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
        scene.draw();
        renderer.setDrawColor(255, 0, 0, 255);
        renderer.draw();
    }
    std::cout << "Hello World !" << std::endl;
    return (1);
}
