#include "Zombie.hpp"


Zombie::Zombie()
{
}

Zombie::~Zombie(void)
{
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
