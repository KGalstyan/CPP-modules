#include "Harl.hpp"

int main(int argc, char **argv)
{
	if(argc != 2){
		std::cout << "Wrong number arguments" << std::endl;
		return(1);
	}
	Harl com;
	int level = 0;
	if(!strcmp(argv[1], "DEBUG"))
		level = 1;
	else if(!strcmp(argv[1], "INFO"))
		level = 2;
	else if(!strcmp(argv[1], "WARNING"))
		level = 3;
	else if(!strcmp(argv[1], "ERROR"))
		level = 4;
	switch(level)
	{
		case(1):{
			std::cout << "[ DEBUG ]" << std::endl;
			com.complain("DEBUG");
		}
		case(2):{
			std::cout << "[ INFO ]" << std::endl;
			com.complain("INFO");
		}
		case(3):{
			std::cout << "[ WARNING ]" << std::endl;
			com.complain("WARNING");
		}
		case(4):{
			std::cout << "[ ERROR ]" << std::endl;
			com.complain("ERROR");
		}
		default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return(0);
}
