#include "Form.hpp"

Form::Form() : name("Unnamed") , is_signed(false) , gradeRequiredToExecute(150) , gradeRequiredToSign(150)
{
}

Form::Form(int _gradeRequiredToSign, int _gradeRequiredToExecute,std::string _name, bool is_signed) : name(_name) , gradeRequiredToExecute(_gradeRequiredToExecute) , gradeRequiredToSign(_gradeRequiredToSign) , is_signed(is_signed)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form& obj) : name(obj.name) , gradeRequiredToExecute(obj.gradeRequiredToExecute) , gradeRequiredToSign(obj.gradeRequiredToSign) , is_signed(obj.s_signed)
{
}

const Form& Form::operator=(const Form& obj)
{
    std::cout << "Form copy assignment operator called" << std::endl;
	if (&obj != this)
	{
		const_cast<std::string &>(this->name) = obj.name;
		this->isSigned = obj.isSigned;
		const_cast<int &>(this->signGrade) = obj.signGrade;
		const_cast<int &>(this->executeGrade) = obj.executeGrade;
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
	if (obj.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
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