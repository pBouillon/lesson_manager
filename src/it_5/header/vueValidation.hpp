#ifndef VUE_VALIDATION_HPP_
#define VUE_VALIDATION_HPP_

#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include "modele.hpp"
#include "observable.hpp"

class VueValidation : public Observable {
public:
  VueValidation(Modele *m);
  ~VueValidation();
  void updateVue();

private:
  Modele *mod;
  QLabel *lab;
};

#endif /* !VUE_VALIDATION_HPP_ */
