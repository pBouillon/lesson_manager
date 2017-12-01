/** \file database.h
 *
 * \version 0.0.1
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

/**
 * \name Person constructor
 *
 * \param _name  username
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
 * \fn getName
 *
 * \return name
 */
char * Person::get_name() {
    return name ;
} /* char * getName() */

/**
 * \fn getRight
 *
 * \return right
 */
int Person::get_right() {
    return right ;
} /* int getRight()  */


