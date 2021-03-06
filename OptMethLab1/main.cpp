﻿#include <iostream>
#include "methodes.h"

const double EPSILON = 1e-4;

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
   find_segment_with_min(2.5, 1, f, "reports/segment.txt");
}