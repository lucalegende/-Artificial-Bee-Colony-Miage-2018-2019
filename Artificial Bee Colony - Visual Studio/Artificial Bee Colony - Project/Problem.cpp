#include "stdafx.h"
#include "Problem.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/**
 * @fn	Problem::Problem()
 *
 * @brief	Constructeur par defaut
 *
 * @author	ELYOUBI Rania
 * @date	03/12/2018
 */

Problem::Problem()
{
	d_lowerLimit = -32.768;
	d_upperLimit = 32.768;
	d_dimension = 30;
	d_fonction = Ackley;
}

/**
 * @fn	Problem::Problem(int num, int dim)
 *
 * @brief	Constructeur
 *
 * @author	ELYOUBI Rania
 * @date	03/12/2018
 *
 * @param	num	Numéro du benchmark.
 * @param	dim	Dimension de la solution.
 */

Problem::Problem(int num, int dim) :
	d_dimension{ dim }
{
	LimitBounds();
	switch (num)
	{
		//Fonction Ackley
	case 1:
		/*d_lowerLimit = -32.768;
		d_upperLimit = 32.768;*/
		d_fonction = Ackley;
		break;

		//Fonction Rastrigin
	case 2:
		/*d_lowerLimit = -5.12;
		d_upperLimit = 5.12;*/
		d_fonction = Rastrigin;
		break;

		//Fonction Rosenbrock
	case 3:
		/*d_lowerLimit = -5;
		d_upperLimit = 10;*/
		d_fonction = Rosenbrock;
		break;

		//Fonction Schwefel
	case 4:
		/*d_lowerLimit = -500;
		d_upperLimit = 500;*/
		d_fonction = Schwefel;
		break;

		//Fonction Schaffer
	case 5:
		/*d_lowerLimit = -100;
		d_upperLimit = 100;*/
		d_fonction = Schaffer;
		break;

		//Fonction Weierstrass
	case 6:
		/*d_lowerLimit = -10;
		d_upperLimit = 10;*/
		d_fonction = Weierstrass;
		break;

	default:
		/*d_lowerLimit = -100;
		d_upperLimit = 100;*/
		d_fonction = sphere;
		break;
	}
}

/**
 * @fn	Problem::~Problem()
 *
 * @brief	Destructeur
 *
 * @author	ELYOUBI Rania
 * @date	03/12/2018
 */

Problem::~Problem()
{
}

void Problem::LimitBounds()
{
	cout << endl;
	cout << "                Choix des limite superieur et inferieur :" << endl;
	cout << endl;
	cout << "Entrer la limite inferieur du Benchmark : ";
	cin >> d_lowerLimit;
	VerificationLimit(d_lowerLimit);
	cout << "Entrer la limite superieur du Benchmark : ";
	cin >> d_upperLimit;
	VerificationLimit(d_upperLimit);
}

void Problem::VerificationLimit(double &limit)
{
	do
	{
		while (cin.fail())
		{
			cout << "Erreur lors du choix de la limit" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Choix de la limite -> ";
			cin >> limit;
		}
	} while (cin.fail());
}

/**
 * @fn	Problem & Problem::operator=(const Problem & pbm)
 *
 * @brief	Opérateur de surcharge affectation (=)
 *
 * @author	ELYOUBI Rania
 * @date	03/12/2018
 *
 * @param	Variable Problème.
 *
 * @return	Une copie superficielle de cet objet.
 */

Problem & Problem::operator=(const Problem & pbm)
{
	d_lowerLimit = pbm.LowerLimit();
	d_upperLimit = pbm.UpperLimit();
	d_dimension = pbm.dimension();
	d_fonction = pbm.fonction();
	return *this;
}

/**
 * @fn	bool Problem::operator==(const Problem & pbm) const
 *
 * @brief	Opérateur de surcharge d'egalité (==)
 *
 * @author	ELYOUBI Rania
 * @date	03/12/2018
 *
 * @param	Variable Problème.
 *
 * @return	Une copie superficielle de cet objet.
 */

bool Problem::operator==(const Problem & pbm) const
{
	return d_lowerLimit == pbm.LowerLimit() &&
		d_upperLimit == pbm.UpperLimit() &&
		d_dimension == pbm.dimension() &&
		d_fonction == pbm.fonction();
}

/**
 * @fn	bool Problem::operator!=(const Problem & pbm) const
 *
 * @brief	Opérateur de surcharge d'inégalité (!=)
 *
 * @author	ELYOUBI Rania
 * @date	03/12/2018
 *
 * @param	Variable Problème.
 *
 * @return	Vrai si le paramètre n'est pas considéré equivalent.
 */

bool Problem::operator!=(const Problem & pbm) const
{
	return d_lowerLimit != pbm.LowerLimit() ||
		d_upperLimit != pbm.UpperLimit() ||
		d_dimension != pbm.dimension() ||
		d_fonction != pbm.fonction();
}

/**
 * @fn	double Problem::LowerLimit() const
 *
 * @brief	Limite inférieur.
 *
 * @author	ELYOUBI Rania
 * @date	03/12/2018
 *
 * @return	Un double.
 */

double Problem::LowerLimit() const
{
	return d_lowerLimit;
}

/**
 * @fn	double Problem::UpperLimit() const
 *
 * @brief	Limite supérieur.
 *
 * @author	ELYOUBI Rania
 * @date	03/12/2018
 *
 * @return	Un double.
 */

double Problem::UpperLimit() const
{
	return d_upperLimit;
}

/**
 * @fn	int Problem::dimension() const
 *
 * @brief	Recupère la taille de la dimension.
 *
 * @author	ELYOUBI Rania
 * @date	03/12/2018
 *
 * @return	Un entier.
 */

int Problem::dimension() const
{
	return d_dimension;
}

/**
 * @fn	Fonction Problem::fonction() const
 *
 * @brief	Recupère la fonction.
 *
 * @author	ELYOUBI Rania
 * @date	03/12/2018
 *
 * @return	Une fonction.
 */

Fonction Problem::fonction() const
{
	return d_fonction;
}

/**
 * @fn	ostream & operator<<(ostream & ost, const Problem & pbm) { ost << " : " << pbm.LowerLimit(); ost << " : " << pbm.UpperLimit(); ost << " : " << pbm.dimension(); return ost;
 *
 * @brief	Opérator de surcharge pour l'affichage
 *
 * @author	ELYOUBI Rania
 * @date	03/12/2018
 *
 * @param [in,out]	ost  	Le flux de sortie ost.
 * @param 		  	pbm	    Une variable contenant la liste des parametres de la classe.
 *
 * @return	flux de sortie.
 */

ostream & operator<<(ostream & ost, const Problem & pbm)
{
	ost << "  : " << pbm.LowerLimit();
	ost << "  : " << pbm.UpperLimit();
	ost << "  : " << pbm.dimension();
	return ost;
}

/**
 * @fn	istream & operator>>(istream & ist, Problem & pbm)
 *
 * @brief	Opérateur de surcharge pour l'insertion
 *
 * @author	ELYOUBI Rania
 * @date	03/12/2018
 *
 * @param [in,out]	ist  	Le flux d'entrée ist.
 * @param [in,out]	pbm 	Un variable contenant la liste des parametres de la classe.
 *
 * @return	flux d'entrée.
 */

istream & operator>>(istream & ist, Problem & pbm)
{
	ist >> pbm.d_lowerLimit >> pbm.d_upperLimit >> pbm.d_dimension;
	return ist;
}

