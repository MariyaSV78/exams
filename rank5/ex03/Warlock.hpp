#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>
# include <vector>
# include "ASpell.hpp"
# include "ATarget.hpp"


class Warlock 
{
    private:
        std::string     _name;
        std::string     _title;
        std::vector<ASpell*>    _spell;


        Warlock();
        Warlock(Warlock const& CopyClass);
        Warlock const& operator=(Warlock const& rhs);       
    
    public:
    
        Warlock(std::string name, std::string title);

       ~Warlock();

        std::string const&   getName() const;
        std::string const&   getTitle() const;

        void                 setTitle(std::string const& title);
        void                 introduce() const;

        void                 learnSpell(ASpell* spell);
        void                 forgetSpell(std::string spell);
        void                 launchSpell(std::string spell, ATarget& target);
};


#endif
