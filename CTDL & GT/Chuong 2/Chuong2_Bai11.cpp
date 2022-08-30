#include<iostream>
using namespace std;


//Khai báo cấu trúc Stack
struct Node
{
	int info;
	Node* link;
};
Node* sp;
//Khỏi tạo stack rỗng
void init()
{
	sp = NULL;
}

//Kiểm tra stack rỗng
int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}

//Thêm phần tử vào stack
int Push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
	return 1;
}

//Lấy ra 1 phần tử từ stack
int pop(int& x)
{
	if (sp != NULL)
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//Xuất stack
void process_stack()
{
	Node* p = sp;
	do {
		cout << p->info << " <-- ";
		p = p->link;
	} while (p != NULL);
	cout << "\n";
}
int main()
{
	int choice = 0;
	int sp;
	int x;
	system("cls");
	cout << "--------------------------------- BT 5: STACK DAC ---------------------------------" << endl;
	cout << "1. Khoi tao stack rong" << endl;
	cout << "2. Kiem tra stack rong" << endl;
	cout << "3. Them mot phan tu vao stack" << endl;
	cout << "4. Lay mot phan tu ra khoi stack" << endl;
	cout << "5. Thoat" << endl;

	do {
		cout << "Vui long chon Menu: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Ban vua khoi tao thanh cong stack" << endl;
			break;
		case 2:
			if (isEmpty() == 1)
				cout << "Stack rong" << endl;
			else
				cout << "Stack da co phan tu" << endl;
			break;
		case 3:
			cout << "Nhap gia tri can them vao stack x = ";
			cin >> x;
			Push(x);
			cout << "Stack sau khi them la: ";
			process_stack();
			break;
		case 4:
			pop(x);
			cout << "Phan tu duoc lay ra khoi stack la: " << x << endl;
			cout << "Stack sau khi duoc ra la: ";
			process_stack();
			break;
		case 5:
			cout << "Ket thuc chuong trinh" << endl;
			break;
		default:
			break;
		}
		system("pause");

	} while (choice >= 1 && choice <= 4);
	return 0;
}