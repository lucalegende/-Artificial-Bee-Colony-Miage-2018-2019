#include "MyAlgorithm.h"
#include <cstdlib>
#include <float.h>
#include <fstream>
#include <cstddef>
#include <cmath>
#include <stdlib.h>

using std::cout;
using std::endl;

double random()
{
	double r = ((double) rand() / (RAND_MAX));
	return r;
}

/**
 * @fn	MyAlgorithm::MyAlgorithm(const Problem & pbm, const SetUpParams & setup)
 *
 * @brief	Constructeurr
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @param	pbm  	Variable contenant les paramètres du problème.
 * @param	setup	Variable contenant les paramètres génréraux.
 */

MyAlgorithm::MyAlgorithm(const Problem & pbm, const SetUpParams & setup):
	d_solutions{},
	d_fitness_values{},
	d_setup{ setup }
{
	d_solutions.resize(d_setup.population_size());
	d_fitness_values.resize(d_setup.population_size());
	for (int i = 0; i<d_setup.population_size(); ++i)
	{
		d_solutions[i] = new Solution{ pbm };
		d_fitness_values[i] = particle{ i,d_solutions[i]->SolutionFitness() };
	}
}

/**
 * @fn	MyAlgorithm::~MyAlgorithm()
 *
 * @brief	Destructeur
 *
 * @author	Tous
 * @date	03/12/2018
 */


MyAlgorithm::~MyAlgorithm()
{
	for (int i = 0; i<d_solutions.size(); ++i)
	{
		delete d_solutions[i];
	}
}

/**
 * @fn	MyAlgorithm & MyAlgorithm::operator=(const MyAlgorithm & myAlgo)
 *
 * @brief	Opérateur de surcharge affectation (=)
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @param	myAlgo	Variable My algorithme.
 *
 * @return	Une copie superficielle de cet objet.
 */

MyAlgorithm & MyAlgorithm::operator=(const MyAlgorithm & myAlgo)
{
	d_solutions = myAlgo.d_solutions;
	d_fitness_values = myAlgo.d_fitness_values;
	d_upper_cost = myAlgo.d_upper_cost;
	d_lower_cost = myAlgo.d_lower_cost;
	return *this;
}

/**
 * @fn	const SetUpParams & MyAlgorithm::setup() const
 *
 * @brief	Recupère les paramètre du progamme
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @return	un référence de la classe SetUpParams.
 */

const SetUpParams & MyAlgorithm::setup() const
{
	return d_setup;
}

/**
 * @fn	const vector<Solution*>& MyAlgorithm::solutions() const
 *
 * @brief	Récupère le vecteur de solutions
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @return	le vecteur de solutions;
 */

const vector<Solution*>& MyAlgorithm::solutions() const
{
	return d_solutions;
}

/**
 * @fn	unsigned int MyAlgorithm::upper_cost() const
 *
 * @brief	Upper cost
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @return	Un entier.
 */

unsigned int MyAlgorithm::upper_cost() const
{
	return d_upper_cost;
}

/**
 * @fn	unsigned int MyAlgorithm::lower_cost() const
 *
 * @brief	Lower cost
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @return	Un entier.
 */

unsigned int MyAlgorithm::lower_cost() const
{
	return d_lower_cost;
}

/**
 * @fn	double MyAlgorithm::best_cost() const
 *
 * @brief	Meilleur cout.
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @return	Un double.
 */

double MyAlgorithm::best_cost() const
{
	int i;
	double best_cost = DBL_MAX;

	for (i = 0; i<d_solutions.size(); i++)
	{
		if (d_fitness_values[i].fitness<best_cost)
		{
			best_cost = d_fitness_values[i].fitness;
		}
	};

	return best_cost;
}

/**
 * @fn	double MyAlgorithm::worst_cost() const
 *
 * @brief	Pire cout.
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @return	Un double.
 */

double MyAlgorithm::worst_cost() const
{
	int i;
	double worst_cost = 0;

	for (i = 0; i<d_solutions.size(); i++)
	{
		if (d_fitness_values[i].fitness>worst_cost)
		{
			worst_cost = d_fitness_values[i].fitness;
		}
	};

	return worst_cost;
}

/**
 * @fn	double MyAlgorithm::fitness(const unsigned int index) const
 *
 * @brief	Recupère la Fitness a un indice index
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @param	index	l'indice du vecteur.
 *
 * @return	Un double.
 */

double MyAlgorithm::fitness(const unsigned int index) const
{
	return d_fitness_values[index].fitness;
}

/**
 * @fn	Solution & MyAlgorithm::best_solution() const
 *
 * @brief	Meilleur solution
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @return	la meilleur Solution.
 */

Solution & MyAlgorithm::best_solution() const
{
	return solution(best_cost());
}

/**
 * @fn	Solution & MyAlgorithm::worst_solution() const
 *
 * @brief	Pire solution.
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @return	La pire Solution.
 */

Solution & MyAlgorithm::worst_solution() const
{
	return solution(worst_cost());
}

/**
 * @fn	Solution & MyAlgorithm::solution(const unsigned int index) const
 *
 * @brief	Solutions the given index
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @param	index	indice du vecteur.
 *
 * @return	Une référence de la Solution a un indice précis.
 */


Solution & MyAlgorithm::solution(const unsigned int index) const
{
	return *d_solutions[index];
}

/**
 * @fn	vector<struct particle>& MyAlgorithm::fitness_values()
 *
 * @brief	Fitness values
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @return	Une référence de la structure de particule;
 */

vector<struct particle>& MyAlgorithm::fitness_values()
{
	return d_fitness_values;
}

/**
 * @fn	void MyAlgorithm::evolution()
 *
 * @brief	Programme principal : Evolutions
 *
 * @author	Tous
 * @date	03/12/2018
 */

void MyAlgorithm::evolution()
{
	//Initialisation des variable
	std::vector<double> resultats;

	double moyenne = 0.0;
	double meilleur = 0;
	//si le nom d'éxécution est différent de 0 alors on mets la meilleur solution au maximum
	if (d_setup.independent_runs() != 0)
	{
		meilleur = DBL_MAX;
	}

    std::ofstream myfile;
    myfile.open("resultat.txt");

	//Pour chaque execution
	for (int run = 0; run<d_setup.independent_runs(); run++)
	{
		//Initialise
		initialize();

		//Pour chaque itération
		for (int iter = 0; iter<d_setup.nb_evolution_steps(); iter++)
		{
			//Phase 1
			SendEmployedBees();

			//Phase 2
			SendOnlookerBees(CalculateProbabilities());

			//Phase 3
			SendScoutBees();

			cout << "Itrs : " << run + 1 << "| Essaie : " << iter + 1 << "| Meilleur Solution : " << best_cost() << endl;
            myfile << "Itrs : " << run + 1 << "| Essaie : " << iter + 1 << "| Meilleur Solution : " << best_cost() << endl;
			//on verifie si il y a une meilleur solution
			if (meilleur > best_cost())
			{
				meilleur = best_cost();
			}
		}

		cout << endl;
		myfile << std::endl;
		moyenne += best_cost() / d_setup.independent_runs();
		resultats.push_back(best_cost());
	}

	//Calcule de l'écart type
	double ecartype = 0;
	for (int i = 0; i < resultats.size(); ++i)
	{
		ecartype += sqrt(1.0 / (i + 1)*pow(resultats[i] - moyenne, 2));
	}

	cout << "Moyenne     = " << moyenne << endl;
	cout << "Ecart Type  = " << ecartype << endl;
	cout << "Meilleur Solution = " << meilleur << endl;

	//on ajoute la moyenne ecart type et la meilleur solution dans le fichier txt
	myfile << "Moyenne     = " << moyenne << endl;
	myfile << "Ecart Type  = " << ecartype << endl;
    myfile << "Meilleur Solution = " << meilleur << endl;

    //on ferme le fichier
	myfile.close();
}

/**
 * @fn	void MyAlgorithm::initialize()
 *
 * @brief	Initialise les sources de nourriture
 *
 * @author	Tous
 * @date	03/12/2018
 */

void MyAlgorithm::initialize()
{
	for (int i = 0; i<d_solutions.size(); i++)
	{
		d_solutions[i]->initialize();
		d_fitness_values[i] = particle{i, d_solutions[i]->SolutionFitness()};
	}
}

/**
 * @fn	std::vector<int> MyAlgorithm::CalculateProbabilities() const
 *
 * @brief	Calculates les probabilities
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @return	Le calcul des probabilities.
 */

std::vector<int> MyAlgorithm::CalculateProbabilities() const
{
	std::vector <int> probabilite;
	probabilite.resize(d_setup.population_size());

	for (int i = 0; i<d_setup.population_size(); i++)
	{
		double maxsol = d_solutions[i]->maxSol();

		for (int j = 0; j<d_setup.solution_size(); j++)
		{
			double test = 0.9 * d_solutions[i]->position(j) / maxsol + 0.1;
			if (test<0) test *= -1;

			double r = random();
			if (r<test)
			{
				probabilite[i] = j;
				j = d_setup.solution_size();
			}
		}
	}
	return probabilite;
}

/**
 * @fn	void MyAlgorithm::SendEmployedBees()
 *
 * @brief	Envoie les employed bees
 *
 * @author	Tous
 * @date	03/12/2018
 */

void MyAlgorithm::SendEmployedBees()
{
	//Pour chaque abeille
	for (int i = 0; i<d_setup.population_size(); i++)
	{
		//On change un parametre de maniere completement aleatoire
		int param2change = random()*(d_setup.independent_runs() - 1);
		BeePhase1(param2change, i);
	}
}

/**
 * @fn	void MyAlgorithm::SendOnlookerBees(std::vector <int> probabilite)
 *
 * @brief	Envoie les onlooker bees
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @param	probabilite	    Le vecteur de probabilité.
 */

void MyAlgorithm::SendOnlookerBees(std::vector <int> probabilite)
{
	//Pour chaque abeille
	for (int i = 0; i<d_setup.population_size(); i++)
	{
		//On change un parametre choisi par la fonction CalculateProbabilities
		BeePhase2( i,probabilite[i]);
	}
}

/**
 * @fn	void MyAlgorithm::SendScoutBees()
 *
 * @brief	Envoie les scout bees
 *
 * @author	Tous
 * @date	03/12/2018
 */

void MyAlgorithm::SendScoutBees()
{
	int maxIndex = 0;

	for (int i = 0; i < d_setup.population_size() && i != lower_cost(); i++)
	{
		if (d_solutions[i]->trial() > d_solutions[maxIndex]->trial())
		{
			maxIndex = i;
		}
	}

	if (d_solutions[maxIndex]->trial() >= d_setup.max_trial())
	{

		Solution* newsol = new Solution{ *d_solutions[maxIndex] };
		d_solutions[maxIndex]->initialize();
		double FitnessSol = newsol->SolutionFitness();

		delete d_solutions[maxIndex];
		d_solutions[maxIndex] = newsol;
		newsol = NULL;
		d_fitness_values[maxIndex].fitness = FitnessSol;

		delete newsol;
	}
}

void MyAlgorithm::BeePhase(int &param2change, int& i,Solution* &newsol)
{
    double neighbour;
	/*The parameter to be changed is determined randomly*/
	do
	{
		param2change = random()*newsol->size();
	} while (param2change < 0 || param2change >= newsol->size());

	/*A randomly chosen solution is used in producing a mutant solution of the solution i*/
	neighbour = random()*d_solutions.size();

	/*Randomly selected solution must be different from the solution i*/
	while (neighbour == i || neighbour < 0 || neighbour >= d_solutions.size())
	{
		neighbour = random()*d_solutions.size();
	}


	//La copie de l'abeille i change une de ses sources avec un mixte de sa source et celle de l'abeille voisine
	double x = newsol->position(param2change);
	double y = d_solutions[neighbour]->position(param2change);

	/*v_{ij}=x_{ij}+\phi_{ij}*(x_{kj}-x_{ij}) */
	newsol->position(param2change, x + (x - y)*(random() - 0.5) * 2);

	//La source / solution doit être dans l'intervalle du problème
	if (newsol->position(param2change) < newsol->pbm().LowerLimit())
	{
		newsol->position(param2change, newsol->pbm().LowerLimit());
	}
	if (newsol->position(param2change) > newsol->pbm().UpperLimit())
	{
		newsol->position(param2change, newsol->pbm().UpperLimit());
	}

	double FitnessSol = newsol->SolutionFitness();

	/*a greedy selection is applied between the current solution i and its mutant*/
	if (FitnessSol<d_fitness_values[i].fitness)
	{
		/*If the mutant solution is better than the current solution i, replace the solution with the mutant and reset the trial counter of solution i*/
		delete d_solutions[i];
			d_solutions[i] = newsol;

		newsol = NULL;
		d_fitness_values[i].fitness =FitnessSol;
	}
	else
	{   /*if the solution i can not be improved, increase its trial counter*/
		d_solutions[i]->incrementerTrial();
	}
}

/**
 * @fn	void MyAlgorithm::BeePhase1(int param2change, int i)
 *
 * @brief	Bee phase 1
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @param	param2change	Les parameter à changé.
 * @param	i				indice.
 */

void MyAlgorithm::BeePhase1(int param2change, int i)
{
	//L'abeille i est copié
	Solution* newsol = new Solution{ *d_solutions[i] };
    BeePhase(param2change,i,newsol);
	delete newsol;
}

/**
 * @fn	void MyAlgorithm::BeePhase2(int i,double prob)
 *
 * @brief	Bee phase 2
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @param	i   	indice.
 * @param	prob	La probabilité.
 */

void MyAlgorithm::BeePhase2(int i,double prob)
{


	int param2change;
	double neighbour;
	int t = 0;

	while (t < d_setup.population_size())
	{
		//L'abeille i est copié
		Solution* newsol = new Solution{ *d_solutions[i] };
		t++;

        /*choose a food source depending on its probability to be chosen*/
		if (random() < prob)
		{
			BeePhase(param2change,i,newsol);
		}

		i++;

		if (i == d_setup.population_size())
			i = 0;
		delete newsol;
	}

}

/**
 * @fn	ostream & operator<<(ostream & ost, const MyAlgorithm & myAlgo) { ost <<"Cout supérieur : "<< myAlgo.d_upper_cost << endl; ost <<"Cout inférieur : "<< myAlgo.d_lower_cost << endl; return ost;
 *
* @brief	Opérator de surcharge pour l'affichage.
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @param [in,out]	ost  	Le flux de sortie ost.
 * @param 		  	pbm	    Une variable contenant la liste des Cout de la classe.
 *
 * @return	flux de sortie.
 */


ostream & operator<<(ostream & ost, const MyAlgorithm & myAlgo)
{
	ost <<"Cout supérieur : "<< myAlgo.d_upper_cost << endl;// Upper fitness of individuals in population
	ost <<"Cout inférieur : "<< myAlgo.d_lower_cost << endl; // Lower fitness of individuals in population
	return ost;
}

/**
 * @fn	istream & operator>>(istream & ist, MyAlgorithm & myAlgo)
 *
 * @brief	Opérateur de surcharge d'insertion.
 *
 * @author	Tous
 * @date	03/12/2018
 *
 * @param [in,out]	ist  	Le flux d'entrée ist.
 * @param [in,out]	pbm 	Un variable contenant la liste des parametres de la classe.
 *
 * @return	flux d'entrée.
 */

istream & operator>>(istream & ist, MyAlgorithm & myAlgo)
{
	ist >> myAlgo.d_lower_cost >> myAlgo.d_upper_cost;
	return ist;
}
