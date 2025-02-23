#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstring>

class Zombie
{
	public:
		Zombie(const std::string &name);
		~Zombie();
		void announce( void );
		void set_name(const std::string &name);
		std::string get_name(void);
	private:
		std::string name;
};

Zombie* newZombie( std::string name );
void randomChump ( std::string name );

#endif
