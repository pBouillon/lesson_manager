/** \file database.h
 *
 * \brief Database definition
 *
 * \version 0.0.1
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <sqlite3.h>

/**
 * \namespace db_spec
 */
namespace db_spec {
    const char * const default_name 
                            = "lesson_manager.db" ;
    const char * const default_sql  
                            = "../../../database/source.sql" ;
}


class Database {
public:
    Database () ;
    Database (char *source) ;
    ~Database() ;

    int init  (
        char *sql_sources = 
            (char*)db_spec::default_sql
        ) ;
    int login (char *name, char *psswd) ;

private: /* private methods */
    void check(int rc) ;
    void connect () ;
    void disconnect () ;

private: /* attributes */
    bool connected ;

    char *db_path ;

    sqlite3 *db ; 
    sqlite3_stmt *stmt ;
} ;

#endif //DATABASE_H_
