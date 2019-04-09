#include<iostream>
using namespace std;
#include<string>
#include<string.h>
#pragma warning(disable:4996)

struct hanghoa
{
	string mahanghoa;
	string tenhanghoa;
	string donvitinh;
	int soluong;
	float VAT;
	hanghoa *pLeft;
	hanghoa *pRight;
};
typedef struct hanghoa Hanghoa;
typedef Hanghoa* Tree;


//khoi tao cay hang hoa
void khoitao(Tree &t)
{
	t = NULL;
}

//them 1 node vao cay nhi phan tim kiem
void nhap_hang(Hanghoa *&a)
{
	fflush(stdin);
	cout << "\nnhap ma hang hoa: ";
	getline(cin, a->mahanghoa);
	cout << "\nnhap ten hang hoa: ";
	getline(cin, a->tenhanghoa);
	cout << "\nnhap don vi tinh: ";
	getline(cin, a->donvitinh);
	cout << "\nnhap so luong: ";
	cin >> a->soluong;
	cout << "\nnhap thue VAT(%): ";
	cin >> a->VAT;
	a->pLeft = NULL;
	a->pRight = NULL;
}
void tao_cay(Tree &t,Hanghoa *a)
{

	if (t == NULL)
	{
		t = a;
	}
	else
	{
		if (stricmp (a->mahanghoa.c_str(), t->mahanghoa.c_str() ) >0)
		{
			tao_cay(t->pRight, a);
		}
		else if (stricmp(a->mahanghoa.c_str(), t->mahanghoa.c_str()) <0)
		{
			tao_cay(t->pLeft, a);
		}
	}
	
}

//ham duyet cay theo NLR
void NLR(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		cout << "\nma hang hoa: "<<t->mahanghoa;
		cout << "\nten hang hoa: " << t->tenhanghoa;
		cout << "\ndon vi tinh: " << t->donvitinh;
		cout << "\nso luong: " << t->soluong;
		cout << "\nthue VAT: " << t->VAT;
		cout << endl;
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}


//ham duyet cay theo NRL
void NRL(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		cout << "\nma hang hoa: " << t->mahanghoa;
		cout << "\nten hang hoa: " << t->tenhanghoa;
		cout << "\ndon vi tinh: " << t->donvitinh;
		cout << "\nso luong: " << t->soluong;
		cout << "\nthue VAT: " << t->VAT;
		cout << endl;
		NRL(t->pRight);
		NRL(t->pLeft);

	}
}

//ham duyet cay theo LNR
void LNR(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		LNR(t->pLeft);
		cout << "\nma hang hoa: " << t->mahanghoa;
		cout << "\nten hang hoa: " << t->tenhanghoa;
		cout << "\ndon vi tinh: " << t->donvitinh;
		cout << "\nso luong: " << t->soluong;
		cout << "\nthue VAT: " << t->VAT;
		cout << endl;
		LNR(t->pRight);
	}
}
//ham duyet cay theo RNL
void RNL(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		RNL(t->pRight);
		cout << "\nma hang hoa: " << t->mahanghoa;
		cout << "\nten hang hoa: " << t->tenhanghoa;
		cout << "\ndon vi tinh: " << t->donvitinh;
		cout << "\nso luong: " << t->soluong;
		cout << "\nthue VAT: " << t->VAT;
		cout << endl;
		RNL(t->pLeft);
	}
	
}

//ham duyet cay theo LRN
void LRN(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		LRN(t->pLeft);
		LRN(t->pRight);
		cout << "\nma hang hoa: " << t->mahanghoa;
		cout << "\nten hang hoa: " << t->tenhanghoa;
		cout << "\ndon vi tinh: " << t->donvitinh;
		cout << "\nso luong: " << t->soluong;
		cout << "\nthue VAT: " << t->VAT;
		cout << endl;
	}
}

//ham duyet cay theo RLN
void RLN(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		RLN(t->pRight);
		RLN(t->pLeft);
		cout << "\nma hang hoa: " << t->mahanghoa;
		cout << "\nten hang hoa: " << t->tenhanghoa;
		cout << "\ndon vi tinh: " << t->donvitinh;
		cout << "\nso luong: " << t->soluong;
		cout << "\nthue VAT: " << t->VAT;
		cout << endl;
	}
}

void tim_kiem(Tree t,string ma)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (stricmp(t->mahanghoa.c_str(), ma.c_str()) == 0)
		{
			cout << "\nma hang hoa: " << t->mahanghoa;
			cout << "\nten hang hoa: " << t->tenhanghoa;
			cout << "\ndon vi tinh: " << t->donvitinh;
			cout << "\nso luong: " << t->soluong;
			cout << "\nthue VAT: " << t->VAT;
			return;
		}
		else
		{
			tim_kiem(t->pLeft, ma);
			tim_kiem(t->pRight,ma);
		}
	}
}


//lay thong tin cua tung hang hoa, dung mang 1 chieu quan ly
void lay_thong_tin(Tree t, Hanghoa *arr[],int &n)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		arr[n++]=t;
		lay_thong_tin(t->pLeft, arr, n);
		lay_thong_tin(t->pRight, arr, n);
	}

}
//xuat ra thong tin cua tung hang hoa va theo thu tu giam dan ve so luong hang ton
void xuat(Tree t, Hanghoa *arr[], int n)
{
	int max = arr[0]->soluong;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i]->soluong < arr[j]->soluong)
			{
				Hanghoa *temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << "\nma hang hoa: " << arr[i]->mahanghoa;
		cout << "\nten hang hoa: " << arr[i]->tenhanghoa;
		cout << "\ndon vi tinh: " << arr[i]->donvitinh;
		cout << "\nso luong: " << arr[i]->soluong;
		cout << "\nthue VAT: " << arr[i]->VAT << endl;

	}
}
//ham giai phong cay
void delete_tree(Tree &t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		delete_tree(t->pLeft);
		delete_tree(t->pRight);
		delete t;
	}
}


void menu(Tree &t)
{

	while (1)
	{
		system("cls");
		cout << "\n==========QUAN LY CAY HANG HOA===========";
		cout << "\n\t\t1.nhap hang hoa";
		cout << "\n\t\t2.duyet cay theo NLR";
		cout << "\n\t\t3.duyet cay theo NRL";
		cout << "\n\t\t4.duyet cay theo LNR";
		cout << "\n\t\t5.duyet cay theo RNL";
		cout << "\n\t\t6.duyet cay theo LRN";
		cout << "\n\t\t7.duyet cay theo RLN";
		cout << "\n\t\t8.tim kiem theo ma hang hoa";
		cout << "\n\t\t9.xuat ra danh sach hang hoa giam dan theo so luong hang ton";
		cout << "\n================END======================";
		int luachon;
		cout << "\nnhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			Hanghoa *a = new Hanghoa();
			nhap_hang(a);
			tao_cay(t, a);
		}
		else if (luachon == 2)
		{
			NLR(t);
			system("pause");
		}
		else if (luachon == 3)
		{
			NRL(t);
			system("pause");
		}
		else if (luachon == 4)
		{
			LNR(t);
			system("pause");
		}
		else if (luachon == 5)
		{
			RNL(t);
			system("pause");
		}
		else if (luachon == 6)
		{
			LRN(t);
			system("pause");
		}
		else if (luachon == 7)
		{
			RLN(t);
			system("pause");
		}
		else if (luachon == 8)
		{
			fflush(stdin);
			string ma;
			cout << "\nnhap ma hang hoa can tim kiem: ";
			getline(cin, ma);
			tim_kiem(t, ma);
			system("pause");
		}
		else if (luachon == 9)
		{
			int n=0;
			Hanghoa *arr[100];
			lay_thong_tin(t, arr, n);
			xuat(t, arr, n);
			system("pause");
		}
		else break;
	}
	delete_tree(t);

}

int main()
{
	Tree t;
	khoitao(t);
	menu(t);


	system("pause");
	return 0;
}