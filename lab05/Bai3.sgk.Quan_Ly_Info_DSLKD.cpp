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
//ham kiem tra danh sach co rong hay khong
bool IsEmpty(Node First);
//ham them node vao danh sach
void Insert(Node &First,Node q);
//ham duyet danh sach
void Traverse(Node First);
//ham xoa node co dia chi p
void Delete_Node(Node &k,Node &q);
//ham xoa node theo info
void Delete_Info(Node &First,int x);
//ham xoa tat ca cac node co noi dung X trong danh sach
void Delete_All_Info(Node &First,int x);
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
//ham xoa node co dia chi p
void Delete_Node(Node &k,Node &p)
{
	if(p==NULL)
	{
		return;
	}
	else
	{
		
		k->pNext=p->pNext;
		delete p;
	}
}
//ham xoa node theo info
void Delete_Info(Node &First,int x)
{
	if(IsEmpty(First))
	{
		return;
	}
	else
	{
		if(First->info==x)
		{
			Node q=First;
			First=First->pNext;
			delete q;
		}
		else
		{
			Node t;
			for(Node k=First;k!=NULL;t=k,k=k->pNext)
			{
	
				if(k->info==x)
				{
					Delete_Node(t,k);
					break;
				}
			}
		}
	}
}
//ham xoa tat ca cac node co noi dung X trong danh sach
void Delete_All_Info(Node &First,int x)
{

	if(IsEmpty(First))
	{
		return;
	}
	while(IsEmpty(First)==false)
	{

		if(First->info==x)
		{
			Node q=First;
			First=First->pNext;
			delete q;	
		
		}
		else break;
	}
	
	if(IsEmpty(First)==false)
	{
		Node q;
		for(Node k=First;k!=NULL;k)
		{
			if(k->info==x)
			{
				Node p=k;
				q->pNext=k->pNext;
				k=k->pNext;
				delete p;
			}
			else
			{
				q=k;
				k=k->pNext;
			}
			if(k==NULL)
			{
				return;
			}
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
		cout<<"\n\t\t3.Xoa node dau tien co info==x";
		cout<<"\n\t\t4.Xoa tat cac node co info==x";
		int luachon;
		cout<<"\nNhap lua chon: ";
		cin>>luachon;
		if(luachon==1)
		{
			int x;
			cout<<"\nNhap x: ";
			cin>>x;
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
			int x;
			cout<<"\nNhap info can xoa: ";
			cin>>x;
			Delete_Info(First,x);
		}
		else if(luachon==4)
		{
			int x;
			cout<<"\nNhap info can xoa: ";
			cin>>x;
			Delete_All_Info(First,x);
		}
		else  // if(luachon<1 || luachon>4)
		{
			break;
		}
	}
	ClearList(First);
}
