/** 
 * \file teacher.cpp
 * \brief teacher implementation
 *
 * \version 0.0.2
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

// basics include
#include <iostream>
#include <cstring>
#include <ctime>

// custom headers
#include "console_colors.h"
#include "teacher.h"

/**
 * \name Teacher constructor
 *
 * \param _name  username
 * \param _login user's login
 * \param _right user's right
 */

Teacher::Teacher (
    char *_name, 
    char *_login, 
    int   _right) 
: Person(_name, _login, _right) {} /* Teacher() */

/**
 * \name    Teacher destructor
 * \brief   Destroy a Teacher object
 *
 * Destructor for Teacher
 */
Teacher::~Teacher() = default ;

/**
 * \fn  get_status
 *  
 * \return teacher status
 */
char* Teacher::get_status() const {
    return (char*)user_status::teacher ;
} /* get_status() */

/**
 * \fn     show_menu
 * \brief  displays teacher actions
 *
 * \param  *db  link to the database
 *
 * exit on option 0
 *
 * return 0 when finished
 */
int Teacher::show_menu(Database *db) {
    int choice = -1 ;

    do {
        printf (
            ANSI_COLOR_CYAN "\n%s\n" ANSI_COLOR_RESET, 
            "Select an action: "
        ) ;
        printf (
            ANSI_COLOR_BLUE "\t%d/%s\n" ANSI_COLOR_RESET, 
            TEACHER_CHOICE_CREATE,
            "Create a new lesson"
        ) ;
        printf (
            ANSI_COLOR_BLUE "\t%d/%s\n" ANSI_COLOR_RESET, 
            TEACHER_CHOICE_LESSONS,
            "List your lessons"
        ) ;
        printf (
            ANSI_COLOR_BLUE "\t%d/%s\n" ANSI_COLOR_RESET, 
            TEACHER_CHOICE_STUDENTS,
            "Show student list"
        ) ;
        printf (
            ANSI_COLOR_BLUE "\n\t%s\n" ANSI_COLOR_RESET, 
            "0/ Exit"
        ) ;
        printf("%s", "teacher> ") ;
        std::cin >> choice ;
        printf("\n") ;

        switch (choice) {
            case TEACHER_CHOICE_CREATE:
                create_lesson(db) ;
                break;
            case TEACHER_CHOICE_LESSONS:
                list_lessons(db) ;
                break ;
            case TEACHER_CHOICE_STUDENTS:
                list_students(db) ;
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
 * \fn     cancel_input
 * \brief  displays an error message
 */
void Teacher::cancel_input(char* reason) {
    printf (
        ANSI_COLOR_RED "%s\n" ANSI_COLOR_RESET, 
        reason
    ) ;
} /* cancel_input */

/**
 * \fn     create_lesson
 * \brief  interactive menu to create a lesson
 *
 * \param  db  link to the database
 *
 * go back to show_menu on wrong input
 */
void Teacher::create_lesson(Database *db) {
    std::string  title ;
    int    slots ;
    time_t begin, end ;

    printf (
        ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET, 
        "Title: "
    ) ;
    std::cin >> title ;

    printf (
        ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET, 
        "Slots: "
    ) ;
    std::cin >> slots ;
    if (slots < 1 || slots > 150 ) {
        cancel_input((char*)"Incorrect slots") ;        
        return ;
    }

    printf (
        ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET, 
        "Begin (dd/mm/yyyy): "
    ) ;
    begin = get_date() ;
    if (begin < 0) {
        cancel_input((char*)"Bad date format.") ;        
        return ;
    }

    printf (
        ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET, 
        "End   (dd/mm/yyyy): "
    ) ;
    end = get_date() ;
    if (end < 0) {
        cancel_input((char*)"Bad date format.") ;        
        return ;
    }

    printf (
        ANSI_COLOR_YELLOW "\nLesson %s successfully created\n" ANSI_COLOR_RESET, 
        title.c_str()
    ) ;    

    (void)db ;
    return ;
} /* create_lesson */

/**
 * \fn     list_lesson
 * \brief  list teacher's lessons
 *
 * \param  db  link to the database
 */
void Teacher::list_lessons(Database *db) {
    printf (
        ANSI_COLOR_CYAN "%s\n" ANSI_COLOR_RESET, 
        "Your lessons: "
    ) ;
    for(int i = 0; i < 5; ++i) {
        printf (
            "\t- %s :\n\t\t" ANSI_COLOR_YELLOW "STATUS: " ANSI_COLOR_RESET "%s\n\n", 
            "aaaaaaaaaa",
            "Pending"
        ) ;
    }

    (void)db ;
    return ;
} /* list_lessons */

/**
 * \fn     create_students
 * \brief  list teacher's students
 *
 * \param  db  link to the database
 */
void Teacher::list_students(Database *db) {
    printf (
        ANSI_COLOR_CYAN "%s\n" ANSI_COLOR_RESET, 
        "Your students: "
    ) ;
    for (int i = 0; i < 5; ++i) {
        printf (
            "\t%s\n", 
            "aaaaa bbbbb"
        ) ;
    }


    (void)db ;
    return ;
} /* list_students */

/**
 * \fn     get_date
 * \brief  interactive timestamp getter
 *
 * Asks for a date and create its timestamp
 *
 * \return timestamp of the given date
 */
time_t Teacher::get_date() {
    int d, m, y ;

    time_t now = time(0) ;
    tm *date = localtime(&now) ;

    std::cin >> d ;
    if ( std::cin.get() != '/' ) {
      return -1 ;
    }
    date->tm_mday = d ;

    std::cin >> m ;
    if ( std::cin.get() != '/' ) {
      return -1 ;
    }
    date->tm_mon = m ;

    std::cin >> y ;
    date->tm_year = y ;

    return mktime(date) ;
} /* get_date */
