#include <random>
#include <iostream>

int main(int argc, char const* argv[])
{
   std::default_random_engine generator;
   std::uniform_real_distribution<double> distribution(0.0, 1.0);
   for (int i = 0; i < 20; i++)
   {
      std::cout << distribution(generator) << std::endl;
   }
   return 0;
}
