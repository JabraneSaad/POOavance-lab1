/*
Auteurs : Vincent Brunette, Saad Jabrane
Date : 29 Janvier 2025
Description du programme :
	Un programme qui détermine la hauteur atteinte par une balle en tenant
	compte de la hauteur initiale et du nombre de rebonds.
*/
#include <iostream>
#include "verifierValeur.hpp"


const float GRAVITE = 9.81;

void hauteurDeRebond() {
	float hauteurPreRebond = 0;
	float vitessePreRebond = 0;
	float vitessePostRebond = 0;
	float coefficientRebond = 0;
	float hauteurPostRebond = 0;
	int  nRebonds = 0;

	std::cout << "Entrez le nombre de rebonds: ";
	std::cin >> nRebonds;

	getValue("Entrez la hauteur initiale de la balle: ", hauteurPreRebond, 0, INFINITY);
	getValue("Entrez le coefficient de rebonds : ", coefficientRebond, 0, 1);

	for (int i = nRebonds; i > 0; i--) {
		vitessePreRebond = sqrt(2 * GRAVITE * hauteurPreRebond);
		vitessePostRebond = coefficientRebond * vitessePreRebond;
		hauteurPostRebond = pow(vitessePostRebond, 2) / (2 * GRAVITE);

		hauteurPreRebond = hauteurPostRebond;
		vitessePreRebond = vitessePostRebond;
	}
	std::cout << "Hauteur de " << hauteurPostRebond << " apres " << nRebonds << " rebonds.";
}
