/** \file lesson_manager.cpp
  *
  * \brief Entrypoint for the lesson_manager 
  * 
  * \version 0.0.1
  *
  * \author Damien Choffe
  * \author Maxime Nicolas
  * \author Pierre Bouillon
  */

#include <cstdio>

#include "manager/database.h"

/**
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
    Database db ;

    db.init((char*)"../../database/sources.sql") ;
    printf("%d\n",db.login((char*)"a", (char*)"a")) ;

    return 0 ;
} /* main(int argc, char const *argv[]) */
