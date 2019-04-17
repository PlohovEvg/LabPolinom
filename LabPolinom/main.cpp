#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Functions.h"
#include "List.h"

using namespace std;                             

int main()
{
	string Polinom1, Polinom2;
	List l1, l2, l3, l4;

	cout << "Polinom 1: ";
	cin >> Polinom1;
	cout << "Polinom 2: ";
	cin >> Polinom2;

	Partition(Polinom1, l1);
	Partition(Polinom2, l2);	
	l1.show();
	l3 = l1 + l2;
	l4 = l1 * l2;
	cout << endl << "p1 + p2 = ";
	l3.show();
	cout << "p1 * p2 = ";
	l4.show();

	return 0;
}