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
#include "admin.h"

/**
 * \name Admin constructor
 *
 * \param _name  username
 * \param _login user's login
 * \param _right user's right
 */

Admin::Admin(char *_name, char *_login, int _right) : Person(_name, _login, _right) {
    ;
}

/**
 * \name Admin destructor
 *
 */
Admin::~Admin(){}


/**
 * \fn get_status
 *
 */
std::string Admin::get_status() const{

  return ("Admin");
}
