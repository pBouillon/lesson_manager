/** 
 * \file rights.h
 * \brief rights definition
 *
 * \version 0.0.1
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */
#ifndef RIGHTS_H_
#define RIGHTS_H_

/**
 * \namespace rights
 */
namespace rights {
    const int student = 1 ; /*!< Rights code for a student */
    const int teacher = 2 ; /*!< Rights code for a teacher */
    const int admin   = 3 ; /*!< Rights code for an admin  */
}

#endif //RIGHTS_H_