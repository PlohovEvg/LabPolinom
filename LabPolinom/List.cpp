#include "List.h"


void List::Add_new_Link(double _coeff, int degrees)
{
	Link *n = new Link;
	n->coeff = _coeff;
	n->degrees = degrees;
	n->next = NULL;
	if (head == NULL)
	{
		head = n;
	}
	else
	{
		Link *p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = n;
	}
}

List List::operator+(const List &l1)
{
	List res;
	Link *p = head;
	Link *t = l1.head;

	while (t != NULL)
	{
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
		}
		t = t->next;
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