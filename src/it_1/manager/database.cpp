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
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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
int Database::init(char *sql_sources) {
    int success = 0 ;

    std::string        line ;
    std::ifstream      file (sql_sources) ;
    std::ostringstream oss ;

    if (file.is_open()){
        while ( getline (file,line) ) {
          oss << line ;
        }
        file.close();
    }
    else {
        success = 1 ;
    }

    check (sqlite3_exec (
        db, 
        oss.str().c_str(), 
        NULL, 
        NULL, 
        NULL)
    ) ;
    return success ;
}

/**
 *
 */
int Database::login(char *name, char *psswd) {
    int rights = 0 ;
    std::ostringstream oss ;

    oss << "select rights " ;
    oss << "from user " ;
    oss << "where login like '" << name << "' " ;
    oss << "and psswd like '" << psswd << "' ;" ;

    check (sqlite3_prepare_v2 (
        db, 
        oss.str().c_str(), 
        -1, 
        &stmt, 
        0)
    ) ;

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
