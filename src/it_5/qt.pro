SOURCES = \
  main.cpp \
  src/modele/modele.cpp \
  src/modele/observer.cpp \
  src/modele/observable.cpp \
  src/vue/vuePrincipale.cpp \
  src/vue/vueConnection.cpp \
  src/vue/vueValidation.cpp \
  src/modele/manager/database.cpp 
  
#Important pour generer le fichier moc

HEADERS = header/vueConnection.hpp

unix:INCLUDEPATH += "./header/"

LIBS += -lsqlite3

TARGET      = lesson_manager          # nom du binaire
QT         += core gui                 # base de Qt + 'widgets' (si Qt > 4)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets 
