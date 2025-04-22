#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern intern;
    Bureaucrat boss("Big Boss", 1);

    AForm* shrub = NULL;
    AForm* robo = NULL;
    AForm* pardon = NULL;
    AForm* fail = NULL;

    try
    {
        shrub = intern.makeForm("shrubbery creation", "Garden");
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }

    try
    {
        robo = intern.makeForm("robotomy request", "Bender");
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }

    try
    {
        pardon = intern.makeForm("presidential pardon", "Rick");
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }

    try
    {
        fail = intern.makeForm("coffee request", "Intern");
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }

    if (shrub)
    {
        boss.signForm(*shrub);
        boss.executeForm(*shrub);
        delete shrub;
    }

    if (robo)
    {
        boss.signForm(*robo);
        boss.executeForm(*robo);
        delete robo;
    }

    if (pardon)
    {
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
        delete pardon;
    }

    if (fail == NULL)
    {
        std::cout << "Failed to create unknown form correctly." << std::endl;
    }

    return 0;
}

