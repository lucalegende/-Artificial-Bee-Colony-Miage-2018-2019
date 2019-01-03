#define _USE_MATH_DEFINES
#include <cmath>
#include "Benchmark.h"
#include <stdlib.h>

//vector<double>sol : vecteur de solution solution

//la valeur de PI
const double PI = 3.14159265358979323846;

//Benchmark Sphère

/**
 * @fn	double sphere(const vector<double> &sol)
 *
 * @brief	Spheres est une fonction  utilisée comme test pour des problèmes d'optimisation mathématique
 *
 * @author	ENNECH Dounya
 * @date	03/12/2018
 *
 * @param	Solution de fitness.
 *
 * @return	Un double.
 */

double sphere(const vector<double> &sol)
{
	int D = sol.size();
	int j;
	double top = 0;

	for (j = 0; j<D; j++)
	{
		top = top + sol[j] * sol[j];
	}

	return top;
}

//Benchmark Rosenbrock

/**
 * @fn	double Rosenbrock(const vector<double> &sol)
 *
 * @brief	Rosenbrock est une fonction non convexe de deux variables utilisée comme test pour des problèmes d'optimisation mathématique
 *
 * @author	ENNECH Dounya
 * @date	03/12/2018
 *
 * @param	Solution de fitness.
 *
 * @return	Un double.
 */

double Rosenbrock(const vector<double> &sol)
{
	int D = sol.size();
	int j;
	double top = 0;

	for (j = 0; j < D - 1; j++)
	{
		top = top + 100 * pow((sol[j + 1] - pow((sol[j]), (double)2)), (double)2) + pow((sol[j] - 1), (double)2);
	}

	return top;
}

//Benchmark Griewank

/**
 * @fn	double Griewank(const vector<double> &sol)
 *
 * @brief	Griewanks est une fonction  utilisée comme test pour des problèmes d'optimisation mathématique
 *
 * @author 	ENNECH Dounya
 * @date	03/12/2018
 *
 * @param	Solution de fitness.
 *
 * @return	Un double.
 */

double Griewank(const vector<double> &sol)
{
	int D = sol.size();
	int j;
	double top = 0,top1 = 0,top2 = 1;

	for (j = 0; j<D; j++)
	{
		top1 = top1 + pow((sol[j]), (double)2);
		top2 = top2 * cos((((sol[j]) / sqrt((double)(j + 1)))*M_PI) / 180);

	}
	top = (1 / (double)4000)*top1 - top2 + 1;

	return top;
}

//Benchmark Rastrigin

/**
 * @fn	double Rastrigin(const vector<double> &sol)
 *
 * @brief	Rastrigins est une fonction  utilisée comme test pour des problèmes d'optimisation mathématique
 *
 * @author 	ENNECH Dounya
 * @date	03/12/2018
 *
 * @param	Solution de fitness.
 *
 * @return	Un double.
 */


double Rastrigin(const vector<double> &sol)
{
	int D = sol.size();
	int j;
	double top = 0;

	for (j = 0; j<D; j++)
	{
		top = top + (pow(sol[j], (double)2) - 10 * cos(2 * M_PI*sol[j]) + 10);
	}

	return top;
}

//Benchmark Ackley

/**
 * @fn	double Ackley(const vector<double> &sol)
 *
 * @brief	Ackleys est une fonction  utilisée comme test pour des problèmes d'optimisation mathématique
 *
 * @author 	ENNECH Dounya
 * @date	03/12/2018
 *
 * @param	Solution de fitness.
 *
 * @return	Un double.
 */

double Ackley(const vector<double> &sol)
{
	int D = sol.size();
	double s1, s2;

	for (int i = 0; i < D; ++i)
	{
		double x = sol[i];
		s1 += x * x;
		s2 += std::cos(2 * M_PI * x);
	}

	return -20 * exp(-0.2 * sqrt(s1 / D)) - exp(s2 / D) + exp(1) + 20;
}

//Benchmark Schwefel

/**
 * @fn	double Schwefel(const vector<double> &sol)
 *
 * @brief	Schwefels est une fonction  utilisée comme test pour des problèmes d'optimisation mathématique
 *
 * @author 	ENNECH Dounya
 * @date	03/12/2018
 *
 * @param	Solution de fitness.
 *
 * @return	Un double.
 */

double Schwefel(const vector<double> &sol)
{
	int D = sol.size();
	double sum = 0;

	for (int i = 0; i < D; i++)
	{
		sum += sol[i] * sin(sqrt(fabs(sol[i])));
	}

	double y = 418.9829 *D - sum;
	return y;
}

//Benchmark Schaffer F7 function

/**
 * @fn	double Schaffer(const vector<double> &sol)
 *
 * @brief	Schaffers est une fonction  utilisée comme test pour des problèmes d'optimisation mathématique
 *
 * @author 	ENNECH Dounya
 * @date	03/12/2018
 *
 * @param	Solution de fitness.
 *
 * @return	Un double.
 */

double Schaffer(const vector<double> &sol)
{
	int D = sol.size();
	double fitness = 0.0, si;
	double normalizer = 1.0 / (D - 1);

	for (int i = 0; i < D - 1; i++)
	{
		si = sqrt(sol[i] * sol[i] + sol[i + 1] * sol[i + 1]);
		fitness += (normalizer * sqrt(si) * (sin(50 * si*(si*0.20)) + 1))*(normalizer * sqrt(si) * (sin(50 * si*(si*0.20)) + 1));
	}

	return fitness;
}

//Benchmark Weierstrass

/**
 * @fn	double Weierstrass(const vector<double> &sol)
 *
 * @brief	Weierstrass est une fonction  utilisée comme test pour des problèmes d'optimisation mathématique
 *
 * @author 	ENNECH Dounya
 * @date	03/12/2018
 *
 * @param	Solution de fitness.
 *
 * @return	Un double.
 */

double Weierstrass(const vector<double> &sol)
{
	int D = sol.size();
	double a = 0.5;
	int b = 3;
	double val = 0.0, sum1 = 0.0, sum2 =0.0;

	for (int i = 0; i < D; i++)
	{
		for (int n = 0; n <= 20; n++)
		{
			sum1 += pow(a, n) * cos(2*M_PI * pow(b, n) * (sol[i]+0.5));
		}
	}

	for (int n = 0; n <= 20; n++)
	{
		sum2 += pow(a, n) * cos(2 * M_PI * pow(b, n) *0.5);
	}

	val = sum1 - D * sum2;
	return val;
}

