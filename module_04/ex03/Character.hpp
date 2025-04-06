#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    public:
        Character(std::string _name);
        Character();
        Character(const Character& obj);
        Character& operator=(const Character& obj);
        ~Character();
        
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
    private:
        AMateria *slots[4];
        std::string name;
};

#endif
