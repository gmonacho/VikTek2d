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
// #include "TileObject.h"

int     main()
{
    vra::Init(SDL_INIT_VIDEO, IMG_INIT_PNG);
    vra::Window     window{"VikTek2d Main Test Program",
                           100, 100, 800, 600,
                           SDL_WINDOW_SHOWN};
    vra::Renderer   renderer{window, true, 0};
    vra::Event      event{};
    vra::Texture    texture{&renderer, "./floss.png"};
    vra::Texture    texture2{&renderer, "./png_des.png"};
    vra::Texture    bgTexture{&renderer, "./unity-2d-background-texture.png"};
    vt2::Scene      scene{&renderer, 3, 400, 300, 800, 600};
    bool            loop{true};

    scene.addSprite(&texture, 400, 300, 100, 200, 2, "player");
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
        renderer.setDrawColor(255, 0, 0, 255);
        scene.draw();
        renderer.draw();
    }
    std::cout << "Hello World !" << std::endl;
    return (1);
}
