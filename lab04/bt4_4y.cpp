#include<iostream>
using namespace std;
#define Max 100

void nhap_mang(int a[], int n);
void xuat_mang(int a[], int n);
void so_le(int a[], int n);
void so_chan(int a[], int n);
void snt(int a[], int n);
void not_snt(int a[], int n);

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
	cout << "\nphan tu le la:";
	so_le(a, n);
	cout << "\nphan tu chan la:";
	so_chan(a, n);
	cout << "\ncac phan tu la so nguyen to la: ";
	snt(a, n);
	cout << "\ncac phan tu khong phai la so nguyen to la: ";
	not_snt(a, n);
	
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
		cout << a[i] << "   ";
	}
}
void so_le(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i <n; i++)
	{
		if (a[i] % 2 != 0)
		{
			cout << a[i] << "   ";
			dem++;
		}
	}
	cout << "\nso luong chu so le la: " << dem;


}
void so_chan(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			cout << a[i] << "   ";
			dem++;
		}
	}
	cout << "\nso luong chu so chan la: "<< dem;
}
bool so_nguyen_to(int n)
{
	if (n == 2)
	{
		return true;
	}
	for (int i = 2; i < n; i++)
	{
		if (n % 2 == 0)
		{
			return false;
		}
	}
	return true;
}
void snt(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (so_nguyen_to(a[i]))
		{
			cout << a[i] << "   ";
		}
	}
}
void not_snt(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (so_nguyen_to(a[i]) == false)
		{
			cout << a[i] << "   ";
		}
	}
}