class MateriaSource : public IMateriaSource {
private:
    static const int MAX_MATERIAS = 4;
    AMateria* templates[MAX_MATERIAS];

public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    virtual ~MateriaSource();
    MateriaSource& operator=(const MateriaSource& other);

    virtual void learnMateria(AMateria*);
    virtual AMateria* createMateria(std::string const & type);
}; 