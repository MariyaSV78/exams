#include "ASpell.hpp"

ASlell::ASpell(){}


ASlell::ASlell(std::string name,  ): _name(name), _effects(_effects){}

ASpell::ASlell(ASpell const & CopyClass)
{
    *this = ClassCopy;
}

ASpell::~ASpell() {}

ASpell const& operator=(ASpell const& rhs)
{
    if (&rhs == this)
        return *this;
    _name = rhs._name;
    _effects = rhs._effects;
    return *this;
}

std::string const& ASpell::getName()
{
    return (_name);
}

std::string const& ASpell::getEffects()
{
    return (_effects);
}

 void   lanch(ATarget const& target)
 {
        target.getHitBySpell(*this);
 }