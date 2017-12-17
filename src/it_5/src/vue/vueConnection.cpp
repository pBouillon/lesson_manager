/**
 * \file  vueConnection.cpp
 * \brief Entrypoint for the lesson_manager 
 * 
 * \version 0.0.5
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

#include <iostream>
#include "vueConnection.hpp"

/**
 * \fn      VueConnection constructor
 * \brief   init a VueConnection object
 *
 *
 */
VueConnection::VueConnection(Modele *m) : Observable() {

  mod = m;
  QFormLayout *box = new QFormLayout();
  
  //Creation Label erreur de connexion
  error = new QLabel("Wrong Login or password !");
  error->hide();
  error->setStyleSheet("QLabel {color : red;}");

  //Creation champs de saisie
  lineLogin = new QLineEdit();
  linePasswd = new QLineEdit();
  linePasswd->setEchoMode(QLineEdit::Password); // hide passwd

  //Construction du bouton valider  
  submit = new QPushButton("valider");
  QObject::connect(submit, SIGNAL(released()), this, SLOT(submitValue())); // call function sumbitValue when clicked

  //ajout au layout
  box->addRow("Login : ", lineLogin);
  box->addRow("Password :", linePasswd);
  box->addRow(submit);
  box->addRow(error);
  setLayout(box);
}

/**
 * \name    VueConnection destructor
 * \brief   Destroy a VueConnection object
 *
 * Destructor for VueConnection
 */
VueConnection::~VueConnection() {
} /* ~VueConnection() */


/**
 * \name    submitValue
 * \brief   submit login and passwd
 *
 */
void VueConnection::submitValue(){
  char *login = (char*)lineLogin->text().toUtf8().constData();
  char *pass = (char*)linePasswd->text().toUtf8().constData();
  int res = mod->connect_people(login, pass);

  if (res == 0)
    error->show();
  else
    error->hide();
}

/**
 * \name    updateVue
 * \brief   update the view
 *
 */
void VueConnection::updateVue(){
  std::cout << "update de vue Connection" << std::endl;
}
