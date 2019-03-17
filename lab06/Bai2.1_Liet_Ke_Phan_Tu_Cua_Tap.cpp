#include<stdio.h>  //thu vien ho tro nhap xuat chuan
#include<conio.h>  //thu vien chua lenh getch()_dung man hinh
#include<iomanip>



//ham doc file
void readFile(FILE *fileIn,int arr[],int &n,int &B);

//ham chuyen day so tu nhien sang 1 mang tam thoi
void Chuyen_Day_So(int arr[],int n,int c[],int &q);


//sap xep day so tang dan
void Sap_Xep(int arr[],int n);
void Xuat_Mang(int tam[],int m);
//chi lay cac phan tu nho hon hoac bang B dua vao mang a
void Duyet_Day_So(int arr[],int n,int a[],int &p,int B);

//ham ghi file
void writeFile(FILE *fileOut,int tam[],int m);
//hàm tìm vi tri ban dau cua cac so tu nhien trong day ban dau
void Tim_Vi_Tri(int a[],int p,int tam[],int m,int c[],int q,int d[],int &r);
void Tim_Phan_Tu_Cua_Tap(FILE *fileOut,int a[],int p,int tam[],int m,int B,int x,int &i,int dem,int &TH,int c[],int q,int d[],int r);


int main()
{
	FILE *fileIn;
	FILE *fileOut;
	int arr[100],tam[100], a[100],c[100],d[100];
	int n,B,q,p,r;
	readFile(fileIn,arr,n,B);
	
	Chuyen_Day_So(arr,n,c,q);
//	printf("\nmang c\n");
//	Xuat_Mang(c,q);
	Sap_Xep(arr,n);
//	printf("\nDay so sau khi sap xep\n");
//	Xuat_Mang(arr,n);
	Duyet_Day_So(arr,n,a,p,B);
//	printf("\nCac phan tu cua day so nho hon hoac bang B \n\n");
//	Xuat_Mang(a,p);
	
	printf("\n\n");
	int m=n;
	for(int k=0;k<m;k++)
	{
		tam[k]=0;
	}

	fileOut=fopen("ketqua2.txt","w");
	if(fileOut==NULL)
	{
		printf("Faile to open this file!");
		system("pause");
	}
	int TH=0;
	fprintf(fileOut,"%d\n\n",0);
	int i=0;
	int x=a[0];
	int dem=0;
	Tim_Phan_Tu_Cua_Tap(fileOut,a,p,tam,m,B,x,i,dem,TH,c,q,d,r);

	fclose(fileOut);
	return 0;
	getch();

}
//ham doc file
void readFile(FILE *fileIn,int arr[],int &n,int &B)
{
	fileIn=fopen("data2.txt","r");
	if(fileIn==NULL)
	{
		printf("Faile to open this file!");
		system("pause");
		return;
	}
	fscanf(fileIn,"%d",&n);
	printf("n=%d",n);
	fscanf(fileIn,"%d",&B);
	printf("\nB=%d\n",B);
	//doc day so tu nhien tu file
	for(int i=0;i<n;i++)
	{
		fscanf(fileIn,"%d",&arr[i]);
	
	}
	fclose(fileIn);
}
//ham ghi file
void writeFile(FILE *fileOut,int tam[],int m)
{
	for(int i=0;i<m;i++)
	{
		fprintf(fileOut,"%d\t",tam[i]);
	}
	fprintf(fileOut,"\n");

}
//ham chuyen day so tu nhien sang 1 mang tam thoi
void Chuyen_Day_So(int arr[],int n,int c[],int &q)
{
	q=0;
	for(int i=0;i<n;i++)
	{
		c[q++]=arr[i];
	}
}


void Sap_Xep(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void Xuat_Mang(int tam[],int m)
{
	for(int i=0;i<m;i++)
	{
		printf("%d\t",tam[i]);
	}
	printf("\n");
}
void Duyet_Day_So(int arr[],int n,int a[],int &p,int B)
{
	p=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<=B)
		{
			a[p++]=arr[i];
		}
		else break;
	}

}
//hàm tim vi tri ban dau cua cac so tu nhien trong day ban dau
void Tim_Vi_Tri(int a[],int p,int tam[],int m,int c[],int q,int d[],int &r)
{
	int arr[100];
	for(int i=0;i<r;i++)
	{
		arr[i]=c[i];
	}
	r=0;
	for(int i=0;i<m;i++)
	{
		d[r++]=0;
	}
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<q;j++)
		{
			if(a[i]==c[j] && arr[j]!=0)
			{
				d[j]=tam[i];
			//	d[j]=tam[i];
				arr[j]=0;
				break;
			}
		
		}
	}
}
void Tim_Phan_Tu_Cua_Tap(FILE *fileOut,int a[],int p,int tam[],int m,int B,int x,int &i,int dem,int &TH,int c[],int q,int d[],int r)
{

	if(x==B)
	{
		tam[i]=1;
		Tim_Vi_Tri(a,p,tam,m,c,q,d,r);
		Xuat_Mang(d,r);
		TH++;
		writeFile(fileOut,d,r);
	}
	else if(x<B && i<p-1)
	{
		tam[i]=1;
		int j,h;
		if(dem==i)
		{
			j=i+1;
			h=i+1;
		}
		else if(dem+1<p)
		{
			
			j=dem+1;
			h=j;
		}
		bool kt=false;
		while(j<p)
		{
			
			if(x+a[j]==B)
			{
				tam[j]=1;
				Tim_Vi_Tri(a,p,tam,m,c,q,d,r);
				Xuat_Mang(d,r);
				TH++;
				writeFile(fileOut,d,r);
				tam[j]=0;
			}
			else if(x+a[j]>B)
			{
				x=x+a[h];
				tam[h]=1;
				dem++;
				kt=true;
				break;
			}
			j++;
			
		}
		if(kt==true && x<B)
		{
			
			Tim_Phan_Tu_Cua_Tap(fileOut,a,p,tam,m,B,x,i,dem,TH,c,q,d,r);
			
		}	
	}


	for(int k=0;k<m;k++)
	{
		tam[k]=0;
	}
	i++;

	if(i<p)
	{
		dem=i;
		x=a[i];
		Tim_Phan_Tu_Cua_Tap(fileOut,a,p,tam,m,B,x,i,dem,TH,c,q,d,r);

	}	
	else if(i==p)
	{
		
		fseek(fileOut,-ftell(fileOut),SEEK_END);
		fprintf(fileOut,"%d",TH);
	}


}

