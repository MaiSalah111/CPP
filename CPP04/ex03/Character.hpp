class Character : public ICharacter {
private:
    static const int MAX_SLOTS = 4;
    static const int MAX_DROPPED = 100;
    std::string name;
    AMateria* inventory[MAX_SLOTS];
    AMateria* dropped[MAX_DROPPED];
    int droppedCount;

public:
    Character(std::string const & name);
    Character(Character const & other);
    virtual ~Character();
    Character& operator=(Character const & other);
    
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
}; 