#include "Harl.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Wrong type" << std::endl;
		return(0);
	}
	Harl com;
	com.complain(argv[1]);
	return(0);
}
