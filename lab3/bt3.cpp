#include<iostream>
using namespace std;
class serial{
	private:
		int id;
		static int number;
	public :
		serial(){
			number++;
			id=number;
		}
		static void create(){
			cout<<number<<endl;
		}
		void xuat(){
			cout<<id<<endl;
		}
};
int serial::number=0;
int main(){
	for(int i=0;i<5;i++)
	{
		serial s;
		s.xuat();cout<<"\t\t";
		serial::create();
		
			
	}
	return 0;

}
