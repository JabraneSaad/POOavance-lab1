

#include <iostream>
#include <random>

// TODO: faire une fonction qui genere un point x et y entre -1 et 1
float genererNombre() {
	std::random_device rd;  // Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(-1.0, 1.0);

	//ref: https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
	return static_cast<float>(dis(gen));
}

bool pointDansCercle(double x, double y) {
	return ((pow(x, 2) + pow(y, 2)) < 1);
}

void approximationPi() {
	double x = 0;
	double y = 0;
	int nPointsDansCercle = 0;
	int nIterations = 0;
	std::cout << "Entrez le nombre d'iterations pour l'approximation de Pi:";
	std::cin >> nIterations;

	for (int i = 0; i < nIterations; i++) {
		x = genererNombre();
		y = genererNombre();
		if (pointDansCercle(x, y)) {
			nPointsDansCercle++;
		}
	}
	double pi = 4.0 * static_cast<double>(nPointsDansCercle) / nIterations;
	std::cout << std::fixed;
	std::cout.precision(6);
	std::cout <<  pi;
}
