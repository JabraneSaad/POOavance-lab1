#include <iostream>

bool estPair(int num) {
	return num % 2 == 0;
}

void printTableau(int tab[10]) {
	std::cout << "{";
	for (int i = 0; i < 10; i++) {
		std::cout << " " << tab[i] << ",";
	}
	std::cout << "}";
}

void  separerParite(int tableau[10]) {
	int pairs[10] = {0};
	int impairs[10] = { 0 };
	int nPairs = 0;
	int nImpairs = 0;
	for (int i = 0; i < 10; i++) {
		if (estPair(tableau[i])) {
			pairs[nPairs] = tableau[i];
			nPairs++;
		}
		else {
			impairs[nImpairs] = tableau[i];
			nImpairs++;
		}
	}
	// par optimisation on utilise le tabelau pair puisque les pairs sont deja a gauche
	int j = 0;

	for (int i = nPairs; i < 10; i++) {
		pairs[i] = impairs[j];
		j++;
	}
	//affichage de tableau
	printTableau(pairs);
}