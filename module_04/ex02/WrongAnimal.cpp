#include "WrongAnimal.hpp"

WrongAAnimal::WrongAAnimal() : type("WrongAAnimal")
{
    std::cout << "WrongAAnimal Constructor called" << std::endl;
}

WrongAAnimal::WrongAAnimal(std::string _type) : type(_type)
{
    std::cout << "WrongAAnimal Parameter Constructor called" << std::endl;
}

WrongAAnimal::WrongAAnimal(const WrongAAnimal &obj)
{
    std::cout << "WrongAAnimal Copy Constructor called" << std::endl;
    set_type(obj.type);
}

WrongAAnimal& WrongAAnimal::operator=(const WrongAAnimal &obj)
{
    std::cout << "WrongAAnimal Copy Assignment Operator called" << std::endl;
    if (this != &obj)
    {
        set_type(obj.type);
    }
    return *this;
}

WrongAAnimal::~WrongAAnimal()
{
    std::cout << "WrongAAnimal Destructor called" << std::endl;
}

std::string WrongAAnimal::getType() const
{
    return this->type;
}

void WrongAAnimal::set_type(std::string _type)
{
    this->type = _type;
}

void WrongAAnimal::makeSound() const
{
    std::cout << "AAAAAAAAAAA I am wRongAAnimal" << std::endl;
}