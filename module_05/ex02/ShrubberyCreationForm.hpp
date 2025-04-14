#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& _target);
        ShrubberyCreationForm(const ShrubberyCreationForm& obj);
        const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj)
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const &executor) const;
};

#endif