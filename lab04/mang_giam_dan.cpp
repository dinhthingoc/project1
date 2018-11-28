#include<iostream>
using namespace std;
#define Max 100
void nhap_mang(float a[], int n);
void xuat_mang(float a[], int n);
void sap_xep(float a[], int n);
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
	cout << "\nmang giam dan la:";
	sap_xep(a, n);
	xuat_mang(a, n);
	system("pause");
	return 0;
}
void nhap_mang(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}
void xuat_mang(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "   ";
	}
}
void sap_xep(float a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
}
