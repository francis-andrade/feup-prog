#include "Vende++.h"
#include<algorithm>
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Vendemaismais * Vendemaismais::singleton_instance = NULL;//Initially singleton_instance points to null
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Private Default Constructor
*/
Vendemaismais::Vendemaismais(){
	clients.clear();
	products.clear();
	transactions.clear();
	leaveprogram = false;
	filename_clients = "";
	filename_products = "";
	filename_transactions = "";
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Private Destructor
*/
Vendemaismais::~Vendemaismais(){
	delete singleton_instance;
	singleton_instance = NULL;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Gets instance of Vendemaismais Class
*/
Vendemaismais * Vendemaismais::getinstance(){
	if (!singleton_instance){
		singleton_instance = new Vendemaismais;
	}
	return singleton_instance;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns leaveprogram
*/
bool Vendemaismais::getleaveprogram() const{
	return leaveprogram;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Return clients vector
*/
vector<Client> Vendemaismais::getclients() const{
	return clients;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Return products vector
*/
vector<Product> Vendemaismais::getproducts() const{
	return products;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns transactions vector
*/
vector<Transaction> Vendemaismais::gettransactions() const{
	return transactions;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns clients filename
*/
string Vendemaismais::getfilename_clients() const{
	return filename_clients;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns products filename
*/
string Vendemaismais::getfilename_products() const{
	return filename_products;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns transactions filename
*/
string Vendemaismais::getfilename_transactions() const{
	return filename_transactions;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const int id - id of a client
Returns true if there is client such that his client_id is id. Returns false, otherwise.
*/
bool Vendemaismais::valid_id(const int id) const{
	unsigned int i = 0;
	while (i < clients.size() && clients[i].getid() != id){
		i++;
	}
	if (i == clients.size() ){
		return false;
	}
	else{
		return true;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const string & name - name of a client
Returns true if there is a client whose name is the one passed as a parameter. Returns false, otherwise.
*/
bool Vendemaismais::valid_name(const string & name) const{
	unsigned int i = 0;
	while (i < clients.size() && clients[i].getname() != name){
		i++;
	}
	if (i == clients.size()){
		return true;
	}
	else{
		return false;
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns a map that associates each id of a client to its position in the list of clients
*/
map<int, int> Vendemaismais::assoaciateidtopos() const{
	map<int, int> idtopos;
	for (unsigned int i = 0; i < clients.size(); i++){
		idtopos[clients[i].getid()] = i;
	}
	return idtopos;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns a map that associates each product to its position in the list of products
*/
map<Product, int> Vendemaismais::associateproducttopos() const{
	map<Product, int> producttopos;
	for (unsigned int i = 0; i < products.size(); i++){
		producttopos[products[i]] = i;
	}
	return producttopos;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns a map that associates each name of a product to the product itself
*/
map<string, Product> Vendemaismais::associatenametoproduct() const{
	map<string, Product> nametoproduct;
	for (unsigned int i = 0; i < products.size(); i++){
		nametoproduct[products[i].getname()] = products[i];
	}
	return nametoproduct;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Returns a multimap that associates each client to its transactions
*/
multimap<Client, Transaction> Vendemaismais::associateclienttotransactions()const{
	multimap<Client, Transaction> clienttotransaction;
	for (unsigned int i = 0; i < clients.size(); i++){
		for (unsigned int j = 0; j < transactions.size(); j++){
			if (clients[i].getid() == transactions[j].getclient_id()){
				clienttotransaction.insert(pair<Client, Transaction>(clients[i], transactions[j]));
			}
		}
	}
	return clienttotransaction;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Prints clients on the screen
*/
void Vendemaismais::showclients() const{
	vector<Client> vector_clients = clients;
	sort(vector_clients.begin(), vector_clients.end(),alphabeticorder);
	cout << "Clients in Alphabetical Order:\n" << endl;
	cout << "Number of clients: " << vector_clients.size()<<endl;
	cout << "Client ID|" << " Purchase Amount|" << " Accession Date|"<< " Name" << endl;
	for (unsigned int i = 0; i < clients.size() ; i++){
		vector_clients[i].show();
		cout << "\n";
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Prints products on the screen
*/
void Vendemaismais::showproducts() const{
	cout << "Products Available:\n" << endl;
	cout << "             Product Name |" << " Cost";
	for (unsigned int i = 0; i < products.size(); i++){
		cout << "\n";
		if (i < 9){
			cout << i + 1 << ".   ";
		}
		else if (i < 99){
			cout << i + 1 << ".  ";
		}
	else if(i<999){
		cout << i + 1 << ". ";
	}
	else{
		cout << i + 1 << ".";
	}
		products[i].show();
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Prints transactions on the screen
*/
void Vendemaismais::showtransactions() const{
	cout << "Transactions:\n" << endl;
	cout << "Client|" << "        Date|" << "  Products" ;
	for (unsigned int i = 0; i < transactions.size(); i++){
		cout << "\n";
		transactions[i].show();
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: bool new_leaveprogram - new value of leave program
Sets leaveprogram to new_leaveprogram
*/
void Vendemaismais::setleaveprogram(bool new_leaveprogram){
	leaveprogram = new_leaveprogram;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const string & filename_clients - path of filename_clients
Sets filename_clients to filename_clients passed as parameter
*/
void Vendemaismais::setfilename_clients(const string & filename_clients){
	this->filename_clients = filename_clients;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const string & filename_products - path of filename_products
Sets filename_products to filename_products passed as parameter
*/
void Vendemaismais::setfilename_products(const string & filename_products){
	this->filename_products = filename_products;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const string & filename_transactions - path of filename_transactions
Sets filename_transactions to filename_transactions passed as parameter
*/
void Vendemaismais::setfilename_transactions(const string & filename_transactions){
	this->filename_transactions = filename_transactions;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const string & client_name - name of the client that is going to be added
Adds to the list a client with name client_name
His id is set automatically to the number consecutive to the largest current
His accession_date is set to the current date
*/
void Vendemaismais::addclient(const string & client_name){
	unsigned int maxidtransaction = 0;//this variable will be used to keep the current maximum id as the program runs through the vector of transactions
	/*The following loop determines the maximum id in the transactions and stores it in maxidtransaction*/
	for (unsigned int i = 0; i <= transactions.size() - 1; i++){
		if (maxidtransaction < transactions[i].getclient_id()){
			maxidtransaction = transactions[i].getclient_id();
		}
	}
	Client new_client(max(maxidtransaction, clients[clients.size() - 1].getid()) + 1, client_name, Date(), 0);
	clients.push_back(new_client);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: int client_id - id of the client that is going to be removed
Removes the client with id passed as parameter from the list of clients
*/
void Vendemaismais::removeclient(int client_id){
	unsigned int i = 0;
	while (i < clients.size() && client_id != clients[i].getid()){
		i++;
	}
	if (i != clients.size()){
		clients.erase(clients.begin() + i);
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: int client_id - id of the client whose name is going to be changed
parameter: const string & new_name - new name of the client
Changes the name of a client
*/
void Vendemaismais::changename(int client_id,const string & new_name){
	vector<Client>::iterator it= clients.begin();
	while (it->getid() != client_id && it != clients.end()){
		it++;
	}
	if (it != clients.end()){
		it->setname(new_name);
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const Transactions & transactions - transactions that is going to be added
Adds the transactions passed as a parameter to the list of transactions
*/
void Vendemaismais::addtransaction(const Transaction & transaction){
	transactions.push_back(transaction);
	stable_sort(transactions.begin(), transactions.end());
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: int id - id of the client whose purchase_amount is going to be raised
parameter: double cost - raise of the client purchase_amount
Raises the client purchase_amount by cost
*/
void Vendemaismais::raisepurchase_amount(int id, double cost){
	if (this->valid_id(id)){
		unsigned int i = 0;
		while (clients[i].getid() != id){
			i++;
		}
		(clients.begin() + i)->setpurchase_amount(clients[i].getpurchase_amount() + cost);
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: istream &in - istream from where information is going to be extracter
parameter: vector<T> & vector_T - vector that will store the information extracted
Reads from an istream and stores it on vector_T
*/
template<class T> 
void readfromstream(istream &in,vector<T> & vector_T){
	vector_T.clear();
	int num;
	in >> num;//number of objects
		for (int i = 0; i < num; i++){
			T new_T;//new object
			in >> new_T;
			vector_T.push_back(new_T);
		}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: istream &in - istream from where clients are going to be read
Reads clients from an istream
*/
void Vendemaismais::readclients(istream &in){
	readfromstream(in, clients);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: istream &in - istream from where products are going to be read
Reads products from an istream
*/
void Vendemaismais::readproducts(istream &in){
	readfromstream(in, products);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: istream &in - istream from where transactions are going to be read
Reads transactions from an istream
*/
void Vendemaismais::readtransactions(istream &in){
	readfromstream(in, transactions);
	stable_sort(transactions.begin(), transactions.end());
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
parameter: const string & filename - name of file where the information is going to be written
parameter: const vector<T> & vector_T - vector that contains the information
Writes to a file that was previously in the vector in the format described in the project guide
*/
template <class T>
void writetofile(const string & filename, const vector<T> & vector_T){
	ofstream out;//file 
	out.open(filename);
	out << vector_T.size() << endl;
	for (unsigned int i = 0; i < vector_T.size(); i++){
		out << vector_T[i] << endl;
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
writes in the clients file
*/
void Vendemaismais::writeclients() const{
	writetofile(filename_clients, clients);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
writes in the products file
*/
void Vendemaismais::writeproducts() const{
	writetofile(filename_products, products);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
writes in the transactions file
*/
void Vendemaismais::writetransactions() const{
	writetofile(filename_transactions, transactions);
}
