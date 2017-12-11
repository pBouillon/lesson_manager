#include "observer.hpp"

Observer::Observer(){}

Observer::~Observer(){}

void Observer::add(Observable *o){
  vue.append(o);
}

void Observer::update(){
  int i;
  Observable *o;
  
  for (i  = 0; i != vue.count(); i++){
    o = (Observable*)vue[i];
    o->updateVue();
  }
}

Observable *Observer::get(int id){
  Observable *o = vue.at(id);
  return o;
}
