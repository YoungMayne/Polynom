#include "rlist.cpp"
#include "../Polynom/Polynom.cpp"

int main() {
		rlist<Polynom> list;
		Polynom p({ { 2, 2 } ,{ 3, 1 } ,{ -4, 2 } });
		list.push(p);
		std::cout << list.pop() << std::endl;

		system("pause");
		return 0;
}