#include "Form.hpp"

Form::Form() : name("Unnamed") , is_signed(false) , gradeRequiredToExecute(150) , gradeRequiredToSign(150)
{
}

Form::Form(int _gradeRequiredToSign, int _gradeRequiredToExecute,std::string _name, bool is_signed) : name(_name) , gradeRequiredToExecute(_gradeRequiredToExecute) , gradeRequiredToSign(_gradeRequiredToSign) , is_signed(is_signed)
{
}

Form::Form(Form& obj) : name(obj.name) , gradeRequiredToExecute(obj.gradeRequiredToExecute) , gradeRequiredToSign(obj.gradeRequiredToSign) , is_signed(obj.s_signed)
{
}

Form& Form::operator=(Form& obj)
{
}

Form::~Form()
{
}

const std::string get_name()
{
}

beSigned(Bureaucrat& Bureau)
{
}

std::ostream& operator<<(std::ostream& os, const Form& b)
{
    // os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}