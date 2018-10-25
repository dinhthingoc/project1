#include<iostream>
using namespace std;

float moneyX(int money,int year,int interest_rase);

int main()
{
	int money;
	int year;
	float interest_rase;
	cout<<"\nnhap money: ";
	cin>>money;
	cout<<"\nnhap year: ";
	cin>>year;
	cout<<"\nnhap interest rase: ";
	cin>>interest_rase;
	
	cout<<"\n\t\ttong tien: "<<moneyX(money,year,interest_rase);
	
	return 0;
}
float moneyX(int money,int year,int interest_rase)
{
	float tongtien=money;
	for(int i=1;i<=year;i++)
	{
		tongtien += (tongtien*(interest_rase/100.0));
	}
	return tongtien;
}
