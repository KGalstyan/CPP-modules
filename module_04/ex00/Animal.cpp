#include "Animal.hpp"

Animal::Animal()
{
    type = "None";
    std::cout << "Animal Constructor called";
}

Animal::Animal(std::string _type) : type(_type)
{
    std::cout << "Animal Constructor called";
}

Animal& Animal::Animal(Animal &obj) : type(obj.type)
{
    std::cout << "Animal Copy Constructor called";
    return(this);
}

Animal& Animal::operator=(Animal const& obj)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called";
}