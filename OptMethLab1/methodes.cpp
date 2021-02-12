#include <cmath>
#include <fstream>
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

   fout.close();
   return a;
}

double golden_ratio_method(double a, double b,
   const double& EPS, double funct(double), const std::string& OUT_FILE)
{
   double x1 = a + (3 - SQRT5) / 2 * (b - a);
   double x2 = a + (SQRT5 - 1) / 2 * (b - a);
   double f1, f2, a1, b1;

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

   fout.close();
   return a;
}

double calc_fibonacñi(const int& N)
{
   return pow((1 + SQRT5) / 2, N) / SQRT5;
}

int calc_reverse_fibonacñi(const int& F)
{
   return round(log(SQRT5 * F) / log((1 + SQRT5) / 2));
}

double fibonacñi_method(const double& a0, const double& b0,
   const double& EPS, double funct(double), const std::string& OUT_FILE)
{
   double a = a0, b = b0;
   const int N = calc_reverse_fibonacñi(round((b - a) / EPS)) - 2;
   double x1 = a + calc_fibonacñi(N + 0) / calc_fibonacñi(N + 2) * (b - a);
   double x2 = a + calc_fibonacñi(N + 1) / calc_fibonacñi(N + 2) * (b - a);
   double f1, f2, a1, b1;

   std::ofstream fout(OUT_FILE);

   fout << "N = " << N << std::endl;
   fout << "    i            x1            x2";
   fout << "            f1            f2";
   fout << "             a             b";
   fout << "         b - a   (b1 - a1) / (b - a)" << std::endl;

   int k = 1;
   for(; k <= N; k++)
   {
      f1 = funct(x1), f2 = funct(x2);
      a1 = a, b1 = b;

      if(f1 < f2)
      {
         b = x2;
         x2 = x1;
         x1 = a + calc_fibonacñi(N - k - 1) / calc_fibonacñi(N - k + 1) * (b - a);
      }
      else
      {
         a = x1;
         x1 = x2;
         x2 = a + calc_fibonacñi(N - k) / calc_fibonacñi(N - k + 1) * (b - a);
      }

      //// Âûâîä äëÿ ïðîñìîòðà òàáëèöû â âîðäå
      //fout << k << "\t" << x1 << "\t" << x2 << "\t" << f1 << "\t" << f2 << "\t";
      //fout << a << "\t" << b << "\t" << b - a << "\t" << (b1 - a1) / (b - a);
      //fout << std::endl;

      // Âûâîä äëÿ ïðîñìîòðà òàáëèöû â txt ôàéëå
      fout << std::fixed;
      fout << std::setw(5) << k;
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

void find_segment_with_min(double x0, const double& DELTA,
   double funct(double), double& a, double& b)
{
   int k = 1;
   double xk, xk1, xk_1, h;

   if(funct(x0) > funct(x0 + DELTA))
   {
      xk = x0 + DELTA;
      h = DELTA;
   }
   else if(funct(x0) > funct(x0 - DELTA))
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
      
      if(funct(xk) > funct(xk1))
      {
         xk_1 = xk;
         xk = xk1;
         k++;
      }
      else
         exit = true;
   } while(!exit);

   a = xk_1, b = xk1;
}
