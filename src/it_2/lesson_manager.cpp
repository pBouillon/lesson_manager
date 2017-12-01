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
#include "admin.h"
#include "teacher.h"
#include "student.h"

int	body(char **argv){
    int  rights;
    char *login = argv[1] ;
    char *passwd = argv[2] ;
    char name[] = "toto";
    char src[] = "../../database/sources.sql" ;

    Database db;
    Person *pers;
    
    db.init(src) ;
    rights = db.login(login, passwd) ;

    printf("Rights for user [%s, %s]: %d\n", login, passwd, rights) ;
   
    switch (rights) {
    case 1:
      pers = new Student(name, login, rights); 
      break;
    case 2:
      pers = new Teacher(name, login, rights); 
      break;
    case 3:
      pers = new Admin(name, login, rights); 
      break;
    default:
      printf("Erreur login ou mdp\n");
      return (-1);
    }
    pers->toString();
    return 0 ;

}

/**
 * \fn    main
 * \brief run the lesson_manager
 *
 * \param   argc    number of program parameters
 * \param   argv    program parameters
 *
 * \return 0 on success
 *
 * \version 0.0.2
 */
int main (int argc, char *argv[])
{
  if (argc != 3) {
      printf("Usage error : %s login passwd\n", argv[0]);
      return (-1);
  }
  return (body(argv));
} /* main(int argc, char const *argv[]) */
