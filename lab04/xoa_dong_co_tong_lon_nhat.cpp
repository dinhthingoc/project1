#include<iostream>
using namespace std;
#define Maxd 50
#define Maxc 100

void nhap_ma_tran(int a[][Maxc], int &m, int &n);
void xuat_ma_tran(int a[][Maxc], int m, int n);
void tong_dong_lon_nhat(int a[][Maxc], int m, int n, int &csd);
void xoa_dong(int a[][Maxc], int &m, int n, int &csd);
int main()
{
	int a[Maxd][Maxc];
	int m, n,csd;
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
	cout << "\nsau khi xoa dong co tong lon nhat\n";
	xoa_dong(a, m, n, csd);
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

void tong_dong_lon_nhat(int a[][Maxc], int m, int n, int &csd)
{
	int max = 0;
	
	for (int i = 0; i < m; i++)
	{
		int tong = 0;
		for (int j = 0; j < n; j++)
		{
			tong += a[i][j];
			if (tong>max)
			{
				max = tong;
				csd = i;

			}
		}
	}
}
void xoa_dong(int a[][Maxc], int &m, int n,int &csd)
{
	tong_dong_lon_nhat(a, m, n, csd);
	for (int i = csd+1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i + 1][j] = a[i][j];
		}
	}
	m--;
}
