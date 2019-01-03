#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>
#include "Benchmark.h"
#include <string>

using std::ostream;
using std::istream;

//Permet l'utilisation des benchmark
typedef double(*Fonction)(const std::vector<double>&);

class Problem
{
	public:
		//Constructeur
		Problem();
		Problem(int num, int dim);

		//Destructeur
		~Problem();

		//Surcharges d'opérateur
		friend ostream& operator<< (ostream& ost, const Problem& pbm);
		friend istream& operator>> (istream& ist, Problem& pbm);

		//Surcharges d'opérateur
		Problem& operator=  (const Problem& pbm);
		bool operator== (const Problem& pbm) const;
		bool operator!= (const Problem& pbm) const;

		//Méthode Revoyant une donnée
		double LowerLimit() const;
		double UpperLimit() const;
		int dimension() const;
		Fonction fonction() const;

		//Méthode d'initialisation des Limite
		void LimitBounds();
		void VerificationLimit(double &limit);

	private:
		//Variable Privé
		double d_lowerLimit; // Limite inférieur
		double d_upperLimit; // Limite supérieur
		int d_dimension;     // Dimension du problème
		Fonction d_fonction; // Benchmark utiliser
};


#endif // PROBLEM_H
