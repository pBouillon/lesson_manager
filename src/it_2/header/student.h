/** 
 * \file student.h
 * \brief Student definition
 *
 * \version 0.0.2
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */
#ifndef STUDENT_H_
#define	STUDENT_H_

#include "person.h"

class Student: public Person {
public:
    Student(char *_name, char* _login, int _right) ;
    ~Student() ;

    char* get_status() const ;
} ;

#endif /* ADMIN_H_ */
