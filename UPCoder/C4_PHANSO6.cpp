//không phải mình làm
#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
#include <stdio.h>
using namespace std;
class PhanSo
{
protected:
	int tu, mau;
public:
	PhanSo() { tu = 0; mau = 1; };
	PhanSo(int x, int y)
	{
		tu = x; mau = y;
		kiemtra();
	}
	PhanSo(const PhanSo&a)
	{
		tu = a.tu;
		mau = a.mau;
	}
	int gettu() { return tu; }
	int getmau() { return mau; }
	void kiemtra()
	{
		if (mau < 0)
		{
			tu *= -1;
			mau *= -1;
		}
	}
	friend istream&operator>>(istream&cin, PhanSo& a);
	friend ostream&operator<<(ostream&cout, PhanSo a);
	void rutgon();
	float lamtron()
	{
		float x, y,r;
		x = float(tu);
		y = float(mau);
		r = round(x / y * 10000) / 10000;
		return r;
	}
};
istream&operator>>(istream&cin, PhanSo& a)
{
	cin >> a.tu >> a.mau;
	a.kiemtra();
	return cin;
}
ostream&operator<<(ostream&cout, PhanSo a)
{
	cout << a.tu << "/" << a.mau;
	return cout;
}
void PhanSo::rutgon()
{
	int x, y, r;
	x = tu > mau ? tu : mau;
	y = tu > mau ? mau : tu;
	do
	{
		r = x % y;
		x = y;
		y = r;
	} while (r != 0);
	tu /= x;
	mau /= x;
}
int main()
{
	float a; int b,a1;
	cin >> a;
	if (cin >> b)
	{
		PhanSo ps;
		a1 = int(a);
		ps = PhanSo(a1, b);
		ps.rutgon();
		cout <<ps <<endl;
		cout << ps.lamtron();
	}
	else
	{
		PhanSo ps1;
		a1 = int(a * 10000);
		b = 10000;
		ps1 = PhanSo(a1, b);
		ps1.rutgon();
		ps1.kiemtra();
		cout << ps1 << endl;
	}
}
