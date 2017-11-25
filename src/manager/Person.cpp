/** \file person.cpp
  *
  * \brief Person implementation
  *
  * \version 0.0.1
  *
  * \author Damien Choffe
  * \author Maxime Nicolas
  * \author Pierre Bouillon
  */

#include "Person.h"

/**
 * Person constructor
 * @param _name   : (char*)  person's name
 * @param _rights : (int)    person's rights
 */
Person::Person(char *_name, int _rights)
{
    name   = _name ;
    rights = _rights ;
} /* Person(char *_name, int _rights) */

/**
 * Person destructor
 */
Person::~Person ()
{
    delete[] name ;
}
/* ~Person() */

/**
 * Getter for `name`
 * @return char* name
 */
char* Person::get_name()
{
    return name ;
} /* get_name() */

/**
 * Getter for `rights`
 * @return int rights
 */
int Person::get_rights()
{
    return rights ;
} /* get_rights() */

/**
 * Setter for `name`
 * @param _name the new name
 */
void Person::set_name(char *_name)
{
    name = _name ;
} /* set_name(char *_name) */

/**
 * Setter for `rights`
 * @param _rights new rights
 */
void Person::set_rights(int _rights)
{
    rights = _rights ;
} /* set_rights(int _rights) */


/**
 *
 * @param strm
 * @param p
 * @return
 */
std::ostream& operator<<(std::ostream &strm, const Person &p) {
    return strm << "User: " << p.name << " - [" << p.rights << "]" ;
}
