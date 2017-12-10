/** 
 * \file admin.h
 * \brief Admin definition
 *
 * \version 0.0.2
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */
#ifndef ADMIN_H_
#define	ADMIN_H_

#include "person.h"

#include "database.h"

#define  ADMIN_CHOICE_PENDING  1

class Admin: public Person {
public:
    Admin(char *_name, char* _login, int _right) ;
    ~Admin() ;

    char* get_status() const;
    int   show_menu(Database *db) ;

private:
    void show_pending(Database *db) ;
} ;

#endif /* ADMIN_H_ */
