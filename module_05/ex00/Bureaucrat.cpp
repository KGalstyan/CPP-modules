#include "Bureaucrat.hpp"   

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade Too High\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade Too Low\n");
}

Bureaucrat::Bureaucrat() : name("Default") , grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& _name, const int& _grade) : name(_name) , grade(_grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.getName()) , grade(obj.getGrade())
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    if(this != &obj)
    {
        this->grade = obj.grade;
        const_cast<std::string&>(this->name) = obj.name;
    }
    return(*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
    return(this->name);
}

int Bureaucrat::getGrade() const
{
    return(this->grade);
}

void Bureaucrat::incrementGrade()
{
    this->grade--;
    if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decrementGrade()
{
    this->grade++;
    if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}