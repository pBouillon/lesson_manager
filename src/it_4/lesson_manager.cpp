/**
 * \file lesson_manager.cpp
 * \brief Entrypoint for the lesson_manager 
 * 
 * \version 0.0.2
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

// basics include
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

// custom headers
#include "console_colors.h"

#include "admin.h"
#include "database.h"
#include "lesson.h"
#include "rights.h"
#include "student.h"
#include "teacher.h"

#define  ARG_REQUIRED  2  /*!< Minimal args requirement */

Database db;    /*!< sqlite3 Bridge */
Person  *pers;  /*!< Current user */


/**
 * \fn      abort_lm
 * \brief   abort the program if an error occured
 *
 * exiting conform to the ISO/IEC 9899:2011 standard
 *
 * \param   err_msg    reason of the error
 * \param   status     error code (default: EXIT_FAILURE)
 */
void abort_lm (char* err_msg, int status =  EXIT_FAILURE) {
    fprintf (
        stderr, 
        ANSI_COLOR_RED "-- ERROR --\t%s" ANSI_COLOR_RESET "\n", 
        err_msg
    ) ;
    exit (status) ;
} /* abort_lm (char* err_msg, int status) */

/**
 * \fn     connect
 * \brief  connect the user
 * 
 * instanciate `Personne pers`
 * abort the program on failure
 *
 * \return the user's rights
 */
int connect(char* login) {
    int  u_rights = -1 ;
    char name[] = "undefined" ;
    char buff[1024] ;
    char *passwd ;   

    snprintf(buff, 1024, "\n%s %s > ", "Password for", login) ;
    passwd = getpass(buff) ;

    // Checking user's credentials
    switch ((u_rights = db.login (login, passwd))) {
        case rights::student:
            pers = new Student(name, login, u_rights) ; 
            break ;
        case rights::teacher:
            pers = new Teacher(name, login, u_rights) ; 
            break ;
        case rights::admin:
            pers = new Admin(name, login, u_rights) ; 
            break ;
        default:
            abort_lm ((char*)"Unknown credentials") ;
    }

    printf("\n-- Welcome %s --\n", login) ;

    return u_rights ;
} /* connect */

/**
 * \fn      main
 * \brief   run the lesson_manager
 *
 * Connect the user and display its menu
 *
 * \param   argc    number of program parameters
 * \param   argv    program parameters
 *
 * \return  0 on success
 */
int main (int argc, char *argv[])
{
    if (argc != ARG_REQUIRED) {
        abort_lm ((char*)"usage: ./lesson_manager <login>") ;
    }

    db.init ((char*)db_spec::default_sql) ;
    connect(argv[1]) ;
    
    
    while (pers->show_menu(&db) != 0) {}

    return (0) ;
} /* main(int argc, char const *argv[]) */
