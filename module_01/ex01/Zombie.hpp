#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstring>

#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define RESET   "\033[0m"

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void announce( void );
		void set_name(const std::string &name);
		std::string get_name(void);
	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
