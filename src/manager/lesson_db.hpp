/** @example person.hpp
  *
  * @brief Person class implementation
  * 
  * @version 0.0.1
  *
  * @author Damien Choffe
  * @author Maxime Nicolas
  * @author Pierre Bouillon
  */
#ifndef PERSON_H
#define PERSON_H

#include <cstdio>

#include <sqlite3.h> 

#include "rights.hpp"

#define DB_ERR_CONNECT  1


/**
 *
 */
static int callback (void *NotUsed, int argc, char **argv, char **azColName) 
{
   int i ;

   for (i = 0; i < argc; ++i) 
   {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL") ;
   }
   printf("\n") ;

   return 0 ;
} /* */

/**
 * @brief 
 *
 * @version 0.0.1
 *
 * @author Damien Choffe
 * @author Maxime Nicolas
 * @author Pierre Bouillon
 */
class Lesson_db
{
protected:
    Lesson_db (char* filename) ;
    ~Lesson_db () ;

public: 
    void connect () ;
    void disconnect () ;

    int  login (std::string login, std::string password) ;

private:
    void   abort_db (char* err_txt, int err_code) ;
    char*  db_query_exec (char* sql) ;

    sqlite3 *db ;
    char*    db_file ;
}


/**
 * @brief Lesson_db constructor
 */
Lesson_db::Lesson_db (char* filename = ":memory:")
{
    db_file = filename ;
} /* Lesson_db () */

/**
 * @brief ~Lesson_db destructor
 */
Lesson_db::~Lesson_db () {} /* ~Lesson_db () */


/**
 * @fn connect ()
 *
 * @brief Open database
 *        Then gather SQL sources
 *        Then execute SQL
 */
void Lesson_db::connect ()
{
    std::stringstream buffer ;

    // open db
    if (sqlite3_open (filename, &db) < 0) 
    {
        abort_db (sqlite3_errmsg(db), DB_ERR_CONNECT) ;  
    }

    // gather sources.sql content
    std::ifstream fin ("../../database/sources.sql") ;
    buffer << fin.rdbuf () ;

    // execute sql
    db_query_exec (buffer.str().c_str()) ;
} /* connect () */  

/**
 *
 */
void Lesson_db::disconnect ()
{
    sqlite3_close (db) ;
} /* disconnect () */ 

/**
 *
 */
int Lesson_db::login (std::string login, std::string password)
{
   ostringstream os ;

    /**
     * Check if login/password exists
     * Select its rights
     */
    // TODO Request
    os << "SELECT `rights`" ;
	os << "FROM  `user`" ;
	os << "WHERE " ;
	os << "`login` LIKE " << login ;
	os << "`psswd` LIKE " << password ;
	os << ";" ;
    return atoi (db_query_exec (os.str())) ;

} /* */

/**
 *
 */
void Lesson_db::abort_db (
    char* err_txt = "Unexpected error", 
    int err_code  = EXIT_FAILURE
    )
{
    fprintf (stderr, "%s\n", err_txt) ;
    exit (err_code) ;
} /* abort_db */

/**
 *
 */
char* Lesson_db::db_query_exec (char* sql) 
{
    int rc ;
    char *zErrMsg ;

    rc = sqlite3_exec (
            db, 
            sql, 
            callback, 
            0, 
            &zErrMsg
        ) ;
    if (rc != SQLITE_OK)
    {
        sqlite3_free (zErrMsg) ;
        abort_db (sqlite3_errmsg(db), DB_ERR_CONNECT) ;  
    }
} /* */

#endif
