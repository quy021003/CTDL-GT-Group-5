﻿#include <iostream>
#include <conio.h>
using namespace std;

//3.1
struct Node
{
	int info;
	Node* link;
};
Node* first;

//3.2 Khởi tạo danh sách
void init()
{
	first = NULL;
}
void inputX(int &x)
{
	cout << "Nhap gia tri X can tim/them/xoa: ";
	cin >> x;
}

//3.3 Xuất danh sách
void process_list()
{
	Node* p;
	p = first;
	while (p != NULL)
	{
		cout << p->info;
		p = p->link;
		if (p != NULL)
			cout << ", ";
	}
}

//3.4 Tìm phần tử trong danh sách 
Node* search(int x)
{
	Node* p = first;
	while ((p != NULL) && (p->info != x))
		p = p->link;
	return p;
}

//3.5 Thêm phần tử đầu danh sách
void intsert_first(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

//3.6 Xóa phần tử đầu danh sách
int delete_first()
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

//3.7 Thêm phần tử cuối danh sách
void insert_last(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)//danh sach rong
		first = p;
	else
	{
		Node* q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}

//3.8 Xóa phần tử cuối danh sách
int delete_last()
{
	if (first != NULL)
	{
		Node* p, * q;
		p = first; q = NULL;
		if (p != NULL)
				while (p->link != NULL)
			{
				q = p;
				p = p->link;
			}
		if (p != first)
			q->link = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}


//3.9 Tìm và xóa 
int	searchDelete(int x)
{
	if (first != NULL)
	{
		Node* p, * q;
		p = first;
		q = NULL;
		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first && p->link != NULL)
		{
			if (p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
		}
		else if (p == first)
		{
			first = p->link;
			delete p;
		}
		else if (p->link == NULL && p->info == x)
		{
			q->link = NULL;
			delete p;
		}
		return 1;
	}
	return 0;
}
//int delete_after(int x)
//{
//	Node* q = search(x);
//	if (q == NULL)
//		return 0;
//	if (q->link == NULL)
//		return 0;
//	Node* p = q->link;
//	q->link = p->link;
//	delete p;
//	return 1;
//}

void Menu()
{
	int op, x;
	bool flag = false;
	do
	{
		system("cls");
		cout << "\n\t\t==============MENU==============\n";
		cout << "\t\t 1.Khoi tao danh sach rong\n";
		cout << "\t\t 2.Xuat danh sach\n";
		cout << "\t\t 3.Tim phan tu trong danh sach\n";
		cout << "\t\t 4.Them phan tu vao dau danh sach\n";
		cout << "\t\t 5.Xoa phan tu dau danh sach\n";
		cout << "\t\t 6.Them phan tu vao cuoi danh sach\n";
		cout << "\t\t 7.Xoa phan tu vao cuoi danh sach\n";
		cout << "\t\t 8.Tim phan tu roi xoa phan tu do\n";
		cout << "\t\t 9.Thoat chuong trinh\n";
		cout << "\t\t=================================\n";
		cout << "Moi ban chon chuc nang: ";
		cin >> op;
		switch (op)
		{
		case 1:
			init();
			cout << "==Khoi tao danh sach thanh cong! " << endl;
			flag = true;
			break;
		case 2:
			if (flag)
			{
				cout << "- Danh sach: ";
				process_list();
			}
			else
				cout << "<!> Vui long khoi tao danh sach truoc" << endl;
			break;
		case 3:
			if (flag)
			{
				inputX(x);
				if (search(x) != NULL)
					cout << x << " co trong danh sach " << endl;
				else
					cout << x << " khong co trong danh sach " << endl;
			}
			else
				cout << "<!> Vui long khoi tao danh sach truoc" << endl;
			break;
		case 4:
			if (flag)
			{
				inputX(x);
				intsert_first(x);
				cout << "=> Them phan tu vao dau danh sach thanh cong!" << endl;
			}
			else
				cout << "<!> Vui long khoi tao danh sach truoc" << endl;
			break;
		case 5:
			if (flag)
			{
				delete_first();
				cout << "=> Xoa phan tu dau danh sach thanh cong! " << endl;
			}
			else
				cout << "<!> Vui long khoi tao danh sach truoc" << endl;
			break;
		case 6:
			if (flag)
			{
				inputX(x);
				insert_last(x);
				cout << "=> Them phan tu vao cuoi danh sach thanh cong!" << endl;
			}
			else
				cout << "<!> Vui long khoi tao danh sach truoc" << endl;
			break;
		case 7:
			if (flag)
			{
				delete_last();
				cout << "=> Xoa phan tu cuoi danh sach thanh cong! " << endl;
			}
			else
				cout << "<!> Vui long khoi tao danh sach truoc" << endl;
			break;
		case 8:
			if (flag)
			{
				inputX(x);
				int result = searchDelete(x);
				if (result == 1)
					cout << "=> Tim thay va xoa thanh cong! " << endl;
				else
					cout << "<!> Tim thay va xoa thanh cong" << endl;

				
			}
			else
				cout << "<!>Vui long khoi tao danh sach truoc" << endl;
			break;
		case 9:
			cout << "==THOAT CHUONG TRINH==" << endl;
			break;
		default:
			cout << "==>KHONG CO CHUC NANG<== " << endl;
		}
		_getch();
	} while (op != 9);
}
int main()
{
	Menu();
	system("pause");
	return 0;
}