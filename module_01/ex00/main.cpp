#include "Zombie.hpp"

int main()
{
	Zombie *z1 = new Zombie("Zobmie1");
	Zombie *z2 = new Zombie("Zobmie2");

	z1->announce();
	z2->announce();

	Zombie *new_zom = newZombie("NewZombie");
	new_zom->announce();

	randomChump("Zombie_made_by_randomChump");

	delete z1;
	delete z2;
	delete new_zom;
	// system("leaks zombie");
	return (0);
}
