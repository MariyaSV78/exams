#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

# include <iostream>
# include "ATarget.hpp"

class BrickWall: public ATarget 
{
    public:
        BrickWall();
        // BrickWall(std::string type);
        // BrickWall(ASpell const& ClassCopy);

        // BrickWall const& operator=(BrickWall const & rhs);

        virtual ~BrickWall();

        ATarget*    clone() const;
   
};

#endif