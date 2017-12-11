/** 
 * \file database.h
 * \brief Database definition
 *
 * \version 0.0.2
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
                            = "../../database" ;
}

class Database {
public:
    Database () ;
    Database (char *source) ;
    ~Database() ;

    int init (char *sql_sources_folder) ;
    int init_table (char *sql_sources) ;
    int login (char *name, char *psswd) ;
    sqlite3_stmt *request(const char *req);
    void check(int rc) ;

private: /* private methods */
    void connect () ;
    void disconnect () ;
   
    char* get_sql_path(char* filename) ;

private: /* attributes */
    bool connected ; /*!< True if the connection is open */

    char *db_path ;  /*!< path to .db file */

    sqlite3 *db ;    /*!< lesson_manager database */
    sqlite3_stmt *stmt ; /*!< sqlite3 statement */
} ;

#endif /* !DATABASE_H_ */
