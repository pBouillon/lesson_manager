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
