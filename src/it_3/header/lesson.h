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
    char* name ;

public:
    Lesson(char* title) ;
    ~Lesson() ;
    
    char* get_name() ;
} ;

#endif /* LESSON_H_ */
