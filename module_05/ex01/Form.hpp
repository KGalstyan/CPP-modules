#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };

    private:
        const std::string name;
        bool is_signed;
        const int gradeRequiredToSign;
        const int gradeRequiredToExecute;
    public:
        Form();
        Form();
        Form(Form& obj);
        Form& operator=(Form& obj);
        ~Form();
        
        const std::string get_name();
        beSigned(Bureaucrat& Bureau);
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif