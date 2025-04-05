#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAAnimal
{
    public:
        WrongCat();
        WrongCat(std::string _type);
        WrongCat(const WrongCat& obj);
        WrongCat& operator=(const WrongCat& obj);
        ~WrongCat();
        void makeSound() const;
    private:
};

#endif