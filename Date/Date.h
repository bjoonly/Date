#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class Date{
	int day;
	int month;
	int year;
	static int DaysInMonths[12];
	void CorrectDate();
	void LeapYear(int year);
public:
	explicit Date(int day=1, int month=1, int year=1);
	void AddDay();
	
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);

	int GetDay()const;
	int GetMonth()const;
	int GetYear()const;

	void operator+=(int days);
	void operator-=(int days);
	
	void operator()(int days);
	void operator()(int months, int days);
	void operator()(int years, int months, int days);

	friend bool operator==(const Date&d1,const Date&d2);
	friend bool operator!=(const Date&d1,const Date& d2);
	friend bool operator>(const Date&d1,const Date& d2);
	friend bool operator<(const Date&d1,const Date& d2);

	friend ofstream&operator<<(ofstream& out, const Date& d);
	friend ifstream& operator>>(ifstream& in,  Date& d);

	friend ostream& operator<<(ostream& out, const Date& d);

	int GetDaysInMonth(int index);
};

Date& operator++(Date&d);
Date operator++(Date&d,int);
Date& operator--(Date&d);
Date operator--(Date&d,int);