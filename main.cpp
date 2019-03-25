#include "Polynom.h"
#include "menu.h"
#include "rlist.h"
#include "t_list.h"
#include "rbtree.h"
#include "t_vector.h"
#include "t_vector_sorted.h"
#include "t_hash.h"

Polynom getPolynomFromConsole() {
		std::vector<Monom> mons;
		std::string pString;

		std::cout << "\nEnter polynom\nExample: {a, b} {c, d} {e, f}\n\n\t";
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
				menu m({"Show", "Add", "Mult", "Divide", "Derivide", "Integrate", "Calculate"});
				return m.join();
		};

		auto create_add_polynom_menu = []() {
				menu m({ "First", "Second", "Both" });
				return m.join();
		};

		while (true) {
				std::string exitCode = create_polynom_menu();

				system("cls");
				std::cout << '\t' << exitCode << std::endl;
				if (exitCode == "Add") {
						auto simpleMenuExitCode = create_add_polynom_menu();

						system("cls");
						std::cout << '\t' << exitCode << std::endl;
						std::cout << '\t' << simpleMenuExitCode << std::endl;
						if (simpleMenuExitCode == "First") {
								p1 = getPolynomFromConsole();
						}
						else if (simpleMenuExitCode == "Second") {
								p2 = getPolynomFromConsole();
						}
						else if (simpleMenuExitCode == "Both") {
								p1 = getPolynomFromConsole();
								p2 = getPolynomFromConsole();
						}
						if (simpleMenuExitCode != "NULL") {
								std::cout << "Polynom(s) are added" << std::endl;
								_getch();
						}
				}
				else {
						if (exitCode == "Show") {
								std::cout << p1 << std::endl;
								std::cout << p2 << std::endl;
						}
						else if (exitCode == "Mult") {
								std::cout << p1.mult(p2) << std::endl;
						}
						else if (exitCode == "Divide") {
								std::cout << p1.div(p2) << std::endl;
						}
						else if (exitCode == "Derivide") {
								std::cout << p1.derivative() << std::endl;
						}
						else if (exitCode == "Integrate") {
								std::cout << p1.integrate() << std::endl;
						}
						else if (exitCode == "Calculate") {
								float point;
								std::cout << "Enter the point: ";
								std::cin >> point;
								std::cout << p1.calculate(point) << std::endl;
						}
						else if (exitCode == "NULL") {
								return;
						}
						_getch();
				}
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
		//createMenu();
		rbtree<std::string, int> t;
		t.add({ "DOG", 1 });
		t.add({ "-", 4 });
		Nexus<std::string, int> result;
		if (t.get("DOG", result) == true) {
				std::cout << result.data << std::endl;
		}
		
		system("pause");
		return 0;
}