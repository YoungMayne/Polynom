#include "Polynom.h"
#include "menu.h"
#include "rlist.h"
#include "t_list.h"
#include "t_vector.h"
#include "t_vector_sorted.h"

Polynom getPolynomFromConsole() {
		std::vector<Monom> mons;
		std::string pString;

		std::cout << "\nEnter polynom\nExample: {a, b} {c, d} {e, f}\n\n";
		std::getline(std::cin, pString);

		float coef = 1;
		float degree = 1;
		std::string number;

		for (const auto &c : pString) {
				if (c == ' ' || c == '{') {
						continue;
				}
				else if (c == ',') {
						coef = atof(number.c_str());
						number.clear();
				}
				else if (c == '}') {
						degree = atof(number.c_str());
						mons.push_back(Monom{ coef, degree });
						number.clear();
				}
				else {
						number += c;
				}
		}

		return Polynom(mons);
}

std::string createDefaultMenu(int remove = -1) {
		menu m;
		std::vector<std::string> items({"Add", "Remove", "Check",  "Get Element", "Clear"});
		if (remove > -1) {
				items.erase(items.begin() + remove);
		}
		m.add(items);

		auto exitCode = m.join();
		return exitCode;
}

void Polynom_menu() {
		Polynom p1;
		Polynom p2;

		auto create_polynom_menu = []() {
				menu m({"Show existing polynoms", "Add polynoms for work", "Mult existing polynoms", "Divide existing polynoms","Derivide first polynom", "Integrate first polynom"});
				return m.join();
		};

		while (true) {
				std::string exitCode = create_polynom_menu();

				system("cls");
				std::cout << '\t' << exitCode << std::endl;
				if (exitCode == "Show existing polynoms") {
						std::cout << p1 << std::endl;
						std::cout << p2 << std::endl;
				}
				else if (exitCode == "Add polynoms for work") {
						p1 = getPolynomFromConsole();
						p2 = getPolynomFromConsole();

						std::cout << "Polynoms are added" << std::endl;
				}
				else if (exitCode == "Mult existing polynoms") {
						std::cout << p1.mult(p2) << std::endl;
				}
				else if (exitCode == "Divide existing polynoms") {
						std::cout << p1.div(p2) << std::endl;
				}
				else if (exitCode == "Derivide first polynom") {
						std::cout << p1.derivative() << std::endl;
				}
				else if (exitCode == "Integrate first polynom") {
						std::cout << p1.integrate() << std::endl;
				}
				else if (exitCode == "NULL") {
						return;
				}
				_getch();
		}
}

void RingList_menu() {
		rlist<Polynom> r;

		while (true) {
				std::string exitCode = createDefaultMenu(2);

				system("cls");
				std::cout << '\t' << exitCode << std::endl;
				if (exitCode == "Add") {
						Polynom temp = getPolynomFromConsole();
						r.push(temp);
						std::cout << "Added " << temp << std::endl;				
				}
				else if (exitCode == "Remove") {			
						std::cout << "\n\tTop element removed" << std::endl;

						r.pop();											
				}
				else if (exitCode == "Get Element") {
						if (r.empty()) {
								std::cout << "\n\tList is empty" << std::endl;
						}
						else {
								std::cout << r.get() << std::endl;
						}
				}
				else if (exitCode == "Clear") {
						r.clear();
						std::cout << "\n\tList is cleared!" << std::endl;
				}
				else if (exitCode == "NULL") {
						return;
				}
				_getch();
		}
}

void LinearArrayTable_menu() {
		t_vector<std::string, Polynom> t;

		while (true) {
				std::string exitCode = createDefaultMenu();

				system("cls");
				std::cout << '\t' << exitCode << std::endl;
				if (exitCode == "Add") {
						std::string key;
						std::cout << "Enter key: ";
						std::getline(std::cin, key);
						Polynom temp = getPolynomFromConsole();
						if (t.add({ key, temp }) == true) {
								std::cout << "Added " << temp << std::endl;
						}
						else {
								std::cout << "Polynom is already exists" << std::endl;
						}
				}
				else if (exitCode == "Remove") {
						std::string key;
						std::cout << "Enter key: ";
						std::getline(std::cin, key);

						t.remove(key);
						std::cout << "\n\tPolynom removed" << std::endl;
				}
				else if (exitCode == "Check") {
						std::string key;
						std::cout << "Enter key: ";
						std::getline(std::cin, key);

						if (t.exist(key) == true) {
								std::cout << "\n\t Polynom exists" << std::endl;
						}
						else {
								std::cout << "\n\t Polynom does not exist" << std::endl;
						}
				}
				else if (exitCode == "Get Element") {
						std::string key;
						std::cout << "Enter key: ";
						std::getline(std::cin, key);

						Nexus<std::string, Polynom> temp;
						if (t.get(key, temp) == true) {
								std::cout << "\n\t" <<  temp.data << std::endl;
						}
						else {
								std::cout << "\n\t Polynom does not exist" << std::endl;
						}
				}
				else if (exitCode == "Clear") {
						t.clear();
						std::cout << "Table is cleared" << std::endl;
				}
				else if (exitCode == "NULL") {
						return;
				}
				_getch();
		}
}

void LinearListTable_menu() {
		t_list<std::string, Polynom> t;

		while (true) {
				std::string exitCode = createDefaultMenu();

				system("cls");
				std::cout << '\t' << exitCode << std::endl;
				if (exitCode == "Add") {
						std::string key;
						std::cout << "Enter key: ";
						std::getline(std::cin, key);
						Polynom temp = getPolynomFromConsole();
						if (t.add({ key, temp }) == true) {
								std::cout << "Added " << temp << std::endl;
						}
						else {
								std::cout << "Polynom is already exists" << std::endl;
						}
				}
				else if (exitCode == "Remove") {
						std::string key;
						std::cout << "Enter key: ";
						std::getline(std::cin, key);

						t.remove(key);
						std::cout << "\n\tPolynom removed" << std::endl;
				}
				else if (exitCode == "Check") {
						std::string key;
						std::cout << "Enter key: ";
						std::getline(std::cin, key);

						if (t.exist(key) == true) {
								std::cout << "\n\t Polynom exists" << std::endl;
						}
						else {
								std::cout << "\n\t Polynom does not exist" << std::endl;
						}
				}
				else if (exitCode == "Get Element") {
						std::string key;
						std::cout << "Enter key: ";
						std::getline(std::cin, key);

						Nexus<std::string, Polynom> temp;
						if (t.get(key, temp) == true) {
								std::cout << "\n\t" << temp.data << std::endl;
						}
						else {
								std::cout << "\n\t Polynom does not exist" << std::endl;
						}
				}
				else if (exitCode == "Clear") {
						t.clear();
						std::cout << "Table is cleared" << std::endl;
				}
				else if (exitCode == "NULL") {
						return;
				}
				_getch();
		}
}

void SortedArrayTable_menu() {
		t_vector_sorted<std::string, Polynom> t;

		while (true) {
				std::string exitCode = createDefaultMenu();

				system("cls");
				std::cout << '\t' << exitCode << std::endl;
				if (exitCode == "Add") {
						std::string key;
						std::cout << "Enter key: ";
						std::getline(std::cin, key);
						Polynom temp = getPolynomFromConsole();
						if (t.add({ key, temp }) == true) {
								std::cout << "Added " << temp << std::endl;
						}
						else {
								std::cout << "Polynom is already exists" << std::endl;
						}
				}
				else if (exitCode == "Remove") {
						std::string key;
						std::cout << "Enter key: ";
						std::getline(std::cin, key);

						t.remove(key);
						std::cout << "\n\tPolynom removed" << std::endl;
				}
				else if (exitCode == "Check") {
						std::string key;
						std::cout << "Enter key: ";
						std::getline(std::cin, key);

						if (t.exist(key) == true) {
								std::cout << "\n\t Polynom exists" << std::endl;
						}
						else {
								std::cout << "\n\t Polynom does not exist" << std::endl;
						}
				}
				else if (exitCode == "Get Element") {
						std::string key;
						std::cout << "Enter key: ";
						std::getline(std::cin, key);

						Nexus<std::string, Polynom> temp;
						if (t.get(key, temp) == true) {
								std::cout << "\n\t" << temp.data << std::endl;
						}
						else {
								std::cout << "\n\t Polynom does not exist" << std::endl;
						}
				}
				else if (exitCode == "Clear") {
						t.clear();
						std::cout << "Table is cleared" << std::endl;
				}
				else if (exitCode == "NULL") {
						return;
				}
				_getch();
		}
}

void createMenu() {
		menu m;

		m.add({ "Polynom", "Ring List", "Linear Array Table", "Linear List Table", "Sorted Array Table", "Tree", "Hash Table" });
		while (true) {
				std::string exitCode = m.join();

				if (exitCode == "Polynom") {
						Polynom_menu();
				}
				else if (exitCode == "Ring List") {
						RingList_menu();
				}
				else if (exitCode == "Linear Array Table") {
						LinearArrayTable_menu();
				}
				else if (exitCode == "Linear List Table") {
						LinearListTable_menu();
				}
				else if (exitCode == "Sorted Array Table") {
						SortedArrayTable_menu();
				}
				else if (exitCode == "Tree") {

				}
				else if (exitCode == "Hash Table") {

				}
				else if (exitCode == "NULL") {
						return;
				}
		}
}

int main() {
		createMenu();

		return 0;
}