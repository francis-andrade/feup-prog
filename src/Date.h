# pragma once
#include <iostream>
#include<ctime>
using namespace std;

class Date {
private:
	unsigned int day;//day 
	unsigned int month;//month
	unsigned int year;//year

public:
	//Methods-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	Date();  // constructor; gets the current date
	Date(unsigned int year, unsigned int month, unsigned int day);//constructor
	unsigned int getyear() const;//gets the year
	unsigned int getmonth() const;//gets the month
	unsigned int getday() const;//gets the day
	void show() const;//prints the date on the screen
	//Friend functions-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	friend bool operator==(const Date &date1, const Date &date2);//checks if two dates are equal
	friend bool operator<(const Date &date1, const Date &date2);//compares two dates the first is smaller if it comes before the second one
	friend ostream& operator<<(ostream& out, const Date& date);//writes date in ostream out
	friend istream& operator>>(istream& in, Date& date);//gets date from instream in
};


