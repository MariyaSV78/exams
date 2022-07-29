#include "Dummy.hpp"

Dummy::Dummy(): ATarget("Target Practice Dummy"){}

// Dummy::Dummy(std::string type): ATarget(_type){}

// Dummy::Dummy(Dummy const& ClassCopy)
// {
// 	*this = ClassCopy;
// }

// Dummy const& opertor=(Dummy const & rhs)
// {
// 	this->_type = rsh._type;
// 	return *this;
// }

ATarget*    Dummy::clone() const
{
	return (new Dummy());
}