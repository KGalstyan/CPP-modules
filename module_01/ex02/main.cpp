#include <iostream>

int main()
{
	std::string stringNAME = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringNAME;
	std::string &stringREF = stringNAME;

	std::cout << &stringNAME << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << stringNAME << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return(0);
}
