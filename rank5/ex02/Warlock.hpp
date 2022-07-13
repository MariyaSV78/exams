#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>


class Warlock 
{
    private:
        std::string     _name;
        std::string     _title;

        // Warlock();
        // Warlock(Warlock const& CopyClass);
        // Warlock const& operator=(Warlock const& rhs);       
    
    public:
    
        Warlock(std::string name, std::string title);

       ~Warlock();

        std::string const&   getName() const;
        std::string const&   getTitle() const;

        void                 setTitle(std::string const& title);
        void                 introduce() const;
};


#endif
