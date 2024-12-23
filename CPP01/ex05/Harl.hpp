#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    // Structure to map levels to member functions
    struct FuncMap {
        std::string level;
        void (Harl::*func)(void);
    };
    
    static FuncMap funcMap[4];

public:
    void complain(std::string level);
};

#endif 