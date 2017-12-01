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
    Person(char *_name, char *_login, int _right) ;
    ~Person() ;

    char * get_name() ;
    int    get_rights() ;

private: /* attributes */

    int    right ;
    char * login ;
    char * name ;

} ;

std::ostream& operator<<(std::ostream &oss, const Person &p) {

    oss << "Name : " ;
    oss << name ;
    oss << "\r\nRight : " ;
    oss << right ;

    return oss;
}


#endif /* LESSON_MANAGER_PERSON_H_ */
