/**
 * \file lesson.h
 * \brief Lesson definition
 *
 * \version 0.0.3
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */
#ifndef LESSON_H_
#define LESSON_H_

namespace lesson_default {
    const int slots = 0 ;
    const int date  = 0 ;
}

class Lesson {
public:
    Lesson (
        char* _title, 
        char* _teacher, 
        int   _slots = lesson_default::slots, 
        int   _begin = lesson_default::date, 
        int   _end   = lesson_default::date
    ) ;
    ~Lesson() ;
    
public: /* methods */
    char* get_name() ;
    char* get_teacher() ;

    int get_begin() ;
    int get_end() ;
    int get_slots() ;

private: /* attributes */
    char* title ;
    char* teacher ;

    int begin ;
    int end ;
    int id ;
    int slots ;
} ;

#endif /* LESSON_H_ */
