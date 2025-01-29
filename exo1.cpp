#include <iostream>
#include <cmath>


int verifierParite(int nombre, int diviseur) {
	if (nombre % 2 == 0) {
		return 2;
	}
	return diviseur;
}

int trouverDiviseurImpair(int nombre, int diviseur) {
	int borneRechercheDiviseur = int(sqrt(nombre)) + 1;
	for (int i = 3; i < borneRechercheDiviseur; i++) {
		if (nombre % i == 0) {
			return i;
		}
	}
	return diviseur;
}

void nombrePremier() {
	int diviseur = 0;
	int nombre = 0;
	std::cout << "Entrer un nombre a verifier : ";
	std::cin >> nombre;
	diviseur = trouverDiviseurImpair(nombre, diviseur);
	diviseur = verifierParite(nombre, diviseur);

	if (diviseur != 0) {
		std::cout << "Ce nombre n'est pas premier car il est divisible par " << diviseur << std::endl;
	}
	else {
		std::cout << "Ce nombre est premier.";
	}
}
