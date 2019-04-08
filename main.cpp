#include "Polynom.h"
#include "rlist.h"
#include "t_list.h"
#include "rbtree.h"
#include "t_vector.h"
#include "t_vector_sorted.h"
#include "t_hash2.h"
#include "t_hash.h"
#include "t_hash2.h"

#include <algorithm>
#include <string>
#include <stack>
#include <locale>

t_list<std::string, Polynom> table_list;
rbtree<std::string, Polynom> tree;
t_vector<std::string, Polynom> vector;
t_vector_sorted<std::string, Polynom> vector_sorted;
hash_table<Polynom> hash;
hash_table2<Polynom> hash2;

int prec(char c) {
		if (c == '*' || c == '/')
				return 2;
		else if (c == '+' || c == '-')
				return 1;
		else
				return -1;
}

auto pop(std::stack<char> &from) {
		auto result = from.top();
		from.pop();
		return result;
}

std::string get_postfix(std::string s) {
		std::stack<char> stack;
		stack.push('!');
		std::string postfix;

		auto split = [&postfix]() {
				if (postfix.empty() == false && postfix.back() != '_') {
						postfix.push_back('_');
				}
		};

		for (int i = 0; i < s.length(); i++) {
				if (s[i] == ' ') {
						continue;
				}
				if (isalpha(s[i]) || isdigit(s[i])) {
						postfix += s[i];
				}
				else if (s[i] == '(') {
						stack.push('(');
				}
				else if (s[i] == ')') {
						while (stack.top() != '!' && stack.top() != '(') {
								split();
								postfix += pop(stack);
								split();
						}
						if (stack.top() == '(') {
								stack.pop();
						}
				}
				else {
						while (stack.top() != '!' && prec(s[i]) <= prec(stack.top())) {
								split();
								postfix += pop(stack);
								split();
						}
						stack.push(s[i]);
						split();
				}

		}
		while (stack.top() != '!') {
				split();
				postfix += pop(stack);
				split();
		}

		return postfix;
}

void add(const Nexus<std::string, Polynom> &pol) {
		if (table_list.add(pol) == false || tree.add(pol) == false || vector.add(pol) == false || vector_sorted.add(pol) == false || hash.add({ pol.key, pol.data }) == false || hash2.add({ pol.key, pol.data }) == false) {
				std::cout << "\tTables already have this name" << std::endl;
		}
		else {
				std::cout << "\tAdded successfuly" << std::endl;
		}
}

void calculate(const std::string &postfix) {
		std::string name;
		std::stack<Polynom> stack;

		for (const auto &c : postfix) {
				if (c >= 'a' && c <= 'z') {
						name += c;
				}
				else if (c == '_' && name.empty() == false) {
						Nexus<std::string, Polynom> result;
						if (vector.get(name, result) == true) {
								stack.push(result.data);
						}
						else {
								std::cout << "incorrect name" << std::endl;
								return;
						}
						name.clear();
				}
				else if (c == '+' || c == '-' || c == '*' || c == '/') {
						Polynom p1 = stack.top();
						stack.pop();
						Polynom p2 = stack.top();
						stack.pop();

						switch (c) {
						case '+': stack.push(p2.add(p1));
								break;
						case '-': stack.push(p2.sub(p1));
								break;
						case '*': stack.push(p2.mult(p1));
								break;
						case '/': stack.push(p2.div(p1));
								break;
						}
				}
				else if (c != '_') {
						name.push_back(c);
				}
		}

		std::cout << '\t' << stack.top().to_str() << std::endl;

		std::cout << "Save?(name / no)";
		std::cout << '>';
		std::string temp;
		std::getline(std::cin, temp);
		if (temp == "no") {
				return;
		}
		else {
				add({ temp, stack.top() });
		}
}

std::vector<std::string> getwordsfromstr(std::string str) {
		std::vector<std::string> words;
		int pos = 0;

		while ((pos = str.find(" ")) != std::string::npos) {
				if ((words.size() == 2 && words.front() == "add") || (words.size() == 1 && words.front() == "calculate")) {
						break;
				}
				else {
						auto temp = str.substr(0, pos);
						if (temp != "") {
								words.push_back(temp);
						}
						str.erase(0, pos + 1);
				}
		}
		words.push_back(str);
		if (words.back() == "") {
				words.erase(words.end() - 1);
		}

		return words;
}

void clear_all() {
		table_list.clear();
		tree.clear();
		vector.clear();
		vector_sorted.clear();
		hash.clear();
		hash2.clear();
		std::cout << "\tCleared successfuly" << std::endl;
}

void remove(const std::string &key) {
		if (vector.empty() == false) {
				vector.remove(key);
		}
		if (vector_sorted.empty() == false) {
				vector_sorted.remove(key);
		}
		if (table_list.empty() == false) {
				table_list.remove(key);
		}
		if (tree.empty() == false) {
				tree.remove(key);
		}
		if (hash.empty() == false) {
				hash.remove(key);
		}
		if (hash2.empty() == false) {
				hash2.remove(key);
		}

		std::cout << "\tRemoved successfuly" << std::endl;
}

void print_all() {
		if (vector.empty() == true && vector_sorted.empty() == true && table_list.empty() == true && tree.empty() == true && hash.empty() == true && hash2.empty() == true) {
				std::cout << "\tTables are empty" << std::endl;
		}
		else {
				std::cout << "\tVector" << std::endl;
				vector.print();
				std::cout << "\tSorted vector" << std::endl;
				vector_sorted.print();
				std::cout << "\tTable list" << std::endl;
				table_list.print();
				std::cout << "\tTree" << std::endl;
				tree.print();
				std::cout << "\tHash table" << std::endl;
				hash.print();
				std::cout << "\tHash table 2" << std::endl;
				hash2.print();
		}
}

void parsing() {
		std::vector<std::string> command;

		std::cout << "-help- for all commands" << std::endl;
		while (true) {
				if (command.size() == 1) {
						if (command.front() == "help") {
								std::cout << std::endl;
								std::cout << "-add 'name' 'polynom'\t\t-add polynom to all tables" << std::endl;
								std::cout << "-remove 'name'\t\t        -remove polynom from all tables" << std::endl;
								std::cout << "-print 'name'\t\t        -print polynom" << std::endl;
								std::cout << "-print\t\t                -print all tables" << std::endl;
								std::cout << "-clear all\t\t        -fully clear all tables" << std::endl;
								std::cout << std::endl;
								std::cout << "-calculate 'expression'\t        -calculate expression" << std::endl;
								std::cout << std::endl;
								std::cout << "'name' - 'name' 'new name'\t-sub polynoms and add new to all tables" << std::endl;
								std::cout << "'name' * 'name' 'new name'\t-mult polynoms and add new to all tables" << std::endl;
								std::cout << "'name' / 'name' 'new name'\t-div polynoms and add new to all tables" << std::endl;
								std::cout << "'name' % 'name' 'new name'\t-mod polynoms and add new to all tables" << std::endl;
								std::cout << "'name' dx/dy/dz 'new name'\t-derivide polynom and add new to all tables" << std::endl;
								std::cout << "'name' Ix/Iy/Iz 'new name'\t-integrate polynom and add new to all tables" << std::endl;
								std::cout << std::endl;
								std::cout << "-cls\t\t                -clear console" << std::endl;
								std::cout << "-exit\t\t                -close programm" << std::endl;
								std::cout << std::endl;
						}
						else if (command.front() == "print") {
								print_all();
						}
						else if (command.front() == "cls") {
								system("cls");
						}
						else if (command.front() == "exit") {
								return;
						}
						else {
								std::cout << "\tUnknown command" << std::endl;
						}
				}
				else if (command.size() == 2) {
						if (command.front() == "remove") {
								remove(command.back());
						}
						else if (command.front() == "print") {
								Nexus<std::string, Polynom> temp;
								if (tree.get(command.back(), temp) == true) {
										std::cout << '\t' << temp.data.to_str() << std::endl;
								}
								else {
										std::cout << "\tPolynom with such name does not exist" << std::endl;
								}
						}
						else if (command.front() == "calculate") {
								calculate(get_postfix(command.back()));
						}
						else if (command.front() == "clear" && command.back() == "all") {
								clear_all();
						}
						else if (command.back() == "dx" || command.back() == "dy" || command.back() == "dz") {
								Nexus<std::string, Polynom> temp;

								if (tree.get(command.front(), temp) == false) {
										std::cout << "\tIncorrect name" << std::endl;
								}
								else {
										std::cout << '\t' << temp.data.d((vType)command[1][1]).to_str() << std::endl;
								}
						}
						else if (command.back() == "ix" || command.back() == "iy" || command.back() == "iz") {
								Nexus<std::string, Polynom> temp;

								if (tree.get(command.front(), temp) == false) {
										std::cout << "\tIncorrect name" << std::endl;
								}
								else {
										std::cout << '\t' << temp.data.Id((vType)command[1][1]).to_str() << std::endl;
								}
						}
						else {
								std::cout << "\tUnknown command" << std::endl;
						}
				}
				else if (command.size() == 3) {
						if (command.front() == "add") {
								add({ command[1], command[2] });
						}
						else if (command[1] == "dx" || command[1] == "dy" || command[1] == "dz") {
								Nexus<std::string, Polynom> temp;

								if (tree.get(command.front(), temp) == false) {
										std::cout << "\tIncorrect name" << std::endl;
								}
								else {
										add({ command.back(), temp.data.d((vType)command[1][1]) });
								}
						}
						else if (command[1] == "ix" || command[1] == "iy" || command[1] == "iz") {
								Nexus<std::string, Polynom> temp;

								if (tree.get(command.front(), temp) == false) {
										std::cout << "\tIncorrect name" << std::endl;
								}
								else {
										add({ command.back(), temp.data.Id((vType)command[1][1]) });
								}
						}
						else if (command[1] == "+" || command[1] == "-" || command[1] == "*" || command[1] == "/" || command[1] == "%") {
								Nexus<std::string, Polynom> temp1;
								Nexus<std::string, Polynom> temp2;
								if (tree.get(command.front(), temp1) == false || tree.get(command[2], temp2) == false) {
										std::cout << "\tIncorrect names" << std::endl;
								}
								else {
										switch (command[1][0]) {
										case '+':
												std::cout << '\t' << temp1.data.add(temp2.data).to_str() << std::endl;
												break;
										case '-':
												std::cout << '\t' << temp1.data.sub(temp2.data).to_str() << std::endl;
												break;
										case '*':
												std::cout << '\t' << temp1.data.mult(temp2.data).to_str() << std::endl;
												break;
										case '/':
												std::cout << '\t' << temp1.data.div(temp2.data).to_str() << std::endl;
												break;
										case '%':
												std::cout << '\t' << temp1.data.mod(temp2.data).to_str() << std::endl;
												break;
										}
								}
						}
						else {
								std::cout << "\tUnknown command" << std::endl;
						}
				}
				else if (command.size() == 4) {
						if (command[1] == "+" || command[1] == "-" || command[1] == "*" || command[1] == "/" || command[1] == "%") {
								Nexus<std::string, Polynom> temp1;
								Nexus<std::string, Polynom> temp2;
								Nexus<std::string, Polynom> result;
								if (tree.get(command.front(), temp1) == false || tree.get(command[2], temp2) == false) {
										std::cout << "\tIncorrect names" << std::endl;
								}
								else {
										result.key = command.back();
										switch (command[1][0]) {
										case '+':
												result.data = Polynom(temp1.data.add(temp2.data));
												break;
										case '-':
												result.data = Polynom(temp1.data.sub(temp2.data));
												break;
										case '*':
												result.data = Polynom(temp1.data.mult(temp2.data));
												break;
										case '/':
												result.data = Polynom(temp1.data.div(temp2.data));
												break;
										case '%':
												result.data = Polynom(temp1.data.mod(temp2.data));
												break;
										}
										add(result);
								}
						}
						else {
								std::cout << "\tUnknown command" << std::endl;
						}
				}

				std::cout << '>';
				std::string temp;
				std::getline(std::cin, temp);
				std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
				command = getwordsfromstr(temp);
		}
}

int main() {
		parsing();

		return 0;
}