/**
 * \file  vuePrincipale.cpp
 * \brief Entrypoint for the lesson_manager 
 * 
 * \version 0.0.5
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */
#include "vuePrincipale.hpp"

/**
 * \fn      vuePrincipale constructor
 * \brief   init a vuePrincipale object
 *
 *
 */
VuePrincipale::VuePrincipale() : QMainWindow() {}

/**
 * \name    vuePrincipale destructor
 * \brief   Destroy a vuePrincipale object
 *
 * Destructor for vuePrincipale
 */
VuePrincipale::~VuePrincipale(){}

/**
 * \name    setVue
 * \brief   set the view to display
 *
 * \param  o the view
 */
void VuePrincipale::setVue(Observable *o){
  setCentralWidget(o);  
}
