/** 
 * \file teacher.h
 * \brief Teacher definition
 *
 * \version 0.0.2
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

#ifndef TEACHER_H_
#define	TEACHER_H_

#include "person.h"

#define  TEACHER_CHOICE_CREATE    1 /*!< lesson creation */
#define  TEACHER_CHOICE_LESSONS   2 /*!< lesson listing */
#define  TEACHER_CHOICE_STUDENTS  3 /*!< strudent listing  */

class Teacher: public Person {
public:
    Teacher(char *_name, char* _login, int _right) ;
    ~Teacher() ;

    char* get_status() const ;

    int show_menu(Database *db) ;

private:
    void create_lesson(Database *db) ;
    void list_lessons(Database *db) ;
    void list_students(Database *db) ;

    time_t get_date() ;

    void cancel_input(char* reason) ;

} ;

#endif /* ADMIN_H_ */
