#pragma once

// ������� ������ ������ ������� ������� ���������
double bisection_method(double a, double b,
   const double& eps, double funct(double), const std::string out_file);