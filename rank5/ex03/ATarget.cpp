#include "ATarget.hpp"

ATarget::ATarget(){}

ATarget::ATarget(std::string type): _type(type){}

ATarget::ATarget(ATarget const & CopyClass): // _type(type) {} ?
{
    *this = ClassCopy;
}

ATarget::~ATarget() {}

ATarget const& operator=(ATarget const& rhs)
{
    if (&rhs == this)
        return *this;
    _type = rhs._type;
     return *this;
}

std::string const& ATarget::getType()
{
    return (_type);
}


void        ATarget::getHitBySpell(ASpell const& spell) const
{
    std::string << _type << " has been " << spell.getEffects() << std::endl;
}

