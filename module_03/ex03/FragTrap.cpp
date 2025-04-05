#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unnamed FragTrap")
{
    set_health(100);
    set_energy_points(100);
    set_attack_damage(30);
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const& _name) : ClapTrap(_name)
{
    set_health(100);
    set_energy_points(100);
    set_attack_damage(30);
    std::cout << "FragTrap Parameter constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &obj)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
		ClapTrap::operator=(obj);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
		std::cout << "FragTrap " << get_name() << " - high fives Guys!" << std::endl;
}

