#include <iostream>
#include "verifierValeur.hpp"


void emprunt() {
	float montantEmprunt = 0;
	float tauxMensuel = 0;
	float remboursement = 0;

	getValue("Entrez le montant emprunte: ", montantEmprunt, 0, INFINITY);


	getValue("Entrez le taux annuel negocie en pourcentage (ex 12 pour 12%) : ", tauxMensuel, 0, 100);
	tauxMensuel /= 100; //passage en centiemes
	tauxMensuel /= 12;

	getValue("Entrez le montant rembourse mensuellement : ", remboursement, 0, INFINITY);

	int nMois = 1;
	while (remboursement < montantEmprunt) {

		montantEmprunt += montantEmprunt * tauxMensuel;
		montantEmprunt -= remboursement;
		nMois++;
	}
	if (montantEmprunt != 0) {
		nMois++;
	}
	std::cout << "Le pret sera rembourse en " << nMois;
}
