#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(std::string _type) : AAnimal("Cat")
{
    (void)_type;
    std::cout << "Cat Parameter Constructor called" << std::endl;
}

Cat::Cat(const Cat &obj) : AAnimal(obj)
{
    std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miaow !" << std::endl;
}
