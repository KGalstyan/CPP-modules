#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include "AForm.hpp"

#define ASCII_TREE "\
        &&& &&  & &&\n\
    && &\\/&\\|& ()|/ @, &&\n\
    &\\/(/&/&||/& /_/)_&/_&\n\
 &() &\\/&|()|/&\\/ '%\" & ()\n\
 &_\\_&&_\\ |& |&&/&__%_/_& &&\n\
&&   && & &| &| /& & % ()& /&&\n\
 ()&_---()&\\&\\|&&-&&--%---()~\n\
     &&     \\|||\n\
             |||\n\
             |||\n\
             |||\n\
       , -=-~  .-^- _\n"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& _target);
        ShrubberyCreationForm(const ShrubberyCreationForm& obj);
        const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
        ~ShrubberyCreationForm();

        const std::string& getTarget() const;
        void execute(Bureaucrat const &executor) const;
};

#endif