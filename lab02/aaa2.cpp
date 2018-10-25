#include<iostream>
using namespace std;
#include<string.h>

double result(int a,int b);

int main()
{

	int a,b,x;
	do
	{
		cout<<"\nresult : "<<result(a,b);
		cout<<"\nDo another (y/n)? \nyes=1\nno=0\n";
		cin>>x;
		
	}
	while(x==1);
	
	return 0;
}

double result(int a,int b)
{
	
	cout<<"\nnhap gia tri a: ";
	cin>>a;
	cout<<"\nnhap gia tri b: ";
	cin>>b;
	int x;
	cout<<"\nnhap phep tinh\n\ 1: + \n 2: -\n 3:*\n 4:/\n";
	cin>>x;
	switch(x)
	{
		case 1: return a+b; break;
		case 2: return a-b;break;
		case 3: return a*b;break;
		case 4: return a*1.0/b;break;
	}
}
