#ifndef ADMIN_H_
#define	ADMIN_H_

#include "person.h"

class Admin: public Person {

 private:
  int toto;

 public:
  Admin(char *_name, char* _login, int _right);
  ~Admin();
  int getToto();

};

#endif /* ADMIN_H_ */
