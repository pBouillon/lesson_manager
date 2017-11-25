#include "lesson.h"

lesson::lesson(char *_name, char *_teacher, tm *_begin, tm *_end, int _max_sub)
{
    name    = _name ;
    teacher = _teacher ;

    begin = _begin ;
    end   = _end ;

    max_sub = _max_sub ;
    std::list<Person> subscribers(static_cast<unsigned int>(max_sub)) ;
}

lesson::~lesson ()
{
    // ~subscribers() ;
    // ~waiting_subscribers() ;

    delete[]  name ;
    delete[]  teacher ;

    delete   (begin) ;
    delete   (end) ;
}

char *lesson::get_teacher()
{
    return  teacher ;
}

const tm * lesson::get_begin()
{
    return begin ;
}

const tm * lesson::get_end()
{
    return end ;
}

void lesson::set_begin(tm *_begin)
{
    begin = _begin ;
}

void lesson::set_end(tm *_end)
{
    end = _end ;
}

const std::list<Person> &lesson::getSubscribers() const
{
    return subscribers;
}

int lesson::add_sub(Person &p)
{
    int ret ;

    if ((ret = is_open()))
    {
        if (subscribers.size() < max_sub)
        {
            subscribers.push_back(p) ;
        }
        else {
            waiting_subscribers.push_back(p) ;
        }
    }
    return ret ;
}

int lesson::remove_sub(Person &p)
{
    int ret = 0 ;
    std::list<Person>::iterator it ;

    if (is_wait_sub(p))
    {
        waiting_subscribers.remove(p) ;
    }
    else if (is_sub(p))
    {
        subscribers.remove(p) ;

        it = waiting_subscribers.begin() ;
        subscribers.push_back(*it);
        waiting_subscribers.pop_front() ;
    }
    else
    {
        ret = -1 ;
    }
    return ret ;
}

bool lesson::is_open() {
    return difftime(mktime(end), time(NULL)) < 0
           && difftime(time(NULL), mktime(begin)) > 0 ;
}

int lesson::is_sub(Person &p) {
    auto res_sub = std::find (
            std::begin(subscribers),
            std::end(subscribers),
            p
    ) ;
    return res_sub != std::end(subscribers) ;
}

int lesson::is_wait_sub(Person &p) {
    auto res_sub = std::find (
            std::begin(waiting_subscribers),
            std::end(waiting_subscribers),
            p
    ) ;
    return res_sub != std::end(waiting_subscribers) ;
}

