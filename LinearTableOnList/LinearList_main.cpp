#include <iostream>
#include "t_list.h"
#include "../Polynom/Polynom.cpp"

int main() {
		t_list<int, Polynom> t({ 1, {{{2, 3}, {1, 1}, {-5, 3}}} });
		t.add({ 1, {{{ 2, 3 },{ 1, 1 },{ -5, 3 } }} });
		Nexus<int, Polynom> result;
		if (t.get(1, result)) {
				std::cout << result.data << std::endl;
		}
		t.remove(1);

		system("pause");
		return 0;
}