#include <iostream>
using namespace std;
#define MAX 100//khai báo hằng số
void nhap(int a[],int &n)
{
	cout<<"So luong phan tu: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
}
void xuat(int a[],int n)
{
	cout<<"Tap hop: ";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void xuatgiao(int a[],int b[],int n1,int n2)
{
	cout<<"Tap hop cac phan tu giao nhau: ";
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			if(a[i]==b[j])
				cout<<a[i]<<" ";
		}
	}
}
void xuatbu(int a[],int b[],int n1,int n2)
{
	cout<<"Phan bu: ";
	
	for(int i=0;i<n1;i++)
	{
		bool kt=true;
		for(int j=0;j<n2;j++)
		{
			if(a[i]==b[j])
				kt=false;
		}
		if(kt==true)
			cout<<a[i]<<" ";
	}
}
int main(){
	int a[MAX];
	int b[MAX];
	int n1,n2;
	nhap(a,n1);
	xuat(a,n1);
	cout<<endl;
	nhap(b,n2);
	xuat(b,n2);
	xuatbu(a,b,n1,n2);
	cout<<endl;
	system("pause");
	return 0;
}