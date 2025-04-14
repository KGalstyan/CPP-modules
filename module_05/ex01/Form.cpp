#include "Form.hpp"

Form::Form() : name("Unnamed") , is_signed(false) , gradeRequiredToSign(150) , gradeRequiredToExecute(150) 
{
}

Form::Form(int _gradeRequiredToSign, int _gradeRequiredToExecute,std::string _name, bool is_signed) : name(_name) , is_signed(is_signed) , gradeRequiredToSign(_gradeRequiredToSign) , gradeRequiredToExecute(_gradeRequiredToExecute)
{
	if (_gradeRequiredToSign < 1 || _gradeRequiredToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeRequiredToSign > 150 || _gradeRequiredToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form& obj) : name(obj.getName()) , is_signed(obj.getSign()) , gradeRequiredToSign(obj.getSignGrade()) , gradeRequiredToExecute(obj.getExecuteGrade())
{
}

const Form& Form::operator=(const Form& obj)
{
    std::cout << "Form copy assignment operator called" << std::endl;
	if (&obj != this)
	{
		const_cast<std::string &>(this->name) = obj.getName();
		this->is_signed = obj.getSign();
		const_cast<int &>(this->gradeRequiredToSign) = obj.getSignGrade();
		const_cast<int &>(this->gradeRequiredToExecute) = obj.getExecuteGrade();
	}
	return *this;
}

Form::~Form()
{
}

const std::string& Form::getName(void) const
{
    return(this->name);
}

bool Form::getSign() const
{
    return(this->is_signed);
}

int Form::getSignGrade() const
{
    return(this->gradeRequiredToSign);
}

int Form::getExecuteGrade() const
{
    return(this->gradeRequiredToExecute);
}

void Form::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > getSignGrade())
		throw Form::GradeTooLowException();
	this->is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "The grade cannot be higher than 1.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "The grade cannot be lower than 150.";
}

std::ostream&	operator<<(std::ostream& os, const Form& ob)
{
    os << "Name: " << ob.getName() << std::endl;
    os << "Is signed: " << ob.getSign() << std::endl;
    os << "Grade to sign: " << ob.getSignGrade() << std::endl;
    os << "Grade to execute: " << ob.getExecuteGrade() << std::endl;
    return os;
}