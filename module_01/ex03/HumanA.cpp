#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weap): weap(weap), name(name)
{
}

HumanA::~HumanA()
{
}

void HumanA::set_name(const std::string &name)
{
	this->name = name;
}

const std::string HumanA::get_name()
{
	return(this->name);
}

void HumanA::attack()
{
	std::cout << get_name() << " attacks with their " << weap.getType() << std::endl;
}

