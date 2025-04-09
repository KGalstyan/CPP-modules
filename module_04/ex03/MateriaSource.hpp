#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource(std::string param);
        MateriaSource(const MateriaSource& obj);
        MateriaSource& operator=(const MateriaSource& obj);
        ~MateriaSource();

        void learnMateria(AMateria* mat);
        AMateria* createMateria(std::string const& type);
    private:
        AMateria *slots[4];
};

#endif