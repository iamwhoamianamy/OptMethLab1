#pragma once

const double SQRT5 = sqrt(5);

// ������� ������ ������ ������� ������� ���������
double bisection_method(double a, double b,
   const double& EPS, double funct(double), const std::string OUT_FILE);

// ������� ������ ������ ������� ������� �������� �������
double golden_ratio_method(double a, double b,
   const double& EPS, double funct(double), const std::string OUT_FILE);

// ���������� n-�� ����� ��������
double calc_fibonac�i(const int& N);

// ���������� n �� ����� ��������
int calc_reverse_fibonac�i(const int& F);

// ������� ������ ������ ������� ������� ���������
double fibonac�i_method(const double& a0, const double& b0,
   const double& EPS, double funct(double), const std::string OUT_FILE);
