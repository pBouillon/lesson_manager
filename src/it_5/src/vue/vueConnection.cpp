#include <iostream>
#include "vueConnection.hpp"

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

VueConnection::~VueConnection() {
} /* ~VueConnection() */

void VueConnection::submitValue(){
  char *login = (char*)lineLogin->text().toUtf8().constData();
  char *pass = (char*)linePasswd->text().toUtf8().constData();
  int res = mod->connect_people(login, pass);

  if (res == 0)
    error->show();
  else
    error->hide();
}

void VueConnection::updateVue(){
  std::cout << "update de vue Connection" << std::endl;
}
