#include "SetUpParams.h"

using std::endl;

/**
 * @fn	SetUpParams::SetUpParams()
 *
 * @brief	Constructeur par défaut.
 *
 * @author	MARFIL Victor
 * @date	03/12/2018
 */

SetUpParams::SetUpParams():
	d_independent_runs{ 30 },
	d_nb_evolution_steps{ 2000000 },
	d_population_size{ 40 },
	d_solution_size{ 20 },
	d_max_trial { 100 }
{
}

/**
 * @fn	SetUpParams::SetUpParams(unsigned int nbExec, unsigned int nbItrs, unsigned int population, unsigned int solSize, unsigned int maxTrial)
 *
 * @brief	Constructeur avec paramètre.
 *
 * @author	MARFIL Victor
 * @date	03/12/2018
 *
 * @param	nbExec	  	Le nombre d'éxécutions.
 * @param	nbItrs	  	Le nombre itérations.
 * @param	population	La taille de la population.
 * @param	solSize   	Taille de la solution.
 * @param	maxTrial  	Nombre maximum d'essai.
 */

SetUpParams::SetUpParams(unsigned int nbExec, unsigned int nbItrs, unsigned int population, unsigned int solSize, unsigned int maxTrial):
	d_independent_runs {nbExec},
	d_nb_evolution_steps{ nbItrs },
	d_population_size{ population },
	d_solution_size{ solSize },
	d_max_trial{maxTrial}
{
}

/**
 * @fn	SetUpParams::~SetUpParams()
 *
 * @brief	Destructeur.
 *
 * @author	MARFIL Victor
 * @date	03/12/2018
 */

SetUpParams::~SetUpParams()
{
}

/**
 * @fn	const unsigned int SetUpParams::independent_runs() const
 *
 * @brief	Independent runs.
 *
 * @author	MARFIL Victor
 * @date	03/12/2018
 *
 * @return	Un entier constent.
 */

const unsigned int SetUpParams::independent_runs() const
{
	return d_independent_runs;
}

/**
 * @fn	const unsigned int SetUpParams::nb_evolution_steps() const
 *
 * @brief	Nombre de pas d'évolution.
 *
 * @author	MARFIL Victor
 * @date	03/12/2018
 *
 * @return	Un entier constent.
 */

const unsigned int SetUpParams::nb_evolution_steps() const
{
	return d_nb_evolution_steps;
}

/**
 * @fn	const unsigned int SetUpParams::population_size() const
 *
 * @brief	Taille de la populations.
 *
 * @author	MARFIL Victor
 * @date	03/12/2018
 *
 * @return	Un entier constent.
 */

const unsigned int SetUpParams::population_size() const
{
	return d_population_size;
}

/**
 * @fn	const unsigned int SetUpParams::solution_size() const
 *
 * @brief	Taille de la solution.
 *
 * @author	MARFIL Victor
 * @date	03/12/2018
 *
 * @return	Un entier constent.
 */

const unsigned int SetUpParams::solution_size() const
{
	return d_solution_size;
}

/**
 * @fn	const unsigned int SetUpParams::max_trial() const
 *
 * @brief	Nombre Maximum d'essai.
 *
 * @author	MARFIL Victor
 * @date	03/12/2018
 *
 * @return	Un entier constent.
 */

const unsigned int SetUpParams::max_trial() const
{
	return d_max_trial;
}

/**
 * @fn	ostream & operator<<(ostream & ost, const SetUpParams & setup) { ost << "Paramamtre "<< endl; ost << "Nombre d’exécutions : "<< setup.independent_runs() << endl; ost << "Nombre total d’appel de la fonction objectif : " << setup.nb_evolution_steps() << endl; ost << "Nombre d’individus dans la population : " << setup.population_size() << endl; ost << "Dimension du problème pour chaque particle : " << setup.solution_size() << endl; ost << "Nombre maximum d'essaie : " << setup.max_trial() << endl; return ost;
 *
 * @brief	Opérator de surcharge pour l'affichage.
 *
 * @author	MARFIL Victor
 * @date	03/12/2018
 *
 * @param [in,out]	ost  	Le flux de sortie ost.
 * @param 		  	setup	Un variable contenant la liste des parametres de la classe.
 *
 * @return	flux de sortie.
 */

ostream & operator<<(ostream & ost, const SetUpParams & setup)
{
	ost << "Paramamtre "<< endl;
	ost << "Nombre d’exécutions : "<< setup.independent_runs() << endl;
	ost << "Nombre total d’appel de la fonction objectif : " << setup.nb_evolution_steps() << endl;
	ost << "Nombre d’individus dans la population : " << setup.population_size() << endl;
	ost << "Dimension du problème pour chaque particle : " << setup.solution_size() << endl;
	ost << "Nombre maximum d'essaie : " << setup.max_trial() << endl;
	return ost;
}

/**
 * @fn	istream & operator>>(istream & ist, SetUpParams & setup)
 *
 * @brief	Operator de surcharge pour l'insertion.
 *
 * @author	MARFIL Victor
 * @date	03/12/2018
 *
 * @param [in,out]	ist  	Le flux d'entrée ist.
 * @param 		  	setup	Un variable contenant la liste des parametres de la classe.
 *
 * @return	flux d'entrée.
 */

istream & operator>>(istream & ist, SetUpParams & setup)
{
	ist >> setup.d_independent_runs >> setup.d_nb_evolution_steps >> setup.d_population_size >> setup.d_solution_size;
	return ist;
}
