#include <iostream>
using namespace std;
#define MAX 100
int a[MAX]
void nhap(int a[],int &n)
{
	cout<<"Nhap so luong phan tu: ";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cout<<"Nhap a["<<i<<"]=";
		cin>>a[i];
	}
}
void xuat(int a[],int n)
{
	cout<<"Danh sach: "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<"\t";
	}
}
int search(int a[],int n,int x)
{
	for(int i=0; i<n; i++)
	{
		if(a[i]==x)
			return i;
	}
	return -1;
}
void addlast(int a[],int &n,int x)
{
	a[n++]=x;
}
void dltlast(int a[],int &n)
{
	n--;
}
void dltInPos_i(int a[],int &n,int k)
{
	for(int i=k;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
	n--;
}
void timvaxoa(int a[],int n,int x)
{
	if(search(a,n,x)!=-1)
		dltInpos_i(a,n,search(a,n,x));
	else return;
}
int main()
{
	return 0;
}