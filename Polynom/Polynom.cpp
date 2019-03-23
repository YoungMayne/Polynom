#include "Polynom.h"

Polynom::Polynom() {}

Polynom::Polynom(const m_vector &mons) {
		monoms = mons;

		for (int i = 0; i < monoms.size(); ++i) {
				for (int j = monoms.size() - 1; j != i; --j) {
						if (monoms[i].degree == monoms[j].degree) {
								monoms[i].coefficient += monoms[j].coefficient;
								monoms.erase(monoms.begin() + j);
						}
						else if (monoms[i].degree < monoms[j].degree) {
								auto temp = monoms[i];
								monoms[i] = monoms[j];
								monoms[j] = temp;
						}
				}
				if (monoms[i].coefficient == 0) {
						monoms.erase(monoms.begin() + i);
				}
		}
}

Polynom::Polynom(const Polynom & pol)
{
		this->monoms = pol.monoms;
}

Polynom::~Polynom() {}

Polynom Polynom::mult(const Polynom & other) {
		m_vector result;

		for (const auto &t : monoms) {
				for (const auto &o : other.monoms) {
						Monom temp;
						temp.coefficient = t.coefficient * o.coefficient;
						temp.degree = t.degree + o.degree;
						result.push_back(temp);
				}
		}

		return Polynom(result);
}

Polynom Polynom::div(const Polynom & other) {
		m_vector result;

		for (const auto &t : monoms) {
				for (const auto &o : other.monoms) {
						Monom temp;
						temp.coefficient = t.coefficient / o.coefficient;
						temp.degree = t.degree - o.degree;
						result.push_back(temp);
				}
		}

		return Polynom(result);
}

Polynom Polynom::derivative(int quantity) {
		auto result = monoms;
		int count = 0;

		while (count < quantity) {
				for (int i = 0; i < result.size(); ++i) {
						if (result[i].degree == 0) {
								result.erase(result.begin() + i);
						}
						else {
								result[i].coefficient *= result[i].degree;
								result[i].degree -= 1;
						}
				}
				count += 1;
		}

		return Polynom(result);
}

Polynom Polynom::integrate() {
		auto result = monoms;

		for (auto &m : result) {
				m.degree += 1;
				m.coefficient /= m.degree;
		}

		return Polynom(result);
}

float Polynom::calculate(float point) {
		float result = 0;

		for (const auto &m : monoms) {
				result += m.coefficient * pow(point, m.degree);
		}

		return result;
}

float Polynom::degree(){
		if (monoms.empty() == true) {
				return 0;
		}
		return monoms[0].degree;
}

Polynom& Polynom::operator=(const Polynom & pol) {
		monoms = pol.monoms;

		return *this;
}

std::ostream & operator<<(std::ostream & os, const Polynom & p) {
		if (p.monoms.empty() == true) {
				os << 0;
				return os;
		}
		for (const auto &m : p.monoms) {
				m.coefficient < 0 ? os << m.coefficient : m.coefficient == 1 ? os << '+' : os << '+' << m.coefficient;
				m.degree == 0 ? os : m.degree == 1 ? os << 'x' : os << "x^" << m.degree;
		}

		return os;
}
