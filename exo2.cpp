/*
Auteurs : Vincent Brunette, Saad Jabrane
Date : 29 Janvier 2025
Description du programme :
	Écrivez un programme qui lit du clavier un nombre entier, puis détermine si ce
	nombre est premier ou non
*/

#include <iostream>
#include "verifierValeur.hpp"


void emprunt() {
	float dette = 0;
	float tauxInteretMensuel = 0;
	float remboursement = 0;
	float sommeInterets = 0;

	getValue("Entrez le montant emprunte: ", dette, 0, INFINITY);
	getValue("Entrez le taux annuel : ", tauxInteretMensuel, 0, 100);

	tauxInteretMensuel /= 100; //passage du pourcentage en centiemes
	tauxInteretMensuel /= 12;

	getValue("Entrez le paiement mensuel : ", remboursement, 0, INFINITY);

	if (remboursement <= (dette * tauxInteretMensuel)) {
		std::cout << "Le pret ne sera jamais rembourse.";
	}
	else {
		int nMois = 1;
		float interetsMensuels = 0;
		while (remboursement < dette) {
			interetsMensuels = dette * tauxInteretMensuel;
			sommeInterets += interetsMensuels;
			dette += interetsMensuels;
			dette -= remboursement;
			nMois++;
		}
		if (dette != 0) {
			nMois++;
		}
		std::cout << "Le pret sera rembourse en " << nMois << " mois." << std::endl;
		std::cout << "Le preteur percevra " << sommeInterets << " en interets." << std::endl;

	}
}
