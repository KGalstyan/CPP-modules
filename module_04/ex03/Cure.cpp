#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const std::string& smth) : AMateria("ice")
{
    (void)smth;
}

Cure::Cure(const Cure& obj) : AMateria(obj.getType())
{
}

Cure& Cure::operator=(const Cure& obj)
{
    if(this != &obj)
    {
        this->type = obj.type;
    }
    return(*this);
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
    return(new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}