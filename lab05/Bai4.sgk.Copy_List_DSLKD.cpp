 #include<iostream>
using namespace std;
#include<conio.h>


struct node
{
	int info;
	node* pNext;
};
typedef struct node* Node;



//ham khoi tao danh sach
void Init(Node &First);
//ham tao node
Node TaoNode(int x);
//ham kiem tra danh sach
bool IsEmpty(Node First);
//ham them node vao danh sach
void Insert(Node &First,Node q);
//ham duyet danh sach
void Traverse(Node First);
//ham sao chep danh sach
void Copy_List(Node First,Node &First1);

//ham xoa danh sach
void Delete_List(Node &First);

void Menu(Node &First);


int main()
{
	
	Node First;
	Init(First);
	Menu(First);
	
	
	return 0;
}
//ham khoi tao danh sach
void Init(Node &First)
{
	First=NULL;
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
//ham tao node
Node TaoNode(int x)
{
	Node q=new node;
	q->info=x;
	q->pNext=NULL;
	return q;
}
//ham them node vao danh sach
void Insert(Node &First,Node q)
{
	if(IsEmpty(First))
	{
		//them dau danh sach
		First=q;
		
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
	for(Node k=First;k!=NULL;k=k->pNext)
	{
		cout<<k->info<<"   ";
	}
}
//ham sao chep danh sach
void Copy_List(Node First,Node &First1)
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
			Node q=TaoNode(k->info);
			Insert(First1,q);
			k=k->pNext;
		}
	}
}

//ham xoa danh sach
void Delete_List(Node &First)
{
	while(First!=NULL)
	{
		Node q=First;
		First=First->pNext;
		delete q;
	}
}
void Menu(Node &First)
{
	while(1)
	{
		system("cls");
		cout<<"\n\t\t1.Them node vao danh sach";
		cout<<"\n\t\t2.Duyet danh sach";
		cout<<"\n\t\t3.Copy List";
		int luachon;
		cout<<"\nNhap lua chon: ";
		cin>>luachon;
		if(luachon==1)
		{
			int x;
			cout<<"\nNhap info can them: ";
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
			Node First1;
			Init(First1);
			Copy_List(First,First1);
			Traverse(First1);
			getch();
		}
	}
}
