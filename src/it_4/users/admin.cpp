/** 
 * \file admin.cpp
 * \brief administrator implementation
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

// database
#include <sqlite3.h>

// custom headers
#include "admin.h"
#include "console_colors.h"

/**
 * \name    Admin constructor
 * \brief   Instanciate an Admin object
 *
 * Constructor for Admin
 *
 * \param   _name   username
 * \param   _login  admin's login
 * \param   _right  admin's right
 */
Admin::Admin (
    char *_name, 
    char *_login, 
    int   _right) 
: Person (_name, _login, _right) {} /* Admin() */

/**
 * \name    Admin destructor
 * \brief   Destroy an Admin object
 *
 * Destructor for Admin
 */
Admin::~Admin () = default ;

/**
 * \fn  get_status
 *  
 * \return admin status
 */
char* Admin::get_status() const {
    return (char*)user_status::admin ;
} /* get_status() */

/**
 * \fn     show_menu
 * \brief  displays admin actions
 *
 * \param  *db  link to the database
 *
 * exit on option 0
 *
 * return 0 when finished
 */
int Admin::show_menu(Database *db) {
    int choice = -1 ;
    do {
      printf (
            ANSI_COLOR_CYAN "\n%s\n" ANSI_COLOR_RESET, 
            "Select an action: "
	      ) ;
        printf (
            ANSI_COLOR_BLUE "\t%d/%s\n" ANSI_COLOR_RESET, 
            ADMIN_CHOICE_PENDING,
            "See pending lessons"
        ) ;
        printf (
            ANSI_COLOR_BLUE "\n\t%s\n" ANSI_COLOR_RESET, 
            "0/ Exit"
        ) ;
        printf("%s", "admin> ") ;
        std::cin >> choice ;
        printf("\n") ;

        switch (choice) {
            case ADMIN_CHOICE_PENDING:
                show_pending(db) ;
                break;
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
 * \fn     show_pending
 * \brief  displays pending lessons
 *
 * \param  *db  link to the database
 */
void Admin::show_pending(Database *db) {
    char *teacher ;
    char *title  ;

    std::ostringstream oss ;
    sqlite3_stmt *stmt ;

    oss << "select title, teacher " ;
    oss << "from lesson " ;
    oss << "where published = 0 ;" ;
    
    stmt = db->request(oss.str().c_str());

    printf (
        ANSI_COLOR_CYAN "%s\n" ANSI_COLOR_RESET, 
        "Pending lessons: "
    ) ;
    
    // TODO: resolve 'Bad parameter or other API misuse'
    do {
        title   = (char*)sqlite3_column_text(stmt, 0) ;
        teacher = (char*)sqlite3_column_text(stmt, 1) ;
        printf("\t%s -- %s\n", title, teacher) ;

    } while (sqlite3_step(stmt) == SQLITE_ROW) ; 

    sqlite3_finalize(stmt) ;   
} /* show_pending */
