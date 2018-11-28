#include<iostream>
using namespace std;
#define Maxd 50
#define Maxc 100

void nhap_ma_tran(int a[][Maxc], int &m, int &n);
void xuat_ma_tran(int a[][Maxc], int m, int n);
int tinh_tong(int a[][100], int m,int n);
int main()
{
	int a[Maxd][Maxc];
	int m, n;
	do
	{
		cout << "\nnhap so dong m= ";
		cin >> m;
		cout << "\nnhap so cot n= ";
		cin >> n;
		if (m <= 0 || m > Maxd || n <= 0 || n > Maxd)
		{
			cout << "\nnhap sai.nhap lai";
		}
	} while (m <= 0 || m > Maxd || n <= 0 || n > Maxd);

	cout << "\n\n\t\tnhap ma tran\n";
	nhap_ma_tran(a, m, n);
	cout << "\n\n\t\t xuat ma tran\n";
	xuat_ma_tran(a, m, n);
	cout << "\ntong tren duong chep chinh la: " << tinh_tong(a, m,n);
	system("pause");
	return 0;
}
void nhap_ma_tran(int a[][Maxc], int &m, int &n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}
void xuat_ma_tran(int a[][Maxc], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}
}
int tinh_tong(int a[][Maxc], int m,int n)
{
	int tong = 0;
	for (int i = 0; i < m; i++)
	{
		int max=a[i][0];
		for (int j = 0; j < n; j++)
		{
			if (a[i][j]>max)
			{
				int temp = max;
				max = a[i][j];
				a[i][j] = max;
			}
		}
		tong += max;

	}
	return tong;
}