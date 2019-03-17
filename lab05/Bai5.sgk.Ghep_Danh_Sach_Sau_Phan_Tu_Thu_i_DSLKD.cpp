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
//ham ghep danh sach First2 vao First1 sau phan tu thu i
void Ghep_Danhsach(Node &First1,Node &First2,int i);

//ham xoa danh sach
void Delete_List(Node &First);

void Menu(Node &First1,Node &First2);



int main()
{
	
	Node First1,First2;
	Init(First1);
	Init(First2);
	Menu(First1,First2);
	
	
	
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
	if(IsEmpty(First))
	{
		return;
	}
	for(Node k=First;k!=NULL;k=k->pNext)
	{
		cout<<k->info<<"   ";
	}
}
//ham sao chep danh sach
void Ghep_Danhsach(Node &First1,Node &First2,int i)
{
	if(IsEmpty(First2))
	{
		return;
	}
	else if(IsEmpty(First1))
	{
		First1=First2;
		First2=NULL;
		return;
		
	}
	else
	{
		if(i==0)
		{
			Node q;
			for(q=First2;q->pNext!=NULL;q=q->pNext);
			q->pNext=First1->pNext;
			First1=First2;
			First2=NULL;
		
		}
		else
		{
			Node k;
			int dem=1;
			for(k=First1;k->pNext!=NULL && dem<i;k=k->pNext,dem++);
		
			Node q;
			for(q=First2;q->pNext!=NULL;q=q->pNext);
			q->pNext=k->pNext;
			k->pNext=First2;
			First2=NULL;
		
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
void Menu(Node &First1,Node &First2)
{
	while(1)
	{
		system("cls");
		cout<<"\n\t\t1.Them node vao danh sach First1";
		cout<<"\n\t\t2.Them node vao danh sach First2";
		cout<<"\n\t\t3.Duyet danh sach First1";
		cout<<"\n\t\t4.Duyet danh sach First2";
		cout<<"\n\t\t5.Ghep danh sach First2 sanh First1 sau phan tu thu i";
		int luachon;
		cout<<"\nNhap lua chon: ";
		cin>>luachon;
		if(luachon==1)
		{
			int x;
			cout<<"\nNhap info can them: ";
			cin>>x;
			Node q=TaoNode(x);
			Insert(First1,q);
		}
		else if(luachon==2)
		{
			int x;
			cout<<"\nNhap info can them: ";
			cin>>x;
			Node q=TaoNode(x);
			Insert(First2,q);
		}
		else if(luachon==3)
		{
			Traverse(First1);
			getch();
		}
		else if(luachon==4)
		{
			Traverse(First2);
			getch();
		}
		else if(luachon==5)
		{
			int i;
			cout<<"\nNhap vi tri thu i: ";
			cin>>i;
			Ghep_Danhsach(First1,First2,i);
		}
		else if(luachon<1 || luachon>5)
		{
			break;
		}
	}
	Delete_List(First1);

}
