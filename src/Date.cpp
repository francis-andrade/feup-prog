#include "Date.h"


//Methods-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Default constructor
Sets date to current date
*/
Date::Date(){
	struct tm timeinfo;
	time_t t = time(0);   // gets current time
	localtime_s(&timeinfo, &t);
	year = timeinfo.tm_year + 1900;
	month = timeinfo.tm_mon + 1;
	day = timeinfo.tm_mday;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: unsigned int year - date year
parameter: unsigned int month - date month
parameter: unsigned int day - date day
Constructor
Constructs a date with year, month and day as the values passed as parameters
*/
Date::Date(unsigned int year, unsigned int month, unsigned int day){
	this->year = year;
	this->month = month;
	this->day = day;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns year of the date
*/
unsigned int Date::getyear() const{
	return year;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns month of the date
*/
unsigned int Date::getmonth() const{
	return month;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns day of the date
*/
unsigned int Date::getday() const{
	return day;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Prints the date on the screen
*/
void Date::show() const{
	cout << year;
	cout << "/";
	if (month < 10){
		std::cout << 0 <<month ;
	}
	else{
		cout << month;
	}
	cout << "/";
	if (day < 10){
		cout << 0 << day;
	}
	else{
		cout << day;
	}
}
// Friend Functions-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const Date &date_left - date passed as left parameter
parameter: const Date &date_right - date passed as right parameter
*/
bool operator==(const Date &date_left, const Date &date_right){
	return (date_left.year == date_right.year && date_left.month == date_right.month && date_left.day == date_right.day);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const Date &date_left - date passed as left parameter
parameter: const Date &date_right - date passed as right parameter
Returns true if date_left comes before date_right. Returns false otherwise.
It also returns false if both dates are equal
*/
bool operator<(const Date &date_left, const Date &date_right){
	if (date_left.year < date_right.year){
		return true;
	}
	else if (date_right.year < date_left.year){
		return false;
	}
	else if (date_left.month < date_right.month){
		return true;
	}
	else if (date_right.month < date_left.month){
		return false;
	}
	else if (date_right.day < date_left.day || date_right.day==date_left.day){
		return false;
	}
	else{
		return true;
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: ostream & out - ostream where date is going to be written
parameter: const Date & date - date
Writes the date passed as a parameter in out
*/
ostream& operator<<(ostream& out, const Date& date){
	out << date.day;
	out << "/";
	if (date.month < 10){
		out << 0;
	}
	out << date.month;
	out << "/";
	out << date.year;
	return out;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: istream & in - istream from where date is going to be read
parameter: Date & date - variable where the date extracted from stream is going to be stored
Reads date from istream
*/
istream& operator>>(istream& in, Date& date){
	in >> date.day;
	in.ignore(1);
	in >> date.month;
	in.ignore(1);
	in >> date.year;
	return in;
}
