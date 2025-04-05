#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAAnimal("WrongCat")
{
    std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(std::string _type) : WrongAAnimal("WrongCat")
{
    (void)_type;
    std::cout << "WrongCat Parameter Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAAnimal(obj)
{
    std::cout << "WrongCat Copy Constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong: Miaow axpers !" << std::endl;
}