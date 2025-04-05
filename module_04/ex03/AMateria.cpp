#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::AMateria() : _type("Default")
{
}

AMateria::AMateria(AMateria &const obj) : _type(obj.type)
{
}

AMateria& AMateria::operator=(AMateria& const obj)
{
    if(this != &obj)
    {
        this->type = obj.type;
    }
    return(*this);
}

~AMateria()
{
}

std::string const& AMateria::getType() const
{
    return(this->type);
}
