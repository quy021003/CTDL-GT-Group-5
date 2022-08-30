#include <iostream>
#include <iomanip>
using namespace std;
struct dathuc //ax+b:đa thức bậc 1
{
	double a,b;
};
struct dathuc2
{
	int a,b,c;
};
void xuat1dathuc2(dathuc2 z)
{
	cout<<z.a<<"x^2"<<" + "<<z.b<<"x"<<" + "<<z.c;
}
void nhap1dathuc(dathuc &n)
{
	cout<<"Nhap a: ";
	cin>>n.a;
	cout<<"Nhap b: ";
	cin>>n.b;
}
void nhapdathuc(dathuc a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap da thuc thu "<<i+1<<" : "<<endl;
		nhap1dathuc(a[i]);
	}
}
void xuat1dathuc(dathuc n)
{
	cout<<n.a<<"x"<<"+"<<n.b<<endl;
}
void xuatdathuc(dathuc a[],int n)
{
	cout<<"-----------------------"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Da thuc thu "<<i+1<<" : "<<endl;
		xuat1dathuc(a[i]);
	}
}
void cong2dathuc(dathuc &x,dathuc &y,dathuc &z)
{
	nhap1dathuc(x);
	nhap1dathuc(y);
	z.a=x.a+y.a;
	z.b=x.b+y.b;
	cout<<"Da thuc ket qua: ";
	xuat1dathuc(z);
}
void tru2dathuc(dathuc &x,dathuc &y,dathuc &z)
{
	nhap1dathuc(x);
	nhap1dathuc(y);
	z.a=x.a-y.a;
	z.b=x.b-y.b;
	cout<<"Da thuc ket qua: ";
	xuat1dathuc(z);
}
void nhan2dathuc(dathuc &x,dathuc &y,dathuc2 &z)
{
	nhap1dathuc(x);
	nhap1dathuc(y);
	z.a=x.a*y.a;
	z.b= x.a*y.b + y.a*x.b;
	z.c= x.b*y.b;
	cout<<"Da thuc ket qua: ";
	xuat1dathuc2(z);
	cout<<endl;
}
void xuatdathucchia(dathuc z)
{
	cout<<z.a<<setprecision(2)<<fixed<<"x + "<<z.b<<setprecision(2)<<fixed;
}
void chia2dathuc(dathuc &x,dathuc &y,dathuc &z)
{
	nhap1dathuc(x);
	nhap1dathuc(y);
	z.a=(x.a/y.a)*1.0;
	z.b=x.b/y.b*1.0;
	setprecision(2);
	cout<<"Da thuc ket qua: ";
	xuatdathucchia(z);
	cout<<endl;
}
int main()
{
	dathuc a[10];
	dathuc x,y,z;
	/*int n;
	cout<<"Nhap bao nhieu da thuc? ";
	cin>>n;
	nhapdathuc(a,n);
	xuatdathuc(a,n);*/
	chia2dathuc(x,y,z);
	system("pause");
	return 0;
}