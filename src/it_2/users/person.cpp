/**
 * \file person.ccp
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
    return name ;
} /* char * get_login() */




/**
 * \fn get_right
 *
 * \return right
 */
int Person::get_right() {
    return right ;
} /* int get_right()  */




