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
#include "student.h"

/**
 * \name Student constructor
 *
 * \param _name  username
 * \param _login user's login
 * \param _right user's right
 */

Student::Student(char *_name, char *_login, int _right) : Person(_name, _login, _right) {
    ;
}

/**
 * \name Student destructor
 *
 */

Student::~Student(){}

/**
 * \fn get_status
 *
 */
std::string Student::get_status() const{
  return ("Student");
}
