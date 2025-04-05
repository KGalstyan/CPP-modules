#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class AMateria
{
    protected:
        const std::string type;
    public:
        AMateria(std::string const & type);
        AMateria();
        AMateria(AMateria& const obj);
        AMateria& operator=(AMateria& const obj);
        ~AMateria();

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif