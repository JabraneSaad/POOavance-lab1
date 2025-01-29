/*
Auteurs : Vincent Brunette, Saad Jabrane
Date : 29 Janvier 2025
Description du programme :
	Un programme qui saisit un tableau d’entiers de taille 10 et qui l’affiche de
	telle sorte que tous les entiers pairs se retrouvent avant les entiers impairs.
*/

#include <iostream>

void printTableau(int tableau[10]) {
	std::cout << "{";
	for (int i = 0; i < 10; i++) {
		std::cout << " " << tableau[i] << ",";
	}
	std::cout << "}";
}

void  tableauPairImpair(int tableau[10]) {

	int nombresPairs[10] = {0};
	int nombresImpairs[10] = {0};
	int nNombresPairs = 0;
	int nNombreImpairs = 0;

	for (int i = 0; i < 10; i++) {

		if ( tableau[i] % 2 == 0) {
			nombresPairs[nNombresPairs] = tableau[i];
			nNombresPairs++;
		}

		else {
			nombresImpairs[nNombreImpairs] = tableau[i];
			nNombreImpairs++;
		}
	}

	// optimisation : on a decide d'utiliser le tabelau des pair car les pairs sont deja en premier
	int j = 0;
	for (int i = nNombresPairs; i < 10; i++) {
		nombresPairs[i] = nombresImpairs[j];
		j++;
	}
	printTableau(nombresPairs);
}