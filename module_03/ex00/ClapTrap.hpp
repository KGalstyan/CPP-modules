#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string constd &name);
		ClapTrap& ClapTrap(ClapTrap& obj);
		ClapTrap& operator=(ClapTrap& obj);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string const get_name();
		set_name(std::string const name);
		int get_health();
		set_health();
		int get_energy_points();
		set_energy_points(int &health);
		int get_attack_damage(int &energy_points);
		set_attack_damage(int& attack_damage);

	private:
		std::string const name;
		int health;
		int energy_points;
		int attack_damage;
};

#endif
