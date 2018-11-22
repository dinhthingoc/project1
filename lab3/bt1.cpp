#include<iostream>
using namespace std;


class time
{
	private:
		int hour2;
		int minute2;
		int second2;
	public:
		time();
		time(int a , int b, int c);
		void xuat();
		time tinh(time t)
		{
			int hour3;
			int minute3;
			int second3;
			time tg = new time(3,2,3);
			
		}
};
time::time()
{
	hour2=0;
	minute2=0;
	second2=0;
}

time::time(int a, int b,  int c)
{
	hour2=a;
	minute2=b;
	second2=c;
}
void time::xuat()
{
	cout << hour2 << ":"  << minute2 << ":" <<second2<<endl; 
}
void time::tinh()
{
	
}
int main()
{
	time *x1 = new time;
	time *x2 = new time(3,2,5);
	x1->xuat();
	x2->xuat();
	return 0;
}
