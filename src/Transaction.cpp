#include "Transaction.h"
#include "functions_auxiliary.h"
#include<iomanip>
#include<sstream>
#include<vector>
//Methods--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Default constructor
*/
Transaction::Transaction(){
	client_id = 0;
	Date date;
	products.clear();
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: unsigned int client_id - client_id
parameter: const Date date & date - date
parameter: const vector<string> & products - products
Constructor
*/
Transaction::Transaction(unsigned int client_id, const Date & date,const vector<string> & products)
	:date(date)
{
	this->client_id = client_id;
	this->products = products;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const string & product - name of the product that is going to be added to this transaction
Adds a new product to the transaction
*/
void Transaction::addproduct(const string & product){
	products.push_back(product);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns the client_id
*/
unsigned int Transaction::getclient_id() const {
	return client_id;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns the date
*/
Date Transaction::getdate() const{
	return date;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns the products
*/
vector<string> Transaction::getproducts() const{
	return products;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Prints the transactions on the screen
*/
void Transaction::show() const{
	cout << setw(6) << client_id << "|  ";
	date.show();
	cout << "|" << " ";
	for (unsigned int i = 0; i < products.size()-1; i++){
		cout << " " << products[i] << ";";
	}
	if (products.size()>0){
		cout << " " << products[products.size()-1];
	}
}
//Friend functions--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const Transaction & transaction_left - transaction passed as left parameter
parameter: const Transaction & transaction_right - transaction passed as right parameter
Returns true if transaction_left was made before than transaction_right
*/
bool operator<(const Transaction &transaction_left, const Transaction &transaction_right){
	return (transaction_left.date < transaction_right.date) ;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: ostream & out - ostream where a transaction is going to be written to
parameter: const Transaction & transaction - Transaction that is going to be written into the ostream
Writes a transaction into an ostream
*/
ostream& operator<<(ostream &out, const Transaction &transaction){
	out << transaction.client_id << " ; " << transaction.date << " ; ";
	for (unsigned int i = 0; i < transaction.products.size(); i++){
		if (i < transaction.products.size() - 1){
			out << transaction.products[i] << ", ";
		}
		else{
			out << transaction.products[i];
		}
	}
	return out;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: istream &in - istream where a new transaction is going to be written from
parameter: Transaction &transaction - variable that will store the new transaction that is going to be read from the istream
Reads a transaction from an istream
*/
istream& operator>>(istream &in, Transaction &transaction){
	in >> transaction.client_id;
	char semicolon;//semicolon that exists in the middle of a transaction
	in >> semicolon;
	in >> transaction.date;
	in >> semicolon;
	string products;//products in this transaction
	getline(in, products);//gets the products
	istringstream ss_products(removespaces(products));
	string product;//new product that is going to be added to the list
	while (getline(ss_products, product, ',')){
		if (removespaces(product).size() > 0){
			transaction.products.push_back(removespaces(product));
		}
	}
	return in;
}

