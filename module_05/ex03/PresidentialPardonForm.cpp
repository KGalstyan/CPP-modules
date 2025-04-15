#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(25, 5, "Default", 0) , target("target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target) : AForm(25, 5, "Default", 0) , target(_target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj) , target(obj.getTarget())
{
}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
    if(this != &obj)
    {
        AForm::operator=(obj);
        this->target = obj.getTarget();
    }
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

const std::string& PresidentialPardonForm::getTarget() const 
{
    return(this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::checkExecute(executor);
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
