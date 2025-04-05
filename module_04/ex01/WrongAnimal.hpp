#ifndef WRONG_AAnimal_HPP
#define WRONG_AAnimal_HPP

#include <iostream>

class WrongAAnimal
{
    protected:
        std::string type;
    public:
        WrongAAnimal();
        WrongAAnimal(std::string _type);
        WrongAAnimal(const WrongAAnimal &obj);
        WrongAAnimal& operator=(const WrongAAnimal& obj);
        std::string getType() const;
        void set_type(std::string _type);
        virtual ~WrongAAnimal();
        void makeSound() const;
};

#endif