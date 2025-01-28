#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

const std::string filePath = "dictionnaire.txt";

struct EntreeDictionnaire {
	std::string mot;
	std::string natureGenre;
	std::string definition;
};

void dictionnaire() {
	std::ifstream entree(filePath);
	if (!entree.is_open()) {
		std::cout << "Impossible d'ouvrir le fichier : " << filePath << std::endl;
		return;
	}

	const int MAX_ENTRIES = 100;
	EntreeDictionnaire dictionnaire[MAX_ENTRIES];
	int count = 0;
	std::string ligne;

	while (std::getline(entree, ligne) && count < MAX_ENTRIES) {
		std::istringstream ss(ligne);
		EntreeDictionnaire nouvelleDef;
		if (std::getline(ss, nouvelleDef.mot, '\t') &&
			std::getline(ss, nouvelleDef.natureGenre, '\t') &&
			std::getline(ss, nouvelleDef.definition, '\t')) {
			dictionnaire[count++] = nouvelleDef;
		}
	}

	for (int i = 0; i < count; ++i) {
		std::cout << "Mot: " << dictionnaire[i].mot << std::endl;
		std::cout << "Nature/Genre: " << dictionnaire[i].natureGenre << std::endl;
		std::cout << "Definition: " << dictionnaire[i].definition << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
}
