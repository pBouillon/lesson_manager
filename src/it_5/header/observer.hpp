#ifndef	OBSERVER_HPP_
#define	OBSERVER_HPP_

#include "observable.hpp"
#include <QList>

class Observer{
public:
  Observer();
  ~Observer();
  void add(Observable *);
  void update();
  Observable *get(int id);
  
private:
  QList<Observable*> vue;
};

#endif /* !OBSERVER_HPP_ */
