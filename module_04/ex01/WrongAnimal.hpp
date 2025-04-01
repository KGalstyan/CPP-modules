#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string _type);
        WrongAnimal(const WrongAnimal &obj);
        WrongAnimal& operator=(const WrongAnimal& obj);
        std::string getType() const;
        void set_type(std::string _type);
        virtual ~WrongAnimal();
        void makeSound() const;
};

#endif