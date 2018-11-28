#include<iostream>
using namespace std;
#define Max 100
void nhap_mang(int a[], int n);
void xuat_mang(int a[], int n);
int nho_nhat(int a[], int n);
int lon_nhat(int a[], int n);
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
	cout << "\ngia tri nho nhat cua day so la: " << nho_nhat(a, n);
	cout << "\ngia tri lon nhat cua day so la: " << lon_nhat(a, n);
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
		cout << a[i]<<"   ";
	}
}
int nho_nhat(int a[], int n)
{
	int min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (min>a[i])
		{
			int temp = min;
			min = a[i];
			a[i] = temp;
		}
	}
	return min;
}
int lon_nhat(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max < a[i])
		{
			int temp = max;
			max = a[i];
			a[i] = temp;
		}
	}
	return max;
}