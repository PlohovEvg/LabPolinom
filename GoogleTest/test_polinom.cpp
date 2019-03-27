#include "List.h"
#include "Functions.cpp"
#include <gtest.h>
#include <string>

using namespace std;

TEST(List, can_create_empty_list)
{
	ASEERT_NO_THROW(List l);
}

TEST(List, throws_when_trying_to_create_list_with_attributes)
{
	ASSERT_ANY_THROW(List l(100));
}

TEST(List, can_insert_one_monom_to_list)
{
	string p = "-2x^7y^8z^9";
	List l;
	Partition(p, l);
	EXPEXT_EQ(l.show(), p);
}
TEST(List, can_insert_multiple_monoms_to_list)
{
	string p = "-2x^7y^8z^9+3.25x^0y^1z^4-6.9659x^10y^0z^0";
	List l;
	Partition(p, l);
	EXPEXT_EQ(l.show(), p);
}
TEST(List, monoms_withs_same_deggreeses_are_summed)
{
	string p ="2x^1y^2z^3+2x^1y^2z^3"
	List l;
	Partition(p, l);
	EXPEXT_EQ(l.show(), "4x^1y^2z^3");
}
TEST(List, can_assign_one_list_to_another_with_same_length)
{
	string p1 = "2x^7z^8";
	string p2 = "6x^1y^2z^3";
	List l1, l2;
	Partition(p1, l1);
	Partition(p2, l2);
	l1 = l2;
	EXPECT_EQ(l1.show(), l2.show());
}
TEST(List, can_assign_one_list_to_another_with_different_length)
{
	string p1 = "2x^7z^8";
	string p2 = "6x^1y^2z^3-2y^7+6.84z^10";
	List l1, l2;
	Partition(p1, l1);
	Partition(p2, l2);
	l1 = l2;
	EXPECT_EQ(l1.show(), l2.show());
}
TEST(List, can_add_lists_with_same_length)
{
	string p1 = "2x^7z^8";
	string p2 = "6x^1y^2z^3";
	List l1, l2, l3;
	Partition(p1, l1);
	Partition(p2, l2);
	l3 = l1 + l2;
	EXPECT_EQ(l3.show(), "6x^1y^2z^3+2x^7z^8");
}
TEST(List, can_add_lists_with_different_length)
{
	string p1 = "2x^7z^8";
	string p2 = "6x^1y^2z^3-2y^7+6.84z^10";
	List l1, l2, l3;
	Partition(p1, l1);
	Partition(p2, l2);
	l3 = l1 + l2;
	EXPECT_EQ(l3.show(), "6.84z^10+6x^1y^2z^3+2x^7z^8");
}
TEST(List, can_multiply_lists)
{
	string p1 = "2x^7z^8";
	string p2 = "6x^1y^2z^3-2y^7+7z^10";
	List l1, l2, l3;
	Partition(p1, l1);
	Partition(p2, l2);
	l3 = l1 * l2;
	EXPECT_EQ(l3.show(), "14x^7y^0z^18+12x^8y^2z^11");
}