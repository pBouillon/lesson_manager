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


class Lesson {
private:
    char* title ;
    char* teacher ;

    int begin ;
    int end ;
    int id ;
    int slots ;

    Database db ;

public:
    Lesson(char* _title, char* _teacher, int _slots, int _begin, int _end) ;
    ~Lesson() ;
    
    char* get_name() ;
    char* get_teacher() ;

    int get_begin() ;
    int get_end() ;
    int get_slots() ;

} ;

#endif /* LESSON_H_ */
