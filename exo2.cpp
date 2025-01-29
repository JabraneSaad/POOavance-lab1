#include <iostream>
#include "verifierValeur.hpp"


void emprunt() {
	float montantEmprunt = 0;
	float tauxMensuel = 0;
	float montantRemboursement = 0;

	getValue("Entrez le montant emprunte: ", montantEmprunt, 0, INFINITY);
	getValue("Entrez le taux annuel : ", tauxMensuel, 0, 100);

	tauxMensuel /= 100; //passage du pourcentage en centiemes
	tauxMensuel /= 12;

	getValue("Entrez le paiement mensuel : ", montantRemboursement, 0, INFINITY);

	if (montantRemboursement <= (montantEmprunt * tauxMensuel)) {
		std::cout << "Le pret ne sera jamais rembourse.";
	}
	else {
		int nMois = 1;
		while (montantRemboursement < montantEmprunt) {

			montantEmprunt += montantEmprunt * tauxMensuel;
			montantEmprunt -= montantRemboursement;
			nMois++;
		}
		if (montantEmprunt != 0) {
			nMois++;
		}
		std::cout << "Le pret sera rembourse en " << nMois << " mois.";

	}
}
