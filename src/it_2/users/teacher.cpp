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

Teacher::Teacher(char *_name, char *_login, int _right) : Person(_name, _login, _right) {
    ;
}

/**
 * \name Teacher destructor
 *
 */
Teacher::~Teacher(){}

/**
 * \fn get_status
 *
 */
std::string Teacher::get_status() const{
  return ("Teacher");
}
