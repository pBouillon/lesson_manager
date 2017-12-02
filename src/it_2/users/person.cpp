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

// custom headers
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
 * \fn toString
 * \brief prints on standart output person's informations
 */
void Person::toString () { 
    std::cout << "Name : "  << name << std::endl ;
    std::cout << "Login : " << login << std::endl ;
    std::cout << "Status : "<< get_status() << std::endl ;
} /* toString () */
