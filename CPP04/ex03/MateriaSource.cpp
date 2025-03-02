MateriaSource::MateriaSource() {
    for (int i = 0; i < MAX_MATERIAS; i++)
        templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < MAX_MATERIAS; i++)
        templates[i] = NULL;
    *this = other;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < MAX_MATERIAS; i++) {
        delete templates[i];
        templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        // Clean up existing templates
        for (int i = 0; i < MAX_MATERIAS; i++) {
            delete templates[i];
            templates[i] = NULL;
        }
        
        // Copy new templates
        for (int i = 0; i < MAX_MATERIAS; i++) {
            if (other.templates[i]) {
                templates[i] = other.templates[i]->clone();
            }
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return;
        
    for (int i = 0; i < MAX_MATERIAS; i++) {
        if (!templates[i]) {
            templates[i] = m;
            return;
        }
    }
    // If we couldn't store it, delete it
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < MAX_MATERIAS; i++) {
        if (templates[i] && templates[i]->getType() == type)
            return templates[i]->clone();  // Return a clone, not the original
    }
    return NULL;
} 