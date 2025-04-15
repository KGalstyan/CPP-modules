#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern intern;
    Bureaucrat boss("Big Boss", 1);

    AForm* shrub = intern.makeForm("shrubbery creation", "Garden");
    AForm* robo = intern.makeForm("robotomy request", "Bender");
    AForm* pardon = intern.makeForm("presidential pardon", "Rick");
    AForm* fail = intern.makeForm("coffee request", "Intern");

    if (shrub) {
        boss.signForm(*shrub);
        boss.executeForm(*shrub);
        delete shrub;
    }

    if (robo) {
        boss.signForm(*robo);
        boss.executeForm(*robo);
        delete robo;
    }

    if (pardon) {
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
        delete pardon;
    }

    if (fail == NULL) {
        std::cout << "Failed to create unknown form correctly." << std::endl;
    }

    return 0;
}
