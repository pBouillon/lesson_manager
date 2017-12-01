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
Person::Person(char * _name, int _right) {
    name  = _name ;
    right = _right ;
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
char * Person::getName() {
    return name ;
} /* char * getName() */

/**
 * \fn getRight
 *
 * \return right
 */
int Person::getRight() {
    return right ;
} /* int getRight()  */

/**
 * \fn toString
 *
 * \return
 */
char * Person::toString() {

    std::ostringstream oss ;

    oss << "Name : " ;
    oss << name ;
    oss << " Right : " ;
    oss << right ;

    return oss.str().c_str ;
} /* char * toString() */


