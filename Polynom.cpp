#include "Polynom.h"

uLab::Polynom::Polynom(const std::vector<uLab::Monom> &mons)
{
		monoms = mons;
		for (int i = 0; i < monoms.size(); ++i)
		{
				for (int j = i + 1; j < monoms.size(); ++j)
				{
						if (monoms[i].degree == monoms[j].degree)
						{
								monoms[i].coefficient += monoms[j].coefficient;
								monoms.erase(monoms.begin() + j);
						}
				}
				if (monoms[i].coefficient == 0)
				{
						monoms.erase(monoms.begin() + i);
				}
		}
		for (int i = 0; i < monoms.size(); ++i)		
		{
				for (int j = monoms.size() - 1; j > i; --j)
				{
						if (monoms[i].degree < monoms[j].degree)
						{
								auto temp = monoms[i];
								monoms[i] = monoms[j];
								monoms[j] = temp;
						}
				}
		}
}

uLab::Polynom::~Polynom()
{
}

uLab::Polynom uLab::Polynom::mult(const Polynom & other)
{
		std::vector<Monom> result;

		for (const auto &tMonom : monoms)
		{
				for (const auto &oMonom : other.monoms)
				{
						Monom temp;
						temp.coefficient = tMonom.coefficient * oMonom.coefficient;
						temp.degree = tMonom.degree + oMonom.degree;
						result.push_back(temp);
				}
		}

		return Polynom(result);
}

uLab::Polynom uLab::Polynom::div(const Polynom & other)
{
		std::vector<Monom> result;

		for (const auto &tMonom : monoms)
		{
				for (const auto &oMonom : other.monoms)
				{
						Monom temp;
						temp.coefficient = tMonom.coefficient / oMonom.coefficient;
						temp.degree = tMonom.degree - oMonom.degree;
						result.push_back(temp);
				}
		}

		return Polynom(result);
}

uLab::Polynom uLab::Polynom::derivative(int quantity)
{
		auto result = monoms;
		int count = 0;

		while (count < quantity)
		{
				for (int i = 0; i < result.size(); ++i)
				{
						if (result[i].degree == 0)
						{
								result.erase(result.begin() + i);
						}
						else
						{
								result[i].coefficient *= result[i].degree;
								result[i].degree -= 1;
						}
				}
				count += 1;
		}

		return Polynom(result);
}

uLab::Polynom uLab::Polynom::integrate()
{
		auto result = monoms;

		for (auto &m : result)
		{
				m.degree += 1;
				m.coefficient /= m.degree;
		}

		return Polynom(result);
}

float uLab::Polynom::calculate(float point)
{
		float result = 0;
		for (const auto &m : monoms)
		{
				result += m.coefficient * pow(point, m.degree);
		}

		return result;
}

std::ostream & uLab::operator<<(std::ostream & os, const Polynom & p)
{
		if (p.monoms.empty()) 
		{
				os << 0;
				return os;
		}
		for (const auto &m : p.monoms)
		{
				m.coefficient < 0 ? os << m.coefficient : os << '+' << m.coefficient;
				m.degree == 0 ? os : m.degree == 1 ? os << 'x' : os << "x^" << m.degree;
		}

		return os;
}
