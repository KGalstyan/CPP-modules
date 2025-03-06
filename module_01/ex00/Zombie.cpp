#include "Zombie.hpp"


Zombie::Zombie(const std::string 	&name)
{
	this->set_name(name);
}

Zombie::~Zombie(void)
{
	std::cout << this->name << ": Dead" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(const std::string &name)
{
	this->name = name;
}

std::string Zombie::get_name(void)
{
	return this->name;
}
