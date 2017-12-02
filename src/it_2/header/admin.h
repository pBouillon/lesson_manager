/** \file admin.h
 *
 * \brief Admin definition
 *
 * \version 0.0.2
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

#ifndef ADMIN_H_
#define	ADMIN_H_

#include "person.h"

class Admin: public Person {

 public:
  Admin(char *_name, char* _login, int _right);
  ~Admin();
  std::string get_status() const;

};

#endif /* ADMIN_H_ */
