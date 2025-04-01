#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain(const Brain& obj)
{
    std::cout << "Brain Copy Constructor called" << std::endl;
    for(int i = 0;i < 100; i++)
        this->ideas[i] = obj.ideas[i];
}

Brain& Brain::operator=(const Brain& obj)
{
    std::cout << "Brain Copy Assignment Operator called" << std::endl;
    if (this != &obj)
    {
        for(int i = 0;i < 100; i++)
            this->ideas[i] = obj.ideas[i];
    }
    return *this;
}

std::string Brain::getIdea(int i)
{
    if(i <= 0 && i >= 100)
        return (ideas[i]);
    return(NULL);
}

void Brain::setIdea(int i, const std::string idea)
{
    ideas[i] = idea;
}
