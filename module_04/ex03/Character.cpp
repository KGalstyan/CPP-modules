#include "Character.hpp"

Character::Character(std::string _name) : name(_name)
{
    for (int i = 0; i < 4; ++i)
        this->slots[i] = NULL;
}

Character::Character() : name("Unnamed")
{
    for (int i = 0; i < 4; ++i)
        this->slots[i] = NULL;
}

Character::Character(const Character& obj) : name(obj.name)
{
    for (int i = 0; i < 4; ++i)
	{
		if (obj.slots[i])
		{
			delete this->slots[i];
			this->slots[i] = obj.slots[i]->clone();
		}
		else
			this->slots[i] = NULL;
	}
}

Character& Character::operator=(const Character& obj)
{
    if(this != &obj)
    {
        this->name = obj.name;
        for (int i = 0; i < 4; i++)
		{
			delete this->slots[i];
			this->slots[i] = obj.slots[i]->clone();
		}
    }
    return(*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        delete this->slots[i];
}

std::string const& Character::getName() const
{
    return(this->name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (!this->slots[i])
		{
			this->slots[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->slots[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->slots[idx])
		this->slots[idx]->use(target);
}
