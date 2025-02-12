#ifndef Contact_HPP
#define Contact_HPP

#include <iostream>

class Contact
{
	public:
		Contact();
		~Contact();
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nick_name();
		std::string get_darkest_secret();
		void set_first_name(const std::string &f_name);
		void set_last_name(const std::string &l_name);
		void set_nick_name(const std::string &n_name);
		void set_darkest_secret(const std::string &d_secret);
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string darkest_secret;
};

#endif
