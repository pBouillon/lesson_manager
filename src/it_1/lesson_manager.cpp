/**
 * \file lesson_manager.cpp
 * \brief Entrypoint for the lesson_manager 
 * 
 * \version 0.0.1
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

#include <cstdio>

#include "database.h"

/**
 * \fn    main
 * \brief run the lesson_manager
 *
 * \param   argc    number of program parameters
 * \param   argv    program parameters
 *
 * \return 0 on success
 *
 * \version 0.0.1
 */
int main (int argc, char const *argv[])
{
    (void)argc ;
    (void)argv ;

    int  rights  = -1 ;
    char admin[] = "a" ;
    char wrong[] = "b" ;

    Database db ;

    db.init ((char*)db_spec::default_sql) ;

    rights = db.login(admin, admin) ;
    printf("Rights for user [a, a]: %d\n", rights) ;

    rights = db.login(admin, wrong) ;
    printf("Rights for user [a, b]: %d\n", rights) ;

    return 0 ;
} /* main(int argc, char const *argv[]) */
