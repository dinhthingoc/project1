#include<iostream>
using namespace std;
#define Maxd 50
#define Maxc 100

void nhap_ma_tran(int a[][Maxc], int &m, int &n);
void xuat_ma_tran(int a[][Maxc], int m, int n);
void vitri(int a[][100], int m, int n, int &csd, int &csc);
int main()
{
	int a[Maxd][Maxc];
	int m, n, csd, csc;
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
	cout << "\nvi tri phan tu chan cuoi cung la: ";
	vitri(a, m, n, csd, csc);
	{
		cout << "a[" << csd << "][" << csc << "]";
	}
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
void vitri(int a[][Maxc], int m, int n, int &csd, int &csc)
{

	for (int i = n-1; i >=0; i--)
	{
		for (int j = n-1; j >=0; j--)
		{
			if (a[i][j]%2==0)
			{
				csd = i;
				csc = j;
				break;
			}
		}
		break;
	}
}