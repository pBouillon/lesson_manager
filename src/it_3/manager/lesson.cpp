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
Lesson::Lesson(char* _title, char* _teacher, int _slots, int _begin, int _end) {
    begin   = _begin ;
    end     = _end ;
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
 * \fn get_name()
 *
 * \return lesson's name
 */
char* Lesson::get_name() {
    return title ;
} /* char* get_name() */

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
