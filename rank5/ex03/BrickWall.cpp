#include "BrickWall.hpp"

BrickWall::BrickWall(): ATarget("Inconspicuous Red-brick Wall"){}

// BrickWall::BrickWall(std::string type): ATarget(_type){}

// BrickWall::BrickWall(BrickWall const& ClassCopy)
// {
// 	*this = ClassCopy;
// }

// BrickWall const& opertor=(BrickWall const & rhs)
// {
// 	this->_type = rsh._type;
// 	return *this;
// }

ATarget*    BrickWall::clone() const
{
	return (new BrickWall());
}