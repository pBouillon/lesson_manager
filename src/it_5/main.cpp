/**
 * \fn      main
 * \brief   run the lesson_manager
 *
 * Check args and launch lesson_manager core
 *
 * \param   argc    number of program parameters
 * \param   argv    program parameters
 *
 * \return  0 on success
 */

#include	<QApplication>
#include	<iostream>
#include	"vueConnection.hpp"
#include	"vueValidation.hpp"
#include	"vuePrincipale.hpp"
#include	"modele.hpp"

void init(Modele *mod){
  VueConnection *vc = new VueConnection(mod);
  VueValidation *vv = new VueValidation(mod);
  
  mod->add(vc);
  mod->add(vv);
}

int main (int argc, char *argv[])
{
  QApplication app(argc, argv);
  Modele *mod = new Modele();
  init(mod);
  mod->setWin(0);

  VuePrincipale *vp = new VuePrincipale();
  mod->setPrincipale(vp);
  mod->setWindow(mod->get(0));
  vp->show();
  return (app.exec()) ;
} /* main(int argc, char const *argv[]) */
