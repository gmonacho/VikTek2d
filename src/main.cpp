#include <iostream>
#include <Init.h>
#include <Window.h>
#include <Event.h>
#include <Renderer.h>
#include <Exception.h>
#include <Texture.h>
#include "vikString.h"
#include "Text.h"
#include "Sprite.h"
#include "Scene.h"

static bool testSprite(vra::Renderer *renderer)
{
    return (true);
}

int     main()
{
    vra::Init(SDL_INIT_VIDEO, IMG_INIT_PNG);
    vra::Window     window{"VikTek2d Main Test Program",
                           100, 100, 800, 600,
                           SDL_WINDOW_SHOWN};
    vra::Renderer   renderer{window, true, 0};
    vra::Event      event{};
    vra::Texture    flossTexture{&renderer, "floss.png"};
    vt2::Sprite     flossSprite{&renderer, &flossTexture, 400, 300, 200, 300};
    vra::Texture    bgTexture{&renderer, "background.png"};
    vt2::Sprite     bgSprite{&renderer, &bgTexture, 400, 300, 800, 600};
    bool            loop{true};
    vt2::Scene      scene{&renderer, 3, 400, 300, 800, 600};

    scene.addSprite(&bgSprite, 0);
    scene.addSprite(&flossSprite, 2);
    renderer.setDrawBlendMode(SDL_BLENDMODE_BLEND);
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
