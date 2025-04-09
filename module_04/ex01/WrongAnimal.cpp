#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& _type) : type(_type)
{
    std::cout << "WrongAnimal Parameter Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
    set_type(obj.type);
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal Copy Assignment Operator called" << std::endl;
    if (this != &obj)
    {
        set_type(obj.type);
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::set_type(std::string _type)
{
    this->type = _type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "AAAAAAAAAAA I am wRongAnimal" << std::endl;
}