#include "Solution.h"
#include <cmath>
#include <stdlib.h>

using std::endl;

/**
 * @fn	Solution::Solution(const Problem & pbm)
 *
 * @brief	Constructeur.
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @param	pbm	Variable problème.
 */


Solution::Solution(const Problem & pbm):
	d_solution{},
	d_current_fitness{ INT_MAX },
	d_fonction_fitness{ INT_MAX },
	d_pbm{ pbm },
	d_trial{ 0 }
{
	d_solution.resize(pbm.dimension());
	initialize();
}

/**
 * @fn	Solution::Solution(const Solution & sol)
 *
 * @brief	Constructeur de copie.
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @param	Solution de solution.
 */

Solution::Solution(const Solution & sol):
	d_solution {},
	d_current_fitness{ sol.d_current_fitness },
	d_fonction_fitness{ sol.d_fonction_fitness },
	d_pbm{ sol.d_pbm },
	d_trial{ 0 }

{
	d_solution = sol.d_solution;
}

/**
 * @fn	Solution::~Solution()
 *
 * @brief	Destructeur.
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 */

Solution::~Solution()
{
}

/**
 * @fn	Solution & Solution::operator=(const Solution & sol)
 *
 * @brief	Opérateur de surcharge affectation (=)
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @param	Solution de solution.
 *
 * @return	Une copie superficielle de cet objet.
 */

Solution & Solution::operator=(const Solution & sol)
{
	d_solution = sol.d_solution;
	d_fonction_fitness = sol.d_fonction_fitness;
	d_current_fitness = sol.d_current_fitness;
	d_trial = sol.d_trial;
	return *(this);
}

/**
 * @fn	bool Solution::operator==(const Solution & sol) const
 *
 * @brief	Opérateur de surcharge d'egalité (==)
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @param	Solution de solution.
 *
 * @return	Une copie superficielle de cet objet.
 */

bool Solution::operator==(const Solution & sol) const
{
	return d_solution == sol.d_solution &&
	d_fonction_fitness == sol.d_fonction_fitness &&
	d_current_fitness == sol.d_current_fitness &&
	d_trial == sol.d_trial;
}

/**
 * @fn	bool Solution::operator!=(const Solution & sol) const
 *
 * @brief	Opérateur de surcharge d'inégalité (!=)
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @param	Solution de solution.
 *
 * @return	Vrai si le paramètre n'est pas considéré equivalent.
 */

bool Solution::operator!=(const Solution & sol) const
{
	return !(*this == sol);
}

/**
 * @fn	const Problem & Solution::pbm() const
 *
 * @brief	Solution de problème.
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @return	A reference to a const Problem.
 */

const Problem & Solution::pbm() const
{
	return d_pbm;
}

/**
 * @fn	double Solution::FonctionFitness() const
 *
 * @brief	Fonction de fitness.
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @return	Un double.
 */

double Solution::FonctionFitness() const
{
	return d_fonction_fitness;
}

/**
 * @fn	double Solution::SolutionFitness() const
 *
 * @brief	Solution de fitness.
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @return	Un double.
 */

double Solution::SolutionFitness() const
{
	return d_pbm.fonction()(d_solution);
}

/**
 * @fn	double Solution::CurrentFitness() const
 *
 * @brief	Fitness courante.
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @return	Un double.
 */

double Solution::CurrentFitness() const
{
	return d_current_fitness;
}

/**
 * @fn	int Solution::trial() const
 *
 * @brief	Recupère le nombre d'essai.
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @return	Un entier.
 */

int Solution::trial() const
{
	return d_trial;
}

/**
 * @fn	vector<double>& Solution::solution()
 *
 * @brief	Recupère la solution.
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @return	Un vecteur de solution.
 */

vector<double>& Solution::solution()
{
	return d_solution;
}

/**
 * @fn	unsigned int Solution::size() const
 *
 * @brief	Recupère la taille de la solution.
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @return	Un entier.
 */

unsigned int Solution::size() const
{
	return d_solution.size();
}

/**
 * @fn	double Solution::CalculateFitness(double fun)
 *
 * @brief	Calcule la fitness.
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @param	Une valeur de la function.
 *
 * @return	Le calcule de la fitness.
 */

double Solution::CalculateFitness(double fun)
{
	double result = 0;
	if (fun >= 0)
	{
		result = 1 / (fun + 1);
	}
	else
	{
		result = 1 + std::abs(fun);
	}
	return result;
}

/**
 * @fn	void Solution::initialize()
 *
 * @brief	Initialise les sources de nouritures.
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 */

void Solution::initialize()
{
	for (int i = 0; i < d_solution.size(); i++) {
		double r = 1.0*rand() / RAND_MAX;
		d_solution[i] = r * (d_pbm.UpperLimit() - d_pbm.LowerLimit()) + d_pbm.LowerLimit();
	}


	d_fonction_fitness = d_pbm.fonction()(d_solution);
	d_current_fitness = CalculateFitness(d_fonction_fitness);

	d_trial = 0;
}

/**
 * @fn	double & Solution::position(const int index)
 *
 * @brief	Position de la solution.
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @param	index	La position.
 *
 * @return	Un reférence de la solution.
 */

double & Solution::position(const int index)
{
	return d_solution[index];
}

/**
 * @fn	void Solution::position(const int index, const double value)
 *
 * @brief	Positions.
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @param	index	La positions.
 * @param	value	La valeur.
 */

void Solution::position(const int index, const double value)
{
	d_solution[index] = value;
}

/**
 * @fn	void Solution::incrementerTrial()
 *
 * @brief	Incremente la variable trial.
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 */

void Solution::incrementerTrial()
{
	d_trial++;
}

/**
 * @fn	double Solution::maxSol() const
 *
 * @brief	Maximum sol
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @return	Un double.
 */

double Solution::maxSol() const
{
	double max = d_solution[0];
	if (max<0) max *= -1;
	for (int i = 1; i < d_solution.size(); i++)
	{
		if (d_solution[i] > max) max = d_solution[i];
		if (d_solution[i] * -1 > max) max = d_solution[i] * -1;
	}
	return max;
}

/**
 * @fn	ostream & operator<<(ostream & ost, const Solution & sol) { ost << "Fitness associées aux sources de nourriture : " << sol.d_current_fitness << endl; ost << "Fonction objectif associées aux sources de nourriture : " << sol.d_fonction_fitness << endl; ost << "Nombre d'essaie : " << sol.d_trial << endl; return ost;
 *
 * @brief	Opérator de surcharge pour l'affichage
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @param [in,out]	ost  	Le flux de sortie ost.
 * @param 		  	sol 	Un variable contenant la liste des parametres de la classe.
 *
 * @return	flux de sortie.
 */

ostream & operator<<(ostream & ost, const Solution & sol)
{
	ost << "Fitness associées aux sources de nourriture : " << sol.d_current_fitness << endl;
	ost << "Fonction objectif associées aux sources de nourriture : " << sol.d_fonction_fitness << endl;
	ost << "Nombre d'essaie : " << sol.d_trial << endl;
	return ost;
}

/**
 * @fn	istream & operator>>(istream & ist, Solution & sol)
 *
 * @brief	Operator de surcharge pour l'insertion
 *
 * @author	GRUNENWALD Luca
 * @date	03/12/2018
 *
 * @param [in,out]	ist  	Le flux d'entrée ist.
 * @param [in,out] 	sol 	Un variable contenant la liste des parametres de la classe.
 *
 * @return	flux d'entrée.
 */

istream & operator>>(istream & ist, Solution & sol)
{
	ist >> sol.d_fonction_fitness >> sol.d_current_fitness >> sol.d_trial;
	return ist;
}
