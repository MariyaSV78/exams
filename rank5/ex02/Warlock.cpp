#include "Warlock.hpp"


Warlock::Warlock(std::string name, std::string title): _name(name), _title(title)
{
    std::cout << _name << ":  This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
     std::cout << _name << ":  My job here is done!" << std::endl;
}

std::string const&    Warlock::getName() const
{
    return(_name);
}

std::string const&    Warlock::getTitle() const
{
    return(_title);
}

void    Warlock::setTitle(std::string  title)
{
    _title = title;
}


void    Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}


https://github.com/gmorange42/Exam_Rank_05/blob/master/01/subject.en.txt

https://github.com/artmende/42-Exam-Rank-5/blob/master/cpp_module_01/ASpell.cpp
