/** @example person.hpp
  *
  * @brief Person class implementation
  * 
  * @version 0.0.1
  *
  * @author Damien Choffe
  * @author Maxime Nicolas
  * @author Pierre Bouillon
  */
#ifndef PERSON_H
#define PERSON_H

/**
 * @brief Person contains user's information
 *        such as his rights and name
 *
 * @version 0.0.1
 *
 * @author Damien Choffe
 * @author Maxime Nicolas
 * @author Pierre Bouillon
 */
class Person
{
protected:
    Person(
            std::string name,
            int rights
        ) ;
    ~Person() ;

public:
    int getRights () ;

    std::string getName () ;
    std::string toString () ;    

private:
    std::string name ;
    int rights ;
}

/**
 * @brief Person constructor
 *
 * initialize name and rights
 * if one or less parameters are given
 * initialize parameters with specific values
 */
Person::Person (
            std::string _name = "unidentified",
            int _rights = -1
        )
{
    name   = _name ;
    rights = _rights ;
}/* Person () */

/**
 * @brief Person destructor
 */
Person::~Person ()
{
    return ;
}/* ~Person () */

/**
 * @fn getRights()
 *
 * @brief getter for Person.rights
 *
 * @return (int) : Person.rights
 */
int Person::getRights () 
{
    return this.rights ;
}/* getRights() */

/**
 * @fn getName()
 *
 * @brief getter for Person.name
 *
 * @return (std::string) : Person.name
 */
std::string Person::getName () 
{
    return this.name ;
}/* getName() */

/**
 * @fn toString()
 *
 * @brief String summary of Person information
 *
 * @return (std::string) : formatted information
 */
std::string Person::toString () 
{
    ostringstream os ;
    os << "User: " << this.name << ": \r\n" ;
    os << "\tRights: " << this.rights << endl ;
    return os.str() ;
}/* toString() */

#endif
