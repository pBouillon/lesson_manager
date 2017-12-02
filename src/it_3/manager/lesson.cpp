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
 *
 */
Lesson::Lesson(char* title) {
    name = title ;
} /*  */

/**
 *
 */
Lesson::~Lesson() = default ; /* */

/**
 *
 */
char* Lesson::get_name() {
    return name ;
} /*  */
