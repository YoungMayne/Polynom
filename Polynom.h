#pragma once
#include "Monom.h"

#ifndef _Polynom_H		
#define _Polynom_H

class Polynom {
public:
		Polynom() {}
		Polynom(const std::string &pol);

		Polynom add(const Polynom &other);
		Polynom sub(const Polynom &other);
		Polynom mult(const Polynom &other);
		Polynom div(Polynom &other);
		Polynom mod(Polynom &other);
		Polynom d(vType dwhat);
		Polynom Id(vType dwhat);
		Polynom operator=(const std::string &pol);

		int degree();
		double calculate(double x = 0, double y = 0, double z = 0);

		std::string to_str();
private:
		std::vector<Monom> mons;

		bool greater_than(Polynom &other);
		bool find_index(const Polynom &other, int &index, int &other_index);

		Polynom& simpify();
};

//..........PUBLIC............//

Polynom::Polynom(const std::string & pol) {
		std::string temp;

		for (const auto &c : pol) {
				if ((c == '-' || c == '+') && temp.empty() == false) {
						mons.push_back(Monom(temp));
						temp.clear();
				}
				if (c != ' ') {
						temp.push_back(c);
				}
		}
		mons.push_back(Monom(temp));
		simpify();
}

inline Polynom Polynom::add(const Polynom & other) {
		Polynom result = *this;

		for (const auto &m : other.mons) {
				result.mons.push_back(m);
		}

		return result.simpify();
}

inline Polynom Polynom::sub(const Polynom & other) {
		Polynom result = *this;

		for (auto m : other.mons) {
				result.mons.push_back(m.mult(Monom("-1")));
		}

		return result.simpify();
}

inline Polynom Polynom::mult(const Polynom & other) {
		Polynom result;

		for (auto &m : mons) {
				for (auto &o : other.mons) {
						result.mons.push_back(m.mult(o));
				}
		}

		return result.simpify();
}

inline Polynom Polynom::div(Polynom & other) {
		Polynom current = *this;
		Polynom result;

		while (current.greater_than(other)) {
				int index = -1;
				int other_index = 0;

				if (current.find_index(other, index, other_index) == false) {
						return result.simpify();
				}
				else {
						result.mons.push_back(current.mons[index].div(other.mons[other_index]));
						current = current.sub(Polynom(result.mons.back().to_str()).mult(other));
				}
		}

		return result.simpify();
}

inline Polynom Polynom::mod(Polynom & other) {
		Polynom current = *this;
		Polynom result;

		while (current.greater_than(other)) {
				int index = -1;
				int other_index = 0;

				if (current.find_index(other, index, other_index) == false) {
						return current.simpify();
				}
				else {
						result.mons.push_back(current.mons[index].div(other.mons[other_index]));
						current = current.sub(Polynom(result.mons.back().to_str()).mult(other));
				}
		}

		return current.simpify();
}

inline Polynom Polynom::d(vType dwhat) {
		Polynom result;

		for (auto &m : mons) {
				result.mons.push_back(m.d(dwhat));
		}

		return result.simpify();
}

inline Polynom Polynom::Id(vType dwhat) {
		Polynom result;

		for (auto &m : mons) {
				result.mons.push_back(m.Id(dwhat));
		}

		return result.simpify();
}

inline Polynom Polynom::operator=(const std::string & pol) {
		return *this = Polynom(pol);
}

//..........PRIVATE............//

inline std::string Polynom::to_str() {
		std::string result;

		if (mons.empty() == true) {
				result += '0';
		}
		else {
				for (auto &m : mons) {
						result += m.to_str() + ' ';
				}
		}

		return result;
}

inline int Polynom::degree() {
		int high = 0;

		for (auto &m : mons) {
				int temp = m.degree();
				if (temp > high) {
						high = temp;
				}
		}

		return high;
}

inline double Polynom::calculate(double x, double y, double z) {
		double result = 0;

		for (auto &m : mons) {
				result += m.calculate(x, y, z);
		}

		return result;
}

inline bool Polynom::greater_than(Polynom & other) {
		for (int i = 0; i < mons.size() && i < other.mons.size(); ++i) {
				if (mons[i].greater_than(other.mons[i])) {
						return true;
				}
		}

		return false;
}

inline bool Polynom::find_index(const Polynom &other, int &index, int &other_index) {
		for (int i = 0; i < other.mons.size(); ++i) {
				for (int j = 0; j < mons.size(); ++j) {
						if (mons[j].contains(other.mons[i]) == true) {
								index = j;
								other_index = i;
								return true;
						}
				}
		}

		return false;
}

inline Polynom& Polynom::simpify() {
		for (int i = 0; i < mons.size(); ++i) {
				for (int j = mons.size() - 1; j != i; --j) {
						if (mons[i] == mons[j]) {
								mons[i] = mons[i].add(mons[j]);
								mons.erase(mons.begin() + j);
								return this->simpify();
						}
						//else if (mons[i].degree() < mons[j].degree()) {
						//		std::swap(mons[i], mons[j]);
						//}
				}
				if (mons[i].dead() == true) {
						mons.erase(mons.begin() + i);
						return this->simpify();
				}
		}

		return *this;
}

#endif 