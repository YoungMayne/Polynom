#pragma once
#include <iostream>
#include <vector>

#include "uLab.h"

class uLab::Polynom
{
public:
		Polynom(const std::vector<Monom> &mons);
		~Polynom();

		Polynom mult(const Polynom &other);
		Polynom div(const Polynom &other);
		Polynom derivative(int quantity = 1);
		Polynom integrate();

		float calculate(float point);

		friend std::ostream & operator<<(std::ostream & os, const Polynom & p);

private:
		std::vector<Monom> monoms;
};

