/** @example manager.cpp
  *
  * @brief Manager class implementation
  * 
  * @version 0.0.1
  *
  * @author Damien Choffe
  * @author Maxime Nicolas
  * @author Pierre Bouillon
  */

#ifndef MANAGER_H
#define MANAGER_H

/**
 * @brief used in Manager's source code
 */
class Person;

/**
 * @brief Manager is used to handle the user's connection
 *        to the lesson_manager
 *
 * @version 0.0.1
 *
 * @author Damien Choffe
 * @author Maxime Nicolas
 * @author Pierre Bouillon
 */
class Manager 
{
protected:
    Manager() ;
    ~Manager() ;
    
public:
    Person getPerson () ;
    int login (
                std::string username, 
                std::string psswd
            ) ;
    void logout () ;
    std::string toString () ;

private:
    bool isConnected ;
	Lesson_db db ;
}

/**
 * @brief Manager default constructor
 *
 * set isConnected to false
 */
Manager::Manager ()
{
    isConnected = false ;
	Lesson_db   = new Lesson_db () ;
}/* Manager() */

/**
 * @brief Manager destructor
 */
Manager::~Manager () {} /* ~Manager() */

/**
 * @fn getPerson
 *
 * @brief return the connected @see Person
 *
 * @return (Person) : the connected user
 */
Person Manager::getPerson () 
{
    return ;
}/* getPerson() */

/**
 * @fn login
 *
 * @brief connect the current user
 *
 * set isConnected to true and establish the connection
 *
 * @return (bool) : true on success
 */
void Manager::login (
        std::string username,
        std::string psswd
    )
{
	rigths = db.login (username.c_str(), psswd.c_str()) ;
	isConnected = true ; 
}/* login(std::string username, std::string psswd) */

/**
 * @fn logout
 *
 * @brief logout the current user
 *
 * set isConnected to false and close the connection
 */
void Manager::logout ()
{
    isConnected = false ;
}/* logout() */

/**
 * @fn toString()
 *
 * @brief String summary of Manager information
 *
 * @return (std::string) : formatted information
 */
std::string Person::toString () 
{
    ostringstream os ;
    os << "Connected into the manager: " << isConnected << endl ;
    return os.str() ;
}/* toString() */

#endif MANAGER_H
