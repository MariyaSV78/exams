#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell 
{
    private:
        std::string     _name;
        std::string     _effects;

    public:
        ASpell();
        ASpell(std::string name, std::string effects);
        ASpell(ASpell const& CopyClass);

        ASpell const& operator=(ASpell const & rhs);

        virtual ~ASpell();

        std::string const&  getName() const;
        std::string const&  getEffects() const;

        virtual ASpell*    clone()  const = 0;

        void                lanch(ATarget const& target);

};

#endif