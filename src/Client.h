#pragma once
#include "Date.h"
#include<iostream>
#include<string>
using namespace std;

class Client{
private:
	unsigned int id;//client id
	string name;//name of the client
	Date accession_date;//date this client registered in the supermarket
	double purchase_amount;//total cost of all the transactions the client made
public:
	//Methods--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	Client();//default constructor
	Client(unsigned int id, string name,const Date & accession_date, double purchase_amount);//constructor
	unsigned int getid() const;//gets client id
	string getname() const;//gets client name
	Date getaccession_date() const;//gets accession_date
	double getpurchase_amount() const;//gets purchase amount
	void show() const;//prints client on the screen
	void setname(const string & name);//sets client name
	void setpurchase_amount(double purchase_amount);//sets purchase_amount
	//Friend functions--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	friend bool operator<(const Client &client_left, const Client &client_right);//operator<:returns true if client_left id is less than client_right id
	friend ostream& operator<<(ostream &out, const Client &client);//operator<<:writes client in an ostream
	friend istream& operator>>(istream &in, Client &client);//operator>>:reads client from an istream
	friend bool alphabeticorder(const Client & client_left, const Client & client_right);//return true if client_left comes before client_right in lexicographical order
	friend bool purchaseamountorder(const Client & client_left, const Client & client_right);//return true if client_left spent less than client_right
};
