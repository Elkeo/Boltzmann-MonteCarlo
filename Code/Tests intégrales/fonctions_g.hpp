#include <iostream>
#include <vector>

//Classe mère des fonctions g
class fonction_g {
 protected:
  double * _vecteur_parametres;
 public:
  //Constructeur 
  fonction_g(double * vecteur_parametres);
  //Constructeur par copie
  fonction_g(fonction_g& fonction_g);
  //Destructeur 
  virtual ~fonction_g();
  //Calcul de g(x) (fonction virtuelle pure)
  virtual double calculer_g_x(double valeur_x)=0;
  //Fonction d'accès
  double * getParameters() {return  _vecteur_parametres;};
};

class fonction_g_sin : public fonction_g {
  using fonction_g::fonction_g;
  
 public:
  //Evaluation:
  double calculer_g_x(double valeur_x);
};

//Classe fille linéaire
//class fonction_lin {
  //private:
  //Pente
  //const double _pente;
  //Ordonée à l'origine
  //const double _ordorig;

  //public:
  //Evaluation:
  //double compute_g_x(const double var_x);

  //};
