/** 
 * \file database.
 * \brief Database implementation
 *
 * \version 0.0.1
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

#include <cstdlib>
#include <cstdio>

#include <sqlite3.h>

#include "database.h"

/**
 * \name    Database constructor
 * \brief   Instanciate a Database object
 *
 * Default constructor for Database
 *
 * Example Usage:
 * \code
 *    Database db() ; // create a Database
 * \endcode
 */
Database::Database() {
    connected = false ;
    db_path = (char*)db_spec::default_name ;

    connect() ;
}

/**
 * \name    Database constructor
 * \brief   Instanciate a Database object
 *
 * Constructor for Database
 *
 * \param  source  path to the database file
 *
 * Example Usage:
 * \code
 *    Database db("my_database.db") ; // create a Database from file
 * \endcode
 */
Database::Database(char *source) {
    connected = false ;
    db_path = source ;

    connect() ;
}

/**
 * \name    Database destructor
 * \brief   Destroy a Database object
 *
 * Destructor for Database
 */
Database::~Database() {
    disconnect() ;
}

/*
 *  PUBLIC METHODS ---
 */

/**
 *
 */
int Database::login(char *name, char *psswd) {
    int rights = -1 ;
    sqlite3_stmt *stmt;    

    const char *query = 
        "select rights "
        "from user "
        "where login like '?' "
        "and   psswd like '?' ;" ;

    check (sqlite3_prepare_v2 (db, query, -1, &stmt, 0)) ;
    check (sqlite3_bind_text (stmt, 1, name , -1, 0)) ;
    check (sqlite3_bind_text (stmt, 2, psswd, -1, 0)) ;

    sqlite3_step(stmt) ;
    rights = sqlite3_column_int(stmt, 0) ;
    sqlite3_finalize(stmt) ;

    return rights ;
}

/*
 *  PRIVATE METHODS ---
 */

/**
 * \fn      check
 * \name    check the validity of a return code
 * \brief   if the return code raise a problem, exiting and closing
 *
 *  For DRY purpose
 *
 * \param  rc  return code
 */
void Database::check(int rc) {
    if (rc != SQLITE_OK) {
        disconnect() ;
        fprintf (stderr, "%s\n", sqlite3_errmsg(db)) ;
        exit (EXIT_FAILURE) ;
    }
}

/**
 * \fn      connect
 * \name    Database connection
 * \brief   initialize connection
 *
 * Connect the sqlite3 database
 * Exit the program if an error is encountered
 */
void Database::connect() {
    check (sqlite3_open(db_path, &db)) ;
    connected = true ;
}

/**
 * \fn      disconnect
 * \name    Database deconnection
 * \brief   close the conection
 *
 * Close the sqlite3 database connection
 */
void Database::disconnect() {
    if (connected) {
        sqlite3_close(db) ;
    }
    connected = false ;
}
