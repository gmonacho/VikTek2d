#ifndef MESSAGEBOX_MESSAGE_H_
#define MESSAGEBOX_MESSAGE_H_

#include <SDL.h>

namespace vt2
{

typedef enum    module
{
    MODULE_NONE = 0,
    MODULE_GRAPHIC = 1,
    MODULE_PHYSIC = 2,
    MODULE_INPUT = 3
}               e_module;

class Message
{
 private:
    e_module    m_module;
    Uint32      m_flags;

 public:
    Message(e_module module, Uint32 flags);
    ~Message() = default;

    Message         &setModule(e_module module);
    const Uint32    &getModule() const;

    Message         &setFlags(Uint32 flags);
    const Uint32    &getFlags() const;
};

}   //  namespace vt2

#endif  //  MESSAGEBOX_MESSAGE_H_
