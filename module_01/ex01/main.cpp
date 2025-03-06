#include "Zombie.hpp"

int main()
{
	Zombie *arr_zombie;
	int n = 4;

	arr_zombie = zombieHorde( n, "Zimbo");
	if(!arr_zombie)
	{
		std::cout << "Wrong N !" << std::endl;
		return(1);
	}
	std::cout << "first one: " << arr_zombie->get_name() << std::endl;
	for(int i = 0; i < n; i++)
		std::cout << i+1 << " "
		<< arr_zombie[i].get_name() << std::endl;
	delete[] arr_zombie;
	// system("leaks hordeofzombie");
	return (0);
}


