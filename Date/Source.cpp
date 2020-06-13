#include<iostream>
#include"Date.h"
using namespace std;

int main() {
	Date d1 (29, 2, 1999),d2(2,3,1999),d3;
	cout << "D1: " << d1 << endl;;
	cout << "D2: " << d2 << endl;
	cout << "D1++: " << d1++ << endl;
	cout << "++D1: "<<++d1<<endl;
	cout << "D1--: " << d1-- << endl;
	cout << "--D1: " << --d1 << endl;
	cout << "D1 > D2 ? " << boolalpha << (d1 > d2) << "\n\n";
	cout << "D1 < D2 ? " << boolalpha << (d1 < d2) << "\n\n";
	cout << "D1 == D2 ? " << boolalpha << (d1 == d2) << "\n\n";
	cout << "D1 != D2 ? " << boolalpha << (d1 != d2) << "\n\n";
	d1 += 15;
	cout << "D1 + 15 days: " << d1<<endl;
	d1 -= 25;
	cout << "D1 - 25 days: " << d1<<endl;
	cout << "Save D1.\n\n";
	ofstream out("Date.txt");
	out << d1;
	out.close();
	d2(30);
	cout << "D2 + 30 days: " << d2 << endl;
	d2(2,10);
	cout << "D2 + 10 days, 2 months: " << d2 << endl;
	d2(3, 5, 7);
	cout << "D2 + 7 days, 5 months, 3 years: " << d2 << endl;
	cout << "Load from file to D3: ";
	ifstream in("Date.txt");
	in >> d3;
	in.close();
	cout << d3 << endl;
	return 0;
}