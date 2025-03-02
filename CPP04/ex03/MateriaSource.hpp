#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
    private:
    AMateria *materias[4];

    public:
    MateriaSource();
    MateriaSource(const MateriaSource &copy);
    ~MateriaSource();

    MateriaSource &operator=(const MateriaSource &other);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif