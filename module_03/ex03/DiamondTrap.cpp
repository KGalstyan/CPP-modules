#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(std::string("Unnamed") + "_clap_name"), FragTrap("Unnamed"), ScavTrap("Unnamed") , name("Unnamed")
{
    std::cout << "DiamondTrap Default constructor called" << std::endl;
	set_health(FragTrap::get_health());
    set_energy_points(ScavTrap::get_energy_points());
    set_attack_damage(FragTrap::get_attack_damage());
}

DiamondTrap::DiamondTrap(std::string const& _name) : ClapTrap(_name + "_clap_name"), FragTrap(_name) , ScavTrap(_name) , name(_name)
{
    std::cout << "DiamondTrap Parameter constructor called" << std::endl;
	set_health(FragTrap::get_health());
    set_energy_points(ScavTrap::get_energy_points());
    set_attack_damage(FragTrap::get_attack_damage());
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &obj)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &obj)
    {
		ClapTrap::operator=(obj);
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::get_name() << std::endl;
}
