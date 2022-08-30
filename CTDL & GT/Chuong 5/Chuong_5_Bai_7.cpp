#include <iostream>
using namespace std;
#define MAX 20
struct Node
{
	int info;
	 Node *link;
};
Node *first[MAX]; // mảng danh sách
int n; // so dinh tren do thi
void init()
{
	for(int i=0;i<n;i++)
		first[i] = NULL;
}
void insert_first(Node *&f, int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = f;
	f = p;
}
void input()
{
int d,x, m;
cout<<"nhap so dinh do thi n: "; 
cin>>n;
for(int i=0;i<n;i++)
{
cout<<"\nnhap dinh thu "<<i+1<<" : ";
cin>>d;
insert_first(first[i],d);
cout<<"nhap vao so dinh ke cua "<<d<<" : ";
cin>>m;
for(int j=0;j<m;j++)
{
	cin>>x;
	insert_first(first[i],x);
}
   }
}
void output_list(Node *f)
{
if(f!=NULL)
{
Node * p=f;
while (p != NULL)
{
	cout<<p->info<<" ";
	p=p->link;
	}
}
}
void output()
{
if(n>0)
for(int i=0;i<n;i++)
{
	cout<<endl<<"Danh sach thu "<<i+1<<": ";
	output_list(first[i]);
}
else 
cout<<"rong";
}
int C[100]; // lưu trữ đỉnh chưa xét; 
void Search_by_BFS(int x, int v) // v là đỉnh bắt đầu
{
int w, p;
PushQueue(v);
C[v]=0;
while(front!=NULL)
{
PopQueue(p);
if (x == p) 
{
	cout<<x<<"ton tai" ;
	return;
}
for(w=0; w<n; w++)
     if(C[w]&&a[p][w]==1)
    {
   PushQueue(w);
   C[w]=0;
	     }
}
}
Node *search(int x)
{
	Node*p=first[MAX];
	while(p!=NULL&&p->info!=x)
		p=p->link;
	return p;
}

Node *front,*rear;
int PushQueue(int x)
{
	Node *p=new Node;
	p->info = x;
	p->link = NULL;	
	if (rear == NULL)
		front =p;
	else
		rear->link = p;
	rear = p;

}
int PopQueue(int &x)
{
		if (front!= NULL)
	{
		Node *p = front;
		x = p -> info;
		front = front ->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}



int main()
{
	system("pause");
	return 0;
}