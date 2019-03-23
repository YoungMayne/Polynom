#pragma once
#include <iostream>
#include <vector>

struct Monom {
		float coefficient;
		float degree;
};

typedef std::vector<Monom> m_vector;

#ifndef _POLYNOM_H
#define _POLYNOM_H

class Polynom {
public:
		Polynom();
		Polynom(const m_vector &mons);
		Polynom(const Polynom &pol);
		~Polynom();

		Polynom mult(const Polynom &other);
		Polynom div(const Polynom &other);
		Polynom derivative(int quantity = 1);
		Polynom integrate();

		float calculate(float point);

		Polynom& operator=(const Polynom &pol);
		friend std::ostream & operator<<(std::ostream & os, const Polynom & p);	

private:
		m_vector monoms;
};

#endif _POLYNOM_H