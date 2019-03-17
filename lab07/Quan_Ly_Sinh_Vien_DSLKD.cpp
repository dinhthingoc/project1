#include<iostream>
using namespace std;
#include<string.h>
#include<string>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include<string>

struct sinhvien
{
	int MSSV;
	char HoTen[30];
	
};
typedef struct sinhvien Sinhvien;

//ham nhap thong tin 1 sinh vien
void Nhap_Thongtin_SV(Sinhvien &sv);
//ham xuat thong tin 1 sinh vien
void Xuat_Thongtin_SV(Sinhvien sv);


struct node
{
	Sinhvien data;
	node *pNext;	
};
typedef struct node* Node;

//ham kiem tra ki tu so
bool Kiem_Tra(char c);
//ham chuyen chuoi sang so
int Chuyen_Chuoi_Sang_So(string str);
//ham nhap so nguyen
int Nhap_So_Nguyen();

//khoi tao danh sach
void Init(Node &First);
//tao node
Node TaoNode(Sinhvien sv);
//ham kiem tra danh sach
bool IsEmpty(Node First);
//ham duyet danh sach
void Traverse(Node First);
//ham them dau danh sach
void Insert_First(Node &First,Node sv);
//ham them cuoi danh sach
void Insert_Last(Node &First,Node sv);
//ham them node q vao sau node p trong danh sach
void Insert_after(Node &p,Node &q);

//ham dem tong so node trong danh sach
int Reccount(Node First);
//ham them phan tu vao sau phan tu thu i trong danh sach
void Insert_i(Node &First,Node sv,int i);
//tim thong tin sinh vien theo ma sinh vien
void Search_Info(Node First,int ma);
//ham xoa dau danh sach
int Delete_First(Node &First);
//ham xoa node sau node p
int Delete_after(Node &p);
//ham xoa node theo ma sinh vien
int Delete_Info(Node &First,int ma);
//ham sap xep danh sach tang dan theo ma so
void Selection_Sort(Node First);



//ham ghi danh sach vao file(mo de ghi)
void WriteFile(ofstream &fileOut, Node First);



//tim do dai chuoi
int STRLEN(char c[]);
//ham xoa ki tu
void Xoa_Ki_Tu(char str[],int vt);
void Chuan_Hoa_Chuoi(char str[]);

//ham doc danh sach tu file vao danh sach lien ket don(mo de doc)
void ReadFile(ifstream &fileIn,Node &First);

//ham xoa danh sach
void ClearList(Node &First);


void Menu(Node &First);



int main()
{
	Node First;
	Init(First);
	
	Menu(First);
	
	
	return 0;
}
//ham kiem tra ki tu so
bool Kiem_Tra(char c)
{
	if(c>='0'&& c<='9')
	{
		return true;
	}
	else
	{
		return false;
	}
}
//ham chuyen chuoi sang so
int Chuyen_Chuoi_Sang_So(string str)
{
	int so=0;
	int n=str.length();
	int i=0;
	while(i<n)
	{
		so=so*10+(str[i]-48);
		i++;
	}
	return so;
}
//ham nhap so nguyen
int Nhap_So_Nguyen()
{
	string str;
	char c;
	c = getch();


	while((int)c != 13)
	{

		if(int(c) == 8)
		{

			if(str.length() != 0) 
			{
				//xoa ki tu cuoi cua chuoi tren man hinh
				cout << "\b \b"; 
				//xoa ki tu cuoi cua chuoi
				str.erase(str.begin() + (str.length() - 1));
			}	
		}
		else 
		{
			cout << c;
			if(Kiem_Tra(c) == false)
			{
				cout << "\nKieu du lieu khong hop le. Xin nhap lai\n";
				str.resize(0);
			}
			else
			{
				str.push_back(c);
			}
		}
		c = getch();
	}
	return Chuyen_Chuoi_Sang_So(str);
}
//ham nhap thong tin 1 sinh vien
void Nhap_Thongtin_SV(Sinhvien &sv)
{
	cout<<"\nNhap ma so sinh vien: ";
	sv.MSSV=Nhap_So_Nguyen();
	fflush(stdin);
	cout<<"\nNhap Ho ten sinh vien: ";
	gets(sv.HoTen);
}
//ham xuat thong tin 1 sinh vien
void Xuat_Thongtin_SV(Sinhvien sv)
{
	cout<<setw(10)<<sv.MSSV<<setw(30)<<sv.HoTen;
}


//khoi tao danh sach
void Init(Node &First)
{
	First=NULL;
}
//tao node
Node TaoNode(Sinhvien sv)
{
	Node SV=new node;
	SV->data=sv;
	SV->pNext=NULL;
	return SV;
}
//ham kiem tra danh sach
bool IsEmpty(Node First)
{
	if(First==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//ham duyet danh sach
void Traverse(Node First)
{
	if(IsEmpty(First))
	{
		return;
	}
	else
	{
		cout<<setw(10)<<"MSSV"<<setw(30)<<"Ho Ten\n";
		for(Node k=First;k!=NULL;k=k->pNext)
		{
			Xuat_Thongtin_SV(k->data);
			cout<<endl;
		}
	}
}
//ham them dau danh sach
void Insert_First(Node &First,Node sv)
{
	if(IsEmpty(First))
	{
		First=sv;
	}
	else
	{
		sv->pNext=First;
		First=sv;
	}
}
//ham them node q vao sau node p trong danh sach
void Insert_after(Node &p,Node &q)
{
	if(p==NULL)
	{
		return;
	}
	else
	{
		q->pNext=p->pNext;
		p->pNext=q;
	}
}
//ham them cuoi danh sach
void Insert_Last(Node &First,Node sv)
{
	if(IsEmpty(First))
	{
		First=sv;
	}
	else
	{
		Node k;
		for(k=First;k->pNext!=NULL;k=k->pNext);
		Insert_after(k,sv);
		
	}
}
//ham dem tong so node trong danh sach
int Reccount(Node First)
{
	int dem=0;
	if(IsEmpty(First))
	{
		return 0;
	}
	else
	{
	
		Node k=First;
		while(k!=NULL)
		{
			dem++;
			k=k->pNext;
		}
	}
	return dem;
}
//ham them phan tu vao sau phan tu thu i trong danh sach
void Insert_i(Node &First,Node sv,int i)
{
	if(i==0)
	{
		Insert_First(First,sv);
	}
	else if(i>Reccount(First))
	{
		Insert_Last(First,sv);
	}
	else
	{
		Node k;
		int dem=0;
		for(k=First;k!=NULL&& dem<i-1;dem++,k=k->pNext);
		if(dem==i-1)
		{
			Insert_after(k,sv);
		}

	}
}
//tim thong tin sinh vien theo ma sinh vien
void Search_Info(Node First,int ma)
{
	if(IsEmpty(First))
	{
		return;
	}
	else
	{
		for(Node k=First;k!=NULL;k=k->pNext)
		{
			if(k->data.MSSV==ma)
			{
				Xuat_Thongtin_SV(k->data);
				break;
			}
		}
	}
}
//ham xoa dau danh sach
int Delete_First(Node &First)
{
	if(IsEmpty(First))
	{
		return 0;
	}
	else
	{
		Node q=First;
		First=First->pNext;
		delete q;
	}
}
//ham xoa node sau node p
int Delete_after(Node &p)
{
	if(p==NULL || p->pNext==NULL)
	{
		return 0;
	}
	else
	{
		Node q=p->pNext;
		p->pNext=q->pNext;
		delete q;
	}
	return 1;
}
//ham xoa node theo ma sinh vien
int Delete_Info(Node &First,int ma)
{
	if(IsEmpty(First))
	{
		return 0;
	}
	else if(First->data.MSSV==ma)
	{
		char x;
		cout<<"\nBan thuc su muon xoa (Y/N)? ";
		cin>>x;
		if(x=='Y')
		{
			Delete_First(First);
			return 1;
		}
		
		
	}
	else
	{
		Node k;
		for(k=First;k->pNext!=NULL && k->pNext->data.MSSV!=ma;k=k->pNext);
		
		if(k->pNext!=NULL)
		{
			char x;
			cout<<"\nBan thuc su muon xoa (Y/N)? ";
			cin>>x;
		
			if(x=='Y')
			{
				Delete_after(k);
		
			}
		
		}
	
		
	}
	return 1;
}
//ham sap xep danh sach theo ma so tang dan
void Selection_Sort(Node First)
{
	if(IsEmpty(First))
	{
		return;
	}
	else
	{
		Node kmin;
		Sinhvien tam;
		int min;
		for(Node k=First;k->pNext!=NULL;k=k->pNext)
		{
			kmin=k;
			tam=k->data;
			min=k->data.MSSV;
			for(Node p=k->pNext;p!=NULL;p=p->pNext)
			{
				if(p->data.MSSV<min)
				{
					min=p->data.MSSV;
					tam=p->data;
					kmin=p;
				}
			}
			kmin->data=k->data;
			k->data=tam;
		}
	}
}

//ham ghi danh sach vao file(mo de ghi)
void WriteFile(ofstream &fileOut, Node First)
{
	fileOut.open("DSSV.DAT.txt",ios::out);
	fileOut<<setw(10)<<"MSSV"<<setw(30)<<"HO TEN\n";
	for(Node k=First;k!=NULL;k=k->pNext)
	{
		
		fileOut<<setw(10)<<k->data.MSSV<<setw(30)<<k->data.HoTen;
		if(k->pNext!=NULL)
		{
			fileOut<<endl;
		}
		
	}
	fileOut.close();
}

//ham tim do dai cua chuoi
int STRLEN(char c[])
{
	int i=0;
	while(c[i]!='\0')
	{
	
		i++;
	}
	return i;
}
//ham xoa ki tu
void Xoa_Ki_Tu(char str[],int vt)
{
	int n=STRLEN(str);
	for(int i=vt;i<n;i++)
	{
		str[i]=str[i+1];
		
	}
	str[n-1]='\0';
}
void Chuan_Hoa_Chuoi(char str[])
{
	int n=STRLEN(str);
	int i=0;
	while(str[i]==' ')
	{
		Xoa_Ki_Tu(str,i);
		
	}
	while(str[n-1]==' ')
	{
		str[n-1]='\0';
		n--;
	}

}

//ham doc danh sach tu file vao danh sach lien ket don(mo de doc)
void ReadFile(ifstream &fileIn,Node &First)
{
	fileIn.open("DSSV.DAT.txt",ios::in);
	if(fileIn.fail())
	{
		cout<<"\nFailed to open this file";
		return;
	}
	fflush(stdin);
	string str;
	getline(fileIn,str);
	while(!fileIn.eof())
	{
		Sinhvien sv;
		fileIn>>sv.MSSV;
		string X;
		fflush(stdin);
		getline(fileIn,X);
		Chuan_Hoa_Chuoi((char*)X.c_str());
		//dua xau X vao Ho Ten
		int i=0;
		while(i<STRLEN((char*)X.c_str()))
		{
			sv.HoTen[i]=X[i];
			i++;
		}
		sv.HoTen[i]='\0';
		Node q=TaoNode(sv);
		Insert_Last(First,q);	
	}

	fileIn.close();
}


//ham xoa danh sach
void ClearList(Node &First)
{
	while(First!=NULL)
	{
		Node k=First;
		First=First->pNext;
		delete k;
	}
}
void Menu(Node &First)
{
	while(1)
	{
		system("cls");
		cout<<"\n\t\t=================QUAN LY SINH VIEN================";
		cout<<"\n\t\t1.Them sinh vien vao danh sach";
		cout<<"\n\t\t2.Them vao dau danh sach";
		cout<<"\n\t\t3.Duyet danh sach";
		cout<<"\n\t\t4.Dem so node(sinh vien) trong danh sach";
		cout<<"\n\t\t5.Them node tai vi tri thu i trong danh sach";
		cout<<"\n\t\t6.Tim sinh vien theo ma";
		cout<<"\n\t\t7.Xoa sinh vien theo ma";
		cout<<"\n\t\t8.Sap xep danh sach theo ma so tang dan";
		cout<<"\n\t\t9.Mo file ghi danh sach vao file";
		cout<<"\n\t\t10.Mo file doc va ghi vao danh sach lien ket";
		string luachon;
		cout<<"\nNhap lua chon: ";
		cin>>luachon;
		if(luachon=="1")
		{
			Sinhvien sv;
			Nhap_Thongtin_SV(sv);
			Node q=TaoNode(sv);
			Insert_Last(First, q);
		}
		else if(luachon=="2")
		{
			Sinhvien sv;
			Nhap_Thongtin_SV(sv);
			Node q=TaoNode(sv);
			Insert_First(First,q);
		}
		else if(luachon=="3")
		{
			Traverse(First);
			getch();
		}
		else if(luachon=="4")
		{
			cout<<"\nSo node: "<<Reccount(First);
			getch();
			
		}
		else if(luachon=="5")
		{
			int i;
			cout<<"\nNhap vi tri can them node: ";
			cin>>i;
			Sinhvien sv;
			Nhap_Thongtin_SV(sv);
			Node q=TaoNode(sv);
			Insert_i(First,q,i);
		}
		else if(luachon=="6")
		{
			int ma;
			cout<<"\nNhap ma sinh vien can tim: ";
			cin>>ma;
			Search_Info(First,ma);
			getch();
		}
		else if(luachon=="7")
		{
			int ma;
			cout<<"\nNhap ma sinh vien can xoa: ";
			cin>>ma;
			Delete_Info(First,ma);
		}
		else if(luachon=="8")
		{
			Selection_Sort(First);
		}
		else if(luachon=="9")
		{
			ofstream fileOut;
			WriteFile(fileOut,First);
		}
		else if(luachon=="10")
		{
			ClearList(First);
			ifstream fileIn;
			ReadFile(fileIn,First);
			getch();
		}
		else if(luachon<"1" || luachon>"10")
		{
			break;
		}
	}
	ClearList(First);
}
