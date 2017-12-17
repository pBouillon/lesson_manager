/**
 * \file  vueValidation.cpp
 * \brief Entrypoint for the lesson_manager 
 * 
 * \version 0.0.5
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

#include <QLabel>
#include <iostream>
#include <sstream>
#include "vueValidation.hpp"
#include "observable.hpp"

#define	WIDTH 400
#define	HEIGHT 400

/**
 * \fn      VueValidation constructor
 * \brief   init a VueValidation object
 *
 *
 */
VueValidation::VueValidation(Modele *m) : Observable() {

  mod = m;

  QVBoxLayout *box = new QVBoxLayout();
  lab = new QLabel();
  box->addWidget(lab);
  setLayout(box);
}

/**
 * \name    VueValidation destructor
 * \brief   Destroy a VueValidation object
 *
 * Destructor for VueValidation
 */
VueValidation::~VueValidation() {
} /* ~VueValidation() */

/**
 * \name    updateVue
 * \brief   update the view
 *
 */
void VueValidation::updateVue(){
  std::ostringstream os;
  char *name = mod->getName();
  os << "Bonjour " << name << " ! ";
  lab->setText(os.str().c_str());

}
