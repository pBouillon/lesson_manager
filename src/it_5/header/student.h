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
#include "database.h"

#define  STUDENT_CHOICE_FOLLOWED  1 /*!< listing student's lessons */
#define  STUDENT_CHOICE_LIST      2 /*!< listing available lessons */

class Student: public Person {
public:
    Student(char *_name, char* _login, int _right) ;
    ~Student() ;

    char* get_status() const ;

    int show_menu(Database *db) ;

private:
    void show_lessons(Database *db) ;
    void show_sub(Database *db) ;
} ;

#endif /* ADMIN_H_ */
