#include<iostream>
using namespace std;
#include<conio.h> //chua getch()

struct node
{
	int info;
	node *pNext;
};
typedef struct node* Node;



//khoi tao danh sach
void Init(Node &First);
//tao node
Node TaoNode(int x);
//ham them vao dau danh sach
void Insert_First(Node &First,Node a);
//ham them node moi vao sau node p
void Insert_after(Node &p,Node q);
//ham them info vao danh sach
void Insert(Node &First,Node a);

//ham duyet danh sach lien ket don
void Traverse(Node First);
//ham tim node dau tien co info = x
Node Search_info(Node First,int x);
//ham kiem tra danh sach co rong hay khong
bool IsEmpty(Node First);
// ham xoa phan tu dau
int Delete_First(Node &First);
//ham xoa phan tu dung sau node co dia chi p
int Delete_after(Node &p);
//ham xoa phan tu dau tien co info==x
int Delete_info(Node &First,int x);
//ham xoa tat ca phan tu co info==x
int Delete_All_info(Node &First,int x);
//ham giai phong danh sach
void ClearList(Node &First);

//ham sap xep info tang dan
void Selection_Sort(Node &First);
//them node moi vao va danh sach van tang dan
void Insert_Order(Node &First,Node q);
//tron 2 danh sach vao voi nhau
Node Merge_Order(Node &First1,Node &First2);




void Menu(Node &First);


int main()
{
	Node First;
	Init(First);
	Menu(First);

	
	return 0;
}
//khoi tao danh sach
void Init(Node &First)
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
//ham them vao dau danh sach
void Insert_First(Node &First,Node q)
{
	if(First==NULL)
	{
		First=q;
	}
	else
	{
		q->pNext=First;
		First=q;
	}
	
}
//ham them node moi vao sau node co dia chi p
void Insert_after(Node &p,Node q)
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
//ham them info vao danh sach
void Insert(Node &First,Node a)
{
	if(IsEmpty(First))
	{
		Insert_First(First,a);
	}
	else
	{
		Node k;
		for(k=First;k->pNext!=NULL;k=k->pNext);
		Insert_after(k,a);
	}
}


//ham duyet danh sach lien ket don
void Traverse(Node First)
{
	if(IsEmpty(First))
	{
		cout<<"\nDanh sach trong!!!";
		return;
	}
	for(Node k=First;k!=NULL;k=k->pNext)
	{
		cout<<k->info<<"  ";
	}
}
//ham tim node dau tien co info == x
Node Search_info(Node First,int x)
{
	for(Node k=First;k!=NULL;k=k->pNext)
	{
		if(k->info==x)
		{
			return k;
		}
	}
	return NULL;
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
// ham xoa phan tu dau
int Delete_First(Node &First)
{
	if(IsEmpty(First))
	{
		return 0;
	}
	else
	{
		Node k=First;
		First=First->pNext;
		delete k;
	}
	return 1;
}
//ham xoa phan tu dung sau node co dia chi p 
int Delete_after(Node &p)
{
	if(p==NULL|| p->pNext==NULL)
	{
		return 0;
	}
	else
	{

		Node k=p->pNext;
		p->pNext=p->pNext->pNext;
		//p->pNext=k->pNext;
		delete k;

	
	}
	return 1;
}
//ham xoa phan tu dau tien co info=x
int Delete_info(Node &First,int x)
{
	if(IsEmpty(First))
	{
		return 0;
	}
	else if(First->info==x)
	{
		Delete_First(First);
	}
	else
	{
		Node k;
		for(k=First;k->pNext!=NULL && k->pNext->info!=x;k=k->pNext);
		if(k->pNext!=NULL)
		{
			Delete_after(k);
		}
	
	}
	return 1;
}
//ham xoa tat ca phan tu co info==x
int Delete_All_info(Node &First,int x)
{

	
	while(1)
	{
		if(IsEmpty(First))
		{
			return 0;
		}
		else if(First->info==x)
		{
			Delete_First(First);
		}
		else
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
					return 1;
				}
			}
		
		}
		
	
	
		
	
	}
	return 1;

}
//ham sap xep info tang dan
void Selection_Sort(Node &First)
{
	Node pmin;
	int min;
	if(IsEmpty(First))
	{
		return;
	}
	else
	{
		for(Node p=First;p->pNext!=NULL;p=p->pNext)
		{
			min=p->info;
			pmin=p;
			for(Node q=p->pNext;q!=NULL;q=q->pNext)
			{
				if(q->info<min)
				{
					min=q->info;
					pmin=q;
				}
			}
			pmin->info=p->info;
			p->info=min;
		}
	}
}
//them node moi vao va danh sach van tang dan
void Insert_Order(Node &First,Node q)
{
	Node k,t;
	for( k=First;k!=NULL && k->info<q->info;t=k,k=k->pNext);
	if(k==First)
	{
		Insert_First(First,q);
	}
	else //them vao truoc k
	{
		q->pNext=k;
		t->pNext=q;
		
	}


}
//tron 2 danh sach vao voi nhau
Node Merge_Order(Node &First1,Node &First2)
{
	Node p1,p2,p3;
	Node First3=new node;
	p1=First1;
	p2=First2;
	p3=First3;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->info<p2->info)
		{
			p3->pNext=p1;
			p3=p1;
			p1=p1->pNext;
		}
		else
		{
			p3->pNext=p2;
			p3=p2;
			p2=p2->pNext;
		}
	}
	if(p1==NULL)
	{
		p3->pNext=p2;
	}
	else if(p2==NULL)
	{
		p3->pNext=p1;
	}
	p3=First3;
	First3=p3->pNext;
	delete p3;
	First1=First2=NULL;
	return First3;
}
//ham giai phong danh sach
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
		cout<<"\n==============QUAN LY DANH SACH INFO==================";
		cout<<"\n\t\t1.Nhap info";
		cout<<"\n\t\t2.Xuat danh sach info";
		cout<<"\n\t\t3.Them node vao dau danh sach";
		cout<<"\n\t\t4.Tim kiem node dau tien co info==x";
		cout<<"\n\t\t5.Xoa phan tu dau danh sach";
		cout<<"\n\t\t6.Xoa phan tu dau tien co info==x";
		cout<<"\n\t\t7.Xoa tat ca cac phan tu co info==x";
		cout<<"\n\t\t8.Sap xep danh sach tang dan";
		cout<<"\n\t\t9.Them node moi vao va danh sach van tang dan";
		int luachon;
		cout<<"\nNhap lua chon: ";
		cin>>luachon;
		if(luachon==1)
		{
			int x;
			cout<<"\nNhap info can them vao danh sach: ";
			cin>>x;
			Node a=TaoNode(x);
			Insert(First,a);
		}
		else if(luachon==2)
		{
			Traverse(First);
			getch();
		}
		if(luachon==3)
		{
			int x;
			cout<<"\nNhap info can them: ";
			cin>>x;
			Node q=TaoNode(x);
			Insert_First(First,q);
		}
		else if(luachon==4)
		{
			int x;
			cout<<"\nNhap info can tim: ";
			cin>>x;
			cout<<Search_info(First,x);
			getch();
		}
		else if(luachon==5)
		{
			Delete_First(First);
		}
		else if(luachon==6)
		{
			int x;
			cout<<"\nNhap info can xoa: ";
			cin>>x;
			Delete_info(First,x);
		}
		else if(luachon==7)
		{
			int x;
			cout<<"\nNhap info can xoa: ";
			cin>>x;
			Delete_All_info(First,x);
		}
		else if(luachon==8)
		{
			Selection_Sort(First);
		}
		else if(luachon==9)
		{
			int x;
			cout<<"\nNhap info can them: ";
			cin>>x;
			Node q=TaoNode(x);
			Insert_Order(First,q);
		}
		else if(luachon<1 || luachon>10)
		{
			break;
		}
		
	}
	ClearList(First);
}
