#include<iostream>
using namespace std;
#include<conio.h> //chua getch()
#include<string.h>
#include<string>

struct node
{
	int info;
	node *pNext;
};
typedef struct node* Node;

//ham kiem tra ki tu so hay khong
bool Kiem_Tra(char x);
//ham tinh do dai chuoi
int STRLEN(char arr[]);
//ham chuyen ki tu so sang so nguyen
int Chuyen_Chuoi_Sang_So(string str);
//ham nhap so nguyen
int Nhap_So_Nguyen(char x);

//ham khoi tao danh sach
void Init(Node & First);
//tao node
Node TaoNode(int x);
//ham kiem tra danh sach co rong hay khong
bool IsEmpty(Node First);
//ham them node vao danh sach
void Insert(Node &First,Node q);
//ham duyet danh sach
void Traverse(Node First);
//ham dao nguoc danh sach lien ket
void Island_List(Node &First);

void Menu(Node &First);

int main()
{
	Node First;
	Init(First);
	Menu(First);
	
	
	
	return 0;
}
//ham kiem tra ki tu so hay khong
bool Kiem_Tra(char x)
{
	if(x>='0' && x<='9')
	{
		return true;
	}
	else
	{
		return false;
	}
}
//ham tinh do dai chuoi
int STRLEN(char arr[])
{
	int i=0;
	while(arr[i]!='\0')
	{
		i++;
	}
	return i;
}

//ham chuyen ki tu so sang so nguyen
int Chuyen_Chuoi_Sang_So(string str)
{
	int so=0;
	int i=0;
	int n=STRLEN((char*)str.c_str());
	while(i<n)
	{
		so=so*10+ (str[i]-48);
		i++;
	}
	return so;
}
//ham nhap so nguyen
int Nhap_So_Nguyen(char x)
{
	string str;
	char c=getch();
	//nhap den khi gap phim enter
	while((int)c!=13)
	{
		if((int)c==8)
		{
			if(STRLEN((char*)str.c_str())!=0)
			{
				cout<<"\b \b"; //xoa tung ki tu cua chuoi danh nhap
			}
			if(STRLEN((char*)str.c_str())!=0)
			{
				str.erase(str.begin() + (str.length()-1)); //xoa ki tu cuoi cua chuoi
			
			}
		}
		else
		{
			cout<<c;
			if(Kiem_Tra(c))
			{
				str.push_back(c);//them c vao cuoi chuoi
			}
			else
			{
				cout<<"\nNhap kieu du lieu khong hop le!!!\n";
				str.resize(0);
			}
		}
		c=getch();
	}
	return Chuyen_Chuoi_Sang_So(str);
}

//ham khoi tao danh sach
void Init(Node & First)
{
	First=NULL;
}
//tao node
Node TaoNode(int x)
{
	Node q=new node;
	q->info=x;
	q->pNext=NULL;
	return q;
}
//ham kiem tra danh sach co rong hay khong
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
//ham them node vao danh sach
void Insert(Node &First,Node q)
{
	if(IsEmpty(First))
	{
		First=q;
	}
	else
	{
		Node k=First;
		while(k->pNext!=NULL)
		{
			k=k->pNext;
		}
		k->pNext=q;
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
		Node k=First;
		while(k!=NULL)
		{
			cout<<k->info<<"   ";
			k=k->pNext;
		}
	}
}
//ham dao nguoc danh sach lien ket
void Island_List(Node &First)
{

	Node p=NULL;
	Node q=NULL;
	while(First!=NULL)
	{
		p=First;
		First=First->pNext;
		p->pNext=q;
		q=p;
	}
	First=q;
}
		
	
		
	

//ham xoa danh sach
void ClearList(Node &First)
{
	if(IsEmpty(First))
	{
		return;
	}
	else
	{
		while(First!=NULL)
		{
			Node k=First;
			First=First->pNext;
			delete k;
		}
	}
}
void Menu(Node & First)
{
	while(1)
	{
		system("cls");
		cout<<"\n\t\t1.Them node vao danh sach";
		cout<<"\n\t\t2.Duyet danh sach";
		cout<<"\n\t\t3.Dao nguoc danh sach";
		int luachon;
		cout<<"\nNhap lua chon: ";
		cin>>luachon;
		if(luachon==1)
		{
			int x;
			cout<<"\nNhap x: ";
			char c;
			
			x=Nhap_So_Nguyen(c);
			Node q=TaoNode(x);
			Insert(First,q);
		}
		else if(luachon==2)
		{
			Traverse(First);
			getch();
		}
		else if(luachon==3)
		{
		
			Island_List(First);
			
			
		}
		else if(luachon<1 || luachon>3)
		{
			break;
		}
	}
	ClearList(First);
}
