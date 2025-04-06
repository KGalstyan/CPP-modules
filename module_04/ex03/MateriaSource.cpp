#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        this->slots[i] = NULL;
}

MateriaSource::MateriaSource(std::string param)
{
    (void)param;
    for (int i = 0; i < 4; ++i)
        this->slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	for (int i = 0; i < 4; ++i)
	{
		delete this->slots[i];
		this->slots[i] = obj.slots[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
    if(this != &obj)
    {
		for (int i = 0; i < 4; ++i)
		{
			delete this->slots[i];
			this->slots[i] = obj.slots[i]->clone();
		}
    }
    return(*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        delete this->slots[i];
}


void MateriaSource::learnMateria(AMateria* materia)
{
    if (!materia)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (!this->slots[i])
        {
            this->slots[i] = materia;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->slots[i] && this->slots[i]->getType() == type)
			return this->slots[i]->clone();
	}
	return (0);
}
