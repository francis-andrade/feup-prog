#include "Client.h"
#include "functions_auxiliary.h"
#include<iomanip>
#include<sstream>

//Methods--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Default constructor
*/
Client::Client(){
	id = 0;
	name = "";
	accession_date = Date();
	purchase_amount = 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: unsigned int id - client id
parameter: const Date & accession_date - Date when the client registered in the supermarket
parameter: double purchase_amount - purchase_amount of the new client object
Constructs an object with the above parameters
*/
Client::Client(unsigned int id, string name,const Date & accession_date, double purchase_amount){
	this->id = id;
	this->name = name;
	this->purchase_amount = purchase_amount;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns client id
*/
unsigned int Client::getid() const{
	return id;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Return name of the client
*/
string Client::getname() const{
	return name;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns the accession_date of the client
*/
Date Client::getaccession_date() const{
	return accession_date;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns the purchase_amount of the client
*/
double Client::getpurchase_amount() const{
	return purchase_amount;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Prints the client on the screen
*/
void Client::show() const{
	cout << setw(9) << id << "|" << setw(16) << setprecision(2) << fixed << purchase_amount << "|";
	cout<<"     ";
	accession_date.show();
	cout<< "| " << name;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const string & name - new name of the client object
Sets a new for the client
*/
void Client::setname(const string & name){
	this->name = name;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: double purchase_amount - new purchase amount of the client object
Sets a new purchase amount for the client
*/
void Client::setpurchase_amount(double purchase_amount){
	this->purchase_amount = purchase_amount;
}
//Friend functions--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const Client &client_left - client passed as left argument
parameter: const Client &client_right - client passed as right argument
Returns true if the id of client_left is less than the id of client_right
*/
bool operator<(const Client &client_left, const Client &client_right){
	return client_left.id < client_right.id;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: ostream &out - ostream where a new client is going to be written
parameter: const Client & client - client that is going to be written in the ostream
Writes a client on an ostream
*/
ostream& operator<<(ostream &out, const Client &client){
	out << client.id << " ; " << client.name << " ; " << client.accession_date << " ; " << client.purchase_amount;
	return out;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: istream &in - istream from where a new client is going to be read
parameter: Client &client - variable that will store the new client
Reads a client from an istream
*/
istream& operator>>(istream &in, Client &client){
	in >> client.id;
	char semicolon;//semicolon that exists in the file
	in >> semicolon;//exctrats the semicolon
	string name;//name of the client
	getline(in, name, ';');
	client.name = removespaces(name);//the name that is put into client name has no spaces
	in >> client.accession_date;
	in >> semicolon;
	in >> client.purchase_amount;
	return in;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const Client &client_left - client passed as left argument
parameter: const Client &client_right - client passed as right argument
Returns true if the name of client_left comes before the name of client_right in lexicographic order. 
Returns false otherwise.
*/
bool alphabeticorder(const Client & client_left, const Client & client_right){
	return alphabeticorderstring(client_left.name , client_right.name);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const Client &client_left - client passed as left argument
parameter: const Client &client_right - client passed as right argument
Returns true if client_left spent less than client_right.
Return false otherwise
*/
bool purchaseamountorder(const Client & client_left, const Client & client_right){
	return client_left.purchase_amount < client_right.purchase_amount;
}


