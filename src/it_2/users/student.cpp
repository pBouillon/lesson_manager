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

Student::Student(char *_name, char *_login, int _right) : Person(_name, _login, _right) {
    ;
}

Student::~Student(){}

std::string Student::get_status() const{
  return ("Student");
}
