#ifndef Animal_HPP
#define Animal_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const std::string& _type);
        Animal(const Animal &obj);
        Animal& operator=(const Animal& obj);
        std::string getType() const;
        void set_type(std::string _type);
        virtual ~Animal();
        virtual void makeSound() const;
};

#endif