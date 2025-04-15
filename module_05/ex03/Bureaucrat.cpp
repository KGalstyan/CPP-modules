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

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name) , grade(_grade)
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
        const_cast<std::string &>(this->name) = obj.name;
        this->grade = obj.grade;
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
    if(this->grade > 1)
        this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if(this->grade < 150)
        this->grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

void Bureaucrat::signForm(AForm &obj) const
{
    try
    {
        if (obj.getSign())
        {
            std::cout<<this->getName()<<" coudn't sign "<<obj.getName()<<" because the form is already signed!"<<std::endl;
            return ;
        }
        obj.beSigned(*this);
        std::cout<<this->getName()<<" signed "<<obj.getName()<<std::endl;
    }
    catch(std::exception& e)    
    {
        std::cout<<this->getName()<<" coudn't sign "<<obj.getName()<<" because "<< e.what()<<std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form) const
{
    try
	{
		form.checkExecute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
