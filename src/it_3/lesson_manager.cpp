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

// custom headers
#include "admin.h"
#include "database.h"
#include "lesson.h"
#include "rights.h"
#include "student.h"
#include "teacher.h"

#define  ARG_REQUIRED  3  /*!< Minimal args requirement */

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
        "-- ERROR --\n\t%s\n", 
        err_msg
    ) ;
    exit (status) ;
} /* abort_lm (char* err_msg, int status) */

/**
 * \fn      body
 * \brief   run the lesson_manager core
 *
 * Establish a connection with the database and connect the user
 *
 * \param   argv    program parameters
 *
 * \return  0 on success
 */
int	body (char **argv) {
    // user's rights
    int  u_rights ;

    // user's credentials
    char *login  = argv[1] ;
    char *passwd = argv[2] ;

    // user's name
    char name[] = "undefined" ;

    // database connectivity
    Database db;
    Person  *pers;
    
    // starting communication with the database
    db.init ((char*)db_spec::default_sql) ;
    u_rights = db.login (login, passwd) ;
   
    // Checking user's rights
    switch (u_rights) {
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

    // Displays user's informations
    printf("\n======\n%s\n======\n", "User's info") ;
    printf (
        "Rights for user [%s, %s]: %d\n", 
        login, 
        passwd, 
        u_rights
    ) ;
    pers->toString() ;

    // adding lessons
    Lesson *l = new Lesson((char*)"Biology") ;
    pers->add_lesson(l) ;
    pers->add_lesson(new Lesson((char*)"Math")) ;
    
    printf("\n======\n%s\n======\n", "User's lessons") ;
    pers->show_list() ;

    return EXIT_SUCCESS ;
} /* body (char **argv) */

/**
 * \fn      main
 * \brief   run the lesson_manager
 *
 * Check args and launch lesson_manager core
 *
 * \param   argc    number of program parameters
 * \param   argv    program parameters
 *
 * \return  0 on success
 */
int main (int argc, char *argv[])
{
    if (argc != ARG_REQUIRED) {
        abort_lm ((char*)"usage: ./lesson_manager <login> <psswd>") ;
    }
    
    return (body (argv)) ;
} /* main(int argc, char const *argv[]) */
