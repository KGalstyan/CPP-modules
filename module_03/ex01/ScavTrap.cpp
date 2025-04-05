#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
    set_health(100);
    set_energy_points(50);
    set_attack_damage(20);
    std::cout << "ScavTrap Parameter constructor called" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap("Unnamed ScavTrap")
{
    set_health(100);
    set_energy_points(50);
    set_attack_damage(20);
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
		ClapTrap::operator=(obj);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (get_energy_points() > 0)
    {
        std::cout << "ScavTrap " << get_name() << " attacks " << target << ", causing " << get_attack_damage() << " points of damage!" << std::endl;
        set_energy_points(get_energy_points() - 1);
    }
    else
        std::cout << "ScavTrap " << get_name() << " has no energy to attack!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << get_name() << " is now in Gate keeper mode." << std::endl;
}
