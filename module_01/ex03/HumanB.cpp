#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::set_name(const std::string &name)
{
	this->name = name;
}

const std::string HumanB::get_name()
{
	return(this->name);
}

void HumanB::attack()
{
	std::cout << get_name() << " attacks with their " << weap->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weap = &weapon;
}
