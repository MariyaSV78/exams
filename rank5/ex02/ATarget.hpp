#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>

# include "Warlock.hpp"
# include "ASpell.hpp"

class ASlell

class ATarget 
{
    private:
        std::string     _type;

    public:
        ATarget();
        ATarget(std::string name, std::string effects);
        ATarget(ATarget const& CopyClass);

        ATarget const& operator=(ATarget const & rhs);

        virtual ~ATarget();

        std::string const&  getType() const;
    
        virtual ATarget*    clone()  const = 0;

        void        getHitBySpell(ASpell const& spell) const;

};

#endif