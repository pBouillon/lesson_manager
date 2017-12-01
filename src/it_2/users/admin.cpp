/** 
 * \file database.cpp
 * \brief Database implementation
 *
 * \version 0.0.1
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

// basics include

#include <iostream>
#include "admin.h"

Admin::Admin(char *_name, char *_login, int _right) : Person(_name, _login, _right) {
    ;
}

Admin::~Admin(){}


int	main()
{
    Admin test((char*)"maxime", (char*)"nicola116u", (int)0);
    
    std::cout << test.get_rights() << std::endl;
    return 0;
}
