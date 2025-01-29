#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

const std::string filePath = "dictionnaire.txt";
const int N_MAX_ENTREE_DIC = 100;

struct EntreeDictionnaire {
	std::string mot;
	std::string natureGenre;
	std::string definition;
};

void afficherMotDefMot(EntreeDictionnaire defMot) {
	std::cout << "Mot: " << defMot.mot << std::endl;
	std::cout << "Nature/Genre: " << defMot.natureGenre << std::endl;
	std::cout << "Definition: " << defMot.definition << std::endl;
}

EntreeDictionnaire trouverMotPlusLong(EntreeDictionnaire dictionnaire[], int dim) {
	EntreeDictionnaire plusLongMot = dictionnaire[0];
	for (int i = 1; i < dim; i++) {
		if (dictionnaire[i].mot.size() > plusLongMot.mot.size()) {
			plusLongMot = dictionnaire[i];
		}
	}
	return plusLongMot;
}

void dictionnaire() {
	std::ifstream entree(filePath);
	if (!entree.is_open()) {
		std::cout << "Impossible d'ouvrir le fichier : " << filePath << std::endl;
		return;
	}

	EntreeDictionnaire dictionnaire[N_MAX_ENTREE_DIC];
	int nEntrees = 0;
	std::string ligne;

	while (std::getline(entree, ligne) && nEntrees < N_MAX_ENTREE_DIC) {
		std::istringstream ss(ligne);
		EntreeDictionnaire nouvelleDef;
		if (std::getline(ss, nouvelleDef.mot, '\t') &&
			std::getline(ss, nouvelleDef.natureGenre, '\t') &&
			std::getline(ss, nouvelleDef.definition, '\t')) {
			dictionnaire[nEntrees++] = nouvelleDef;
		}
	}

	EntreeDictionnaire motPlusLong = trouverMotPlusLong(dictionnaire, nEntrees);
	std::cout << "Le mot le plus long de ce dictionnair est :" << std::endl;
	afficherMotDefMot(motPlusLong);
}
