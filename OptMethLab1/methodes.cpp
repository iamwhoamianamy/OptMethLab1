#include <cmath>
#include <fstream>
#include <iomanip>
#include"methodes.h"

double bisection_method(double a, double b,
   const double& EPS, double funct(double), const std::string out_file)
{
   const double DELTA = EPS / 2;
   double x1, x2, f1, f2, a1, b1;

   std::ofstream fout(out_file);

   fout << "Expected min n = ";
   fout << round(log((b - a) / EPS) / log(2)) << std::endl;

   fout << "    i            x1            x2";
   fout << "            f1            f2";
   fout << "             a             b";
   fout << "         b - a   (b1 - a1) / (b - a)" << std::endl;

   for(int i = 0; abs(b - a) > EPS; i++)
   {
      x1 = (a + b - DELTA) / 2;
      x2 = (a + b + DELTA) / 2;

      f1 = funct(x1); f2 = funct(x2);
      a1 = a, b1 = b;

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
      fout << std::setw(5) << i + 1;
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

double golden_ratio_method(double a, double b,
   const double& EPS, double funct(double), const std::string out_file)
{
   const double SQRT5 = sqrt(5);
   double x1 = a + (3 - SQRT5) / 2 * (b - a);
   double x2 = a + (SQRT5 - 1) / 2 * (b - a);
   double f1, f2, a1, b1;

   std::ofstream fout(out_file);

   fout << "Expected min n = ";
   fout << round(log((b - a) / EPS) / log((SQRT5 + 1) / 2)) << std::endl;

   fout << "    i            x1            x2";
   fout << "            f1            f2";
   fout << "             a             b";
   fout << "         b - a   (b1 - a1) / (b - a)" << std::endl;

   for(int i = 0; abs(b - a) > EPS; i++)
   {
      f1 = funct(x1), f2 = funct(x2);
      a1 = a, b1 = b;

      if(f1 < f2)
      {

         b = x2;
         x2 = x1;
         x1 = a + (3 - SQRT5) / 2 * (b - a);
      }
      else
      {
         a = x1;
         x1 = x2;
         x2 = a + (SQRT5 - 1) / 2 * (b - a);
      }

      //// Вывод для просмотра таблицы в ворде
      //fout << i + 1 << "\t" << x1 << "\t" << x2 << "\t" << f1 << "\t" << f2 << "\t";
      //fout << a << "\t" << b << "\t" << b - a << "\t" << (b1 - a1) / (b - a);
      //fout << std::endl;

      // Вывод для просмотра таблицы в txt файле
      fout << std::fixed;
      fout << std::setw(5) << i + 1;
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

