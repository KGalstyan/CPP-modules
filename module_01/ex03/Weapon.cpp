#include "Weapon.hpp"

Weapon::Weapon(const std::string &name) : type(name)
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType()
{
	return(this->type);
}

void Weapon::setType(std::string new_type)
{
	this->type = new_type;
}
