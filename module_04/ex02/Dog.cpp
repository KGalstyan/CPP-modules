#include "Dog.hpp"
#include <cstdio>

Dog::Dog() : AAnimal("Dog")
{
    std::cout << "Dog Constructor called" << std::endl;
    this->DogBrain = new Brain();
}

Dog::Dog(std::string _type) : AAnimal("Dog")
{
    (void)_type;
    std::cout << "Dog Parameter Constructor called" << std::endl;
    this->DogBrain = new Brain();
}

Dog::Dog(const Dog &obj) : AAnimal(obj)
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    this->DogBrain = new Brain(*obj.DogBrain);
}

Dog& Dog::operator=(const Dog &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
        delete this->DogBrain;
        this->DogBrain = new Brain(*obj.DogBrain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    delete this->DogBrain;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain()
{
    return(this->DogBrain);
}