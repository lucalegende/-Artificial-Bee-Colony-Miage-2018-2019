#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>
#include "Problem.h"


//contient la déclaration d'une solution
class Solution
{
	public:
		//Constructeur
		Solution(const Problem& pbm);
		Solution(const Solution& sol);

		//Destructeur
		~Solution();

		//Surcharges d'opérateur
		friend ostream& operator<< (ostream& ost, const Solution& sol);
		friend istream& operator>> (istream& ist, Solution& sol);

		//Surcharges d'opéraeur
		Solution& operator=  (const Solution& sol);
		bool operator== (const Solution& sol) const;
		bool operator!= (const Solution& sol) const;

		//Retourne des donnée
		const Problem& pbm() const;
		double FonctionFitness() const;
		double SolutionFitness() const;
		double CurrentFitness() const;
		int trial() const;
		vector<double>& solution();
		unsigned int size() const; //retourn la taille de la solution

		//Calcule la fitness
		double CalculateFitness(double fun);

		//Initialise les source de nourriture
		//lower limit + rand(0, 1) * (upper limit - lower limit)
		void initialize();

		//retournera une position du tableau d_solution
		double& position(const int index);

		//Modifie un position du tableau d_solution
		void  position(const int index, const double value);

		void incrementerTrial();
		double maxSol() const;

	private:
		//Méthode privé
		vector<double> d_solution;
		double  d_fonction_fitness;
		double d_current_fitness;
		const Problem& d_pbm;
		int d_trial;
};

#endif // SOLUTION_H

