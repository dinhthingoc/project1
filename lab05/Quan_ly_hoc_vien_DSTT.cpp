#include<iostream>
#include<string.h>
#include<string>
#include<conio.h> //chua lenh getch()
//#include<stdio.h> //fflush
#include<iomanip> //setw()
using namespace std;
#include<fstream>
#define Max 100
#pragma warning(disabe:4996)

struct hocvien
{
	int Maso;
	char Ho[30];
	char Ten[10];
};
typedef struct hocvien HOCVIEN;


struct list
{
	HOCVIEN DS[Max];
	int n;
};
typedef struct list LIST;




//ham kiem tra ky tu la so hay chu
bool Kiem_Tra(char c);
//ham chuyen chuoi sang so
int Chuyen_Chuoi_Sang_So(string str);
//nhap so nguyen
int Nhap_So_Nguyen();
//nhap thong tin 1 hoc vien
void Nhap_Hoc_Vien(HOCVIEN &hv);
void Xuat_Thong_Tin(HOCVIEN hv);
//nhap danh sach hoc vien
void Nhap_Danh_Sach_Hv(LIST &ds);
void Xuat_Danh_Sach_Hv(LIST ds);

//sap xep danh sach theo thu tu tang dan theo ten va ho
void Sap_Xep(LIST &ds);

//ham them
void Them(LIST &ds,int vt,HOCVIEN hv);
//them 1 hoc vien va van dam bao tinh tang dan cua danh sach
void Them_Hoc_Vien(LIST &ds);
//tim hoc vien theo ma so
void Tim_Hoc_Vien(LIST ds,int maso);
//ham xoa
void Xoa(LIST &ds,int vt);
//xoa hoc vien theo ma so
void Xoa_Hoc_Vien(LIST &ds,int maso);

//ham ghi 1 hoc vien ra file
void writeFile(ofstream &fileOut,HOCVIEN hv);
//ghi danh sach hoc vien ra file
void writeFile_DS(ofstream &fileOut,LIST ds);

//tim do dai chuoi
int STRLEN(char c[]);
//ham xoa ki tu
void Xoa_Ki_Tu(char str[],int vt);
void Chuan_Hoa_Chuoi(char str[]);
//ham cat chuoi lay tu cuoi cua chuoi
void Cat_Chuoi(char str[],char temp[]);
//ham doc file vao danh sach tuyen tinh
void readFile_DS(ifstream &fileIn,LIST &ds);

void Menu(LIST &ds);


int main()
{
	LIST ds;
	ds.n=0;
	Menu(ds);

	
	
	
	return 0;
}




//ham kiem tra ky tu la so hay chu
bool Kiem_Tra(char c)
{
	if(c>='0' && c<='9')
	{
		return true;
	}
	else
	{
	  return false;
	}
}
//ham chuyen kt tu so sang so nguyen
int Chuyen_Chuoi_Sang_So(string str)
{
	int so=0;
	int n=str.length();
	for(int i=0;i<n;i++)
	{
		so=so*10+(str[i]-48);
	}
	return so;
}
//nhap so nguyen
int Nhap_So_Nguyen()
{
	string str;
	char c=getch();
	while((int)c!=13)
	{

		if((int)c==8)
		{
			if(str.length() != 0) // neu =0 thi dung xoa
			{
				cout << "\b \b"; // xoa tung ki tu cua chuoi dang nhap hien tai
			}
			if(str.length()!=0)
			{
				str.erase(str.begin()+(str.length()-1)); //xoa ki tu cuoi trong chuoi
			}
		}
		else
		{
			cout<<c;
			if(Kiem_Tra(c)==true)
			{
				str.push_back(c);
			}
			else
			{
				cout<<"\nKieu du lieu nhap khong hop le.Nhap lai\n";
				str.resize(0);
			}
			
		}
		c=getch();

	}
	return Chuyen_Chuoi_Sang_So(str);
}
//nhap thong tin 1 hoc vien
void Nhap_Hoc_Vien(HOCVIEN &hv)
{
	cout<<"\nNhap ma so: ";
	hv.Maso=Nhap_So_Nguyen();
	fflush(stdin);
	cout<<"\nNhap ho (first name): ";
	//getline(cin,hv.Ho);
	gets(hv.Ho);
	cout<<"\nNhap ten (last name): ";
	//getline(cin,hv.Ten);
	gets(hv.Ten);
	
}
void Xuat_Thong_Tin(HOCVIEN hv)
{
	cout<<setw(20)<<hv.Maso<<setw(25)<<hv.Ho<<setw(10)<<hv.Ten;
}
//nhap danh sach hoc vien
void Nhap_Danh_Sach_Hv(LIST &ds)
{


	do
	{
		cout<<"\nNhap so luong hoc vien: ";
		ds.n=Nhap_So_Nguyen();
		if(ds.n<1|| ds.n>100)
		{
			cout<<"\nNhap qua so luong hoc vien.Nhap lai: ";
		}
	}
	while(ds.n<1|| ds.n>100);
	int arr[100];
	int n=0;
	for(int i=0;i<ds.n;i++)
	{
		cout<<"\n\tNhap hoc vien thu "<<i+1;
		HOCVIEN hv;
		
		bool kt;
		do
		{
			kt=true;
			Nhap_Hoc_Vien(hv);
			arr[n++]=hv.Maso;
			for(int j=0;j<n-1;j++)
			{
				if(arr[j]==hv.Maso)
				{
					kt=false;
					cout<<"\nMa so bi trung.Nhap lai";
					break;
				}
			}
		}
		while(kt==false);
		ds.DS[i]=hv;
	}

}
void Xuat_Danh_Sach_Hv(LIST ds)
{
	if(ds.n<1)
	{
		cout<<"\n\tDanh sach rong!!!";
	}
	else
	{
		cout<<"\n\n\t\t DANH SACH HOC VIEN\n\n";
		cout<<setw(10)<<"STT"<<setw(20)<<"MS"<<setw(25)<<"Ho"<<setw(10)<<"Ten"<<endl;
		for(int i=0;i<ds.n;i++)
		{
		
			cout<<setw(10)<<i+1;
			Xuat_Thong_Tin(ds.DS[i]);
			cout<<endl;
		}
		cout<<"\nTong so: "<<ds.n;
	}

}
//sap xep danh sach theo thu tu tang dan theo ten va ho
void Sap_Xep(LIST &ds)
{
	if(ds.n<2)
	{
		cout<<"\nDanh sach khong the sap xep!!!";
	}
	else
	{
		for(int i=0;i<ds.n-1;i++)
		{
			for(int j=i+1;j<ds.n;j++)
			{
				if(stricmp(ds.DS[i].Ten,ds.DS[j].Ten )>0)
				{
					HOCVIEN x=ds.DS[i];
					ds.DS[i]=ds.DS[j];
					ds.DS[j]=x;
				}
				else if(stricmp(ds.DS[i].Ten,ds.DS[j].Ten)==0)
				{
					if(stricmp(ds.DS[i].Ho,ds.DS[j].Ho )>0 )
					{
						HOCVIEN x=ds.DS[i];
						ds.DS[i]=ds.DS[j];
						ds.DS[j]=x;
					}
				}
			}
		}
	}

	
	
	
}

//ham them
void Them(LIST &ds,int vt,HOCVIEN hv)
{
	for(int i=ds.n-1;i>=vt;i--)
	{
		ds.DS[i+1]=ds.DS[i];
	}
	ds.DS[vt]=hv;
	ds.n++;
}
//them 1 hoc vien va van dam bao tinh tang dan cua danh sach
void Them_Hoc_Vien(LIST &ds)
{
	if(ds.n==Max)
	{
		cout<<"\nDanh sach day!!!";
	}
	if(ds.n==0)
	{
		HOCVIEN hv;
		Nhap_Hoc_Vien(hv);
		Them(ds,0,hv);
	}
	else
	{
		HOCVIEN hv;
		cout<<"\nNhap thong tin hoc vien can them";
		bool kt;
		do
		{
			kt=true;
			Nhap_Hoc_Vien(hv);
			for(int i=0;i<ds.n;i++)
			{
				if(ds.DS[i].Maso==hv.Maso)
				{
					cout<<"\nMa so bi trung.Nhap lai";
					kt=false;
					break;
				}
			}
		}
		while(kt==false);
		
		
		for(int i=0;i<ds.n;i++)
		{
			if(stricmp(ds.DS[i].Ten,hv.Ten ) >0)
			{
				Them(ds,i,hv);
				break;
			}
			else if(stricmp(ds.DS[i].Ten,hv.Ten ) ==0)
			{
				if(stricmp(ds.DS[i].Ho,hv.Ho ) >=0)
				{
					Them(ds,i,hv);
					break;
				}
//				else if(stricmp(ds.DS[i].Ho.c_str(),hv.Ho.c_str() ) ==0)
//				{
//					
//					Them(ds,i,hv);
//					break;
//				}
			}
			else if(stricmp(ds.DS[i].Ten,hv.Ten )<0 && i==ds.n-1)
			{
				//them cuoi danh sach
				ds.DS[ds.n]=hv;
				ds.n++;
				break;
			}
		}
	}

	
}
//tim hoc vien theo ma so
void Tim_Hoc_Vien(LIST ds,int maso)
{
	if(ds.n<1)
	{
		cout<<"\nDanh sach trong!!!";
	}
	else
	{
		for(int i=0;i<ds.n;i++)
		{
			if(ds.DS[i].Maso==maso)
			{
				cout<<"\nMS\tHo\tTen\n";
				Xuat_Thong_Tin(ds.DS[i]);
				break;
			}
		}
		
	}

}

//ham xoa
void Xoa(LIST &ds,int vt)
{
	for(int i=vt;i<ds.n;i++)
	{
		ds.DS[i]=ds.DS[i+1];
	}
	ds.n--;
}
//xoa hoc vien theo ma so
void Xoa_Hoc_Vien(LIST &ds,int maso)
{
	if(ds.n<1)
	{
		cout<<"\n\tDanh sach trong!!!";
		getch();
	}
	else
	{
		for(int i=0;i<ds.n;i++)
		{
			if(ds.DS[i].Maso==maso)
			{
				Xoa(ds,i);
			}
		}
	}

}

//ham ghi 1 hoc vien ra file
void writeFile(ofstream &fileOut,HOCVIEN hv)
{

	fileOut<<setw(10)<<hv.Maso<<setw(25)<<hv.Ho<<setw(10)<<hv.Ten;

}
//ghi danh sach hoc vien ra file (mo file de ghi)
void writeFile_DS(ofstream &fileOut,LIST ds)
{
	fileOut.open("DSHV.txt",ios::out);
	fileOut<<"\t\tDANH SACH HOC VIEN\n";
	fileOut<<setw(10)<<"STT"<<setw(10)<<"MS"<<setw(25)<<"HO"<<setw(10)<<"Ten"<<endl;
	for(int i=0;i<ds.n;i++)
	{
		fileOut<<setw(10)<<i+1;
		writeFile(fileOut,ds.DS[i]);
		fileOut<<endl;
	}
	fileOut<<"\nTong so: "<<ds.n;
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
//ham cat chuoi lay tu cuoi cua chuoi
void Cat_Chuoi(char str[],char temp[])
{
	int m=0;
	int n=STRLEN(str);
	while(str[n-1]!=' ')
	{
		
		temp[m++]=str[n-1];
		str[n-1]='\0';
		n--;
		
	}
	for(int i=0;i<m/2;i++)
	{
		int x=temp[i];
		temp[i]=temp[m-1-i];
		temp[m-1-i]=x;
	}

}

void readFile_DS(ifstream &fileIn,LIST &ds)
{
	fileIn.open("DSHV.txt",ios::in);
	if(fileIn.fail())
	{
		cout<<"\nFailed to open this file";
		return;
	}
	string str;
	fflush(stdin);
	getline(fileIn,str);
	getline(fileIn,str);
	ds.n=0;
	while(!fileIn.eof())
	{
		int x;
		fileIn>>x;
		fileIn>>ds.DS[ds.n].Maso;
		fflush(stdin);
		string X;
		getline(fileIn,X);
		Chuan_Hoa_Chuoi((char*)X.c_str());
		char c[10]={}; 
		//chuyen string X sang char
		int i=0;
		while(i<STRLEN((char*)X.c_str()))
		{
			ds.DS[ds.n].Ho[i]=X[i];
			i++;
		}
		ds.DS[ds.n].Ho[i]='\0';
		Cat_Chuoi(ds.DS[ds.n].Ho,c);
		Chuan_Hoa_Chuoi(ds.DS[ds.n].Ho);
		Chuan_Hoa_Chuoi(c);
		//cout<<c<<'.'<<STRLEN(c)<<endl;
		
		cout<<ds.DS[ds.n].Ho<<STRLEN(ds.DS[ds.n].Ho )<<c;
		getch();
		
		i=0;
		while(c[i]!='\0')
		{
			ds.DS[ds.n].Ten[i]=c[i];
			i++;
		}
		ds.DS[ds.n].Ten[i]='\0';
		ds.n++;
		
		
	}

	fileIn.close();

}


void Menu(LIST &ds)
{
	while(1)
	{
		system("cls");
		cout<<"\n\t\t\tQUAN LY HOC VIEN\n";
		cout<<"\n\t\t0.Thoat";
		cout<<"\n\t\t1.Nhap danh sach hoc vien";
		cout<<"\n\t\t2.Xuat danh sach hoc vien";
		cout<<"\n\t\t3.Sap xep danh sach theo ten ho tang dan";
		cout<<"\n\t\t4.Them hoc vien vao danh sach";
		cout<<"\n\t\t5.Tim hoc vien theo ma so";
		cout<<"\n\t\t6.Xoa hoc vien theo ma so";
		cout<<"\n\t\t7.Luu danh sach hoc vien vao file DSHV.TXT";
		cout<<"\n\t\t8.Doc danh sach hoc vien tu file vao danh sach tuyen tinh\n";
		int luachon;
		cout<<"\nNhap lua chon: ";
		luachon=Nhap_So_Nguyen();
		if(luachon==1)
		{
			Nhap_Danh_Sach_Hv(ds);
		}
		else if(luachon==2)
		{
			Xuat_Danh_Sach_Hv(ds);
			getch();
		}
		else if(luachon==3)
		{

			Sap_Xep(ds);

		}
		else if(luachon==4)
		{
			if(ds.n<100)
			{
				Them_Hoc_Vien(ds);
				
			}
			else
			{
				cout<<"\nDanh sach day";
				getch();
			}
			
		}
		else if(luachon==5)
		{
			int maso;
			cout<<"\nNhap ma so hoc vien can tim: ";
			maso=Nhap_So_Nguyen();
			Tim_Hoc_Vien(ds,maso);
			getch();
		}
		else if(luachon==6)
		{
			int maso;
			cout<<"\nNhap ma so hoc vien can xoa: ";
			maso=Nhap_So_Nguyen();
			Xoa_Hoc_Vien(ds,maso);
		}
		else if(luachon==7)
		{
			ofstream fileOut;
			writeFile_DS(fileOut,ds);
		}
		else if(luachon==8)
		{
			ifstream fileIn;
			readFile_DS(fileIn,ds);
		//	getch();
		}
		else 
		{
			break;
		}

	}
}
