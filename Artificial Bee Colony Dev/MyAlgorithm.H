#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include "Solution.h"
#include "SetUpParams.h"
#include <iostream>

// index of a particle in the swarm and its fitness
struct particle
{
	int index;
	double fitness;
};

class MyAlgorithm
{
	public:
		//Constructeur
		MyAlgorithm(const Problem& pbm, const SetUpParams& setup);

		//Destructeur
		~MyAlgorithm();

		//Surcharges d'opérateur
		friend ostream& operator<< (ostream& ost, const MyAlgorithm& myAlgo);
		friend istream& operator>> (istream& ist, MyAlgorithm& myAlgo);

		//Surcharges d'opérateur
		MyAlgorithm& operator= (const MyAlgorithm& myAlgo);

		//Retourne des donnée
		const SetUpParams& setup() const;
		const vector<Solution*>& solutions() const;
		unsigned int upper_cost() const;
		unsigned int lower_cost() const;
		double best_cost(/*double best_cost*/) const;
		double worst_cost() const;
		double fitness(const unsigned int index) const;
		Solution& best_solution() const;
		Solution& worst_solution() const;
		Solution& solution(const unsigned int index) const;
		vector<struct particle>&  fitness_values();

		void evolution(); /*makes an evolution step*/
		void initialize();
		std::vector<int> CalculateProbabilities() const;
		void SendEmployedBees();
		void SendOnlookerBees(std::vector <int> probabilite);
		void SendScoutBees();

		// creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
		void evaluate();

	private:
		//Variable privé
		vector<Solution*> d_solutions;     // individuals in population
		vector<struct particle> d_fitness_values;
		vector <double> d_prob;
		const SetUpParams& d_setup;
		unsigned int d_upper_cost;// Upper fitness of individuals in population
		unsigned int d_lower_cost; // Lower fitness of individuals in population

		//Méthode privé
		void BeePhase(int &param2change, int& i,Solution* &newsol);
		void BeePhase1(int param2change, int i);
		void BeePhase2(int i, double prob);

};

#endif // MYALGORITHM_H

