#include<iostream>
using namespace std;
#define Max 100

void nhap_mang(int a[], int n);
void xuat_mang(int a[], int n);
void sap_xep(int a[], int n);
void them_sap_xep(int a[], int &n,int x);

int main()
{
	int a[Max];
	int n,x;
	do
	{
		cout << "\nnhap n= ";
		cin >> n;
		if (n <= 0 || n > Max)
		{
			cout << "\nnhap sai.nhap lai";
		}
	} while (n <= 0 || n > Max);
	cout << "\nnhap gia tri can them: ";
	cin >> x;
	cout << "\n\n\t\tnhap mang\n";
	nhap_mang(a, n);
	cout << "\n\n\t\txuat mang\n";
	xuat_mang(a, n);
	cout << "\nmang sau khi sap xep la: ";
	sap_xep(a, n);
	xuat_mang(a, n);
	cout << "\nmang sau khi them la:";
	them_sap_xep(a, n,x);
	xuat_mang(a, n);
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
void sap_xep(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

}
void them(int a[], int &n,int vt,int x)
{
	for (int i = n-1; i >=vt; i--)
	{
		a[i + 1] = a[i];

	}
	a[vt] = x;
	n++;
}
void them_sap_xep(int a[], int &n,int x)
{
	int i;
	for (i = n - 1; i >= 0; i--)
	{
		if (a[i] < x)
		{
			break;
		}
	}
	i++;
	them(a, n, i, x);
}