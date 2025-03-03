#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Contact.hpp"

#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define RESET   "\033[0m"

int check_number(const std::string &name);

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		int add_contact(Contact *new_contact,const std::string &f_name, const std::string &l_name, const std::string &n_name, const std::string &p_number, const std::string &d_secret, int i);
		void search_contact(Contact *contacts, int index, int con_num);
		void print_all_contacts(Contact *contact, int con_num);
		Contact *get_contacts();
		int index;
		int number_of_contacts;
	private:
		Contact cont[8];
};

#endif
