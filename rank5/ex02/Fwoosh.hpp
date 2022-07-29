#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include <iostream>
# include "ASpell.hpp"

class Fwoosh: public ASpell 
{
    public:
        Fwoosh();
        // Fwoosh(std::string name, std::string effects);
        // Fwoosh(ASpell const& ClassCopy);

        // Fwoosh const& operator=(Fwoosh const & rhs);

        virtual ~Fwoosh();

        ASpell*    clone() const;
   
};

#endif