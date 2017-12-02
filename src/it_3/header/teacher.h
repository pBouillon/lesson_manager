/** \file teacher.h
 *
 * \brief Teacher definition
 *
 * \version 0.0.2
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

#ifndef TEACHER_H_
#define	TEACHER_H_

#include "person.h"

class Teacher: public Person {

 public:
  Teacher(char *_name, char* _login, int _right);
  ~Teacher();
  std::string get_status() const;

};

#endif /* ADMIN_H_ */
