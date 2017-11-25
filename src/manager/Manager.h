#ifndef UNTITLED_MANAGER_H_
#define UNTITLED_MANAGER_H_

#include <ostream>
#include "Person.h"

class Manager {
public:
    Manager();
    ~Manager() ;

    int login (const char* login, const char* password) ;
    int logout () ;

    bool is_connected()const;

    Person get_person () ;

private:
    bool connected ;
};


#endif //UNTITLED_MANAGER_H_
