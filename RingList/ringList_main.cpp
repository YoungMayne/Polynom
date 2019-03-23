#include <ctime>

#include "rlist.h"
#include "../Polynom/Polynom.cpp"


Polynom get_polynom_randomly(int size) {	
		std::vector<Monom> mons;

		for (int i = 0; i < size; ++i) {
				Monom temp;
				temp.coefficient = rand() % 20 - 10;
				temp.degree = rand() % 11;
				mons.push_back(temp);
		}

		return Polynom(mons);
}

int main() {
		srand(time(0));
		rlist<Polynom> list;

		for(int i = 0; i < 100; ++i) {
				int size = rand() % 101;
				list.push(get_polynom_randomly(size));
		}
		while (!list.empty()) {
				std::cout << list.get() << std::endl;
				list.pop();
		}

		list.clear();
		std::cout << "cleared!" << std::endl;

		system("pause");
		return 0;
}
