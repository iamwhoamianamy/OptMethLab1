#include <iostream>
#include "methodes.h"

const double EPSILON = 10e-8;

double f(double x)
{
   return (x - 2) * (x - 2);
}

int main()
{
   std::cout << bisection_method(-2, 20, EPSILON, f, "reports/bisect.txt");
   std::cout << std::endl;
   std::cout << golden_ratio_method(-2, 20, EPSILON, f, "reports/golden.txt");
   std::cout << std::endl;
   std::cout << fibonacсi_method(-2, 20, EPSILON, f, "reports/fibonacci.txt");
   std::cout << std::endl;

   double a, b;
   find_segment_with_min(-2, EPSILON, f, a, b);
   std::cout << a << " " << b;
}