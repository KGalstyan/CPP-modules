#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap , public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string const &name);
		DiamondTrap(const DiamondTrap& obj);
    	DiamondTrap &operator=(const DiamondTrap &obj);
		~DiamondTrap();
		const std::string get_di_name(void);
		void attack(const std::string& target);
		void whoAmI();
	private:
		const std::string name;
};

#endif
