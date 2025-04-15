#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm(72, 45, "Default", 0) , target("target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target) : AForm(72, 45, "Default", 0) , target(_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj) , target(obj.getTarget())
{
}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
    if(this != &obj)
    {
        AForm::operator=(obj);
        this->target = obj.getTarget();
    }
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const std::string& RobotomyRequestForm::getTarget() const 
{
    return(this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    AForm::checkExecute(executor);
    std::cout << "Some drilling noices " << std::endl;
    if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " robotomy failed." << std::endl;
}
