#include <iostream>
#include "bisection_method.h"

const double eps = 10e-7;

double f(double x)
{
   return (x - 2) * (x - 2);
}

int main()
{
   std::cout << bisection_method(-2, 20, eps, f, "reports/bisect.txt");
}