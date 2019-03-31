#include "Polynom.h"
#include "menu.h"
#include "rlist.h"
#include "t_list.h"
#include "rbtree.h"
#include "t_vector.h"
#include "t_vector_sorted.h"
#include "t_hash.h"

Polynom getPolynomFromConsole() {
		std::string pString;

		std::cout << "\nEnter polynom\nExample: x^2y + xy + z\n\n\t";
		std::getline(std::cin, pString);

		return Polynom(pString);
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
				menu m({ "Show", "Add", "Mult", "Divide", "Derivide", "Integrate", "Calculate" });
				return m.join();
		};

		auto create_add_polynom_menu = []() {
				menu m({ "First", "Second", "Both" });
				return m.join();
		};

		auto create_d_menu = []() {
				menu m({ "dx", "dy", "dz" });
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
				else if (exitCode == "Derivide") {
						std::string eCode = create_d_menu();
						system("cls");
						std::cout << '\t' << exitCode << std::endl;
						std::cout << '\t' << eCode << std::endl << std::endl;
						std::cout << '(' << p1.to_str() << ")'" << eCode << " = ";
						if (eCode == "dx") {
								std::cout << p1.d(x).to_str() << std::endl;
						}
						if (eCode == "dy") {
								std::cout << p1.d(y).to_str() << std::endl;
						}
						if (eCode == "dz") {
								std::cout << p1.d(z).to_str() << std::endl;
						}
						if (eCode != "NULL") {
								_getch();
						}
				}
				else if (exitCode == "Integrate") {
						std::string eCode = create_d_menu();
						system("cls");
						std::cout << '\t' << exitCode << std::endl;
						std::cout << '(' << p1.to_str() << ')' << eCode << " = ";
						if (eCode == "dx") {
								std::cout << p1.Id(x).to_str() << std::endl;
						}
						if (eCode == "dy") {
								std::cout << p1.Id(y).to_str() << std::endl;
						}
						if (eCode == "dz") {
								std::cout << p1.Id(z).to_str() << std::endl;
						}
						if (eCode != "NULL") {
								_getch();
						}
				}
				else {
						if (exitCode == "Show") {
								std::cout << p1.to_str() << std::endl;
								std::cout << p2.to_str() << std::endl;
						}
						else if (exitCode == "Mult") {
								std::cout << p1.to_str() << std::endl;
								std::cout << p2.to_str() << std::endl;
								std::cout << "\nmult: " << p1.mult(p2).to_str() << std::endl;
						}
						else if (exitCode == "Divide") {
								std::cout << p1.to_str() << std::endl;
								std::cout << p2.to_str() << std::endl;
								std::cout << "\ndivide: " << p1.div(p2).to_str() << std::endl;
						}

						else if (exitCode == "Calculate") {
								int pointX;
								int pointY;
								int pointZ;
								std::cout << "Enter the point x: ";
								std::cin >> pointX;
								std::cout << "Enter the point y: ";
								std::cin >> pointY;
								std::cout << "Enter the point z: ";
								std::cin >> pointZ;
								std::cout << std::endl << p1.to_str() << std::endl;
								std::cout << "calc(" << pointX << ',' << pointY << ',' << pointZ << "): " << p1.calculate(pointX, pointY, pointZ) << std::endl;
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
						std::cout << "Added " << temp.to_str() << std::endl;				
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
								std::cout << r.get().to_str() << std::endl;
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
								std::cout << "Added " << temp.to_str() << std::endl;
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
								std::cout << "\n\t" <<  temp.data.to_str() << std::endl;
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
								std::cout << "Added " << temp.to_str() << std::endl;
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
								std::cout << "\n\t" << temp.data.to_str() << std::endl;
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
								std::cout << "Added " << temp.to_str() << std::endl;
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
								std::cout << "\n\t" << temp.data.to_str() << std::endl;
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