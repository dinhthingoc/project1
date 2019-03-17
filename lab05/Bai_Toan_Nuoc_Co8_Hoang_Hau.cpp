#include<iostream>
using namespace std;
#include<windows.h> //ho tro tao ham gotoxy
#include<conio.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define N 8
int hang_trong[N];
int cheo_xuoi[2*N-1];
int cheo_nguoc[2*N-1];
int loi_giai[N];
char arr[N][N];


void gotoxy(short x, short y)
{
 HANDLE hConsoleOutput;
 COORD Cursor_an_Pos = { x, y };
 hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}


void Xuat_Ma_Tran(char arr[][N]);
void In_Loi_Giai(char arr[][N],int loi_giai[N]);
void Tim_Vi_Tri(int i,int &q);




int main()
{


	int q;
	for(int i=0;i<N;i++)
	{
		hang_trong[i]=TRUE;
	}
	for(int i=0;i<2*N-1;i++)
	{
		cheo_xuoi[i]=cheo_nguoc[i]=TRUE;
	}
	Tim_Vi_Tri(0,q);
	In_Loi_Giai(arr,loi_giai);
	Xuat_Ma_Tran(arr);
	
	
	gotoxy(20,20);
	return 0;
}
void Xuat_Ma_Tran(char arr[][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<arr[i][j]<<"  ";
		}
		cout<<endl;
	}
}
void In_Loi_Giai(char arr[][N],int loi_giai[N])
{
	//cai dat ma tran mac dinh ban dau
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			arr[i][j]='=';
		}
	}
	//gan Q cho ma tran tai cac vi tri chua con hau
	for(int i=0;i<N;i++)
	{
		arr[i][loi_giai[i]]='Q';
	}
}
void Tim_Vi_Tri(int i,int &q)
{
	int j=-1;
	do
	{
		j++;
		q=FALSE;
		if(hang_trong[j] && cheo_xuoi[i-j+N] && cheo_nguoc[i+j])
		{
			loi_giai[i]=j;
			hang_trong[j]=FALSE;
			cheo_xuoi[i-j+N]=FALSE;
			cheo_nguoc[i+j]=FALSE;
			if(i<N-1)
			{
				Tim_Vi_Tri(i+1,q);
				if(q==FALSE)
				{
					hang_trong[j]=TRUE;
					cheo_xuoi[i-j+N]=TRUE;
					cheo_nguoc[i+j]=TRUE;	
				}
			
			}
			else
			{
				q=TRUE;
			}
		
		}
	}
	while(q==FALSE && j<N-1);

}
