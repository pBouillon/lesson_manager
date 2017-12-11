#ifndef VUE_CONNECTION_HPP_
#define VUE_CONNECTION_HPP_

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QLabel>
#include <QFormLayout>
#include "modele.hpp"
#include "observable.hpp"

class VueConnection : public Observable 
{
  Q_OBJECT

public:
  VueConnection(Modele *);
  ~VueConnection();
  void updateVue();
	       
public slots:
  void submitValue();
  
private:
  Modele *mod;
  QPushButton *submit;
  QLabel *error;
  QLineEdit *lineLogin;
  QLineEdit *linePasswd;
};

#endif /* !VUE_CONNECTION_HPP_ */
