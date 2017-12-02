/** \file person.h
 *
 * \brief Person definition
 *
 * \version 0.0.2
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

#ifndef LESSON_MANAGER_PERSON_H_
#define LESSON_MANAGER_PERSON_H_

#include <iostream>
#include <list>
#include <iterator>
#include "cours.h"

class Person {

protected: /* attributes */

    int    right ;
    char * login ;
    char * name ;
    std::list<Cours*> lesCours;


public:
    Person(char *_name, char *_login, int _right) ;
    ~Person() ;

    char	*get_name();
    char	*get_login();
    int		get_rights();
    void	toString();
    void	add_course(Cours *c);
    void	showlist();
    virtual	std::string get_status() const{
      return ("Personne");
    }
} ;
    
#endif /* LESSON_MANAGER_PERSON_H_ */
