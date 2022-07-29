#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include <iostream>
# include "ASpell.hpp"

class Polymorph: public ASpell 
{
    public:
        Polymorph();
        // Polymorph(std::string name, std::string effects);
        // Polymorph(ASpell const& ClassCopy);

        // Polymorph const& operator=(Polymorph const & rhs);

        virtual ~Polymorph();

        ASpell*    clone() const;
   
};

#endif