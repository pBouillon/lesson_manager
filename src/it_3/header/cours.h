#ifndef		COURS_H_
#define		COURS_H_

class		Cours {
 private:
  char	*name;
  
 public:
  Cours(char *);
  ~Cours();
  char *get_nom();
};

#endif	/* COURS_H_ */
