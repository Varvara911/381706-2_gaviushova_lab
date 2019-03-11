#include "gtest.h"
#include "Polynom.h"

int mon1[] = { 1, 2, 3 };
int mon2[] = { 1, 0, 5 };
int mon3[] = { 1, -2, 2 };
int mon4[] = { 1, 0, 4, 6 };
int mon5[] = { 4, 5, 6 };
TMonom A(3, mon1, 1);
TMonom B(3, mon2, 2);
TMonom C(4, mon4, 1);
TMonom D(3, mon5, 3);
TMonom E(3, mon1, 0);

TEST(TMonom, can_create_monom_wiht_zero_size)
{
	ASSERT_NO_THROW(TMonom J(0, mon1, 1));
}

TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom J(3, mon1, 1));
}

TEST(TMonom, throws_when_create_monom_with_negative_size)
{
	ASSERT_ANY_THROW(TMonom J(-1, mon1, 1));
}

TEST(TMonom, throws_when_create_monom_with_negative_power)
{
	ASSERT_ANY_THROW(TMonom J(3, mon1, 1));
}

TEST(TMonom, can_create_copy_monom)
{
	TMonom S(3, mon1, 1);
	ASSERT_NO_THROW(TMonom A(S));
}

TEST(TMonom, throws_when_assign_monoms_with_different_n)
{
	TMonom A(3, mon1, 1);
	TMonom B(4, mon2, 4);
	ASSERT_ANY_THROW(A = B);
}

TEST(TMonom, can_add_equal_monoms)
{
	TMonom A(3, mon1, 1);
	TMonom B(4, mon2, 4);
	ASSERT_NO_THROW(A + B);
	TMonom C(3, mon1, 1);
	C = A + B;
	ASSERT_EQ(4, C.GetK());
}

TEST(TMonom, trows_when_add_different_monoms)
{
	TMonom A(3, mon1, 3.5);
	TMonom B(3, mon2, 1.4);
	TMonom C(4, mon3, 1);
	ASSERT_ANY_THROW(A + C);
	ASSERT_ANY_THROW(A + B);
}

TEST(TMonom, can_substract_equal_monoms)
{
	TMonom A(3, mon1, 3.5);
	TMonom B(3, mon1, 1.4);
	ASSERT_NO_THROW(A - C);
	TMonom B(3, mon1, 1);
	B = A - C;
	ASSERT_EQ(2.6, B.GetK());
}

TEST(TMonom, trows_when_substract_different_monoms)
{
	TMonom A(3, mon1, 3.5);
	TMonom C(3, mon2, 1.4);
	TMonom B(4, mon3, 1);
	ASSERT_ANY_THROW(A - C);
	ASSERT_ANY_THROW(A - B);
}

TEST(TMonom, can_multiply_equal_monoms)
{
	TMonom A(3, mon1, 3);
	TMonom C(3, mon2, 4);
	ASSERT_NO_THROW(A * C);
	TMonom B(3, mon1, 4);
	B = A * C;
	ASSERT_EQ(12, B.GetK());
	ASSERT_EQ(2, B.GetPower()[0]);
	ASSERT_EQ(2, B.GetPower()[1]);
	ASSERT_EQ(6, B.GetPower()[2]);
}

TEST(TMonom, trows_when_substract_different_monoms)
{
	TMonom X(3, mon1, 3.6);
	TMonom Z(3, mon2, 1.0);
	TMonom Y(4, mon4, 1);
	ASSERT_ANY_THROW(X - Z);
	ASSERT_ANY_THROW(X - Y);
}

TEST(TMonom, can_multiply_equal_monoms)
{
	TMonom X(3, mon1, 3);
	TMonom Z(3, mon2, 4);
	ASSERT_NO_THROW(X * Z);
	TMonom Y(3, mon1, 4);
	Y = X * Z;
	ASSERT_EQ(12, Y.GetK());
	ASSERT_EQ(2, Y.GetPower()[0]);
	ASSERT_EQ(2, Y.GetPower()[1]);
	ASSERT_EQ(6, Y.GetPower()[2]);
}

TEST(TMonom, trows_when_multiply_different_monoms)
{
	TMonom X(3, mon1, 2);
	TMonom Z(4, mon4, 2);
	ASSERT_ANY_THROW(X * Z);
}

TEST(TMonom, can_equivalence_monoms)
{
	TMonom X(3, mon1, 3.1);
	TMonom Z(3, mon1, 3.1);
	TMonom Y(3, mon2, 3.1);
	ASSERT_TRUE(X == Z);
	ASSERT_FALSE(X == Y);
}

TEST(TMonom, trows_when_equivalence_monoms_with_different_n)
{
	TMonom X(3, mon1, 1);
	TMonom Z(4, mon4, 1);
	ASSERT_ANY_THROW(X == Z);
}

TEST(TMonom, can_compare_equal_monoms)
{
	TMonom X(3, mon1, 1);
	TMonom Z(3, mon2, 2);
	ASSERT_TRUE(X > Z);
	ASSERT_FALSE(X < Z);
	TMonom Y(3, mon5, 4);
	ASSERT_TRUE(X < Y);
	ASSERT_FALSE(Y < X);
}

TEST(TMonom, trows_compare_monoms_with_different_n)
{
	TMonom X(3, mon1, 1);
	TMonom Z(4, mon4, 2);
	ASSERT_ANY_THROW(X > Z);
	ASSERT_ANY_THROW(X < Z);
}

TEST(TMonom, trows_compare_when_monoms_eq)
{
	TMonom X(3, mon1, 1);
	TMonom Z(3, mon1, 2);
	ASSERT_ANY_THROW(X > Z);
	ASSERT_ANY_THROW(Z < X);
}

TEST(TPolynom, can_create_polynom)
{
	ASSERT_NO_THROW(TPolynom P(3));
}

TEST(TPolynom, throws_when_create_polynom_with_negative_size)
{
	ASSERT_ANY_THROW(TPolynom P(-3));
}

TEST(TPolynom, can_create_copy_polynom)
{
	TPolynom P(3);
	P += A;
	P += B;
	ASSERT_NO_THROW(TPolynom Q(P));
	TPolynom Q(P);
	ASSERT_TRUE(Q == P);
}

TEST(TPolynom, can_get_size_polynom)
{
	TPolynom P(3);
	P += A;
	P += B;
	ASSERT_EQ(P.GetSize(), 2);
}

TEST(TPolynom, trows_when_add_different_polynoms)
{
	TPolynom P(4);
	P += C;
	TPolynom Q(3);
	Q += A;
	ASSERT_ANY_THROW(P + Q);
}
