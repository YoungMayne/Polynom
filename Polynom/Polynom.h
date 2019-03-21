#pragma once
#include <iostream>
#include <vector>

struct Monom
{
		float coefficient;
		float degree;
};

typedef std::vector<Monom> m_vector;

class Polynom
{
public:
		Polynom(const m_vector &mons);
		~Polynom();

		Polynom mult(const Polynom &other);
		Polynom div(const Polynom &other);
		Polynom derivative(int quantity = 1);
		Polynom integrate();

		float calculate(float point);

		friend std::ostream & operator<<(std::ostream & os, const Polynom & p);
		Polynom operator=(const Polynom &pol);

private:
		m_vector monoms;
};

