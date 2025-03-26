#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string _type);
        Animal& Animal(Animal &obj);
        Animal& operator=(Animal const& obj)
        virtual ~Animal();
        virtual makeSound() = 0;
}