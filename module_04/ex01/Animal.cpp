#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const std::string& _type) : type(_type)
{
    std::cout << "Animal Parameter Constructor called" << std::endl;
}

Animal::Animal(const Animal &obj)
{
    std::cout << "Animal Copy Constructor called" << std::endl;
    set_type(obj.type);
}

Animal& Animal::operator=(const Animal &obj)
{
    std::cout << "Animal Copy Assignment Operator called" << std::endl;
    if (this != &obj)
    {
        set_type(obj.type);
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::set_type(std::string _type)
{
    this->type = _type;
}

void Animal::makeSound() const
{
}