#include "polynom.h"
#include <gtest.h>


TEST(Polynom, can_create_polynom)
{
	ASSERT_NO_THROW(Polynom p);
}


TEST(Polynom, can_add_monoms)
{
	Polynom p;
	ASSERT_NO_THROW(p.AddMonom(432, 534));
}

TEST(Polynom, can_add_polynoms)
{
	Polynom p1;
	p1.AddMonom(432, 534);

	Polynom p2;
	p2.AddMonom(432, 534);

	Polynom res = p1 + p2;
	Polynom exp;
	exp.AddMonom(432, 1068);
	EXPECT_TRUE(res == exp);

}

TEST(Polynom, delete_monoms_with_zero_koef)
{
	Polynom p1;
	p1.AddMonom(123, -13.5);

	Polynom p2;
	p2.AddMonom(123, 13.5);

	Polynom res = p1 + p2;
	Polynom exp;
	EXPECT_TRUE(res == exp);
}

TEST(Polynom, can_add_big_monoms)
{
	Polynom p1;
	p1.AddMonom(123, 10);
	p1.AddMonom(121, 4);
	p1.AddMonom(045, -10);
	p1.AddMonom(031, -4);
	p1.AddMonom(005, -5);
	p1.AddMonom(000, 8);

	Polynom p2;
	p2.AddMonom(123, -10);
	p2.AddMonom(122, 10);
	p2.AddMonom(005, 5);
	p2.AddMonom(000, 41);

	Polynom res = p1 + p2;
	Polynom exp;
	exp.AddMonom(122, 10);
	exp.AddMonom(121, 4);
	exp.AddMonom(045, -10);
	exp.AddMonom(031, -4);
	exp.AddMonom(000, 49);


	EXPECT_TRUE(res == exp);
}

TEST(Polynom, can_calculate)
{
	Polynom exp;
	exp.AddMonom(122, 10);
	exp.AddMonom(121, 4);
	exp.AddMonom(45, -10);
	exp.AddMonom(31, -4);
	exp.AddMonom(0, 49);

	auto a = exp.Calculate(1, 2, 3);
	EXPECT_EQ(-38519, a);
}