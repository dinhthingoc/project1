#include<iostream>
using namespace std;
#include<conio.h> //chua getch()

struct node
{
	int info;
	node *pNext;
};
typedef struct node* Node;





//ham khoi tao danh sach
void Init(Node & First);
//tao node
Node TaoNode(int x);
//ham loc danh sach lien ket
bool Loc_Danhsach(Node First,int info);
//ham kiem tra danh sach co rong hay khong
bool IsEmpty(Node First);
//ham them node vao danh sach
void Insert(Node &First,Node q);



//ham duyet danh sach
void Traverse(Node First);
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
//ham loc danh sach lien ket
bool Loc_Danhsach(Node First,int info)
{
	if(IsEmpty(First))
	{
		return true;
	}
	else
	{
		for(Node k=First;k!=NULL;k=k->pNext)
		{
			if(info==k->info)
			{
				return false;
			}
		}
	}
	return true;
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
		int luachon;
		cout<<"\nNhap lua chon: ";
		cin>>luachon;
		if(luachon==1)
		{
			int x;
			cout<<"\nNhap x: ";
			cin>>x;
			if(Loc_Danhsach(First,x)==true)
			{
				Node q=TaoNode(x);
				Insert(First,q);
			}
			
		}
		else if(luachon==2)
		{
			Traverse(First);
			getch();
		}

		else if(luachon<1 || luachon>2)
		{
			break;
		}
	}
	ClearList(First);
}
