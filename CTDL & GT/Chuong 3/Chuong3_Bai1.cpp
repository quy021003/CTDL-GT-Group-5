//BAI 1 - CHƯƠNG 3 XẾP THỨ TỰ VÀ TÌM KIẾM
#include<stdio.h>
#include<iostream>
#include<ctime>
using namespace std;
#define MAX 100
//1.1 khai báo cấu trúc danh sách
int a[MAX];

//1.2 Nhập danh sách
void nhapDanhSach(int a[], int &n)
{
	cout << "Nhap so phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap gia tri cac phan tu" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

//1.2* Khởi tạo tự động
void khoiTaoTuDong(int a[], int &n) 
{
	cout << "Nhap so phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000 + 1;
	}
	cout << "Danh sach them vao ngau nhien la: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

//1.3 Xuất danh sách
void xuatDanhSach(int a[], int n)
{
	//cout << "Xuat danh sach cac phan tu trong mang: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

//Hoán vị
void swap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

// Copy array
void copyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}

//1.4 Insertionsort
void Insertionsort(int a[], int n)
{
	int x, i, j;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (j >= 0 && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}


//1.5 Selectionsort
void Selectionsort(int a[], int n)
{
	int min_pos, i, j;
	for (int i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[min_pos])
				min_pos = j;
			swap(a[min_pos], a[i]);
		}
	}

}

//1.6 Interchangesort
void Interchangesort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
	}
}

//1.7 Bubblesort
void Bubblesort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(a[j], a[j - 1]);
	}
}

//1.8 Quicksort
void Quicksort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while(a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(left < j) Quicksort(a, left, i);
	if(i < right) Quicksort(a, i, right);
}
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n) //Nếu vị trí j không tồn tại trong danh sách đang xét thì thoát khỏi chương trình
		return;
	if (j + 1 < n) //Nếu tồn tại vị trí j + 1 trong danh sách đang xét thì thoát khỏi chương trình
		if (a[j] < a[j + 1])
			j++;
	if (a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}

//1.9 Heapsort
void Heapsort(int a[], int n)
{
	int i = (n / 2) - 1;
	while (i >= 0) //Tạo heap ban đầu
	{
		shift(a, i, n);
		i--;
	}
	int right = n - 1; //right là vị trí cuối Heap đang xét
	while (right > 0)
	{
		swap(a[0], a[right]); //Hoán vị phần tử a[0] cho phần tử cuối Heap đang xét
		right--;
		if (right > 0) //Kiểm tra dãy đang xét còn nhiều hơn 1 phần tử
			shift(a, 0, right);
	}
}

int main()
{
	int n, choice;
	bool input = false;
	int b[MAX];
	clock_t start;
	double duration;
	system("cls");
	cout << "------------------------------------ MENU ------------------------------------" << endl;
	cout << "0. Khoi tao danh sach ngau nhien" << endl;
	cout << "1. Nhap danh sach cac phan tu" << endl;
	cout << "2. Xuat danh sach cac phan tu" << endl;
	cout << "3. Sap xep danh sach theo thu tu tang dan bang thuat toan Insertion sort" << endl;
	cout << "4. Sap xep danh sach theo thu tu tang dan bang thuat toan Selection sort" << endl;
	cout << "5. Sap xep danh sach theo thu tu tang dan bang thuat toan Bubble sort" << endl;
	cout << "6. Sap xep danh sach theo thu tu tang dan bang thuat toan Quick sort" << endl;
	cout << "7. Sap xep danh sach theo thu tu tang dan bang thuat toan Heap sort" << endl;
	cout << "8. Sap xep danh sach theo thu tu tang dan bang thuat toan Interchange sort" << endl;
	cout << "9. Ket thuc chuong trinh" << endl;
	do {
		do {
			cout << "Chon MENU: ";
			cin >> choice;
			if (choice < 0 || choice > 9)
				cout << "Loi gia tri, vui long chon lai MENU" << endl;
		} while (choice < 0 || choice > 9);
		switch (choice)
		{
		case 0:
			khoiTaoTuDong(a, n);
			input = true;
			break;
		case 1:
			nhapDanhSach(a, n);
			input = true;
			break;
		case 2:
			if (input == false)
				cout << "Danh sach chua co phan tu, vui long nhap gia tri cho phan tu" << endl;
			else
				xuatDanhSach(a, n);
			break;
		case 3:
			if (input == false)
				cout << "Danh sach chua co phan tu, vui long nhap gia tri cho phan tu" << endl;
			else
			{
				copyArray(a, b, n);
				start = clock();
				Insertionsort(a, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi sap xep voi Insertion sort la: " << endl;
					xuatDanhSach(a, n);
				}
				if (duration > 0)
				{
					cout << "Thoi gian Insertion sort la " << duration * 1000000 << "Miliseconds" << endl;
				}
			}	
			break;
		case 4:
			if (input == false)
				cout << "Danh sach chua co phan tu, vui long nhap gia tri cho phan tu" << endl;
			else
			{
				copyArray(a, b, n);
				start = clock();
				Selectionsort(a, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi sap xep voi Selection sort la: " << endl;
					xuatDanhSach(a, n);
				}
				if (duration > 0)
				{
					cout << "Thoi gian Selection sort la " << duration * 1000000 << "Miliseconds" << endl;
				}
			}
			break;
		case 5:
			if (input == false)
				cout << "Danh sach chua co phan tu, vui long nhap gia tri cho phan tu" << endl;
			else
			{
				copyArray(a, b, n);
				start = clock();
				Bubblesort(a, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi sap xep voi Bubble sort la: " << endl;
					xuatDanhSach(a, n);
				}
				if (duration > 0)
				{
					cout << "Thoi gian Bubble sort la " << duration * 1000000 << "Miliseconds" << endl;
				}
			}
			break;
		case 6:
			if (input == false)
				cout << "Danh sach chua co phan tu, vui long nhap gia tri cho phan tu" << endl;
			else
			{
				copyArray(a, b, n);
				start = clock();
				Quicksort(b, 0, n - 1);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi sap xep voi Quick sort la: " << endl;
					xuatDanhSach(b, n);
				}
				if (duration > 0)
				{
					cout << "Thoi gian Quick sort la " << duration * 1000000 << "Miliseconds" << endl;
				}
			}
			break;
		case 7:
			if (input == false)
				cout << "Danh sach chua co phan tu, vui long nhap gia tri cho phan tu" << endl;
			else
			{
				copyArray(a, b, n);
				start = clock();
				Heapsort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi sap xep voi Heap sort la: " << endl;
					xuatDanhSach(b, n);
				}
				if (duration > 0)
				{
					cout << "Thoi gian Heap sort la " << duration * 1000000 << "Miliseconds" << endl;
				}
			}
			break;
		case 8:
			if (input == false)
				cout << "Danh sach chua co phan tu, vui long nhap gia tri cho phan tu" << endl;
			else
			{
				copyArray(a, b, n);
				start = clock();
				Interchangesort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi sap xep voi Interchange sort la: " << endl;
					xuatDanhSach(b, n);
				}
				if (duration > 0)
				{
					cout << "Thoi gian Interchange sort la " << duration * 1000000 << "Miliseconds" << endl;
				}
			}
			break;
		case 9:
			break;
		default:
			break;
			system("pause");
		}
	} while (choice >= 0 && choice <= 8);
	return 0;
}