#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(const std::string& _type);
        AAnimal(const AAnimal &obj);
        AAnimal& operator=(const AAnimal& obj);
        std::string getType() const;
        void set_type(std::string _type);
        virtual ~AAnimal();
        virtual void makeSound() const = 0;
};

#endif