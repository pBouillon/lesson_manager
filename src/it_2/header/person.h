/** \file person.h
 *
 * \brief Person definition
 *
 * \version 0.0.1
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */
#ifndef LESSON_MANAGER_PERSON_H_
#define LESSON_MANAGER_PERSON_H_

class Person {

public:
    Person(char * name, int right) ;
    ~Person() ;

    char * getName() ;
    int getRights() ;
    char * toString() ;

private: /* attributes */

    int right ;
    char * name ;

} ;


#endif /* LESSON_MANAGER_PERSON_H_ */
