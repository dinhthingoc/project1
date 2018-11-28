#include<iostream>
using namespace std;
#define Maxd 50
#define Maxc 100

void nhap_ma_tran(int a[][Maxc], int &m, int &n);
void xuat_ma_tran(int a[][Maxc], int m, int n);
int tong_ptu(int a[][Maxc], int m, int n);
int main()
{
	int a[Maxd][Maxc];
	int b[100];
	int m, n;
	do
	{
		cout << "\nnhap so dong m= ";
		cin >> m;
		cout << "\nnhap so cot n= ";
		cin >> n;
		if (m <= 0 || m > Maxd || n <= 0 || n > Maxd || m != n)
		{
			cout << "\nnhap sai.nhap lai";
		}
	} while (m <= 0 || m > Maxd || n <= 0 || n > Maxd || m != n);

	cout << "\n\n\t\tnhap ma tran\n";
	nhap_ma_tran(a, m, n);
	cout << "\n\n\t\t xuat ma tran\n";
	xuat_ma_tran(a, m, n);
	cout << "\ntong gia tri cua cac ptu nho nhat tren cac duong cheo songsong duong cheo chinh la: " << tong_ptu(a, m, n);
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
int tong_ptu(int a[][Maxc], int m, int n)
{

	int tong = 0;
	for (int i = 1; i < n; i++)
	{
		int min = 1000;
		for (int j = 0; j < n-i; j++)
		{
			int k = i + j;
			if (a[j][k] < min)
			{
				min = a[j][k];
				
			}
		}
		tong += min;

	}
	for (int i = 1; i < n; i++)
	{
		int min = 1000;
		for (int j = 1; j <= n-1; j++)
		{
			int k = j - i;
			if (k>=0 && a[j][k] < min)
			{
				min = a[j][k];
				
			}
		}
		tong += min;

	}
	
	return tong;
}