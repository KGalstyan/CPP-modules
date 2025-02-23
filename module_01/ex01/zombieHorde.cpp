#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zom_ptr;
	if(N < 0 || N > 2147483646)
		return(NULL);
	zom_ptr = new Zombie[N];
	for(int i = 0; i < N; i++)
		zom_ptr[i].set_name(name);
	return (zom_ptr);
}
