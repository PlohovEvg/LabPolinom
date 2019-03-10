#include <iostream>
#include <string>
#include "List.h"

using namespace std;

void Partition(string s, List &l)
{
	string tstr1, tstr2;
	int st = 0;
	int i = 0;
	int k;
	int temp = 0;
	double tcoeff;

	tstr1 = tstr2 = "";

	while (s[i] != '\0')
	{
		if (st == 0)
		{
			if (((s[i] >= '0') && (s[i] <= '9')) || (s[i] == '-') || (s[i] == '+') || (s[i] == '.'))
			{
				tstr1 += s[i];
			}
			if ((s[i] == 'x') || (s[i] == 'y') || (s[i] == 'z'))
			{
				tcoeff = atof(tstr1.c_str());
				st = 1;
				tstr1 = "";
			}
		}
		else
		{
			if ((s[i] >= '0') && (s[i] <= '9'))
			{
				tstr2 += s[i];
				if ((s[i + 1] == 'y') || (s[i + 1] == 'z') || (s[i + 1] == '\0') || (s[i + 1] == '+') || (s[i + 1] == '-'))
				{
					if ((s[i - 2] == 'x') || (s[i - 3] == 'x'))
					{
						k = 2;
					}
					else
					{
						if ((s[i - 2] == 'y') || (s[i - 3] == 'y'))
						{
							k = 1;
						}
						else
						{
							if ((s[i - 2] == 'z') || (s[i - 3] == 'z'))
							{
								k = 0;
							}
						}
					}
					temp = temp + (atoi(tstr2.c_str())*pow(20, k));
					tstr2 = "";
				}
			}
			if ((s[i+1] == '+') || (s[i+1] == '-') || (s[i+1] == '\0'))
			{
				st = 0;
				l.Add_new_Link(tcoeff, temp);
				temp = 0;
				tcoeff = 0.0;
			}
		}
		i++;		
	}
}