#include <iostream>
using namespace std;
#define MAX 100
int a[MAX]
void them(int a[],int &n,int k,int x)
{
	if(k>=0&&k<=n-1)
	{
	for(int i=n;i>k;i++)
	{
		a[i]=a[i-1];
	}
	a[k]=x;
	n++;
	}
	return;
}
void xuat(int a[],int n)
{
	cout<<"Danh sach: "<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
int timKiemTuanTu(int a[],int n,int x)
{
	for(int i=0;i<n;i++)
		if(a[i]==x)
			return i;
	return -1;
}
int timKiemNhiPhan(int a[],int n,int x)
{
	int left = 0;
	int right = n-1;
	int mid;
	while(left<=right)
	{
		mid = 0.5 * (left + right);
		if(a[mid]==x) return mid;
		if(x>a[mid]) left=mid+1;
		else right = mid - 1;
	}
	return 0;
}
void xoa(int a[],int &n,int k)
{
	for(int i=k;i<n-1;i++)
		a[i]=a[i+1];
	n--;
}
void timvaxoa(int a[],int &n,int x)
{
	if(timKiemNhiPhan(a,n,x)!=0)
		xoa(a,n,timKiemNhiPhan(a,n,x));
}
int main()
{
	return 0;
}