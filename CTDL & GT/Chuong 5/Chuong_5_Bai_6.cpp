#include <iostream>
using namespace std;
#define MAX 100
int a[MAX][MAX];
int n;
int c[100];
int bfs[100];
int nbfs[100];
int PushQueue(int a[], int &front, int &rear, int x)
{
	if (rear – front = MAX - 1)
		return 0;
	else
	{
		if (front == -1) 
			front = 0;
		if (rear == MAX - 1) 
		{
			for(int i = front; i<=rear; i++) 
				a[i-front]=a[i];
			rear = MAX -1-front;
			front = 0; 
		}
		a[++rear] = x;
		return 1;
	}
}
int PopQueue(int a[], int &front, int &rear, int &x)
{
	if (front == -1) // hàng đợi rỗng
		return 0;
	else
	{
		x = a[front++];
		if (front > rear) 
		// trường hợp hang đợi có 1 phần tử, sau khi xóa hang rỗng
		{
			front = - 1; 
			rear = -1; 
		}
		return 1;
	}
}

void BFS(int v)
{
	int w,p;
	PushQueue(v);
	c[v]=0;
	while(front!=NULL)
	{
		PopQueue(p);
		bfs[nbfs]=p;
		nbfs++;
		for(w=0;w<n;w++)
			if(C[w]&&a[p][w]==1)
			{
				PushQueue(w);
				c[w]=0;
			}
	}
}
int PushStack(int a[], int &sp, int x)
{
	if (sp< MAX -1)
	{
		a[++sp] = x;
		return 1; 
	}
	return 0;
}
int PopStack(int a[], int &sp, int &x)
{
	if (sp!=-1)
	{
		 x = a[sp--];
		return 1;
	}
	return 0;
}

int C[100];
int dfs[100];
int ndfs=0;  
void DFS(int s)
{       
     PushStack(s); 
   	dfs[ndfs]=s;
     ndfs++;
   	C[s]=0;
    int v=-1, u=s;
    while(!isEmpty())
    {
if(v==n)
		  PopStack(u);
     	for(v=0;v<n;v++)
	   if(a[u][v]!=0 && C[v]==1)
	   {
		  PushStack(u);
  		  PushStack(v);
		  dfs[ndfs]=v;
		  ndfs++;
		  C[v] = 0;
		  u=v;
		  break;
	    }
     }
}
void init()
{
	n=0;
}
void nhap(int a[],int &n)
{
	cout<<"Nhap so dinh: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap vao dong thu "<<i+1<<": ";
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
}
void output(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

int K[100]; 
void Search_by_BFS(int x, int v) 
{
int w, p;
PushStack(v);
K[v]=0;
while(front!=NULL)
{
PopStack(p);
if (x == p) 
{
	cout<<x<<“ton tai” ;
	return;
}
for(w=0; w<n; w++)
     if(K[w]&&a[p][w]==1)
    {
   PushStack(w);
   K[w]=0;
	     }
}
}

int main()
{
	system("pause");
	return 0;
}