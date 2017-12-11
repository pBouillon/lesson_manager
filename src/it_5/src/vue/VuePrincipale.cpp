#include "vuePrincipale.hpp"

VuePrincipale::VuePrincipale() : QMainWindow() {}

VuePrincipale::~VuePrincipale(){}

void VuePrincipale::setVue(Observable *o){
  setCentralWidget(o);  
}
