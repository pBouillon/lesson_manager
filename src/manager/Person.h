/** \file person.h
  *
  * \brief Person definition
  *
  * \version 0.0.1
  *
  * \author Damien Choffe
  * \author Maxime Nicolas
  * \author Pierre Bouillon
  */

#ifndef UNTITLED_PERSON_H_
#define UNTITLED_PERSON_H_

#include <ostream>

class Person {
public:
    Person (char* _name, int _rights) ;
    ~Person() ;

    char* get_name () ;

    int   get_rights () ;

    void  set_name   (char* _name) ;
    void  set_rights (int _rights) ;

private:
    friend std::ostream& operator<<(std::ostream&, const Person&);

    char* name ;
    int   rights ;
} ;

#endif //UNTITLED_PERSON_H_
