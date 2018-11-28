#include<iostream>
using namespace std;
#define Maxd 50
#define Maxc 100

void nhap_ma_tran(int a[][Maxc], int &m, int &n);
void xuat_ma_tran(int a[][Maxc], int m, int n);
void nhap_mang_them(int b[], int n);
void them(int a[][Maxc], int m, int &n, int vt, int b[]);

int main()
{
	int a[Maxd][Maxc];
	int b[100];
	int m, n, vt;
	do
	{
		cout << "\nnhap so dong m= ";
		cin >> m;
		cout << "\nnhap so cot n= ";
		cin >> n;
		cout << "\nnhap vi tri cot can chen vt= ";
		cin >> vt;
		if (m <= 0 || m > Maxd || n <= 0 || n > Maxd || vt<0 || vt>n)
		{
			cout << "\nnhap sai.nhap lai";
		}
	} while (m <= 0 || m > Maxd || n <= 0 || n > Maxd || vt<0 || vt>n);

	cout << "\n\n\t\tnhap ma tran\n";
	nhap_ma_tran(a, m, n);
	cout << "\n\n\t\t xuat ma tran\n";
	xuat_ma_tran(a, m, n);
	cout << "\nnhap mang can them\n";
	nhap_mang_them(b, n);
	cout << "\nsau khi them 1 cot\n";
	them(a, m, n, vt, b);
	xuat_ma_tran(a, m, n);

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
void nhap_mang_them(int b[], int m)
{
	for (int i = 0; i < m; i++)
	{
		cout << "b[" << i << "]= ";
		cin >> b[i];
	}
}
void them(int a[][Maxc], int m, int &n, int vt, int b[])
{
	for (int i = n - 1; i >= vt; i--)
	{
		for (int j = 0; j < m; j++)
		{
			a[j][i+1] = a[j][i];
		}
	}
	for (int i = 0; i < m; i++)
	{
		a[i][vt] = b[i];
	}
	n++;
}

