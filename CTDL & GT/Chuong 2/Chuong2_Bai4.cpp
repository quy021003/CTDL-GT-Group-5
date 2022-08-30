#include <iostream>
using namespace std;
//4.1 khai bao cau truc danh sach
struct node
{
	int info;
	node* link;
};
node* first;
// 4.2 khoi tao danh sach rong
void init()
{
	first = NULL;
}
//4.3 them mot phan tu vao danh sach co thu tu
int insert(int x)
{
	node* q = first;
	node* p = new node;
	p->info = x;
	p->link = NULL;
	//chen vao ds ko co phan tu
	if (q == NULL)
	{
		first=p;
		return 1;
	}
	//danh sach not phan tu
	if (q->link == NULL)
	{
		if (q->info <= p->info)
		{
			p->link = q;
			first = p;
			return 1;
		}
		else
		{
			q->link = p;
			first = q;
			return 1;
		}

	}
	//danh sach nhieu phan tu
	else
	{
		node* t = first;
		t = t->link;
		while (t != NULL)
		{
			if (p->info > q->info)
			{
				p->link = q;
				first = p;
				return 1;
			}
			if ((p->info <= q->info) && (p->info >= t->info))
			{
				p->link = t;
				q->link = p;
				return 1;
			}
			q = q->link;
			t = t->link;
		}
		q->link = p;
		return 1;
	}
}
//4.4 xuat cac phan tu 
void process()
{
	node* p = first;
	while (p != NULL)
	{
		cout << p->info <<"<--";
		p = p->link;
	}
}
//4.5 tim phan tu
node* search(int x)
{
	node* p = first;
	while ((p != NULL) && (p->info != x))
	{
		p = p->link;
	}
	return p;
}
//4.6 tim va xoa
int search_delete(int x)
{
	node* p = first;
	if (p == NULL) return 0;
	if (p->link == NULL)
	{
		if (p->info == x)
		{
			first = NULL;
			delete p;
			return 1;
		}
		else
		 delete p;
		 return 0;
	}
	else
	{
		node* t = first;
		t = t->link;
		if (p->info == x)
		{
			p = p->link;
			first = p;
			//delete p;
			return 1;
		}
		while(t != NULL)
		{
			if (t->info == x)
			{
				if (t->link == NULL)
				{
					p->link = NULL;
					//delete p, t;
					return 1;
				}
				else
				{
					p->link = t->link;
					//delete p, t;
					return 1;
				}
			}
			t = t->link;
			p = p->link;
		}
		//delete p, t;
		return 0;
	}
}
int main()
{
	cout << "1.khoi tao danh sach rong" << endl;
	cout << "2.chen phan tu" << endl;
	cout << "3.tim phan tu" << endl;
	cout << "4.tim va xoa phan tu" << endl;
	cout << "5.ket thuc" << endl;
	int i, choice,x;
	node* h = NULL;
	do
	{
		cout << "nhap lua chon";
		cin >> choice;
		switch (choice)
		{
		case 1:
			{
				init();
				cout << "danh sach da duoc khoi tao rong" << endl;
				break;
			}
		case 2:
			{
				cout << "nhap so muon chen";
				cin >> x;
				insert(x);
				cout << "danh sach sau khi chen la";
					process();
				cout << endl;
				break;
			}
		case 3:
			{
				cout << "nhap phan tu can tim";
				cin >> x;
				cout << endl;
				h = search(x);
				if (h == NULL)
					cout << "khong tim thay x" << endl;
				else
					cout << "tim thay x trong danh sach" << endl;
				break;
			}
		case 4:
			{
				cout << "nhap x ban muon tim va xoa";
				cin >> x;
				i = search_delete(x);
				if (i == 0)
					cout << "khong tim thay phan tu de xoa" << endl;
				else
					cout << "da tim thay phan tu va da xoa phan tu =x" << endl;
				cout << "danh sach sau khi xoa la";
				process();
				cout << endl;
				break;
			}
		    default:
				break;
		}
	} while (choice != 5);
	return 0;
}