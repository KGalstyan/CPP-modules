#include "Harl.hpp"

int main(int argc, char **argv)
{
	if(argc != 2){
		std::cout << "Wrong number arguments" << std::endl;
		return(1);
	}
	Harl com;
	int level = 1;
	std::string var[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for(int i = 0; i < 4 ; i++)
	{
		if(argv[1] == var[i])
			break;
		level++;
	}
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
			break;
		}
		default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return(0);
}
