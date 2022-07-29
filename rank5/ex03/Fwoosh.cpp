#include "Fireball.hpp"

Fireball::Fireball(): ASpell("Fireball", "burnt to a crisp"){}

// Fireball::Fireball(std::string name, std::string effects): ASpell(_name, _effects){}

// Fireball::Fireball(Fireball const& ClassCopy)
// {
// 	*this = ClassCopy;
// }

// Fireball const& opertor=(Fireball const & rhs)
// {
// 	this->_name = rsh._name;
// 	this->_effects = rsh._effects;
// 	return *this;
// }

ASpell*    Fireball::clone() const
{
	return (new Fireball());
}