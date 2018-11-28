#include<iostream>
using namespace std;
#define Maxd 50
#define Maxc 100
void nhap_ma_tran(int a[][100], int &m, int &n);
void xuat_ma_tran(int a[][100], int m, int n);
int tinh_tong(int a[][100], int n,int &x);
int main()
{
	int a[Maxd][Maxc];
	int m,n,x;
	do
	{
		cout << "\nnhap so dong m= ";
		cin >> m;
		cout << "\nnhap so cot n= ";
		cin >> n;
		cout << "\nnhap dong can tinh tong x= ";
		cin >> x;
		if (m <= 0 || m > Maxd || n <= 0 || n > Maxc ||n>m-1)
		{
			cout << "\nnhap sai.nhap lai";
		}
	} while (m <= 0 || m > Maxd || n <= 0 || n > Maxc|| n>m-1);

	cout << "\n\n\t\tnhap ma tran\n";
	nhap_ma_tran(a, m, n);
	cout << "\n\n\t\txuat ma tran\n";
	xuat_ma_tran(a, m, n);
	cout << "\ntong tren 1 dong dau la: " << tinh_tong(a, n,x);
	system("pause");
	return 0;
}
void nhap_ma_tran(int a[][100], int &m, int &n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" <<i<<"]["<<j<<"]=  ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}
void xuat_ma_tran(int a[][100], int m, int n)
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
int tinh_tong(int a[][100], int n,int &x)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += a[x][i];
	}
	return tong;
}