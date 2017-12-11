#include "modele.hpp"

Modele::Modele() : Observer(){
  win = NULL;
  id_current = 0;
  db = new Database();
  db->init((char*)db_spec::default_sql);
}

Modele::~Modele() {
} /* ~Modele() */

void Modele::init_person(int right){
  if (right == 0)
    return ;
}

int Modele::connect_people(char *login, char *passwd){
  int right = db->login(login, passwd);
  if (right > 0) {
    init_person(right);
    name = login;
  }
  return right;
}

char *Modele::getName(){
  return name;
}

void Modele::update(){
  update();
}

Observable *Modele::window(){
  return win;
}
