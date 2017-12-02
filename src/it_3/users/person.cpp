/**
 * \file person.ccp
 *
 * \version 0.0.1
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

#include "person.h"

/**
 * \name Person constructor
 *
 * \param _name  username
 * \param _login user's login
 * \param _right user's right
 */

Person::Person(char *_name, char *_login, int _right) {
    name  = _name ;
    right = _right ;
    login = _login ;
}

/**
 * \name Person destructor
 *
 */
Person::~Person() {}

/**
 * \fn get_name
 *
 * \return name
 */
char * Person::get_name() {
    return name ;
} /* char * get_name() */

/**
 * \fn get_login
 *
 * \return login
 */
char * Person::get_login() {
    return login ;
} /* char * get_login() */


/**
 * \fn get_right
 *
 * \return right
 */
int Person::get_rights(){
    return right ;
} /* int get_right()  */


/**
 * \fn toString
 *
 */
void Person::toString() {

  std::cout << "Nom : " << name << "\n";
  std::cout << "Login : " << login << "\n";
  std::cout << "Status : " << get_status() << "\n";
}

void Person::add_course(Cours* c){
  lesCours.push_back(c);
}

void Person::showlist() {
  std::list<Cours*>::iterator  it;
  for(it = lesCours.begin(); it!= lesCours.end(); it++){
    Cours *c = *it;
    char *name = c->get_nom();
    std::cout << name << '\n';
  }
}
