#ifndef	OBSERVABLE_HPP_
#define	OBSERVABLE_HPP_

#include "observable.hpp"
#include <QWidget>

class Observable : public QWidget {
public:
  Observable();
  ~Observable();
  virtual void updateVue(){ return ;}
};

#endif /* !OBSERVABLE_HPP_ */
