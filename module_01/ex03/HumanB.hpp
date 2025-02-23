#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(const std::string &name);
		~HumanB();
		void attack();
		const std::string get_name();
		void set_name(const std::string &name);
		void setWeapon(Weapon &weapon);
	private:
		Weapon *weap;
		std::string name;
};
