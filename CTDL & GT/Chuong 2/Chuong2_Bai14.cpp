#include <iostream>
using namespace std;
struct Element
{
	double coeffs;
	int order;
};
struct Node
{
	Element value;
	Node *next;
};
void init(Node *&head)
{
	head=NULL;
}
Node *creatNode(Element el)
{
	Node *p=new node;
	p->value=el;
	p->next=NULL;
}
void insertNode(Node *&head, Element el)
{
	Node *r=head;
	Node *prev=NULL;
	while(r!=NULL && r->value.order<=el.order)
	{
		if(r->value.order==el.order)
		{
			r->value=el;
			break;
		}

		prev=r;
		r=r->next;
	}
	Node *p=creatNode(el);
	if(r==NULL)
	{
		r->next=p;
	}
	else if(r->value.order!=el.order)
	{
	p->next=r;
	if(prev==NULL)
	{
		head=p;
	}
	else
		prev->next=p;
	}
}
void show(Node *head)
{
	Node *p=head;
	while(p!=NULL)
	{
		cout<<p->value.coeffs << "*x^"<<p->value.order;
		if(p->next!=NULL)
			cout<<" + ";
		p=p->next;
	}
}
int main()
{
	Node *head;
	init(head);
	return 0;
}