#include "Message.h"

namespace vt2
{

Message::Message(e_module module, Uint32 flags) :
                 m_module(module), m_flags(flags) {}


Message         &Message::setModule(e_module module)
{
    m_module = module;
}


const Uint32    &Message::getModule() const
{
    return (m_module);
}

Message         &Message::setFlags(Uint32 flags)
{
    m_flags = flags;
}

const Uint32    &Message::getFlags() const
{
    return (m_flags);
}

}   //  namespace vt2
