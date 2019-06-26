#ifndef GRAPHIC_SCENE_H_
#define GRAPHIC_SCENE_H_

#include <vector>
#include <map>
#include <string>
#include <Renderer.h>
#include <Texture.h>
#include "Sprite.h"

namespace vt2
{


enum spriteModication {SPRITE_SET_TEXTURE,
                       SPRITE_MOVE,
                       SPRITE_SET_POSITION,
                       SPRITE_SET_WIDTH,
                       SPRITE_SET_HEIGHT,
                       SPRITE_ROTATE,
                       SPRITE_SET_FLIP,
                       SPRITE_SET_CENTER,
                       SPRITE_HIDE,
                       SPRITE_SHOW};

class Scene
{
 private:
    std::vector<std::map<std::string, Sprite*>>    m_sprites;

    vra::Renderer   *m_renderer;
    vra::Texture    m_texture;
    Sprite          m_rendererSprite;


    Scene          &updateRendererSprite();

 public:
    Scene(vra::Renderer *renderer,
          const int &groundNumber,
          const int &x,
          const int &y,
          const int &w,
          const int &h);

    ~Scene() = default;

    Scene   &draw();

    Scene           &addSprite(Sprite *sprite,
                       const int &i_ground,
                       const std::string &key);
    Scene           &removeSprite(const std::string &key);
    const Sprite    *getSprite(const std::string &key);
    Scene           &setSpriteTexture(const std::string &key,
                                      vra::Texture *texture);
    Scene           &moveSprite(const std::string &key,
                                const int &dx,
                                const int &dy);
    Scene           &setSpritePosition(const std::string &key,
                                       const int &x,
                                       const int &y);
    Scene           &setSpriteWidth(const std::string &key,
                                    const int &width);
    Scene           &setSpriteHeight(const std::string &key,
                                     const int &height);
    Scene           &rotateSprite(const std::string &key,
                                  const float &angle);
    Scene           &setSpriteFlip(const std::string &key,
                                   const SDL_RendererFlip &sdlFlip);
    Scene           &setSpriteCenter(const std::string &key,
                                     const vra::Point &center);
    Scene           &hideSprite(const std::string &key);
    Scene           &showSprite(const std::string &key);
};

}   //  namespace vt2
#endif  //  GRAPHIC_SCENE_H_
