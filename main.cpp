#include "Polynom.h"

int main() {
		uLab::Polynom p1({ {1, 3}, { 2, 5},  {3, 6}, {-3, 6} });
		uLab::Polynom p2({ {1, 1}, {-4, 5}, {5, 5}, {2, 3 } });

		std::cout << p1 << std::endl;
		std::cout << p2 << std::endl;
		std::cout << p1.mult(p2) << std::endl;
		std::cout << p1.div(p2) << std::endl;
		std::cout << p1.derivative(6) << std::endl;
		std::cout << p1.integrate() << std::endl;
		std::cout << p1.calculate(5) << std::endl;

		system("pause");
		return 0;
}