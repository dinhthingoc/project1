#include<iostream>
using namespace std;

struct phanso
{
	int tuso;
	int mauso;	
};
typedef struct phanso PHANSO;
struct danhsach
{
	PHANSO ps[5];
	int n;
};
typedef struct danhsach DANHSACH;

void nhap_ps(PHANSO &ps);
void xuat_ps(PHANSO ps);
void nhap_ds(DANHSACH &ds);
void xuat_ds(DANHSACH ds);
double phep_tinh(DANHSACH ds);

int main()
{
	PHANSO ps;
	DANHSACH ds;
	ds.n=2;
//	nhap_ps(ps);
//	xuat_ps(ps);
	int x;
	do
	{
		nhap_ds(ds);
		xuat_ds(ds);
		cout<<"\nresult: "<<phep_tinh(ds);
		cout<<"\nyou wants to continue???\n1 = yes \n0 = false\n";
		cin>>x;		
	}
	while(x==1);

	
	
	return 0; 
}
void nhap_ps(PHANSO &ps)
{
	cout<<"\nnhap tu so: ";
	cin>>ps.tuso;
	do
	{
		cout<<"\nnhap mau so: ";
		cin>>ps.mauso;
		if(ps.mauso==0)
		{
			cout<<"\nnhap sai.nhap lai";
		}
	}
	while(ps.mauso == 0);
	
}
void xuat_ps(PHANSO ps)
{
	cout <<ps.tuso <<'/'<<ps.mauso <<"\n";
}
void nhap_ds(DANHSACH &ds)
{
	PHANSO ps;
	for(int i=0;i<ds.n;i++)
	{
		nhap_ps(ds.ps[i]);
	}
}
void xuat_ds(DANHSACH ds)
{
	PHANSO ps;
	for(int i=0;i<ds.n;i++)
	{

		xuat_ps(ds.ps[i]);
	}
}
double phep_tinh(DANHSACH ds)
{
	int x;
	cout<<"\nnhap phep tinh\n 1: +\n 2: -\n 3: *\n 4: /\n ";
	cin>>x;
	int i=0;
	switch(x)
	{
		case 1: 
				return ( (ds.ps[i].tuso * ds.ps[i+1].mauso + ds.ps[i].mauso * ds.ps[i+1].tuso )*1.0 / (ds.ps[i].mauso*ds.ps[i+1].mauso) );
				break;
		case 2:
				return ( (ds.ps[i].tuso*ds.ps[i+1].mauso - ds.ps[i].mauso*ds.ps[i+1].tuso )*1.0 / (ds.ps[i].mauso*ds.ps[i+1].mauso) );
				break;
		case 3:
				return ( (ds.ps[i].tuso*ds.ps[i+1].tuso)*1.0 / (ds.ps[i].mauso*ds.ps[i+1].mauso) );
				break;
		case 4:
		 		return ( (ds.ps[i].tuso*ds.ps[i+1].mauso)*1.0 / (ds.ps[i].mauso*ds.ps[i+1].tuso) );
				break;
	}
}
