#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
using std::vector;

double sphere(const vector<double> &sol);
double Rosenbrock(const vector<double> &sol);
double Griewank(const vector<double> &sol);
double Rastrigin(const vector<double> &sol);
double Ackley(const vector<double> &sol);
double Schwefel(const vector<double> &sol);
double Schaffer(const vector<double> &sol);
double Weierstrass(const vector<double> &sol);

#endif // BENCHMARK_H
