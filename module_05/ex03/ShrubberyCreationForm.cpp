#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(145, 137, "Default", 0) , target("target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target) : AForm(145, 137, "Default", 0) , target(_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj) , target(obj.getTarget())
{
}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
    if(this != &obj)
    {
        AForm::operator=(obj);
        this->target = obj.getTarget();
    }
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string& ShrubberyCreationForm::getTarget() const 
{
    return(this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    AForm::checkExecute(executor);
    std::ofstream outfile((this->target + "_shrubbery").c_str());
    if (outfile.is_open())
    {
        outfile << ASCII_TREE;
        outfile.close();
    }
}
