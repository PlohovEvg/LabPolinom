#pragma once
#include <iostream>

using namespace std;

struct Link
{
	Link *next;
	double coeff;
	int degrees;
 };

class List
{
	Link *head;
public:
	List() { head = NULL; }
	void Add_new_Link(double _coeff, int degrees);
	List operator +(const List &l1);
	List operator *(const List &l1);
	List& operator =(const List &l1);
	void Delete_last_Link();
	void show();
};