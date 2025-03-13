#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const& _name)
    : name(_name), health(10), energy_points(10), attack_damage(0)
{
    std::cout << "Parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap()
    : name("Unnamed"), health(10), energy_points(10), attack_damage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& obj)
    : name(obj.name), health(obj.health), energy_points(obj.energy_points), attack_damage(obj.attack_damage)
{
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->attack_damage = obj.attack_damage;
        this->health = obj.health;
        this->energy_points = obj.energy_points;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (get_energy_points() > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
        set_energy_points(get_energy_points() - 1);
    }
    else
        std::cout << "ClapTrap " << this->name << " has no energy to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= (unsigned int)health)
        health = 0;
    else
        health -= amount;
    std::cout << "ClapTrap " << get_name() << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (get_energy_points() > 0)
    {
        set_energy_points(get_energy_points() - 1);
        set_health(get_health() + amount);
        std::cout << "ClapTrap " << this->name << " repairs itself, restoring " << amount << " hit points!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " has no energy to repair!" << std::endl;
}

std::string const ClapTrap::get_name() const
{
    return this->name;
}

int ClapTrap::get_health() const
{
    return this->health;
}

void ClapTrap::set_health(int health)
{
    this->health = health;
}

int ClapTrap::get_energy_points() const
{
    return this->energy_points;
}

void ClapTrap::set_energy_points(int energy_points)
{
    this->energy_points = energy_points;
}

int ClapTrap::get_attack_damage() const
{
    return this->attack_damage;
}

void ClapTrap::set_attack_damage(int attack_damage)
{
    this->attack_damage = attack_damage;
}
