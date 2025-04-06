#include "AMateria.hpp"

AMateria::AMateria(const std::string& _type) : type(_type)
{
}

AMateria::AMateria() : type("Default")
{
}

AMateria::AMateria(const AMateria& obj) : type(obj.getType())
{
}

AMateria& AMateria::operator=(const AMateria& obj)
{
    if(this != &obj)
    {
        this->type = obj.type;
    }
    return(*this);
}

AMateria::~AMateria()
{
}

std::string const& AMateria::getType() const
{
    return(this->type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria name is " << target.getName() << std::endl;
}