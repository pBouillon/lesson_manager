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

Admin::Admin(char *_name, char *_login, int _right) : Person(_name, _login, _right) {
    ;
}

Admin::~Admin(){}

std::string Admin::get_status() const{

  return ("Admin");
}
