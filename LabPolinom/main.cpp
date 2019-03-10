#include <string>
#include <iostream>
#include "Functions.h"
#include "List.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	string Polinom1, Polinom2;
	List l1, l2, l3, l4;

	cout << "¬ведите полином 1: ";
	cin >> Polinom1;
	cout << "¬ведите полином 2: ";
	cin >> Polinom2;

	Partition(Polinom1, l1);
	Partition(Polinom2, l2);

	l3 = l1 + l2;
	l4 = l1 * l2;

	l3.show();
	l4.show();

	return 0;
}