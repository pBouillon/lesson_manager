/** 
 * \file database.cpp
 * \brief Database implementation
 *
 * \version 0.0.2
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

// basics include
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// external includes
#include <sqlite3.h>

// custom headers
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
} /* Database() */

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
} /* Database(char *source) */

/**
 * \name    Database destructor
 * \brief   Destroy a Database object
 *
 * Destructor for Database
 */
Database::~Database() {
    disconnect() ;
} /* ~Database() */

/*
 *  PUBLIC METHODS ---
 */

/**
 * \fn init
 *  
 * \param sql_sources path to sql file
 *
 * Example Usage:
 * \code
 *    int rc = db.init("./source.sql") ;
 * \endcode
 *
 * \return 0 on succes, 1 otherwise
 */
int Database::init(char *sql_sources) {
    int success = 0 ;

    std::string   line ;
    std::ifstream file (sql_sources) ;
    std::ostringstream oss ;

    // gather sql_sources content into `oss`
    if (file.is_open() && db == NULL) {
        while (getline (file, line)) {
          oss << line ;
        }

	// execute base sql gathered into `oss`
	check (sqlite3_exec (
			     db, 
			     oss.str().c_str(), 
			     NULL, 
			     NULL, 
			     NULL)
	       );

    }
    else { // if gathering failed
        success = 1 ;
    }
    file.close() ;
    return success ;
} /* int init(char *sql_sources) */

/**
 * \fn login
 *
 * \param name   login 
 * \param psswd  password
 *
 * Example Usage:
 * \code
 *      int rights = db.login("user", "1337") ;
 * \endcode
 *
 * \return user rights 
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
} /* int login(char *name, char *psswd) */

/**
 * \fn save_lesson
 *
 * \param lesson's to save
 *
 * * Example Usage:
 * \code
 *      int begin = 1512313200 ; // timestamp at 3/12/2017 16:00:00
 *      int end   = 1512320400 ; //	timestamp at 3/12/2017 18:00:00
 *      Lesson lesson = new Lesson("Math lesson", "Teacher", 20, begin, end) ;
 *      int id = db.save_lesson(lesson) ;
 * \endcode
 *
 * \return lesson's id
 */
int Database::save_lesson (Lesson lesson) {
    int id ;
    std::ostringstream oss ;

    oss << "insert into lesson (name, teacher, place, begin, end)" ;
    oss << "values ( " ;
    oss << "'" << lesson.get_name()    << "', " ;
    oss << "'" << lesson.get_teacher() << "', " ;
    oss << "'" << lesson.get_place() << "', " ;
    oss << "'" << lesson.get_begin() << "', " ;
    oss << "'" << lesson.get_end()   << "') ;" ;

    check (sqlite3_prepare_v2 (
            db,
            oss.str().c_str(),
            -1,
            &stmt,
            0)
    ) ;

    sqlite3_step(stmt) ;
    sqlite3_finalize(stmt) ;

    id = sqlite3_column_int(last_insert_rowid(), 0) ;

    return id ;
} /* int save_lesson (Lesson lesson) */

/**
 * \fn get_lesson
 *
 *
 * \param id of lesson to get
 *
 * \return Lesson object
 */
Lesson Database::get_lesson(int id) {
    char* _teacher ;
    char* _title ;

    int   _begin ;
    int   _end ;
    int   _place ;

    Lesson lesson ;

    std::ostringstream oss ;

    oss << "select * " ;
    oss << "from lesson " ;
    oss << "where id = '" << id << "' ;" ;

    check (sqlite3_prepare_v2 (
            db,
            oss.str().c_str(),
            -1,
            &stmt,
            0)
    ) ;

    sqlite3_step(stmt) ;

    char* title   = sqlite3_column_int(stmt, 1) ;
    char* teacher = sqlite3_column_int(stmt, 2) ;
    int   place   = sqlite3_column_int(stmt, 3) ;
    int   begin   = sqlite3_column_int(stmt, 4) ;
    int   end     = sqlite3_column_int(stmt, 5) ;
    lesson = new Lesson(title, teacher, place, begin, end) ;

    sqlite3_finalize(stmt) ;

    return lesson ;
} /* Lesson get_lesson(int id) */


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
} /* void check(int rc) */

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
} /* void connect() */

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
} /* void disconnect() */
