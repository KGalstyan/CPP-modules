#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
        ideas[i] = "What is SOLID ?";
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

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "";
}
