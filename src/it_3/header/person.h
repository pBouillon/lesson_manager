/** 
 * \file person.h
 * \brief Person definition
 *
 * \version 0.0.2
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */
#ifndef LESSON_MANAGER_PERSON_H_
#define LESSON_MANAGER_PERSON_H_

// basics include
#include <list>

// custom headers
#include "lesson.h"

/**
 * \namespace user_status
 */
namespace user_status {
    const char * const admin   = "Admin" ;
    const char * const person  = "Person" ;
    const char * const student = "Student" ;
    const char * const teacher = "Teacher" ;
}

class Person {
public:
    Person(char *_name, char *_login, int _right) ;
    ~Person() ;

    char * get_name() ;
    char * get_login() ;

    int    get_rights() ;

    void   add_lesson(Lesson* l) ;
    void   toString() ;
    void   show_list() ;

    virtual char* get_status() const {
        return (char*)user_status::person ;
    }
    
protected: /* attributes */
    int    right ;

    char * login ;
    char * name ;

    std::list<Lesson*> lessons ;
} ;
    
#endif /* LESSON_MANAGER_PERSON_H_ */
