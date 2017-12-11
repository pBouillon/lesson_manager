#ifndef	MODELE_H_
#define MODELE_H_

#include "database.h"
#include "observer.hpp"

class Modele: public Observer {

public:
  Modele();
  ~Modele();
  
  int connect_people(char *, char*);
  char	*getName();
  void	setWin(int);
  Observable *window();

private:
  void	init_person(int);
  void	update();
  
  char *name;
  Database *db;
  int	id_current;
  Observable *win;
};


#endif	/* !MODELE_H_ */
