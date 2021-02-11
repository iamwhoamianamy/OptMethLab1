#pragma once

const double SQRT5 = sqrt(5);

// Функция поиска метода функции методом дихотомии
double bisection_method(double a, double b,
   const double& EPS, double funct(double), const std::string OUT_FILE);

// Функция поиска метода функции методом золотого сечения
double golden_ratio_method(double a, double b,
   const double& EPS, double funct(double), const std::string OUT_FILE);

// Вычисление n-го числа фибоначи
double calc_fibonacсi(const int& N);

// Вычисление n из числа Фибоначи
int calc_reverse_fibonacсi(const int& F);

// Функция поиска метода функции методом Фибоначчи
double fibonacсi_method(const double& a0, const double& b0,
   const double& EPS, double funct(double), const std::string OUT_FILE);
