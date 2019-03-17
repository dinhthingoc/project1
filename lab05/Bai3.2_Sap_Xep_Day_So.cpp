#include<iostream>
using namespace std;
#include<iomanip>
#define Max 20000

void Nhap_Day_So(int A[],int &n);
void Xuat_Day_So(int A[],int n);
void Swap(int &a,int &b);
void Sap_Xep_Day_So(int A[],int n);



int main()
{
	int A[Max];
	int n;
	cout<<"\nNhap so luong cua day so nguyen: ";
	cin>>n;
	
	Nhap_Day_So(A,n);
	Xuat_Day_So(A,n);
	cout<<"\nDay so sau khi sap xep\n";
	Sap_Xep_Day_So(A,n);
	Xuat_Day_So(A,n);
	return 0;
}

void Nhap_Day_So(int A[],int &n)
{
	for(int i=0;i<n;i++)
	{
		bool kt;
		do
		{
			kt=true;
			cout<<"A["<<i<<"]= ";
			cin>>A[i];
			int j=i-1;
			if(A[i]<1||A[i]>30000)
			{
				kt=false;
			}
			else
			{
				while(j>=0)
				{
					if(A[i]==A[j])
					{
						kt=false;
						break;
					}
					j--;
				}
			}

		}
		while(kt==false);

	}
}
void Xuat_Day_So(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<setw(20);
	}
	cout<<endl;
}
void Swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void Sap_Xep_Day_So(int A[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(A[i]>A[j])
			{
				Swap(A[i],A[j]);
			}
		}
	}
}
