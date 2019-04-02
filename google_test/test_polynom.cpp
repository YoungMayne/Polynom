#include "pch.h"
#include "../Polynom.h"

TEST(Polynom, can_create_polynom) {
		ASSERT_NO_THROW(Polynom a("4x + y"));
}

TEST(Polynom, can_add_polynoms) {
		Polynom a("x^2 + y + z^3");
		Polynom b("-2x^2 + z^3");
		EXPECT_EQ(a.add(b).to_str(), "-1x^2 +1y^1 +2z^3 ");

}

TEST(Polynom, can_subtract_polynoms) {
		Polynom a("x^2 + y + z^3");
		Polynom b("-2x^2 + z^3");
		EXPECT_EQ(a.sub(b).to_str(), "+3x^2 +1y^1 ");
}

TEST(Polynom, can_multiply_polynoms) {
		Polynom a("x^2 + y + z^3");
		Polynom b("-2x^2 + z^3");
		EXPECT_EQ(a.mult(b).to_str(), "-2x^4 -1x^2z^3 -2x^2y^1 +1y^1z^3 +1z^6 ");
}

TEST(Polynom, can_divide_polynoms) {
		Polynom a("x + y + z");
		Polynom b("xy + z");
		EXPECT_EQ(a.mult(b).div(b).to_str(), "+1x^1 +1y^1 +1z^1 ");
}

TEST(Polynom, can_dirvide_polynom) {
		Polynom a("xy + z");
		EXPECT_EQ(a.d(x).to_str(), "+1y^1 ");
		EXPECT_EQ(a.d(y).to_str(), "+1x^1 ");
		EXPECT_EQ(a.d(z).to_str(), "+1 ");
}

TEST(Polynom, can_integrate_polynom) {
		Polynom a("2xy + z");
		EXPECT_EQ(a.Id(x).to_str(), "+1x^2y^1 +1x^1z^1 ");
		EXPECT_EQ(a.Id(y).to_str(), "+1x^1y^2 +1y^1z^1 ");
		EXPECT_EQ(a.Id(z).to_str(), "+2x^1y^1z^1 ");
}

TEST(Polynom, can_calculate_polynom) {
		Polynom a("2xy + z");
		EXPECT_EQ(a.calculate(2, 3, 4), 16);
		system("pause");
}