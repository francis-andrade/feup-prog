#pragma once
#include "Client.h"
#include "Product.h"
#include "Transaction.h"
#include "functions_auxiliary.h"
#include <vector>
#include<map>
#include<iostream>
#include<fstream>
using namespace std;

class Vendemaismais{
private:
	vector<Client> clients;//vector with client
	vector<Product> products;//vector with products
	vector<Transaction> transactions;//vector with transactions
	bool leaveprogram;//boolean that will tell the program to leave
	string filename_clients;//clients filename
	string filename_products;//products filename
	string filename_transactions;//transactions filename
	static Vendemaismais * singleton_instance;//pointer to instance of class Vendemaismais
	Vendemaismais();//constructor
	~Vendemaismais();//destructor
public:
	//Methods-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	static Vendemaismais * getinstance();//gets instance of class Vendemaismais
	bool getleaveprogram() const;//gets leaveprogram
	vector<Client> getclients() const;//gets clients
	vector<Product> getproducts() const;//gets products
	vector<Transaction> gettransactions() const;//gets transactions
	string getfilename_clients() const;//gets clients file_name
	string getfilename_products() const;//gets products file_name
	string getfilename_transactions() const;//gets transactions file_name
	bool valid_id(const int id) const;//sees if id is valid
	bool valid_name(const string & name) const;//checks if a name is valid or already exists
	map<int, int> assoaciateidtopos() const;//associates a client ID to its position on the vector of clients
	map<Product, int> associateproducttopos() const;//associates a product to its position on the vector of products
	map<string, Product> associatenametoproduct() const;//associates a string with a product name to the product itself
	multimap<Client, Transaction> associateclienttotransactions()const;//associates a client with his transactions
	void showclients() const;//prints the clients on the screen
	void showproducts() const;//prints the products on the screen
	void showtransactions() const;//prints the transactions on the screen
	void setleaveprogram(bool new_leaveprogram);//sets leaveprogram to a new value
	void setfilename_clients(const string & filename_clients);//sets filename_clients to a new value
	void setfilename_products(const string & filename_products);//sets filename_products to a new value
	void setfilename_transactions(const string & filename_transactions);//sets filename_transactions to a new value
	void addclient(const string & client_name);//adds a new client
	void removeclient(int client_id);//removes a client by his id
	void changename(int client_id, const string & new_name);//changes the name of a client
	void addtransaction(const Transaction & transaction);//adds a new transaction
	void raisepurchase_amount(int id, double cost);//actualizes purchase amount of a given client
	void readclients(istream &in);//reads clients from an istream
	void readproducts(istream &in);//reads products from an istream
	void readtransactions(istream &in);//reads transactions from an istream
	void writeclients() const;//writes clients on a file
	void writeproducts() const;//writes products on a file
	void writetransactions() const;//writes transactions on a file
};