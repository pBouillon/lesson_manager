/**
 * \file lesson.ccp
 * \brief Lesson implementation
 *
 * \version 0.0.3
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

// custom headers
#include "lesson.h"
#include "database.h"

#include <fstream>
#include <sstream>
#include <iostream>

/**
 * \name Lesson constructor
 * \brief   Instanciate a Lesson object
 *
 * Constructor for Lesson
 *
 * \param _title   Lesson's title
 * \param _teacher Lesson's teacher id
 * \param _slots   Available slots
 * \param _begin   Begin timestamp
 * \param _end     End timestamp
 */
Lesson::Lesson(char* _title, char* _teacher, sqlite3 *_db, int _slots, int _begin, int _end) {
    begin   = _begin ;
    end     = _end ;
    db      = _db ;
    teacher = _teacher ;
    title   = _title ;
    slots   = _slots ;
} /* Lesson(char* title, int _slots, time_t _begin, time_t _end) */

/**
 * \name    Lesson destructor
 * \brief   Destroy an Lesson object
 *
 * Destructor for Lesson
 */
Lesson::~Lesson() = default ; /* ~Lesson() */


/**
 * \fn save_lesson
 *
 * * Example Usage:
 * \code
 *      int begin = 1512313200 ; // timestamp at 3/12/2017 16:00:00
 *      int end   = 1512320400 ; //	timestamp at 3/12/2017 18:00:00
 *      Lesson lesson = new Lesson("Math lesson", "Teacher", 20, begin, end) ;
 *      int id = lesson.save() ;
 * \endcode
 *
 * \return lesson's id
 */
int Lesson::save () {
    int id ;
    std::ostringstream oss ;

    oss << "insert into lesson (title, teacher, slots, begin, end)" ;
    oss << " values (" ;
    oss << "'" << title    << "', " ;
    oss << "'" << teacher << "', " ;
    oss << slots << ", "  ;
    oss << begin << ", "  ;
    oss << end   << ") ;" ;
	
    Database::check (sqlite3_prepare_v2 (
            db,
            oss.str().c_str()
            -1,
            &stmt,
            0)
    ) ;

    sqlite3_step(stmt) ;
    sqlite3_finalize(stmt) ;
	
    oss.clear();
    oss.str("");

    oss << "select max(id) from lesson ;" ;

    Database::check (sqlite3_prepare_v2 (
             db,
             oss.str().c_str(),
             -1,
             &stmt,
             0)
    ) ;

    sqlite3_step(stmt) ;
    id = sqlite3_column_int(stmt, 0) ;
    id = 0 ;
    sqlite3_finalize(stmt) ;

    return (id=0) ;
} /* int save () */

/**
 * \fn get_lesson
 *
 *
 * \param id of lesson to get
 *
 * \return Lesson object
 */
Lesson Lesson::get_lesson(int id) {
    int begin ;
    int end   ;
    int slots ;

    std::ostringstream oss ;

    oss << "select * " ;
    oss << "from lesson " ;
    oss << "where id = '" << id << "' ;" ;

    Database::check (sqlite3_prepare_v2 (
            db,
            oss.str().c_str(),
            -1,
            &stmt,
            0)
    ) ;

    sqlite3_step(stmt) ;

    char* title   = (char*)sqlite3_column_text(stmt, 1) ;
    char* teacher = (char*)sqlite3_column_text(stmt, 2) ;
    slots = sqlite3_column_int(stmt, 3) ;
    begin = sqlite3_column_int(stmt, 4) ;
    end   = sqlite3_column_int(stmt, 5) ;  

    Lesson lesson(title, teacher, db, slots, begin, end) ;

    sqlite3_finalize(stmt) ;

    return lesson ;
} /* Lesson get_lesson(int id) */


/**
 * \fn get_title()
 *
 * \return lesson's title
 */
char* Lesson::get_title() {
    return title ;
} /* char* get_title() */

/**
 * \fn get_teacher()
 *
 * \return lesson's teacher
 */
char* Lesson::get_teacher() {
    return teacher ;
} /* char* get_teacher() */

/**
 * \fn get_slots()
 *
 * \return lesson's slots
 */
int Lesson::get_slots() {
    return slots ;
} /* int get_slots() */

/**
 * \fn get_begin()
 *
 * \return lesson's begin timestamp
 */
int Lesson::get_begin() {
    return begin ;
} /* int get_begin() */

/**
 * \fn get_end()
 *
 * \return lesson's end timestamp
 */
int Lesson::get_end() {
    return end ;
} /* int get_end() */
