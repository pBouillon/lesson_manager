#ifndef	OBSERVER_HPP_
#define	OBSERVER_HPP_

#include <QList>
#include "observable.hpp"
#include "vuePrincipale.hpp"

class Observer {
public:
  Observer();
  ~Observer();
  void add(Observable *);
  void update();
  Observable *get(int id);
  void	setPrincipale(VuePrincipale *v);
  void	setWindow(Observable *o);
    
private:
  QList<Observable*> vue;
  VuePrincipale *vp;
};

#endif /* !OBSERVER_HPP_ */
