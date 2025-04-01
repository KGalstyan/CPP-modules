#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Constructor called" << std::endl;
    this->CatBrain = new Brain();
}

Cat::Cat(std::string _type) : Animal("Cat")
{
    (void)_type;
    std::cout << "Cat Parameter Constructor called" << std::endl;
    this->CatBrain = new Brain();
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
    std::cout << "Cat Copy Constructor called" << std::endl;
    this->CatBrain = new Brain();
}

Cat& Cat::operator=(const Cat &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
        this->CatBrain = new Brain();
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
    delete this->CatBrain;
}

void Cat::makeSound() const
{
    std::cout << "Miaow !" << std::endl;
}

Brain * Cat::getBrain()
{
    return(this->CatBrain);
}