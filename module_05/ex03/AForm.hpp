#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
    class IsSignedException : public std::exception 
    {
        public:
            const char* what() const throw();
    };

    private:
        const std::string name;
        bool is_signed;
        const int gradeRequiredToSign;
        const int gradeRequiredToExecute;
    public:
        AForm();
        AForm(int _gradeRequiredToSign, int _gradeRequiredToExecute,std::string _name, bool is_signed);
        AForm(const AForm& obj);
        const AForm& operator=(const AForm& obj);
        virtual ~AForm();
        
        const std::string &getName(void) const;
        bool getSign() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        void beSigned(const Bureaucrat &);
        void checkExecute(const Bureaucrat &executor) const;
    protected:
        virtual void execute(Bureaucrat const &executor) const = 0;
        
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif