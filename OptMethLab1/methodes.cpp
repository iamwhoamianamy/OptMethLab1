#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include"methodes.h"

double bisection_method(double a, double b,
   const double& EPS, double funct(double), const std::string& OUT_FILE)
{
   const double DELTA = EPS / 2;
   double x1, x2, f1, f2, a1, b1;

   std::ofstream fout(OUT_FILE);

   fout << "Expected min n = ";
   fout << round(log((b - a) / EPS) / log(2)) << std::endl;

   fout << "    n            x1            x2";
   fout << "            f1            f2";
   fout << "             a             b";
   fout << "         b - a   (b1 - a1) / (b - a)" << std::endl;

   int n = 0;
   for(; abs(b - a) > EPS; n++)
   {
      x1 = (a + b - DELTA) / 2;
      x2 = (a + b + DELTA) / 2;

      f1 = funct(x1); f2 = funct(x2);
      a1 = a, b1 = b;

      if(f1 < f2)
         b = x2;
      else
         a = x1;

      //// Âûâîä äëÿ ïðîñìîòðà òàáëèöû â âîðäå
      //fout << n << "\t" << x1 << "\t" << x2 << "\t" << f1 << "\t" << f2 << "\t";
      //fout << a << "\t" << b << "\t" << b - a << "\t" << (b1 - a1) / (b - a);
      //fout << std::endl;

      // Âûâîä äëÿ ïðîñìîòðà òàáëèöû â txt ôàéëå
      fout << std::fixed;
      fout << std::setw(5) << n + 1;
      fout << std::scientific;
      fout << std::setw(14) << x1 << std::setw(14) << x2;
      fout << std::setw(14) << f1 << std::setw(14) << f2;
      fout << std::setw(14) << a << std::setw(14) << b;
      fout << std::setw(14) << b - a << std::setw(22) << (b1 - a1) / (b - a);
      fout << std::endl;
   }
   fout << "Real n = " << n << std::endl;
   fout << "min = " << a << std::endl;
   fout << "dif = " << abs(a-2) << std::endl;

   fout.close();
   return a;
}

double golden_ratio_method(double a, double b,
   const double& EPS, double funct(double), const std::string& OUT_FILE)
{
   double x1 = a + (3 - SQRT5) / 2 * (b - a);
   double x2 = a + (SQRT5 - 1) / 2 * (b - a);
   double f1 = funct(x1);
   double f2 = funct(x2);
   double a1, b1;

   std::ofstream fout(OUT_FILE);

   fout << "Expected min n = ";
   fout << round(log((b - a) / EPS) / log((SQRT5 + 1) / 2)) << std::endl;

   fout << "    n            x1            x2";
   fout << "            f1            f2";
   fout << "             a             b";
   fout << "         b - a   (b1 - a1) / (b - a)" << std::endl;
   
   int n = 0;
   for(; abs(b - a) > EPS; n++)
   {
      a1 = a, b1 = b;
      if(f1 < f2)
      {
         b = x2;
         x2 = x1;
         x1 = a + (3 - SQRT5) / 2 * (b - a);
		 f2 = f1;
		 f1 = funct(x1);
      }
      else
      {
         a = x1;
         x1 = x2;
         x2 = a + (SQRT5 - 1) / 2 * (b - a);
		 f1 = f2;
		 f2 = funct(x2);
      }

      //// Âûâîä äëÿ ïðîñìîòðà òàáëèöû â âîðäå
      //fout << n + 1 << "\t" << x1 << "\t" << x2 << "\t" << f1 << "\t" << f2 << "\t";
      //fout << a << "\t" << b << "\t" << b - a << "\t" << (b1 - a1) / (b - a);
      //fout << std::endl;

      // Âûâîä äëÿ ïðîñìîòðà òàáëèöû â txt ôàéëå
      fout << std::fixed;
      fout << std::setw(5) << n + 1;
      fout << std::scientific;
      fout << std::setw(14) << x1 << std::setw(14) << x2;
      fout << std::setw(14) << f1 << std::setw(14) << f2;
      fout << std::setw(14) << a << std::setw(14) << b;
      fout << std::setw(14) << b - a << std::setw(22) << (b1 - a1) / (b - a);
      fout << std::endl;
   }
   fout << "Real n = " << n << std::endl;
   fout << "min = " << a << std::endl;
   fout << "dif = " << abs(a - 2) << std::endl;

   fout.close();
   return a;
}

//double calc_fibonacñi(const int& N)
//{
//   return pow((1 + SQRT5) / 2, N) / SQRT5;
//}

double calc_fibonacñi(const int& N)
{
    return (pow((1 + SQRT5) / 2, N) - pow((1 - SQRT5) / 2, N)) / SQRT5;
}

//int calc_reverse_fibonacñi(const double& F)
//{
//   return round(log(SQRT5 * F) / log((1 + SQRT5) / 2));
//}

double fibonacñi_method(const double& a0, const double& b0,
   const double& EPS, double funct(double), const std::string& OUT_FILE)
{
   double a = a0, b = b0;
   //const int N = calc_reverse_fibonacñi((b - a) / EPS) - 2;
   int N = 0;
   while (calc_fibonacñi(N + 2) < (b - a) / EPS) N++;

   double x1 = a + calc_fibonacñi(N + 0) / calc_fibonacñi(N + 2) * (b - a);
   double x2 = a + calc_fibonacñi(N + 1) / calc_fibonacñi(N + 2) * (b - a);
   double f1 = funct(x1);
   double f2 = funct(x2);
   double a1, b1;

   std::ofstream fout(OUT_FILE);

   fout << "N = " << N << std::endl;
   fout << "    i            x1            x2";
   fout << "            f1            f2";
   fout << "             a             b";
   fout << "         b - a   (b1 - a1) / (b - a)" << std::endl;

   int k = 0;
   for(; k < N-1; k++)
   {
      a1 = a, b1 = b;

      if(f1 < f2)
      {
         b = x2;
         x2 = x1;
         x1 = a + calc_fibonacñi(N - k - 1) / calc_fibonacñi(N - k + 1) * (b - a);
		 f2 = f1;
		 f1 = funct(x1);
      }
      else
      {
         a = x1;
         x1 = x2;
         x2 = a + calc_fibonacñi(N - k) / calc_fibonacñi(N - k + 1) * (b - a);
		 f1 = f2;
		 f2 = funct(x2);
      }

      //// Âûâîä äëÿ ïðîñìîòðà òàáëèöû â âîðäå
      //fout << k << "\t" << x1 << "\t" << x2 << "\t" << f1 << "\t" << f2 << "\t";
      //fout << a << "\t" << b << "\t" << b - a << "\t" << (b1 - a1) / (b - a);
      //fout << std::endl;

      // Âûâîä äëÿ ïðîñìîòðà òàáëèöû â txt ôàéëå
      fout << std::fixed;
      fout << std::setw(5) << k + 1;
      fout << std::scientific;
      fout << std::setw(14) << x1 << std::setw(14) << x2;
      fout << std::setw(14) << f1 << std::setw(14) << f2;
      fout << std::setw(14) << a << std::setw(14) << b;
      fout << std::setw(14) << b - a << std::setw(22) << (b1 - a1) / (b - a);
      fout << std::endl;
   }

   a1 = a, b1 = b;

   x2 = x1 = a + calc_fibonacñi(N - k - 1) / calc_fibonacñi(N - k + 1) * (b - a);

   a = x1;
   b = x2;
     
   // Âûâîä äëÿ ïðîñìîòðà òàáëèöû â txt ôàéëå
   fout << std::fixed;
   fout << std::setw(5) << k + 1 << std::endl;
   fout << std::scientific;
   fout << "min = " << a << std::endl;
   fout << "dif = " << abs(a - 2) << std::endl;

   fout.close();
   return a;
}

void find_segment_with_min(double x0, const double& DELTA,
   double funct(double), const std::string& OUT_FILE)
{
   int k = 1;
   double xk, xk1, xk_1, h;

   std::ofstream fout(OUT_FILE);
   fout << "    i            xi         f(xi)" << std::endl;
   fout << std::fixed << std::setw(5) << k;
   fout << std::scientific;
   fout << std::setw(14) << x0 << std::setw(14) << funct(x0);
   fout << std::endl;

   double f = funct(x0);
   if (f == funct(x0 + DELTA))
      fout << "segment with minimum: [" << x0 << ";" << x0 + DELTA << "]";
   else if (f == funct(x0 - DELTA))
      fout << "segment with minimum: [" << x0 << ";" << x0 - DELTA << "]";
   else
   {
      if (f > funct(x0 + DELTA))
      {
         xk = x0 + DELTA;
         h = DELTA;
      }
      else if (f > funct(x0 - DELTA))
      {
         xk = x0 - DELTA;
         h = -DELTA;
      }

      xk_1 = x0;

      bool exit = false;
      do
      {

         h *= 2;
         xk1 = xk + h;

         if (funct(xk) > funct(xk1))
         {
            xk_1 = xk;
            xk = xk1;
            k++;

            fout << std::fixed << std::setw(5) << k;
            fout << std::scientific;
            fout << std::setw(14) << xk << std::setw(14) << funct(xk);
            fout << std::endl;
         }
         else
            exit = true;
      } while (!exit);

      fout << "segment with minimum: [" << xk_1 << ";" << xk1 << "]";
   }
   fout.close();
}
