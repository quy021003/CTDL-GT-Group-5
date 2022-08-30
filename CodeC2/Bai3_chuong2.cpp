#include<iostream>
using namespace std;

//Cau 3.1
struct Node {
	int info;
	Node* link;
};
Node* first;

//Cau 3.2 Khởi tạo danh sách rỗng
void init()
{
	first = NULL;
}

//Câu 3.3 Xuất danh sách
void Process_List()
{
	Node* p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}

//Câu 3.4 Tìm phần tử trong danh sách
Node* Search(int x)
{
	Node* p = first;
	while (p != NULL && p->info != x)
	{
		p = p->link;
	}
	return p;
}

//Câu 3.5 Thêm đầu danh sách
void Insert_first(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
//Câu 3.6 Xóa phần tử đầu danh sách
int Delete_first()
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
//Câu 3.7 Thêm cuối danh sách
void Insert_last(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
	{
		first = p;
	}
	else
	{
		Node* q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}
//Câu 3.8 Xóa cuối danh sách
int Delete_last()
{
	if (first != NULL)
	{
		Node* p, * q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
		{
			q->link = NULL;
		}
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//Câu 3.9 Tìm và xóa phần tử
int SearchAndDelete(int x)
{
	if (first != NULL)
	{
		Node* p, * q;
		p = first;
		q = first;
		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first && p->link != NULL)
		{
			//Phần tử giữa danh sách
			if (p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
		}
		else
			if (p == first)
			{
				//Phần tử đầu danh sách
				first = p->link;
				delete p;
			}
			else
				if (p->link == NULL && p->info == x)
				{
					//Phần tử cuối danh sách
					q->link = NULL;
					delete p;
				}
		return 1;
	}
	return 0;
}

int main()
{
	int choice = 0;
	int x, i;
	Node* p;
	system("cls");
	cout << "--------------------------------- BT 3, Chuong 2 - DSLK DON ---------------------------------" << endl;
	cout << "1. Khoi tao danh sach lien ket don rong" << endl;
	cout << "2. Them phan tu vao dau danh sach" << endl;
	cout << "3. Them phan tu vao cuoi danh sach" << endl;
	cout << "4. Xoa phan tu o dau danh sach" << endl;
	cout << "5. Xoa phan tu o cuoi danh sach" << endl;
	cout << "6. Xuat danh sach lien ket don" << endl;
	cout << "7. Tim phan tu gia tri x trong danh sach lien ket don" << endl;
	cout << "8. Tim va xoa phan tu gia tri x trong danh sach lien ket don" << endl;
	cout << "9. Thoat" << endl;

	do {
		cout << "Vui long chon Menu: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Ban vua khoi tao thanh cong danh sach lien ket don" << endl;
			break;
		case 2:
			cout << "Vui long nhap x: ";
			cin >> x;
			Insert_first(x);
			cout << "Sau khi them dau danh sach voi gia tri x = " << x << " la: ";
			Process_List();
			break;
		case 3:
			cout << "Vui long nhap x = ";
			cin >> x;
			Insert_last(x);
			cout << "Sau khi them cuoi danh sach voi gia tri x = " << x << "la: ";
			Process_List();
			break;
		case 4:
			i = Delete_first();
			if (i == 0)
				cout << "Xoa khong thanh cong, danh sach rong" << endl;
			else
			{
				cout << "Xoa thanh cong phan tu dau danh sach, danh sach sau khi xoa la: " << endl;
				Process_List();
			}
			break;
		case 5:
			i = Delete_last();
			if (i == 0)
			{
				cout << "Xoa khong thanh cong, danh sach rong" << endl;
			}
			else
			{
				cout << "Xoa thanh cong phan tu cuoi danh sach, danh sach sau khi xoa la: " << endl;
				Process_List();
			}
			break;
		case 6:
			cout << "Danh sach lien ket hien tai la: " << endl;
			Process_List();
			break;
		case 7:
			cout << "Vui long nhap gia tri can tim x = ";
			cin >> x;
			p = Search(x);
			if (p == NULL)
				cout << "Khong tim thay x = " << x << " trong danh sach lien ket don" << endl;
			else
				cout << "Tim thay x = " << x << " trong danh sach lien ket don" << endl;
			break;
		case 8:
			cout << "Vui long nhap gia tri can tim x = ";
			cin >> x;
			i = SearchAndDelete(x);
			if (i == 0)
				cout << "Khong tim thay x = " << x << " trong danh sach lien ket don" << endl;
			else
			{
				cout << "Tim thay x = " << x << " trong danh sach lien ket don" << endl;
				cout << "Danh sach sau khi xoa la: " << endl;
				Process_List();
			}
			break;
		case 9:
			cout << "Ket thuc chuong trinh" << endl;
			break;
		default:
			break;
		}
		system("pause");

	} while (choice >= 1 && choice <= 8);
	return 0;
}