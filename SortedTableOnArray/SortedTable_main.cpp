#include <iostream>

#include "t_vector_sorted.h"

int main() {
		t_vector_sorted<int, float> v;
		v.add({ 2, 4.5f });
		std::cout << v.exist(2) << std::endl;
		v.add({ 3, 4.5f });
		std::cout << v.exist(3) << std::endl;
		v.add({ 5, 4.5f });
		std::cout << v.exist(5) << std::endl;
		v.remove(5);
		std::cout << v.exist(5) << std::endl;

		Nexus<int, float> result;
		if (v.get(3, result) == true) {
				std::cout << result.data << std::endl;
		}
		std::cout << v.size() << std::endl;
		std::cout << v.exist(4) << std::endl;
		v.clear();
		std::cout << v.size() << std::endl;

		system("pause");
		return 0;
}