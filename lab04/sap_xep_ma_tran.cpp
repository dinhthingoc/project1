#include<iostream>
using namespace std;
#define Maxd 50
#define Maxc 100

void nhap_ma_tran(int a[][Maxc], int &m, int &n);
void xuat_ma_tran(int a[][Maxc], int m, int n);
void chuyen_mang(int a[][Maxc], int m, int n, int b[], int &p);
void sap_xep_mang(int b[], int p);
void chuyen_ma_tran(int a[][Maxc], int m, int n, int b[], int p);
int main()
{
	int a[Maxd][Maxc];
	int b[100];
	int m, n,p;
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
	chuyen_mang(a, m, n, b, p);
	sap_xep_mang(b, p);
	cout << "\nma tran sau khi sap xep\n";
	chuyen_ma_tran(a, m, n, b, p);
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
void chuyen_mang(int a[][Maxc], int m, int n, int b[], int &p)
{
	p = m*n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i*n + j] = a[i][j];
		}
	}
}
void sap_xep_mang(int b[], int p)
{
	for (int i = 0; i < p - 1; i++)
	{
		for (int j = i + 1; j < p; j++)
		{
			if (b[i]>b[j])
			{
				int temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
}
void chuyen_ma_tran(int a[][Maxc], int m, int n, int b[], int p)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = b[i*n + j];
		}
	}
}
