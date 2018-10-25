#include<iostream>
using namespace std;
#include<string.h>

struct phonenumber
{
	string erea;
	int exchange;
	int number;
};
typedef struct phonenumber PHONENUMBER;

void nhap_number(PHONENUMBER &nb);
void xuat_number(PHONENUMBER nb);

int main()
{
	PHONENUMBER nb;
	nhap_number(nb);
	cout<<"\n\t\t result\n";
	xuat_number(nb);
	
	
	return 0;
}
void nhap_number(PHONENUMBER &nb)
{
	cout<<"\nphone number: ";
	
	getline(cin,nb.erea);
	cin>>nb.exchange>>nb.number;
}
void xuat_number(PHONENUMBER nb)
{
	cout<<"\n\t my number is: "<<"555 777 3333";
	cout<<"\n\t your number is: "<<nb.erea<<' '<<nb.exchange<<'-'<<nb.number;
}
