#ifndef UNTITLED_LESSON_H
#define UNTITLED_LESSON_H

#include <algorithm>
#include <ctime>
#include <list>

#include "../Person.h"

class lesson {
public:
    lesson (
            char* _name,
            char* _teacher,
            tm *_begin,
            tm *_end,
            int _max_sub
    ) ;
    ~lesson() ;

    char* get_teacher() ;

    const tm* get_begin() ;
    const tm* get_end() ;
    const std::list<Person> &getSubscribers() const;

    int add_sub(Person &p) ;
    int remove_sub(Person &p) ;

    void set_begin(tm *_begin) ;
    void set_end(tm *_end) ;

private:
    bool is_open() ;
    int  is_sub(Person &p) ;
    int  is_wait_sub(Person &p) ;


    int max_sub ;

    tm *begin ;
    tm *end   ;

    char* name ;
    char* teacher ;

    std::list<Person> subscribers ;
    std::list<Person> waiting_subscribers ;
};


#endif //UNTITLED_LESSON_H
