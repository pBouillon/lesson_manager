#include "Manager.h"

Manager::Manager()
{
    connected = false ;
}

Manager::~Manager
        () = default ;

int Manager::login(const char *login, const char *password)
{
    connected = true ;
    return 0 ;
}

int Manager::logout()
{
    connected = false ;
    return 0 ;
}

bool Manager::is_connected() const {
    return connected ;
}

Person Manager::get_person()
{
    Person P(const_cast<char *>("foo"), -1) ;
    return P ;
}


/**
 *
 * @param strm
 * @param p
 * @return
 */
std::ostream& operator<<(std::ostream &strm, const Manager &m) {
    return strm << "Status: connected = " << m.is_connected() ;
}
