#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(const std::string &name);
		~Weapon();
		const std::string &getType();
		void setType(std::string new_type);
	private:
		std::string type;
};

#endif
