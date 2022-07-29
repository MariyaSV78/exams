#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include <iostream>
# include "ASpell.hpp"

class Fireball: public ASpell 
{
    public:
        Fireball();
        // Fwoosh(std::string name, std::string effects);
        // Fwoosh(ASpell const& ClassCopy);

        // Fwoosh const& operator=(Fwoosh const & rhs);

        virtual ~Fireball();

        ASpell*    clone() const;
   
};

#endif