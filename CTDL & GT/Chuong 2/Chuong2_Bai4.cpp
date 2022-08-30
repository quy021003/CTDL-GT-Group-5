#include <iostream>
using namespace std;
struct node
{
	int info;
	node *link;
};
node *first;
void init()
{
	first = NULL;
}
void insert_first(int x)
{
	node *p = new node;
	p->info = x;
	p->link=first;
	first=p;
}
void insert_last(int x)
{
	node *p = new node;
	p->info=x;
	p->link=NULL;
	if(first==NULL) 
		first=p;
	else
	{
		node *q=first;
		while(q->link!=NULL)
			q=q->link;
		q->link=p;
	}
}
void process_list()
{
	node *q=first;
	while(q!=NULL)
	{
		cout<<q->info<<" ";
		q=q->link;
	}
	cout<<endl;
}
node *search(int x)
{
	node *p=first;
	while(p!=NULL && p->info!=x)
		p=p->link;
	return p;
}


int searchanddelete(int x)
{
	if (first != NULL)
	{
		node* p, * q;
		p = first;
		q = first;
		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first && p->link != NULL)
		{
			//ptu giua danh sach
				q->link = p->link;
			delete p;
			return 1;
		}
		else if (p==first && p->info == x)
		{
			//ptu dau ds
			first = p->link;
			delete p;
			return 1;
		}
		else if (p->link == NULL && p->info == x)
		{
			//ptu cuoi ds
			q->link = NULL;
			delete p;
			return 1;
		}
	}
	return 0;
}
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void sapxep()
{
	node *p  = first;
	node *q = p;
	while(p!=NULL)
	{
		q=p;
		p=p->link;
		if(p->info > q->info)
			swap(p->info,q->info);
	}
}
void themvitribatki(int x,int vt)
{
	int n=0;
	for(node *q=first;q!=NULL;q=q->link)
	{
		n++;
	}
	if(first==NULL || vt == 1)
		insert_first(x)
	else if(vt == n+1)
		insert_last(x)
	else if(vt>=2 &&vt<=n)
	{
		int dem=0;
		node *g=new node;
		for(node *q=first;q!=NULL;q=q->link)
		{
			dem++;
			if(dem==vt)
			{
				node *h=new node;
				h->info=x;
				h->link=q;
				g->link=h;
			}
			break;
		}
		g=q;
	}

}
int main()
{
	int temp=0;
	int chon;
	int x;
	do
	{
		system("cls");
		cout<<"1.Khoi tao danh sach"<<endl
			<<"2.Them dau danh sach"<<endl
			<<"3.Them vao cuoi"<<endl
			<<"4.Them vao sau node bat ki"<<endl
			<<"5.Xuat danh sach"<<endl
			<<"6.Tim kiem"<<endl
			<<"7.Xoa dau danh sach"<<endl
			<<"8.Xoa cuoi danh sach"<<endl
			<<"9.Xoa sau node bat ki"<<endl
			<<"10.Xoa node bat ki"<<endl
			<<"11.Thoat"<<endl
			<<"Chon chuc nang: ";
		cin>>chon;
	if(chon==1)
	{
		init();
		cout<<"Khoi tao thanh cong!"<<endl;
		system("pause");
		temp++;
	}
	if(chon==2)
	{
		if(temp==0)
		{
			cout<<"Vui long khoi tao danh sach"<<endl;
			system("pause");
		}
		else
		{
			cout<<"Nhap gia tri can them: ";
			cin>>x;
			insert_first(x);
		}
	}
	if(chon==3)
	{
		if(temp==0)
		{
			cout<<"Vui long khoi tao danh sach"<<endl;
			system("pause");
		}
		else
		{
			cout<<"Nhap gia tri can them: ";
			cin>>x;
			insert_last(x);
		}
	}
	if(chon==4)
	{
		if(temp==0)
		{
			cout<<"Vui long khoi tao danh sach"<<endl;
			system("pause");
		}
		else
		{
			themsaunodebatki(x);
			system("pause");
		}
	}
	if(chon==5)
	{
		if(temp==0)
		{
			cout<<"Vui long khoi tao danh sach"<<endl;
			system("pause");
		}
		else
		{
			process_list();
			system("pause");
		}
	}
	if(chon==6)
	{
		if(temp==0)
		{
			cout<<"Vui long khoi tao danh sach"<<endl;
			system("pause");
		}
	}
	if(chon==7)
	{
		if(temp==0)
		{
			cout<<"Vui long khoi tao danh sach"<<endl;
			system("pause");
		}
		else
		{
			dlt_fst();
			system("pause");
		}
	}
	if(chon==8)
	{
		if(temp==0)
		{
			cout<<"Vui long khoi tao danh sach"<<endl;
			system("pause");
		}
		else
		{
			dlt_lst();
			system("pause");
		}
	}
	if(chon==9)
	{
		if(temp==0)
		{
			cout<<"Vui long khoi tao danh sach"<<endl;
			system("pause");
		}
		else
		{
			dlt_saunodebatki(x);
			system("pause");
		}
	}
	if(chon==10)
	{
		if(temp==0)
		{
			cout<<"Vui long khoi tao danh sach"<<endl;
			system("pause");
		}
		else
		{
			cout<<"Nhap gia tri muon xoa: ";
			cin>>x;
			if(searchanddelete(x)==1)
				cout<<"xoa thanh cong\n";
			else cout<<"xoa khong thanh cong\n";
			system("pause");
		}
	}
	}
	while(chon>=1&&chon<=10);
	system("pause");
	return 0;
}
