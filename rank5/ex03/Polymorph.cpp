#include "Polymorph.hpp"

Polymorph::Polymorph():ASpell("Polymorph", "turned into a critter"){}

// Polymorph::Polymorph(std::string name, std::string effects): ASpell(_name, _effects){}

// Polymorph::Polymorph(Polymorph const& ClassCopy)
// {
// 	*this = ClassCopy;
// }

// Polymorph const& opertor=(Polymorph const & rhs)
// {
// 	this->_name = rsh._name;
// 	this->_effects = rsh._effects;
// 	return *this;
// }

ASpell*    Polymorph::clone() const
{
	return (new Polymorph());
}