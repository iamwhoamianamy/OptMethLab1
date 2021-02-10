#include <cmath>
#include <fstream>
#include <iomanip>
#include"bisection_method.h"

double bisection_method(double a, double b,
   const double& eps, double funct(double), const std::string out_file)
{
   double d = eps / 2, x1, x2;

   std::ofstream fout(out_file);

   fout << "    i            x1            x2";
   fout << "            f1            f2";
   fout << "             a             b";
   fout << "         b - a   (b1 - a1) / (b - a)" << std::endl;

   for(int i = 0; abs(b - a) > eps; i++)
   {
      x1 = (a + b - d) / 2, x2 = (a + b + d) / 2;

      double f1 = funct(x1), f2 = funct(x2);
      double a1 = a, b1 = b;

      if(f1 < f2)
         b = x2;
      else
         a = x1;

      //// Вывод для просмотра таблицы в ворде
      //fout << i << "\t" << x1 << "\t" << x2 << "\t" << f1 << "\t" << f2 << "\t";
      //fout << a << "\t" << b << "\t" << b - a << "\t" << (b1 - a1) / (b - a);
      //fout << std::endl;

      // Вывод для просмотра таблицы в txt файле
      fout << std::fixed;
      fout << std::setw(5) << i;
      fout << std::scientific;
      fout << std::setw(14) << x1 << std::setw(14) << x2;
      fout << std::setw(14) << f1 << std::setw(14) << f2;
      fout << std::setw(14) << a << std::setw(14) << b;
      fout << std::setw(14) << b - a << std::setw(22) << (b1 - a1) / (b - a);
      fout << std::endl;
   }

   fout.close();
   return a;
}