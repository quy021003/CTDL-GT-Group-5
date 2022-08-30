#include <iostream>
using namespace std;
struct node
{
	int info;
	node *next;
};
node *first,*first1;
void init()
{
	first=NULL;
}
void init1()
{
	first1=NULL;
}
void xuat()
{
	node *p=first;
	while(p!=NULL)
	{
		cout<<p->info<<" ";
		p=p->next;
	}
	cout<<endl;
}
void xuat1()
{
	node *p=first1;
	while(p!=NULL)
	{
		cout<<p->info<<" ";
		p=p->next;
	}
	cout<<endl;
}
void insert_last(int &x)
{
	cout<<"Nhap x: ";
	cin>>x;
	node *p=new node;
	p->info=x;
	p->next=NULL;
	if(first==NULL)
		first=p;
	else
	{
		node *q=first;
		while(q->next!=NULL)
			q=q->next;
		q->next=p;
	}
}
void insert_last1(int &x)
{
	cout<<"Nhap x: ";
	cin>>x;
	node *p=new node;
	p->info=x;
	p->next=NULL;
	if(first1==NULL)
		first1=p;
	else
	{
		node *q=first1;
		while(q->next!=NULL)
			q=q->next;
		q->next=p;
	}
}
void xuatgiao()
{
	for(node *p=first;p!=NULL;p=p->next)
	{
		bool kt=false;
		for(node *q=first1;q!=NULL;q=q->next)
			{
				if(p->info == q->info)
				kt=true;
			}
		if(kt==true) cout<<p->info<<" ";
	}
}
void xuatbu()
{
	for(node *p=first;p!=NULL;p=p->next)
	{
		bool kt=true;
		for(node *q=first1;q!=NULL;q=q->next)
			{
				if(p->info == q->info)
				kt=false;
			}
		if(kt==true) cout<<p->info<<" ";
	}
}
int main(){
	node *p;
	node *q;
	int n1,n2;
	int x;
	cout<<"Muon bao nhieu phan tu mang 1? ";
	cin>>n1;
	for(int i=1;i<=n1;i++)
		insert_last(x);
	xuat();
	cout<<endl;
	cout<<"Muon bao nhieu phan tu mang 2? ";
	cin>>n2;
	for(int i=1;i<=n2;i++)
		insert_last1(x);
	xuat1();
	cout<<"Cac phan tu giao nhau: ";
	xuatgiao();
	xuatbu();
	system("pause");
	return 0;
}