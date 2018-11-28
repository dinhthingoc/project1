#include<iostream>
using namespace std;
#define Maxd 50
#define Maxc 100

void nhap_ma_tran(int a[][Maxc], int &m, int &n);
void xuat_ma_tran(int a[][Maxc], int m, int n);
void nhap_ma_tranb(int b[][Maxc], int &x, int &y);
void xuat_ma_tranb(int b[][Maxc], int x, int y);
void nhan_ma_tran(int a[][Maxc], int m, int n, int b[][Maxc], int &x, int &y,int c[][Maxc],int &p,int &q);
int main()
{
	int a[Maxd][Maxc];
	int b[Maxd][Maxc];
	int c[Maxd][Maxc];
	int m, n, x,y,p,q;
	do
	{
		cout << "\nnhap so dong m= ";
		cin >> m;
		cout << "\nnhap so cot n= ";
		cin >> n;
		cout << "\nnhap so dong x= ";
		cin >> x;
		cout << "\nnhap so cot y= ";
		cin >> y;
		if (m <= 0 || m > Maxd || n <= 0 || n > Maxd || x <= 0 || x > Maxd || y <= 0 || y > Maxd || n!=x)
		{
			cout << "\nnhap sai.nhap lai";
		}
	} while (m <= 0 || m > Maxd || n <= 0 || n > Maxd || x <= 0 || x > Maxd || y <= 0 || y > Maxd || n != x);
	cout << "\nnhap ma tran a\n";
	nhap_ma_tran(a, m, n);
	cout << "\nxuat ma tran a\n";
	xuat_ma_tran(a, m, n);
	cout << "\nnhap ma tran b\n";
	nhap_ma_tran(b, x, y);
	cout << "\nxuat ma tran b\n";
	xuat_ma_tran(b, x, y);
	cout << "\nma tran sau khi nhan\n";
	nhan_ma_tran(a, m, n, b, x, y, c, p, q);
	xuat_ma_tran(c, p, q);

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
void nhap_ma_tranb(int b[][Maxc], int &x, int &y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << "b[" << i << "][" << j << "]= ";
			cin >> b[i][j];
		}
		cout << endl;
	}
}
void xuat_ma_tranb(int b[][Maxc], int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << b[i][j] << "   ";
		}
		cout << endl;
	}
}
void nhan_ma_tran(int a[][Maxc], int m, int n, int b[][Maxc], int &x, int &y, int c[][Maxc], int &p,int &q)
{
	p = m;
	q = y;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < q; j++)
		{
			c[i][j] = 0;
			for (int k = 1; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}