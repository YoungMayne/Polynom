#include <vector>
#include <iostream>
#include <string>

#ifndef _Monom_H
#define _Monom_H

enum vType {
		x = 'x',
		y = 'y',
		z = 'z',
		none = 0
};

struct Var {
		vType type = none;
		int degree = 1;
};

class Monom {
public:
		Monom(const std::string &mon);
		Monom(const Monom &mon);

		Monom sub(const Monom &other);
		Monom add(const Monom &other);
		Monom mult(const Monom &other);
		Monom div(Monom &other);
		Monom d(vType dwhat);
		Monom Id(vType dwhat);

		bool operator==(const Monom &other);
		bool dead();
		bool greater_than(Monom &other);
		bool contains(const Monom &other);

		int degree();
		double calculate(double x = 0, double y = 0, double z = 0);

		std::string to_str();
private:
		std::vector<Var> vars;
		double coefficient = 1.0;

		Monom() {};

		Monom& sort();

		int get_contains(vType type);
};

//..........PUBLIC............//

inline  Monom::Monom(const std::string & mon) {
		std::string temp;
		vType var = none;

		for (const auto &c : mon) {
				if (c == x || c == y || c == z) {
						if (var == none && temp.empty() == false) {
								coefficient = temp == "-" ? -1 : temp == "+" ? 1 : atoi(temp.c_str());
						}
						else if (var != none) {
								temp.empty() == true ? vars.push_back({ var }) : vars.push_back({ var, atoi(temp.c_str()) });
						}
						var = (vType)c;
						temp.clear();
				}
				else if (c != '^') {
						temp.push_back(c);
				}
		}
		if (var == none && temp.empty() == false) {
				coefficient = atoi(temp.c_str());
		}
		else if (var != none) {
				temp.empty() == true ? vars.push_back({ var }) : vars.push_back({ var, atoi(temp.c_str()) });
		}
		sort();
}

inline Monom::Monom(const Monom & mon) {
		coefficient = mon.coefficient;
		vars = mon.vars;
}

inline Monom Monom::sub(const Monom & other) {
		Monom result = *this;
		result.coefficient -= other.coefficient;
		return result.sort();
}

inline Monom Monom::add(const Monom & other) {
		Monom result = *this;
		result.coefficient += other.coefficient;
		return result.sort();
}

Monom Monom::mult(const Monom & other) {
		Monom result = *this;

		result.coefficient = coefficient * other.coefficient;
		for (const auto &o : other.vars) {
				int index = get_contains(o.type);
				if (o.type != none && index != -1) {
						result.vars[index].degree += o.degree;
				}
				else {
						result.vars.push_back(o);
				}
		}

		return result.sort();
}

inline Monom Monom::div(Monom & other) {
		Monom result = *this;

		result.coefficient = coefficient / other.coefficient;
		for (auto &t : result.vars) {
				for (const auto &v : other.vars) {
						if (t.type == v.type) {
								int temp = t.degree - v.degree;
								if (temp >= 0) {
										t.degree = temp;
								}
						}
				}
		}

		return result.sort();
}

inline Monom Monom::d(vType dwhat) {
		Monom result = *this;

		int index = get_contains(dwhat);
		if (index == -1) {
				result.coefficient = 0;
		}
		else {
				result.coefficient *= result.vars[index].degree;
				result.vars[index].degree -= 1;
		}

		return result.sort();
}

inline Monom Monom::Id(vType dwhat) {
		Monom result = *this;

		int index = get_contains(dwhat);
		if (index == -1) {
				result.vars.push_back({ dwhat });
		}
		else {
				result.vars[index].degree += 1;
				result.coefficient /= result.vars[index].degree;
		}

		return result.sort();
}

inline bool Monom::operator==(const Monom & other) {
		if (vars.size() != other.vars.size()) {
				return false;
		}
		else if (&vars == &other.vars) {
				return true;
		}
		else {
				for (int i = 0; i < vars.size(); ++i) {
						if (vars[i].degree != other.vars[i].degree || vars[i].type != other.vars[i].type) {
								return false;
						}
				}
		}

		return true;
}

inline bool Monom::dead() {
		return coefficient == 0;
}

inline bool Monom::greater_than(Monom & other) {
		if (vars.empty() == true && other.vars.empty() == true) {
				return coefficient >= other.coefficient;
		}
		else if (vars.empty() == true) {
				return false;
		}
		else if (other.vars.empty() == true) {
				return true;
		}
		else {
				return degree() >= other.degree();
		}
}

inline bool Monom::contains(const Monom & other) {
		if (other.vars.size() > vars.size()) {
				return false;
		}
		for (auto &v : other.vars) {
				int index = -1;
				for (int i = 0; i < vars.size(); ++i) {
						if (v.type == vars[i].type && v.degree <= vars[i].degree) {
								index = i;
								break;
						}
				}
				if (index == -1) {
						return false;
				}
				else {
						index = -1;
				}
		}

		return true;
}

inline int Monom::degree() {
		int high = 0;
		for (auto &v : vars) {
				if (v.degree > high) {
						high = v.degree;
				}
		}
		return high;
}

inline double Monom::calculate(double x, double y, double z) {
		double result = coefficient;

		for (const auto &v : vars) {
				switch (v.type) {
				case 'x':
						result *= pow(x, v.degree);
						break;
				case 'y':
						result *= pow(y, v.degree);
						break;
				case 'z':
						result *= pow(z, v.degree);
						break;
				}
		}

		return result;
}

inline std::string Monom::to_str() {
		std::string result;

		result += coefficient < 0 ? std::to_string(coefficient) : "+" + std::to_string(coefficient);
		for (const auto &v : vars) {
				result += v.degree == 0 ? (const char*)v.type : (char)v.type + ('^' + std::to_string(v.degree));
		}

		return result;
}

//..........PRIVATE............//

inline int Monom::get_contains(vType type) {
		for (int i = 0; i < vars.size(); ++i) {
				if (vars[i].type == type) {
						return i;
				}
		}
		return -1;
}

inline Monom& Monom::sort() {
		if (coefficient == 0) {
				vars.clear();
		}

		for (int i = 0; i < vars.size(); ++i) {
				for (int j = vars.size() - 1; j != i; --j) {
						if (vars[i].type == vars[j].type) {
								vars[i].degree += vars[j].degree;
								vars.erase(vars.begin() + j);
								return this->sort();
						}
						else if (vars[i].type > vars[j].type) {
								std::swap(vars[j], vars[i]);
						}
				}
				if (vars[i].degree == 0) {
						vars.erase(vars.begin() + i);
						return this->sort();
				}
		}

		return *this;
}


#endif // !_Monom_H
