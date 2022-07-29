#include "Fwoosh.hpp"

Fwoosh::Fwoosh(): ASpell("Fwoosh", "fwooshed"){}

// Fwoosh::Fwoosh(std::string name, std::string effects): ASpell(_name, _effects){}

// Fwoosh::Fwoosh(Fwoosh const& ClassCopy)
// {
// 	*this = ClassCopy;
// }

// Fwoosh const& opertor=(Fwoosh const & rhs)
// {
// 	this->_name = rsh._name;
// 	this->_effects = rsh._effects;
// 	return *this;
// }

ASpell*    Fwoosh::clone() const
{
	return (new Fwoosh());
}