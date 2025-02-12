#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
	if(argc <= 1)
	{
		std::cout << "Please enter command  " << YELLOW "ADD | SEARCH | EXIT " RESET << std::endl;
		return(0);
	}
	PhoneBook my_note;
	if(!strcmp(argv[1], "ADD"))
		my_note.add_contact();
	else if(!strcmp(argv[1], "SEARCH"))
		my_note.search_contact();
	else if(!strcmp(argv[1], "EXIT") && argc == 2)
	{
		std::cout << "EXIT" << std::endl;
		return(0);
	}
	else
	{
		std::cout << RED "Something is wrong" RESET << std::endl;
		std::cout << "Please enter command " << YELLOW "ADD | SEARCH | EXIT " RESET << std::endl;
	}
	return(0);
}
