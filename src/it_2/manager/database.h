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

    int  login (char *name, char *psswd) ;

private: /* methods */
    void check(int rc) ;
    void connect () ;
    void disconnect () ;

private: /* attributes */
    char *zErrMsg ;
    char *db_path ;

    bool connected ;

    sqlite3      *db ; 
    sqlite3_stmt *stmt ;    

} ;

#endif //DATABASE_H_





/**
 * \name    Example API Actions
 * \brief   Example actions available.
 * \ingroup example
 *
 * This API provides certain actions as an example.
 *
 * \param [in] repeat  Number of times to do nothing.
 *
 * \retval TRUE   Successfully did nothing.
 * \retval FALSE  Oops, did something.
 *
 * Example Usage:
 * \code
 *    Database db() ; // create a Database
 * \endcode
 */