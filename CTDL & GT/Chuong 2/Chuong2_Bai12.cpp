#include <iostream>
using namespace std;
struct node
{
	int info;
	node *pre,*next;
};
node *first,*last;
void init()
{
	first=lsat=NULL;
}
void xuat()
{
	node *p=first;
	while(p!=NULL)
	{
		cout<<p->info<<" ";
		p=p->next;
	}
}
void themdau(int x)
{
	node *p=new node;
	p->info=x;
	p->next=first;
	p->pre=NULL;
	if(first!=NULL)
		first->pre=p;
	else
		last=p;
	first=p;
}
void themcuoi(int x)
{
	node *p=new node;
	p->info=x;
	p->next=NULL;
	p->pre=last;
	if(last!=NULL)
		last->next=p;
	else
		first=p;
	last=p;
}
void xoadau()
{
	if(first!=NULL)
	{
		node *p=first;
		first=first->next;
		if(first!=NULL)
			first->pre=NULL;
		else
			last=NULL;
		delete p;
	}
	return
}
void xoacuoi()
{
	if(lasst!=NULL)
	{
		node *p=last;
		last=last->pre;
		if(lasst!=NULL)
			last->next=NULL;
		else
			first=NULL;
		delete p;
	}
	return
}
node *search(int x)
{
	node *p=first;
	while(p!=NULL && p->info!=x)
	{
		p=p->next;
	}
	return p;
}
void timvaxoa(int x)
{
	if(search(x)!=NULL)
	{
		node *p=search(x);
		if(p->pre==NULL)
			xoadau();
		if(p->next==NULL)
			xoacuoi();
		if(p->pre!=NULL && p->next!=NULL)
		{
			node *q=p->pre;
			node *k=p->next;
			q->next=k;
			k->pre=q;
		}
	}
	return;
}
node  *timgannhat(int x)
{
	if(search(x)!=NULL) return search(x);
	else
	{
		node *p=first;
		while(p!=NULL)
		{
			if(p->info>x)
				return p;
			else
			p=p->link;
		}
	}
}
void themTruocNodeGanNhat(int x)
{
	node *p=timgannhat(x);
	if(p!=NULL)
	{
		node *k=new node;
		if(p==first)
			themdau(int x);
		if(p==last)
			themcuoi(int x);
		if(p!=last&&p!=first)
		{
		k->info=x;
		k->pre=p->pre;
		k->next=p;
		p->pre=k;
		}
	}
	return;
}
int main(){
	system("pause");
	return 0;
}