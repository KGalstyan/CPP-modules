#include "PhoneBook.hpp"

void my_getter(std::string &dst)
{
	std::getline(std::cin, dst);
	if (!std::cin)
	{
        std::cout << MAGENTA "EOF reached or input error occurred. Exiting program." RESET << std::endl;
        exit(1);
	}
}

int my_stoi(std::string &num)
{
	int res = 0;
	for(unsigned long i = 0; i < num.length(); i++)
		res = res * 10 + (num[i] - '0');
	return(res);
}

int main()
{
    PhoneBook my_note;
    std::string command;
	std::string search_index;
	my_note.index = 0;
	my_note.number_of_contacts = 0;

    std::cout << "Please enter command: " << YELLOW "ADD | SEARCH | EXIT " RESET << std::endl;
    while (true)
	{
        my_getter(command);
		if (!std::cin)
		{
            std::cout << MAGENTA "\nEOF reached or input error occurred. Exiting program." RESET << std::endl;
            break;
		}
        if (command == "ADD")
		{
            if (my_note.index >= 8)
				my_note.index = 0;
            std::string f_name, l_name, n_name, p_number, d_secret;
            std::cout << "Enter first name: ";
            my_getter(f_name);
            std::cout << "Enter last name: ";
            my_getter(l_name);
            std::cout << "Enter nickname: ";
            my_getter(n_name);
            std::cout << "Enter phone number: ";
            my_getter(p_number);
            std::cout << "Enter darkest secret: ";
            my_getter(d_secret);
			if(!f_name.empty() && !l_name.empty() && !n_name.empty() && !p_number.empty() && !d_secret.empty())
			{
            	if(my_note.add_contact(my_note.get_contacts(), f_name, l_name, n_name, p_number, d_secret, my_note.index))
				{
            		my_note.index++;
					if(my_note.number_of_contacts < 8)
						my_note.number_of_contacts++;
            		std::cout << GREEN "Contact added successfully!" RESET << std::endl;
				}
			}
			else
				std::cout << RED "There are empty data.Please enter correct data." RESET << std::endl;
        }
		else if (command == "SEARCH")
		{
			my_note.print_all_contacts(my_note.get_contacts(), my_note.number_of_contacts);
			std::cout << "Which index contact do you need : ";
			my_getter(search_index);
			if(!search_index.empty())
			{
				if(search_index.length() < 2 && check_number(search_index))
					my_note.search_contact(my_note.get_contacts(), my_stoi(search_index), my_note.number_of_contacts);
				else
					std::cout << RED "There are no contacts here.Add contacts ! " RESET << std::endl;
			}
			else
				std::cout << RED "There are empty data.Please enter correct data." RESET << std::endl;
        }
		else if (command == "EXIT")
		{
            std::cout << "Exiting program." << std::endl;
            break;
        }
		else
            std::cout << RED "Invalid command. Please try again." RESET << std::endl << "Please enter command: " << YELLOW "ADD | SEARCH | EXIT " RESET << std::endl;
    }
    return 0;
}
