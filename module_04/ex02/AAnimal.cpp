#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal Constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& _type) : type(_type)
{
    std::cout << "AAnimal Parameter Constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj)
{
    std::cout << "AAnimal Copy Constructor called" << std::endl;
    set_type(obj.type);
}

AAnimal& AAnimal::operator=(const AAnimal &obj)
{
    std::cout << "AAnimal Copy Assignment Operator called" << std::endl;
    if (this != &obj)
    {
        set_type(obj.type);
    }
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal Destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return this->type;
}

void AAnimal::set_type(std::string _type)
{
    this->type = _type;
}

