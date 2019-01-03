#ifndef SETUPPARAMS_H
#define SETUPPARAMS_H

#include <iostream>

using std::ostream;
using std::istream;

//Initialisation des paramètres de l'algorithme ABC
class SetUpParams
{
	public:
		//Constructeur
		SetUpParams();
		SetUpParams(unsigned int nbExec, unsigned int nbItrs, unsigned int population, unsigned int solSize, unsigned int maxTrial);

		//Destructeur
		~SetUpParams();

		//Surchages d'opérateur
		friend ostream& operator<< (ostream& os, const SetUpParams& setup);
		friend istream& operator>> (istream& is, SetUpParams& setup);

		//Méhode de renvoie de donnée
		const unsigned int   independent_runs() const;
		const unsigned int   nb_evolution_steps() const;
		const unsigned int   population_size() const;
		const unsigned int   solution_size() const;
		const unsigned int   max_trial() const;

	private:
		//Variable privé
		unsigned int d_independent_runs;    // Nombre d’exécutions |30
		unsigned int d_nb_evolution_steps;  // Nombre total d’appel de la fonction objectif |2e6
		unsigned int d_population_size;		// Nombre d’individus dans la population |40
		unsigned int d_solution_size;	    // Taille de la solution |20
		unsigned int d_max_trial;			// Nombre maximum d'essaie | 100
};

#endif // SETUPPARAMS_H
