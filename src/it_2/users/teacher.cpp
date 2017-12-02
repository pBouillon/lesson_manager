/** 
 * \file teacher.cpp
 * \brief teacher implementation
 *
 * \version 0.0.2
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

// basics include

#include <iostream>
#include "teacher.h"

/**
 * \name Teacher constructor
 *
 * \param _name  username
 * \param _login user's login
 * \param _right user's right
 */

Teacher::Teacher (
    char *_name, 
    char *_login, 
    int   _right) 
: Person(_name, _login, _right) {} /* Teacher() */

/**
 * \name    Teacher destructor
 * \brief   Destroy a Teacher object
 *
 * Destructor for Teacher
 */
Teacher::~Teacher() = default ;

/**
 * \fn  get_status
 *  
 * \return teacher status
 */
char* Teacher::get_status() const {
    return (char*)user_status::teacher ;
} /* get_status() */
