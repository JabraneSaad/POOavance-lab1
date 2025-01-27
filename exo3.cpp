#include <iostream>
#include "verifierValeur.hpp"


const float GRAVITE = 9.81f;

// 3-Rebonds
float calcVitessePreRebond(float hauteurPreRebond) {
	return sqrt(2 * GRAVITE * hauteurPreRebond);
}

float calcVitessePostRebond(float vitessePreRebond, float coefficientRebonds) {
	return (coefficientRebonds * vitessePreRebond);
}

float calcHauteurPostRebond(double vitessePostRebond) {
	return static_cast<float>(pow(vitessePostRebond, 2) / (2 * GRAVITE)); // pour fix l erreur de trunking de double a float
}

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
		vitessePreRebond = calcVitessePreRebond(hauteurPreRebond);
		vitessePostRebond = calcVitessePostRebond(vitessePreRebond, coefficientRebond);
		hauteurPostRebond = calcHauteurPostRebond(vitessePostRebond);

		hauteurPreRebond = hauteurPostRebond;
		vitessePreRebond = vitessePostRebond;
	}
	std::cout << "Hauteur de " << hauteurPostRebond << " apres " << nRebonds << " rebonds.";
}
