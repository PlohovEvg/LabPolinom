#include "List.h"
#include "Functions.cpp"
#include <gtest.h>
#include <string>

using namespace std;

TEST(List, can_create_empty_list)
{
	ASSERT_NO_THROW(List());
}

TEST(List, can_insert_one_monom_to_list)
{
	string p = "-2x^7y^8z^9";
	List l;
	Partition(p, l);
	EXPECT_EQ(l.ConvertToString(), string("-2.00x^7y^8z^9"));
}

TEST(List, can_insert_multiple_monoms_to_list)
{
	string p = "3.25y^1z^4-2x^7y^8z^9-6.9659x^10";
	List l;
	Partition(p, l);
	EXPECT_EQ(l.ConvertToString(), string("3.25y^1z^4-2.00x^7y^8z^9-6.97x^10"));
}

TEST(List, monoms_withs_same_deggreeses_are_summed)
{
	string p = "2x^1y^2z^3+2x^1y^2z^3";
	List l;
	Partition(p, l);
	List l2;
	Partition(string("4x^1y^2z^3"), l2);
	EXPECT_EQ(l.ConvertToString(), l2.ConvertToString());
}

TEST(List, can_assign_one_list_to_another_with_same_length)
{
	string p1 = "2x^7z^8";
	string p2 = "6x^1y^2z^3";
	List l1, l2;
	Partition(p1, l1);
	Partition(p2, l2);
	l1 = l2;
	EXPECT_EQ(l1.ConvertToString(), l2.ConvertToString());
}

TEST(List, can_assign_one_list_to_another_with_different_length)
{
	string p1 = "2x^7z^8";
	string p2 = "6x^1y^2z^3-2y^7+6.84z^10";
	List l1, l2;
	Partition(p1, l1);
	Partition(p2, l2);
	l1 = l2;
	EXPECT_EQ(l1.ConvertToString(), l2.ConvertToString());
}

TEST(List, can_add_lists_with_same_length)
{
	string p1 = "2x^7z^8";
	string p2 = "6x^1y^2z^3";
	List l1, l2, l3;
	Partition(p1, l1);
	Partition(p2, l2);
	l3 = l1 + l2;
	List l4;
	Partition(string("6x^1y^2z^3+2x^7z^8"), l4);
	EXPECT_EQ(l3.ConvertToString(), l4.ConvertToString());
}

TEST(List, can_add_lists_with_different_length)
{
	string p1 = "2x^7z^8";
	string p2 = "6x^1y^2z^3-2y^7+6.84z^10";
	List l1, l2, l3;
	Partition(p1, l1);
	Partition(p2, l2);
	l3 = l1 + l2;
	List l4;
	Partition(string("6.84z^10-2y^7+6x^1y^2z^3+2x^7z^8"), l4);
	EXPECT_EQ(l3.ConvertToString(), l4.ConvertToString());
}

TEST(List, can_multiply_lists)
{
	string p1 = "2x^7z^8";
	string p2 = "6x^1y^2z^3-2y^7+7z^10";
	List l1, l2, l3;
	Partition(p1, l1);
	Partition(p2, l2);
	l3 = l1 * l2;
	List l4;
	Partition(string("14x^7z^18-4x^7y^7z^8+12x^8y^2z^11"), l4);
	EXPECT_EQ(l3.ConvertToString(), l4.ConvertToString());
}