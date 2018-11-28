#include<iostream>
using namespace std;
#define Max 100
void nhap_mang(int a[], int n);
void xuat_mang(int a[], int n);
void dao_nguoc_mang(int a[], int n);
int main()
{
	int a[Max];
	int n;
	do
	{
		cout << "\nnhap n= ";
		cin >> n;
		if (n <= 0 || n > Max)
		{
			cout << "\nnhap sai.nhap lai";
		}
	} while (n <= 0 || n > Max);
	cout << "\n\n\t\tnhap mang\n";
	nhap_mang(a, n);
	cout << "\n\n\t\txuat mang\n";
	xuat_mang(a, n);
	cout << "\nmang sau khi dao la:";
	dao_nguoc_mang(a, n);
	xuat_mang(a, n);
	system("pause");
	return 0;
}
void nhap_mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}
void xuat_mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "   ";
	}
}
void dao_nguoc_mang(int a[], int n)
{
	int m = n / 2;
	for (int i = 0; i <= m; i++) 
	{
		int temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
		m--;
	}
	

}
