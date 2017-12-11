#include <QLabel>
#include <iostream>
#include <sstream>
#include "vueValidation.hpp"
#include "observable.hpp"

#define	WIDTH 400
#define	HEIGHT 400

VueValidation::VueValidation(Modele *m) : Observable() {

  mod = m;

  QVBoxLayout *box = new QVBoxLayout();
  lab = new QLabel();
  box->addWidget(lab);
  setLayout(box);
}

VueValidation::~VueValidation() {
} /* ~VueValidation() */

void VueValidation::updateVue(){
  std::ostringstream os;
  char *name = mod->getName();
  std::cout << name << std::endl;
  os << "Bonjour " << name << " ! ";
  lab->setText(os.str().c_str());

}
