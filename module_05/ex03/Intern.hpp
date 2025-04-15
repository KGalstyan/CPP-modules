#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    class NoSuchFormType : public std::exception
    {
        public:
            const char *what() const throw();
    };
    public:
        Intern();
        Intern(const std::string& smth);
        Intern(const Intern& obj);
        const Intern& operator=(const Intern& obj);
        ~Intern();

        AForm *makeForm(const std::string& name, const std::string& target);
};

#endif