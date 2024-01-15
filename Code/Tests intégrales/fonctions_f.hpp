#include <iostream>
#include <vector>

class fonction_f_unif {
 private:
  //minimum de la distribution
  const double _min;
  //maximum de la disribution
  const double _max;

 public:
  //Constructeurs :
  fonction_f_unif(const double min, const double max);
  fonction_f_unif(const fonction_f_unif& fonction_f_unif);
  //Evaluation:
  double compute_f_x(const double var_x);

  //Fonctions d'accès :
  const double& getMin() const {return _min;};
  const double& getMax() const {return _max;};
};

