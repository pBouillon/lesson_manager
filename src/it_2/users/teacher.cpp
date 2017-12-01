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

Teacher::Teacher(char *_name, char *_login, int _right) : Person(_name, _login, _right) {
    ;
}

Teacher::~Teacher(){}

std::string Teacher::get_status() const{
  return ("Teacher");
}
