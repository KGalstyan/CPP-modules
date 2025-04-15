#include "Intern.hpp"

const char * Intern::NoSuchFormType::what() const throw()
{
    return "No such form type!\n";
}

Intern::Intern()
{
}

Intern::Intern(const std::string& smth)
{
    (void)smth;
}

Intern::Intern(const Intern& obj)
{
    *this = obj;
}

const Intern& Intern::operator=(const Intern& obj)
{
    if(this != &obj)
    {
        *this = obj;
    }
    return(*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	int i = 0;
	while (i < 3 && formNames[i] != name)
		i++;

	std::cout << "Intern ";
	if (i == 3) {
		std::cout << "couldn't find the form: " << name << std::endl;
		throw Intern::NoSuchFormType();
	}

	std::cout << "creates " << name << std::endl;

	if (i == 0)
		return new ShrubberyCreationForm(target);
	else if (i == 1)
		return new RobotomyRequestForm(target);
	return new PresidentialPardonForm(target);
}
