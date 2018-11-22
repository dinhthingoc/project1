#include<iostream>
using namespace std;
#include<string>

class employee
{
private:
	string ID;
	int thamnien;
public:
	void nhap();
	float baohiem();
	employee::employee();
	employee::~employee();
};
void employee::nhap()
{
	fflush(stdin);
	cout << "\nnhap ID: ";
	getline(cin, ID);
	cout << "\nnhap tham nien: ";
	cin >> thamnien;
}
float employee::baohiem()
{
	float tienBH=3000;
	for (int i = 0; i < thamnien; i++)
	{
		tienBH += (tienBH*0.055);
	}
	return tienBH;
}
employee::employee()
{

}
employee::~employee()
{

}
int main()
{
	employee *a = new employee();
	a->nhap();
	cout << "\ntien bao hiem: " << a->baohiem();
	delete a;
	system("pause");
	return 0;
}