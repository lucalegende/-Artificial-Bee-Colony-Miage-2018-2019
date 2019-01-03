// Artificial Bee Colony - Project.cpp : definit le point d'entree pour l'application console.
// Creer par Luca Grunenwald le 26/11/2018

#include <iostream>
#include <ctime>
#include "Solution.h"
#include "Problem.h"
#include "SetUpParams.h"
#include "MyAlgorithm.h"
#include <stdlib.h>

using namespace std;

void Verif(int &num)
{
	do
	{
		while (cin.fail() || num < 0 )
		{
			cout << "Erreur lors du choix de la fonction" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout <<  "Choix de la fonction ->";
			cin >> num;
		}
	} while (cin.fail());
}

int main()
{
    srand(time(0));
	//Programme Principal
	cout << "#####################################################" << endl;
	cout << "###             Artificial Bee Colony             ###" << endl;
	cout << "#####################################################" << endl;
	cout << endl;
	cout << "L'algorithme Artificial Bee Colony (ABC) est un algorithme d'optimisation" << endl;
	cout << "base sur le comportement d'alimentation intelligent d'un essaim d'abeilles." << endl;
	cout << "Il a ete propose par Dervis Karaboga en 2005." << endl;
	cout << endl;
	cout << endl;
	cout << "Ce Projet autour de l'algorithme Artificial Bee Colony" << endl;
	cout << "a ete cree par le groupe de Miagiste." << endl;
	cout << endl;
	cout << endl;
	cout << "#######################################################" << endl;
	cout << "###             Lancement du Programme:             ###" << endl;
	cout << "#######################################################" << endl;
	cout << endl;
	cout << "Choix du benchmark pour l'optimisation (Choissiser un numero) :" << endl;
	cout << endl;
	cout << " | 1 |	Ackley" << endl;
	cout << " | 2 |	Rastigrin" << endl;
	cout << " | 3 |	Rosenbrock" << endl;
	cout << " | 4 |	Schwefel" << endl;
	cout << " | 5 |	Schaffer" << endl;
	cout << " | 6 |	Weierstrass" << endl;
	cout << endl;

	//Choix de la fonction
	int numFonct;

	cout << "Choix de la fonction -> ";
	cin >> numFonct;

	//verifie si  c'est un numero
	do
	{
		while (cin.fail() || numFonct < 1 || numFonct >6)
		{
			cout << "Erreur lors du choix de la fonction" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Choix de la fonction -> ";
			cin >> numFonct;
		}
	} while (cin.fail());

	cout << endl;
	cout << "            flux de sortie.    Choix des parametres pour l'optimisation :" << endl;
	cout << endl;

	int nbExec, nbItrs, population, dim;
	cout << "Nombre d'executions : ";
	cin >> nbExec;
	Verif(nbExec);
	cout << "Nombre total d'appel de la fonction objectif : ";
	cin >> nbItrs;
	Verif(nbItrs);
	cout << "Nombre d'individus dans la population : ";
	cin >> population;
	Verif(population);
	cout << "Dimension du probleme pour chaque particle : ";
	cin >> dim;
	Verif(population);

	//Parametre pour la validation :
	//SetUpParams Param{ 30, 50000, 40, 20, 100 };
	SetUpParams Param( (unsigned int)nbExec,(unsigned int)nbItrs,(unsigned int)population,(unsigned int)dim, 100);

	//Initialisation du Probleme
	//Problem P(numFonct, 20);
	Problem P( numFonct, dim );

	//Mise en place de L'algorithm d'optimisation
	MyAlgorithm Optim( P, Param );

    //Affichage du code principal
    cout << endl;
    cout << "######################################################" << endl;
	cout << "###             LANCEMENT DU PROGRAMME             ###" << endl;
	cout << "######################################################" << endl;
	cout << endl;

	//Lancement de l'algorithme
	Optim.evolution();

	//Appuyer sur une touche pour fermer
	return 0;
}

