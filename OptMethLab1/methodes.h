#pragma once

// Функция поиска метода функции методом дихотомии
double bisection_method(double a, double b,
   const double& eps, double funct(double), const std::string out_file);

// Функция поиска метода функции методом золотого сечения
double golden_ratio_method(double a, double b,
   const double& eps, double funct(double), const std::string out_file);