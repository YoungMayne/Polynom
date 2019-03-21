#include "rlist.h"
#include "rlist.cpp"

int main() {
		rlist<int> list;
		list.push(1);
		std::cout << list.pop() << std::endl;
		list.push(2);
		std::cout << list.pop() << std::endl;
		list.push(2);
		std::cout << list.pop() << std::endl;

		system("pause");
		return 0;
}