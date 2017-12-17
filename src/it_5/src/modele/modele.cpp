/**
 * \file  modele.cpp
 * \brief Entrypoint for the lesson_manager 
 * 
 * \version 0.0.5
 *
 * \author Damien Choffe
 * \author Maxime Nicolas
 * \author Pierre Bouillon
 */

#include "modele.hpp"

/**
 * \fn      Modele constructor
 * \brief   init a Database, set a windows
 *
 *
 */
Modele::Modele() : Observer(){
  win = NULL;
  id_current = 0;
  db = new Database();
  db->init((char*)db_spec::default_sql);
}

/**
 * \name    Modele destructor
 * \brief   Destroy a Modele object
 *
 * Destructor for Modele
 */
Modele::~Modele() {
} /* ~Modele() */


/**
 * \fn      init_person
 * \brief   initialise a new Person with right
 *
 *
 * \param   right     the right of a Person
 */
void Modele::init_person(int right){
  if (right == 0)
    return ;
}

/**
 * \fn      connect_people
 * \brief   Connect the user
 *
 *
 * \param   login      the login
 * \param   passwd     the password
 */

int Modele::connect_people(char *login, char *passwd){
  int right = db->login(login, passwd);
  if (right > 0) {
    init_person(right);
    name = login;
    setWin(1);
    win->updateVue();
    setWindow(win);
  }
  return right;
}


/**
 * \fn      getName
 * \brief   get the name of the user
 *
 *
 * \return name
 */
char *Modele::getName(){
  return name;
}

/**
 * \fn      update
 * \brief   update view
 *
 *
 */
void Modele::update(){
  update();
}

/**
 * \fn      setWin
 * \brief   set which view to display
 *
 *
 */
void  Modele::setWin(int id){
  win = get(id);
}


/**
 * \fn      window
 * \brief   get which view is curently displayed
 *
 * \return win
 */
Observable *Modele::window(){
  return win;
}
