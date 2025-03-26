#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
}

Dog::Dog(std::string _type) : Animal("Dog")
{

}

Dog& Dog::Dog(Dog& obj) : Animal(obj.type)
{

}

Dog& Dog::operator=(const Dog& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "woof, woof" << std::endl;
}
