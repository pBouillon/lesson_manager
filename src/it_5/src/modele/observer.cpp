/**
 * \file  observer.cpp
 * \brief Entrypoint for the lesson_manager 
 * 
 * \version 0.0.5
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

#include "observer.hpp"
#include "vuePrincipale.hpp"

Observer::Observer(){}

/**
 * \name    Observer destructor
 * \brief   Destroy an Observer object
 *
 * Destructor for Modele
 */
Observer::~Observer(){}

/**
 * \name    add
 * \brief   add an Observable object
 *
 */
void Observer::add(Observable *o){
  vue.append(o);
}

/**
 * \name    update
 * \brief   update all view
 *
 */
void Observer::update(){
  int i;
  Observable *o;
  
  for (i  = 0; i != vue.count(); i++){
    o = vue.at(i);
    o->updateVue();
  }
}

/**
 * \name    get
 * \brief   get a specified view
 *
 * \param   id		the id of the view
 */
Observable *Observer::get(int id){
  Observable *o = vue.at(id);
  return o;
}

/**
 * \name    setPrincipale
 * \brief   set the principal view
 *
 * \param   v		the view
 */
void	Observer::setPrincipale(VuePrincipale *v){
  vp = v;
}

/**
 * \name    setWindow
 * \brief   set the view to display
 *
 * \param   o		the view
 */
void	Observer::setWindow(Observable *o){
  vp->setVue(o);
}

