#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& _target);
        RobotomyRequestForm(const RobotomyRequestForm& obj);
        const RobotomyRequestForm& operator=(const RobotomyRequestForm& obj)
        ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor) const;
};

#endif