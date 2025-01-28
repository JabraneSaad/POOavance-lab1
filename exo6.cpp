#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


struct  EntreeDictionnaire {
	std::string mot;
	std::string natureGenre;
	std::string definition;
};

void dictionnaire(std::string filePath) {
	std::ifstream entree(filePath);
	if (!entree.is_open()) {
		std::cout << "Impossible d'ouvrir le fichier : " << filePath << std::endl;
		return;
	}

	std::vector<EntreeDictionnaire> dictionnaire;
	std::string ligne;

	while (std::getline(entree, ligne)) {
		std::istringstream ss(ligne);
		EntreeDictionnaire nouvelleDef;
		if (std::getline(ss, nouvelleDef.mot, '\t') &&
			std::getline(ss, nouvelleDef.natureGenre, '\t') &&
			std::getline(ss, nouvelleDef.definition, '\t')) {
			dictionnaire.push_back(nouvelleDef);
		}
	}

	for (auto& mot : dictionnaire) {
		std::cout << "Mot: " << mot.mot << std::endl;
		std::cout << "Nature/Genre: " << mot.natureGenre << std::endl;
		std::cout << "Definition: " << mot.definition << std::endl;
		std::cout << "-----------------------------------------" << std::endl;

	}

}
