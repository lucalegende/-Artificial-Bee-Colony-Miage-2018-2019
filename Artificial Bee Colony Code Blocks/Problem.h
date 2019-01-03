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

		//Surcharges d'op�rateur
		friend ostream& operator<< (ostream& ost, const Problem& pbm);
		friend istream& operator>> (istream& ist, Problem& pbm);

		//Surcharges d'op�rateur
		Problem& operator=  (const Problem& pbm);
		bool operator== (const Problem& pbm) const;
		bool operator!= (const Problem& pbm) const;

		//M�thode Revoyant une donn�e
		double LowerLimit() const;
		double UpperLimit() const;
		int dimension() const;
		Fonction fonction() const;

		//M�thode d'initialisation des Limite
		void LimitBounds();
		void VerificationLimit(double &limit);

	private:
		//Variable Priv�
		double d_lowerLimit; // Limite inf�rieur
		double d_upperLimit; // Limite sup�rieur
		int d_dimension;     // Dimension du probl�me
		Fonction d_fonction; // Benchmark utiliser
};


#endif // PROBLEM_H
