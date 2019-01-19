#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Date.h"

using namespace std;

class Transaction{
private:
	unsigned int client_id;//id of the client that made the transaction
	Date date;//date when the transaction was made
	vector<string> products;//vector of products that were bought
public:
	//Methods--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	Transaction();//default constructor
	Transaction(unsigned int client_id,const Date & date, const vector<string> & products);//constructor
	void addproduct(const string & product);//adds product to the transactions
	unsigned int getclient_id() const;//gets client_id
	Date getdate() const;//gets date
	vector<string> getproducts() const;//gets products
	void show() const;//prints transaction on the screen
	//Friend functions--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	friend bool operator<(const Transaction &transaction_left, const Transaction &transaction_right);//operator<: transaction_left was made before transactions_right
	friend ostream& operator<<(ostream &out, const Transaction &transaction);//operator<<: writes Transactions in an ostream
	friend istream& operator>>(istream &in, Transaction &transaction);//operator>>: reads Transactions from an istream
	};