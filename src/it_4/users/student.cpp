/** 
 * \file student.cpp
 * \brief student implementation
 *
 * \version 0.0.2
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

// basics include
#include <iostream>

// custom headers
#include "student.h"

/**
 * \name    Student constructor
 * \brief   Instanciate a Student object
 *
 * Constructor for Student
 *
 * \param   _name   username
 * \param   _login  student's login
 * \param   _right  student's right
 */
Student::Student (
    char *_name, 
    char *_login, 
    int   _right) 
: Person(_name, _login, _right) {} /* Student() */

/**
 * \name    Student destructor
 * \brief   Destroy a Student object
 *
 * Destructor for Student
 */
Student::~Student() = default ;

/**
 * \fn  get_status
 *  
 * \return student status
 */
char* Student::get_status() const {
    return (char*)user_status::student ;
} /* get_status() */
