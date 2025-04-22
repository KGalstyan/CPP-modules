#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 1);

        Bureaucrat joe("Joe", 140);
        Bureaucrat tim("Tim", 50);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Marvin");
        PresidentialPardonForm pardon("Arthur");

        std::cout << "\n--- Testing signing and execution ---\n";
        joe.signForm(shrub);
        joe.executeForm(shrub);
        bob.signForm(robo);
        bob.signForm(pardon);
        bob.executeForm(robo);
        bob.executeForm(pardon);
        bob.signForm(shrub);
        bob.executeForm(shrub);
        shrub.execute(bob);


        std::cout << "\n--- Testing execution without signing ---\n";
        ShrubberyCreationForm unsignedForm("garden");
        bob.executeForm(unsignedForm);

        std::cout << "\n--- Testing grade too low to execute ---\n";
        tim.signForm(robo);
        tim.executeForm(robo);

    }
	catch (std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
