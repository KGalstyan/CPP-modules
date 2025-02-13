#include "PhoneBook.hpp"

//    index, first name, last name and nickname, darkest secret.

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

int check_name(const std::string &name)
{
	for (int i = 0; name[i]; i++)
	{
		if(!isalpha(name[i]))
			return(0);
	}
	return(1);
}

int check_number(const std::string &name)
{
	for (int i = 0; name[i]; i++)
	{
		if(!isdigit(name[i]))
			return(0);
	}
	return(1);
}

int PhoneBook::add_contact(Contact *new_contact, const std::string &f_name, const std::string &l_name, const std::string &n_name, const std::string &p_number, const std::string &d_secret, int i)
{
	if(check_number(p_number) && check_name(f_name) && check_name(l_name) && check_name(n_name))
	{
    	new_contact[i].set_first_name(f_name);
    	new_contact[i].set_last_name(l_name);
    	new_contact[i].set_nick_name(n_name);
    	new_contact[i].set_phone_number(p_number);
    	new_contact[i].set_darkest_secret(d_secret);
	}
	else
	{
		std::cout << RED "Invalid format of names or number !" RESET << std::endl;
		return(0);
	}
	return(1);
}

void PhoneBook::search_contact(Contact *contacts, int index, int con_num)
{
	if(con_num == 0)
	{
		std::cout << RED "There are no contacts here.Add contacts ! " RESET << std::endl;
		return ;
	}
	if(index >= con_num)
	{
		std::cout << RED "There is no such index.Try again." RESET << std::endl;
		return ;
	}
	std::string f_name = contacts[index].get_first_name();
	std::string l_name = contacts[index].get_last_name();
	std::string n_name = contacts[index].get_nick_name();
	std::cout << index << " | ";
	std::cout << f_name << " | ";
	std::cout << l_name << " | ";
	std::cout << n_name << std::endl;

}

void PhoneBook::print_all_contacts(Contact *contacts, int con_num)
{
	for(int i = 0; i < con_num; i++)
	{
		std::string f_name = contacts[i].get_first_name();
		std::string l_name = contacts[i].get_last_name();
		std::string n_name = contacts[i].get_nick_name();
		if(f_name.length() > 10)
			f_name = f_name.substr(0, 9) + ".";
		if(l_name.length() > 10)
			l_name = l_name.substr(0, 9) + ".";
		if(n_name.length() > 10)
			n_name = n_name.substr(0, 9) + ".";
		std::cout << i << " | ";
		std::cout << f_name << " | ";
		std::cout << l_name << " | ";
		std::cout << n_name << std::endl;
	}
}

Contact *PhoneBook::get_contacts()
{
	return(this->cont);
}

