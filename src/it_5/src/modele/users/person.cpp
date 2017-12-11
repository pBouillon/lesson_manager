/**
 * \file person.ccp
 * \brief Person implementation
 *
 * \version 0.0.1
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */
// basics include
#include <iostream>
#include <iterator>

// custom headers
#include "lesson.h"
#include "person.h"

/**
 * \name    Person constructor
 * \brief   Instanciate a Person object
 *
 * Constructor for Person
 *
 * \param   _name   username
 * \param   _login  person's login
 * \param   _right  person's right
 */     
Person::Person (char *_name, char *_login, int _right) {
    name  = _name ;
    right = _right ;
    login = _login ;
} /* Person (char *_name, char *_login, int _right) */

/**
 * \name    Person destructor
 * \brief   Destroy an Person object
 *
 * Destructor for Person
 */
Person::~Person() = default ;

/**
 * \fn      add_lesson
 * \brief   add a lesson to the current person
 *
 * \param   c   lesson to add
 */
void Person::add_lesson(Lesson* l) {
    lessons.push_back(l) ;
} /* add_course(Cours* l) */

/**
 * \fn get_name
 *
 * \return person's name
 */
char * Person::get_name() {
    return name ;
} /* char * get_name() */

/**
 * \fn get_login
 *
 * \return person's login
 */
char * Person::get_login() {
    return login ;
} /* char * get_login() */

/**
 * \fn get_rights
 *
 * \return person's right
 */
int Person::get_rights(){
    return right ;
} /* int get_rights ()  */

/**
 * \fn      show_list
 * \brief   lists all lessons of the person
 */
void Person::show_list() {
    std::list<Lesson*>::iterator it;

    for (it = lessons.begin(); it != lessons.end(); ++it) {
        Lesson *l  = *it ;
        char *name = l->get_title() ;

        std::cout << name << std::endl ;
    }
} /* show_list() */

/**
 * \fn toString
 * \brief prints on standart output person's informations
 */
void Person::toString () { 
    std::cout << "Name : "  << name << std::endl ;
    std::cout << "Login : " << login << std::endl ;
    std::cout << "Status : "<< get_status() << std::endl ;
} /* toString () */
