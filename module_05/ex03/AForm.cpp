#include "AForm.hpp"

AForm::AForm() : name("Unnamed") , is_signed(false) , gradeRequiredToSign(150) , gradeRequiredToExecute(150) 
{
}

AForm::AForm(int _gradeRequiredToSign, int _gradeRequiredToExecute,std::string _name, bool is_signed) : name(_name) , is_signed(is_signed) , gradeRequiredToSign(_gradeRequiredToSign) , gradeRequiredToExecute(_gradeRequiredToExecute)
{
	if (_gradeRequiredToSign < 1 || _gradeRequiredToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeRequiredToSign > 150 || _gradeRequiredToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& obj) : name(obj.getName()) , is_signed(obj.getSign()) , gradeRequiredToSign(obj.getSignGrade()) , gradeRequiredToExecute(obj.getExecuteGrade())
{
}

const AForm& AForm::operator=(const AForm& obj)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
	if (&obj != this)
	{
		const_cast<std::string &>(this->name) = obj.getName();
		this->is_signed = obj.getSign();
		const_cast<int &>(this->gradeRequiredToSign) = obj.getSignGrade();
		const_cast<int &>(this->gradeRequiredToExecute) = obj.getExecuteGrade();
	}
	return *this;
}

AForm::~AForm()
{
}

const std::string& AForm::getName(void) const
{
    return(this->name);
}

bool AForm::getSign() const
{
    return(this->is_signed);
}

int AForm::getSignGrade() const
{
    return(this->gradeRequiredToSign);
}

int AForm::getExecuteGrade() const
{
    return(this->gradeRequiredToExecute);
}

void AForm::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > getSignGrade())
		throw AForm::GradeTooLowException();
	this->is_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "The grade cannot be higher than 1.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "The grade cannot be lower than 150.";
}

std::ostream&	operator<<(std::ostream& os, const AForm& ob)
{
    os << "Name: " << ob.getName() << std::endl;
    os << "Is signed: " << ob.getSign() << std::endl;
    os << "Grade to sign: " << ob.getSignGrade() << std::endl;
    os << "Grade to execute: " << ob.getExecuteGrade() << std::endl;
    return os;
}

const char* AForm::IsSignedException::what() const throw()
{
	return "The form is not signed!";
}

void AForm::checkExecute(const Bureaucrat &executor) const
{
	if (!this->getSign())
		throw AForm::IsSignedException();
	else if (executor.getGrade() > this->gradeRequiredToExecute)
		throw AForm::GradeTooLowException();
}