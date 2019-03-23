#include <iostream>
#include <ctime>

#include "LLOAA.cpp"
#include "../Polynom/Polynom.cpp"


Polynom get_polynom_randomly(int size) {
		std::vector<Monom> mons;

		for (int i = 0; i < size; ++i) {
				Monom temp;
				temp.coefficient = rand() % 20 + 1;
				temp.degree = rand() % 101 + 1;
				mons.push_back(temp);
		}

		return Polynom(mons);
}

int main() {
			srand(time(0));
			LLOAA<float, Polynom> l_table;
			Nexus<float, Polynom> result;

			for (int i = 0; i < 100; ++i) {
					int size = rand() % 10;
					Polynom temp = get_polynom_randomly(size);					
					l_table.add({ temp.degree(), temp });
			}

			std::cout << "size: " << l_table.size() << std::endl;

			int s = 0;
			while(s != 10) {
					float key = rand() % 101 + 1;
					if (l_table.get(key, result) == true) {
							std::cout << result.data << std::endl;
							l_table.remove(key);
							s += 1;
					}
			}

			std::cout << "size: " << l_table.size() << std::endl;
			l_table.clear();
			std::cout << "size: " << l_table.size() << std::endl;

		system("pause");
		return 0;
}