#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

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
        Form(int _gradeRequiredToSign, int _gradeRequiredToExecute,std::string _name, bool is_signed);
        Form(Form& obj);
        const Form& operator=(const Form& obj);
        ~Form();
        
        void beSigned(Bureaucrat& Bureau);
        const std::string& getName(void) const;
        bool getSign() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        void beSigned(const Bureaucrat &obj);
        
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif