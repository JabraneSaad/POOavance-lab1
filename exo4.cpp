#include <iostream>
#include <random>
#include <iomanip>

float genererNombre() {
	std::random_device graine; 
	std::mt19937 gen(graine()); 
	std::uniform_real_distribution<> dis(-1.0, 1.0);

	return static_cast<float>(dis(gen));
	//ref: https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
}

struct Point {
	double x;
	double y;
};

bool pointDansCercle(Point point) {
	return ((pow(point.x, 2) + pow(point.y, 2)) < 1);
}

void approximationPi() {
	Point point{ 0,0 };
	double nPointsDansCercle = 0;
	int nIterations = 0;
	std::cout << "Entrez le nombre d'iterations pour l'approximation de Pi:";
	std::cin >> nIterations;

	for (int i = 0; i < nIterations; i++) {
		point.x = genererNombre();
		point.y = genererNombre();
		if (pointDansCercle(point)) {
			nPointsDansCercle++;
		}
	}
	double pi = 4.0 * nPointsDansCercle/ nIterations;
	std::cout << std::fixed << std::setprecision(6);
	//ref : https://en.cppreference.com/w/cpp/io/manip/fixed
	// ref : https://en.cppreference.com/w/cpp/io/manip/setprecision
	std::cout << pi;
}