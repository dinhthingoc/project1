#include<iostream>
#include<conio.h>
using namespace std;
#include<string.h>
#include<iomanip>
#define Max 100


struct hocvien
{
	char TenHocVien[30];
	float DiemTB;
	int Hang;
	
};
typedef struct hocvien Hocvien;


struct node
{
	Hocvien info;
	node *pNext;
};
typedef struct node* Node;


//ham kiem tra ki tu
bool Kiem_Tra_Chuoi(char arr[]);

//ham nhap thong tin 1 hoc vien
void Nhap_Thongtin_Hv(Hocvien &hv);
//ham xuat thong tin 1 hoc vien
void Xuat_Thongtin_Hv(Hocvien hv);

//ham khoi tao danh sach
void Init(Node &First);
//ham kiem tra
bool IsEmpty(Node First);
//ham tao node
Node Create_Node(Hocvien hv);
//ham them hoc vien vao dau danh sach
void Insert_First(Node &First,Node q);
//ham them hoc vien vao cuoi danh sach
void Insert_Last(Node &First,Node q);
//ham duyet danh sach
void Traverse(Node First);

//ham sap xep danh sach theo diem trung binh
void Sap_Xep(Node &First);
//ham xep hang cho hoc vien
void Xep_Hang(Node First);

void Delete_List(Node &First);

void Menu(Node &First);

int main()
{
	
	Node First;
	Init(First);
	Menu(First);
	
	
	
	return 0;
}


//ham kiem tra ki tu
bool Kiem_Tra_Chuoi(char arr[])
{
	int i=0;
	while(arr[i]!='\0')
	{
		if((arr[i]>='A' && arr[i]<='Z')|| (arr[i]>='a' && arr[i]<='z'))
		{
			return true;
		}
	}
	return false;
}

//ham nhap thong tin 1 hoc vien
void Nhap_Thongtin_Hv(Hocvien &hv)
{
	fflush(stdin);
	cout<<"\nNhap ho ten hoc vien: ";
	gets(hv.TenHocVien);
	if(Kiem_Tra_Chuoi(hv.TenHocVien)==false)
	{
		return;
	}
	cout<<"\nNhap diem trung binh: ";
	cin>>hv.DiemTB;
}
//ham xuat thong tin 1 hoc vien
void Xuat_Thongtin_Hv(Hocvien hv)
{
	cout<<setw(30)<<hv.TenHocVien<<setw(15)<<hv.DiemTB<<setw(5)<<hv.Hang;
}

//ham khoi tao danh sach
void Init(Node &First)
{
	First=NULL;
}
//ham kiem tra
bool IsEmpty(Node First)
{
	return( First==NULL?true:false);
}
//ham tao node
Node Create_Node(Hocvien hv)
{
	Node q=new node;
	q->info=hv;
	q->pNext=NULL;
	return q;
}
//ham them hoc vien vao dau danh sach
void Insert_First(Node &First,Node q)
{
	if(IsEmpty(First))
	{
		First=q;
	}
	else
	{
		q->pNext=First;
		First=q;
	}
}
//ham them hoc vien vao cuoi danh sach
void Insert_Last(Node &First,Node q)
{
	if(IsEmpty(First))
	{
		Insert_First(First,q);
	}
	else
	{
		Node k;
		for(k=First;k->pNext!=NULL;k=k->pNext);
		k->pNext=q;
	}
}
//ham duyet danh sach
void Traverse(Node First)
{
	if(IsEmpty(First))
	{
		cout<<"Danh sach trong!!!";
		return;
	}
	else
	{
		cout<<endl<<setw(30)<<"HO TEN"<<setw(15)<<"DIEM TB\n";
		for(Node k=First;k!=NULL;k=k->pNext)
		{
			Xuat_Thongtin_Hv(k->info);
			cout<<endl;
		}
	}
}
//ham sap xep danh sach theo diem trung binh
void Sap_Xep(Node &First)
{
	if(IsEmpty(First))
	{
		return;
	}
	else
	{
		Node k,kmax;
		Hocvien infomax;
		float max;
		for(k=First;k->pNext!=NULL;k=k->pNext)
		{
			kmax=k;
			max=k->info.DiemTB;
			infomax=k->info;
			for(Node q=k->pNext;q!=NULL;q=q->pNext)
			{
				if(q->info.DiemTB>max)
				{
					max=q->info.DiemTB;
					kmax=q;
					infomax=q->info;
				}
			}
			kmax->info=k->info;
			k->info=infomax;
		}
	}
}
//ham xep hang cho hoc vien
void Xep_Hang(Node First)
{
	int dem=1;
	int soluong=1;
	float max=First->info.DiemTB;
	First->info.Hang=1;
	for(Node k=First->pNext;k!=NULL;k=k->pNext)
	{
		++soluong;
		if(k->info.DiemTB==max)
		{
			k->info.Hang=dem;
		}
		else
		{
			dem=soluong;
			k->info.Hang=dem;
		}
		
		max=k->info.DiemTB;
	}
}
void Delete_List(Node &First)
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
		cout<<"\n\t\t===========QUAN LY HOC VIEN=============";
		cout<<"\n\t\t1.Nhap danh sach hoc vien";
		cout<<"\n\t\t2.Xuat danh sach hoc vien";
		cout<<"\n\t\t3.Xep hang cho hoc vien";
		int luachon;
		cout<<"\nNhap lua chon: ";
		cin>>luachon;
		if(luachon==1)
		{
			
			int i=1;
			while(1)
			{
				Hocvien hv;
				system("cls");
				cout<<"\nNhap thong tin hoc vien thu "<<i;
				Nhap_Thongtin_Hv(hv);
				if(Kiem_Tra_Chuoi(hv.TenHocVien)==false)
				{
					break;
				}
				Node q=Create_Node(hv);
				Insert_Last(First,q);
				i++;
			}
		}
		else if(luachon==2)
		{
			Traverse(First);
			getch();
		}
		else if(luachon==3)
		{
			Sap_Xep(First);
			Xep_Hang(First);
		}
		else if(luachon<1 || luachon>3)
		{
			break;
		}
	}
	Delete_List(First);
}

