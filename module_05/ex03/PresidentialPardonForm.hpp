#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& _target);
        PresidentialPardonForm(const PresidentialPardonForm& obj);
        const PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
        ~PresidentialPardonForm();
        
        const std::string& getTarget() const;
        void execute(Bureaucrat const &executor) const;
};

#endif