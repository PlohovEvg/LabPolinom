#include "List.h"


void List::Add_new_Link(double _coeff, int _degrees)
{
	Link *n = new Link;                 
	n->coeff = _coeff;
	n->degrees = _degrees;
	n->next = NULL;
	if (head == NULL)
	{
		head = n;
	}
	else
	{		
			if (n->degrees < head->degrees)
			{
				n->next = head;
				head = n;
			}
			else
			{
				if (n->degrees == head->degrees)
				{
					head->coeff += n->coeff;
				}
				else
				{
					Link *p = head;
					while (p->next != NULL)
					{
						if (n->degrees < p->next->degrees)
						{
							n->next = p->next;
							p->next = n;
							break;
						}
						else
						{
							if (n->degrees == p->next->degrees)
							{
								p->next->coeff += n->coeff;
								break;
							}
							p = p->next;
						}
					}
					if (p->next == NULL)
					{
						p->next = n;
					}
				}
			}		
	}
}

List List::operator+(const List &l1)
{
	List res;                               
	Link *p = head;
	Link *t = l1.head;

	while ((t != NULL) || (p != NULL))
	{
		/*p = head;
		while (p != NULL)
		{
			if (p->degrees == t->degrees)
			{
				res.Add_new_Link(p->coeff + t->coeff, p->degrees);
				break;
			}
			else
			{
				p = p->next;
				if (p == NULL)
				{
					res.Add_new_Link(t->coeff, t->degrees);
				}
			}
		}*/
		if (p->degrees == t->degrees)
		{
			res.Add_new_Link(p->coeff + t->coeff, p->degrees);			
		}
		else
		{
			res.Add_new_Link(p->coeff, p->degrees);
			res.Add_new_Link(t->coeff, t->degrees);
		}
		t = t->next;
		p = p->next;
	}
	if (p != NULL)
	{
		while (p != NULL)
		{
			res.Add_new_Link(p->coeff, p->degrees);
			p = p->next;
		}
	}
	
	if (t != NULL)
	{
		while (t != NULL)
		{
			res.Add_new_Link(t->coeff, t->degrees);
			t = t->next;
		}
	}	
	return res;
}

List List::operator*(const List &l1)
{
	List res;
	Link *p = head;
	Link *t = l1.head;

	while(t != NULL)
	{
		p = head;
		while (p != NULL)
		{
			/*if (p->degrees + t->degrees <= 7999);
			{
				res.Add_new_Link(p->coeff*t->coeff, p->degrees + t->degrees);
			}*/
			res.Add_new_Link(p->coeff*t->coeff, p->degrees + t->degrees);
			p = p->next;
		}
		t = t->next;
	}
	return res;
}

void List::show()
{
	Link *p = head;
	int xd, yd, zd;
	cout << endl;
	while (p != NULL)
	{
		xd = p->degrees / 400;
		yd = (p->degrees % 400) / 20;
		zd = (p->degrees % 400) % 20;
		if (p->coeff > 0)
		{
			if (p != head)
			{
				cout << "+" << p->coeff << "x^" << xd << "y^" << yd << "z^" << zd;
			}
			else
			{
				cout << p->coeff << "x^" << xd << "y^" << yd << "z^" << zd;
			}
		}
		else
		{
			cout << p->coeff << "x^" << xd << "y^" << yd << "z^" << zd;
		}
		p = p->next;
	}
	cout << endl << endl;
}

void List::Delete_last_Link()
{
	Link *p = head;
	
	while (p->next->next != NULL)
	{
		p = p->next;
	}
	p->next = NULL;
}

List& List:: operator=(const List &l1)
{
	Link *p = head;
	Link *t = l1.head;
	int i, j;
	int k;

	i = j = 0;

	while (t != NULL)
	{
		i++;
		t = t->next;
	}
	while (p != NULL)
	{
		j++;
		p = p->next;
	}

	p = head;
	t = l1.head;

	if (i == j)
	{
		while (t != NULL)
		{
			p->coeff = t->coeff;
			p->degrees = t->degrees;
			p = p->next;
			t = t->next;
		}
	}
	else
	{
		if (i > j)
		{
			for (k = 0; k < j; k++)
			{
				p->coeff = t->coeff;
				p->degrees = t->degrees;
				p = p->next;
				t = t->next;
			}
			for (k = j; k < i; k++)
			{
				Add_new_Link(t->coeff, t->degrees);
				t = t->next;
			}
		}
		else
		{
			for (k = 0; k < i; k++)
			{
				p->coeff = t->coeff;
				p->degrees = t->degrees;
				p = p->next;
				t = t->next;
			}
			for (k = j; k > j; k--)
			{
				Delete_last_Link();
			}
		}
	}
	return *this;
}