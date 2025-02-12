#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include <iostream>
#include <string>
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


class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void add_contact();
		void search_contact();
		Contact note[8];
		int index;
};

#endif
