#incldue "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string constd &name) : name(name)
{
	std::cout << "Parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap() : health(10) , energy_points(10) , attack_damage(0)
{
}

ClapTrap& ClapTrap::ClapTrap(ClapTrap& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	// this->fixed_point_number = obj.getRawBits();
}

ClapTrap& ClapTrap::operator=(ClapTrap& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &obj)
		return(*this);
	// this->fixed_point_number = obj.getRawBits();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void attack(const std::string& target)
{
	if(get_energy_points() > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target ", causing " << this->attack_damage << " points of damage!" << std::endl;;
		set_energy_points(--get_energy_points());
	}
	else
		std::cout << "ClapTrap " << this->name << "'s energy points left" << std::endl;
}

void takeDamage(unsigned int amount)
{
	
}

void beRepaired(unsigned int amount)
{
	if(get_energy_points() > 0)
	{
		std::cout << "ClapTrap " << this->name << " repairs " << std::endl;
		set_energy_points(--get_energy_points());
	}
	else
		std::cout << "ClapTrap " << this->name << "'s energy points left" << std::endl;
}

