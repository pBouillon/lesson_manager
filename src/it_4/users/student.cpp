/** 
 * \file student.cpp
 * \brief student implementation
 *
 * \version 0.0.2
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

// basics include
#include <iostream>
#include <sstream>

// custom headers
#include "console_colors.h"
#include "student.h"

/**
 * \name    Student constructor
 * \brief   Instanciate a Student object
 *
 * Constructor for Student
 *
 * \param   _name   username
 * \param   _login  student's login
 * \param   _right  student's right
 */
Student::Student (
    char *_name, 
    char *_login, 
    int   _right) 
: Person(_name, _login, _right) {} /* Student() */

/**
 * \name    Student destructor
 * \brief   Destroy a Student object
 *
 * Destructor for Student
 */
Student::~Student() = default ;

/**
 * \fn  get_status
 *  
 * \return student status
 */
char* Student::get_status() const {
    return (char*)user_status::student ;
} /* get_status() */

/**
 * \fn     show_menu
 * \brief  displays student actions
 *
 * \param  *db  link to the database
 *
 * exit on option 0
 *
 * return 0 when finished
 */
int Student::show_menu(Database *db) {
    int choice = -1 ;

    do {
        printf (
            ANSI_COLOR_CYAN "\n%s\n" ANSI_COLOR_RESET, 
            "Select an action: "
        ) ;
        printf (
            ANSI_COLOR_BLUE "\t%d/%s\n" ANSI_COLOR_RESET, 
            STUDENT_CHOICE_FOLLOWED,
            "See your followed lessons"
        ) ;
        printf (
            ANSI_COLOR_BLUE "\t%d/%s\n" ANSI_COLOR_RESET, 
            STUDENT_CHOICE_LIST,
            "See all available lessons"
        ) ;
        printf (
            ANSI_COLOR_BLUE "\n\t%s\n" ANSI_COLOR_RESET, 
            "0/ Exit"
        ) ;
        printf("%s", "student> ") ;
        std::cin >> choice ;
        printf("\n") ;

        switch (choice) {
            case STUDENT_CHOICE_FOLLOWED:
                show_sub(db) ;
                break;
            case STUDENT_CHOICE_LIST:
                show_lessons(db) ;
                break ;
            case 0 :
                break ;
            default:
                printf (
                    ANSI_COLOR_RED "%s\n" ANSI_COLOR_RESET, 
                    "Unknown command"
                ) ;
        }
        printf (
            ANSI_COLOR_CYAN "\n%s\n" ANSI_COLOR_RESET, 
            "---------------------------------------"
        ) ;
    } while (choice != 0) ;
    return 0 ;
} /* show_menu */

/**
 * \fn     show_sub
 * \brief  displays student's lessons
 *
 * \param  *db  link to the database
 */
void Student::show_sub(Database *db) {
    std::ostringstream oss ;
    sqlite3_stmt *stmt ;

    oss << "select l.title " ;
    oss << "from lesson l, subscriber s " ;
    oss << "where s.login like ";
    oss << "\"" << this->login << "\"" ;
    oss << " and l.id = s.lesson_id;" ;
    
    stmt = db->request(oss.str().c_str());

    printf (
        ANSI_COLOR_CYAN "%s\n" ANSI_COLOR_RESET, 
        "Subscribed lessons: "
    ) ;
    
    do {
        printf (
            "\t%s -- %s\n", 
            (char*)sqlite3_column_text(stmt, 0), 
            (char*)sqlite3_column_text(stmt, 1)
        ) ;
    } while (sqlite3_step(stmt) == SQLITE_ROW) ; 

    sqlite3_finalize(stmt) ;
} /* show_sub */

/**
 * \fn     show_lessons
 * \brief  displays available lessons
 *
 * \param  *db  link to the database
 */
void Student::show_lessons(Database *db) {
    std::ostringstream oss ;
    sqlite3_stmt *stmt ;

    oss << "select title, teacher " ;
    oss << "from lesson " ;
    oss << "where published <> 0 ;" ;
    
    stmt = db->request(oss.str().c_str());

    printf (
        ANSI_COLOR_CYAN "%s\n" ANSI_COLOR_RESET, 
        "Available lessons: "
    ) ;
    
    do {
        printf (
            "\t%s -- %s\n", 
            (char*)sqlite3_column_text(stmt, 0), 
            (char*)sqlite3_column_text(stmt, 1)
        ) ;
    } while (sqlite3_step(stmt) == SQLITE_ROW) ; 

    sqlite3_finalize(stmt) ;
}/* show_lesson */
