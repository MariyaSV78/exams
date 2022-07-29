#ifndef DUMMY_HPP
# define DUMMY_HPP

# include <iostream>
# include "ATarget.hpp"

class Dummy: public ATarget 
{
    public:
        Dummy();
        // Dummy(std::string type);
        // Dummy(ASpell const& ClassCopy);

        // Dummy const& operator=(Dummy const & rhs);

        virtual ~Dummy();

        ATarget*    clone() const;
   
};

#endif