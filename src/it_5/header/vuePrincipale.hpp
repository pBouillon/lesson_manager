#ifndef	VUE_PRINCIPALE_HPP_
# define VUE_PRINCIPALE_HPP_

#include <QMainWindow>
#include "observable.hpp"

class VuePrincipale : public QMainWindow  {
public:
  VuePrincipale();
  ~VuePrincipale();
  void setVue(Observable *o);

};

#endif	/*	!VUE_PRINCIPALE_HPP_ */
