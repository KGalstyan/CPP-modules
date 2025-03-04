#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(const std::string &name, Weapon &weap);
		~HumanA();
		void attack();
		const std::string get_name();
		void set_name(const std::string &name);
	private:
		Weapon &weap;
		std::string name;
};

#endif
