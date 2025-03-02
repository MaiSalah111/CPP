#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
        materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        if(materias[i])
            delete materias[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    for(int i = 0; i < 4; i++)
        materias[i] = NULL;
    for(int i = 0; i < 4; i++)
    {
        if(copy.materias[i])
            this->materias[i] = copy.materias[i]->clone();
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if(this != &other)
    {
        for(int i = 0; i < 4; i++)
        {
            if(materias[i])
            {
                delete materias[i];
                materias[i] = NULL;
            }
        }
        for(int i = 0; i < 4; i++)
        {
            if(other.materias[i])
                materias[i] = other.materias[i]->clone();
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
    if(!m)
    {
        std::cout << " No Materia provided to learn" << std::endl;
        return ;
    }
    for(int i = 0; i < 4; i++)
        {
            if(materias[i] == NULL)
            {
                materias[i] = m;
                return ;
            }
        }
    std::cout << "Cannot learn any more materia as inventory is full" << std::endl;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
    for(int i = 0; i < 4; i++)
    {
        if(materias[i] && materias[i]->getType() == type)
        {
            return (materias[i]->clone());
        }
    }
    std::cout << type << " materia is not found in inventory" << std::endl;
    return (NULL);
}