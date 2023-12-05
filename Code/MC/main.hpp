#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <valarray>

void addVector(std::vector<double>, std::vector<double>);

// Performs A = A + B
void addVector(std::vector<double> A, std::vector<double> B)
{
   std::transform(A.begin(), A.end(), B.begin(),
      A.begin(), std::plus<double>());
}