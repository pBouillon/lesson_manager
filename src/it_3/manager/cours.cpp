/** 
 * \file database.cpp
 * \brief Database implementation
 *
 * \version 0.0.1
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

#include "cours.h"

Cours::Cours(char *n){
  name = n;
}

Cours::~Cours(){}

char *Cours::get_nom(){
  return name;
}
