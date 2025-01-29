/*
Auteurs : Vincent Brunette, Saad Jabrane
Date : 29 Janvier 2025
Description du programme :
	Un programme pour verifier la validite du nombre entree par l'utilisateur
	programme utilisee par emprunt() et hauteurDeRebond()
*/
#include <iostream>

void verificationValeur(float& valeur, float min, float max) {
	while (valeur > max || valeur < min) {
		std::cout << "La valeur doit etre entre " << min << " et " << max << "." << std::endl;
		std::cout << "Veuillez entrer une valeur respectant les conditions : ";
		std::cin >> valeur;
	}
}

void getValue(std::string message, float& value, float min, float max) {
	std::cout << message;
	std::cin >> value;
	verificationValeur(value, min, max);
}