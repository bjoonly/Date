#include "Date.h"
int Date::DaysInMonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

void Date::CorrectDate(){
	if (month > 12) {
		year += month / 12;
		month %= 12;
	}
	
	LeapYear(year);
	while (day / DaysInMonths[month - 1]) {
		if (day - DaysInMonths[month - 1] > 0) {
			day -= DaysInMonths[month - 1];
			++month;
			if (month > 12) {
				month = 1;
				++year;
				LeapYear(year);
			}
		}
		else
			break;
	}
	DaysInMonths[1] = 28;
}

void Date::LeapYear(int year){
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		DaysInMonths[1] = 29;
	else
		DaysInMonths[1] = 28;
}

Date::Date(int day, int month, int year){
	if (day < 1)
		day = 1;
	this->day = day;
	if (month < 1)
		month = 1;
	this->month = month;
	if (year < 1)
		year = 1;
	this->year = year;
	CorrectDate();
}

void Date::AddDay(){
	day++;
	CorrectDate();
}

void Date::SetDay(int day){
	if (day < 1)
		return;

	this->day = day;
	CorrectDate();
}

void Date::SetMonth(int month){
	if (month < 1)
		return;
	this->month = month;
	CorrectDate();
}

void Date::SetYear(int year){
	if (year < 1)
		return;
	this->year = year;
}

int Date::GetDay() const{
	return day;
}

int Date::GetMonth() const{
	return month;
}

int Date::GetYear() const{
	return year;
}

void Date::operator+=(int days){
	if (days < 1)
		return;

		day += days;
		CorrectDate();
	
}

void Date::operator-=(int days){
	if (days < 1)
		return;

	LeapYear(year);
	if (day - days < 1) {
		days -= day;
		if (--month == 0) {
			month = 12;
			--year;
			LeapYear(year);
		}
		while (days / DaysInMonths[month - 1]) {
			days -= DaysInMonths[month - 1];
			if (--month == 0) {
				month = 12;
				--year;
				LeapYear(year);
			}
		}
		day = DaysInMonths[month - 1] - days;
	}
	else
		day -= days;

	CorrectDate();

}

void Date::operator()(int days){
	if (days > 0) {
		day += days;
		CorrectDate();
	}
}

void Date::operator()(int months, int days){
	if (days > 0 && month > 0) {
		month += months;
		day += days;
		CorrectDate();
	}

}

void Date::operator()(int years, int months, int days){
	if (days > 0 && month > 0 && years>0) {
		year += years;
		month += months;
		day += days;
		CorrectDate();
	}
}



int Date::GetDaysInMonth(int month) {
	if (month > 0 && month < 13)
		return DaysInMonths[month-1];
	else
		return 0;
}

bool operator==(const Date& d1, const Date& d2){
	return (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day);
}

bool operator!=(const Date& d1, const Date& d2){
	return (d1.year != d2.year || d1.month != d2.month || d1.day != d2.day);

}

bool operator>(const Date& d1, const Date& d2){
	return ((d1.year > d2.year) || ((d1.year == d2.year) && (d1.month > d2.month)) || ((d1.year == d2.year) && (d1.month == d2.month) && (d1.day > d2.day)));

}

bool operator<(const Date& d1, const Date& d2){
	return ((d1.year < d2.year) || ((d1.year == d2.year) && (d1.month < d2.month)) || ((d1.year == d2.year) && (d1.month == d2.month) && (d1.day < d2.day)));
	

}

ofstream& operator<<(ofstream& out, const Date& d){
	out << d.day << endl << d.month << endl << d.year << endl;
	return out;
}

ifstream& operator>>(ifstream& in, Date& d){
	in >> d.day;
	in >> d.month;
	in >> d.year;
	return in;
}

ostream& operator<<(ostream& out, const Date& d){
	out << d.day << "\\" << d.month << "\\" << d.year << endl;
	return out;
}

Date& operator++(Date& d){
	d += 1;
	return d;
}

Date operator++(Date& d, int){
	Date res = d;
	d -= 1;
	return res;

}

Date& operator--(Date& d){
	d -= 1;
	return d;
}

Date operator--(Date& d, int){
	Date res = d;
	d -= 1;
	return res;

}
