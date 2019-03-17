#include<iostream>
using namespace std;
#include<string.h>
#include<conio.h> //chua getch()

struct dathuc
{
	float heso;
	float somu;
};
typedef struct dathuc Dathuc;


struct node
{
	Dathuc data;
	node* pNext;
};
typedef struct node* Node;


//ham nhap phan tu da thuc
void Nhap_Phantu_DT(Dathuc &pt);
//ham xuat phan tu da thuc
void Xuat_Phantu_DT(Dathuc pt);


//ham khoi tao danh sach
void Init(Node &First);
//ham tao node
Node Create_Node(Dathuc pt);
//ham kiem tra da thuc
bool IsEmpty(Node First);

//ham nhap da thuc
void Insert_Last(Node &First,Node q);
//ham xuat da thuc
void Traverse(Node First);


//ham nhan 2 da thuc
void Nhan_DT(Node First1,Node First2,Node &First3);
//ham cong cac phan tu cung so mu voi nhau
void Gom_Dathuc(Node &First3);
//ham xoa nhung phan tu =0
void Delete_0(Node &First3);
//ham xoa danh sach lien ket
void Clear_List(Node &First);

void Menu(Node &First1,Node &First2);

int main()
{
	Node First1,First2;
	Init(First1);
	Init(First2);
	Menu(First1,First2);
	
	
	
	return 0;
}
//ham nhap phan tu da thuc
void Nhap_Phantu_DT(Dathuc &pt)
{
	cout<<"\nNhap he so: ";
	cin>>pt.heso;
	cout<<"\nNhap so mu: ";
	cin>>pt.somu;
}
//ham xuat phan tu da thuc
void Xuat_Phantu_DT(Dathuc pt)
{
	if(pt.somu==0)
	{
		cout<<pt.heso;
	}
	else
	{
		if(pt.heso==1)
		{
			cout<<"x";
			if(pt.somu!=1)
			{
				cout<<'^'<<pt.somu;
			}
		}
		else if(pt.heso==-1)
		{
			cout<<"-x";
			
			if(pt.somu!=1)
			{
				cout<<'^'<<pt.somu;
			}
		}
		else if(pt.somu==1)
		{
			cout<<pt.heso<<'x';
		}
		else
		{
			cout<<pt.heso<<"x^"<<pt.somu;
		}
	}



}


//ham khoi tao danh sach
void Init(Node &First)
{
	First=NULL;
}
//ham tao node
Node Create_Node(Dathuc pt)
{
	Node q=new node;
	q->data=pt;
	q->pNext=NULL;
	return q;
}
//ham kiem tra da thuc
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

//ham nhap da thuc
void Insert_Last(Node &First,Node q)
{
	if(IsEmpty(First))
	{
		First=q;
	}
	else
	{
		Node k;
		for(k=First;k->pNext!=NULL;k=k->pNext);
		k->pNext=q;
	}
}
//ham xuat da thuc
void Traverse(Node First)
{
	if(IsEmpty(First))
	{
		return;
	}
	else
	{
		for(Node k=First;k!=NULL;k=k->pNext)
		{
			Xuat_Phantu_DT(k->data);
			if(k->pNext!=NULL && k->pNext->data.heso>0)
			{
				cout<<'+';
			}
			
		}
	}
}


//ham nhan 2 da thuc
void Nhan_DT(Node First1,Node First2,Node &First3)
{
	for(Node k=First1;k!=NULL;k=k->pNext)
	{
		for(Node q=First2;q!=NULL;q=q->pNext)
		{
			Node a=new node;
			a->data.heso=(k->data.heso*q->data.heso*1.0);
			a->data.somu=(k->data.somu+q->data.somu);
			a->pNext=NULL;
			if(IsEmpty(First3))
			{
				
				First3=a;
			}
			else
			{
				Node p;
				for(p=First3;p->pNext!=NULL;p=p->pNext);
				p->pNext=a;
			}
		}
	}
}
//ham cong cac phan tu cung so mu voi nhau
void Gom_Dathuc(Node &First3)
{
	for(Node k=First3;k!=NULL && k->pNext!=NULL;k=k->pNext)
	{
		float mu=k->data.somu;
		Node p=k;
		for(Node q=k->pNext;q!=NULL;q=q->pNext)
		{
			if(q->data.somu==mu)
			{
				k->data.heso+=q->data.heso;
				Node tam=q;
				q=p;
				p->pNext=tam->pNext;
				delete tam;
			}
			p=q;
		}
	}
	
}
//ham xoa nhung phan tu =0
void Delete_0(Node &First3)
{
	if(IsEmpty(First3))
	{
		return;
	}
	else
	{
		while(First3->data.heso==0)
		{
			Node x=First3;
			First3=First3->pNext;
			delete x;
		}
		Node q;
		for(Node k=First3;k!=NULL;k=k->pNext)
		{
			if(k->data.heso==0)
			{
				Node x=k;
				k=q;
				q->pNext=x->pNext;
				delete x;
			}
			q=k;
		}
	}
}
//ham xoa danh sach lien ket
void Clear_List(Node &First)
{
	while(First!=NULL)
	{
		Node k=First;
		First=First->pNext;
		delete k;
	}
}
void Menu(Node &First1,Node &First2)
{
	while(1)
	{
		system("cls");
		cout<<"\n===============NHAN DA THUC=============";
		cout<<"\n\t\t1.Nhap da thuc 1";
		cout<<"\n\t\t2.Nhap da thuc 2";
		cout<<"\n\t\t3.Xuat da thuc 1";
		cout<<"\n\t\t4.Xuat da thuc 2";
		cout<<"\n\t\t5.Nhan 2 da thuc";
		int luachon;
		cout<<"\nNhap lua chon: ";
		cin>>luachon;
		if(luachon==1)
		{
		
			Dathuc pt;
			Nhap_Phantu_DT(pt);
			Node q=Create_Node(pt);
			Insert_Last(First1,q);
			
		}
		else if(luachon==2)
		{
			Dathuc pt;
			Nhap_Phantu_DT(pt);
			Node q=Create_Node(pt);
			Insert_Last(First2,q);
		}
		else if(luachon==3)
		{
			Delete_0(First1);
			Traverse(First1);
			getch();
		}
		else if(luachon==4)
		{
			Delete_0(First2);
			Traverse(First2);
			getch();
		}
		else if(luachon==5)
		{
			Node First3;
			Init(First3);
			Nhan_DT(First1,First2,First3);
			Gom_Dathuc(First3);
			Delete_0(First3);
			Traverse(First3);
			getch();
			Clear_List(First3);
		}
		else if(luachon<1|| luachon>5)
		{
			break;
		}
		
		
		
	}
	Clear_List(First1);
	Clear_List(First2);
}
