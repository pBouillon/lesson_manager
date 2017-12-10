/** 
 * \file admin.cpp
 * \brief administrator implementation
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
#include "admin.h"

/**
 * \name    Admin constructor
 * \brief   Instanciate an Admin object
 *
 * Constructor for Admin
 *
 * \param   _name   username
 * \param   _login  admin's login
 * \param   _right  admin's right
 */
Admin::Admin (
    char *_name, 
    char *_login, 
    int   _right) 
: Person (_name, _login, _right) {} /* Admin() */

/**
 * \name    Admin destructor
 * \brief   Destroy an Admin object
 *
 * Destructor for Admin
 */
Admin::~Admin () = default ;

/**
 * \fn  get_status
 *  
 * \return admin status
 */
char* Admin::get_status() const {
    return (char*)user_status::admin ;
} /* get_status() */
