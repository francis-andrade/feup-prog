#include "menus.h"
#include "Vende++.h"
#include "functions_auxiliary.h"
#include <iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

// READ FUNCTIONS---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This function gets information from the clients file into the vector clients
*/
void readclients(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	ifstream file_clients;//clients file
	string filename_clients;//name of the file with the clients
	bool errormessage = false;//if true it will display an error message
	do{
		if (errormessage){
			cout << "\n\nThe path you introduced is not valid." << endl;
		}
		cout << "Introduce the path of the file with the clients (or press l if you want to leave): ";
		cin.clear();
		getline(cin, filename_clients);
		if ((filename_clients.size() == 1) && (filename_clients[0] == 'l')){
			supermarket->setleaveprogram(true);
		}
		else{
			file_clients.open(filename_clients);
		}
	} while (file_clients.fail() && !supermarket->getleaveprogram());
	if (!supermarket->getleaveprogram()){
		supermarket->setfilename_clients(filename_clients);//sets a new clients filename
		supermarket->readclients(file_clients);//reads clients
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This function gets information from the products file into the vector produts
*/
void readproducts(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	ifstream file_products;//products file
	string filename_products;//name of the file with the products
	bool errormessage = false;//if true it will display an error message
	do{
		if (errormessage){
			cout << "\n\nThe path you introduced is not valid." ;
		}
		cout << "\nIntroduce the path of the file with the products (or press l if you want to leave): ";
		cin.clear();
		getline(cin, filename_products);
		if ((filename_products.size() == 1) && (filename_products[0] == 'l')){
			supermarket->setleaveprogram(true);
		}
		else{
			file_products.open(filename_products);
		}
	} while (file_products.fail() && !supermarket->getleaveprogram());
	if (!supermarket->getleaveprogram()){
		supermarket->setfilename_products(filename_products);//sets a new products filename
		supermarket->readproducts(file_products);//reads products
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This function gets information from the transactions file into the vector transactions
*/
void readtransactions(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	ifstream file_transactions;//transactions file
	string filename_transactions;//name of the file with the transactions
	bool errormessage = false;//if true it will display an error message
	do{
		if (errormessage){
			cout << "\n\nThe path you introduced is not valid." ;
		}
		cout << "\nIntroduce the path of the file with the transactions (or press l if you want to leave): ";
		cin.clear();
		getline(cin, filename_transactions);
		if ((filename_transactions.size() == 1) && (filename_transactions[0] == 'l')){
			supermarket->setleaveprogram(true);
		}
		else{
			file_transactions.open(filename_transactions);
		}
	} while (file_transactions.fail() && !supermarket->getleaveprogram());
	if (!supermarket->getleaveprogram()){
	supermarket->setfilename_transactions(filename_transactions);//sets a new transactions filename
	supermarket->readtransactions(file_transactions);//reads transactions
	}
}
//MAIN MENUS FUNCTIONS-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//0 level---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Displays the initial menu on the sceen and asks the user to choose an option
Then, directs the user to the option he chose
*/
void initialmenu(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	do{
		bool errormessage = false;//If true will display an error message
		bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
		while (repeatmenu){
			system("cls");// clears the screen
			cout << "INITIAL MENU - VENDE++\n" << endl;
			if (errormessage){
				cout << "The option you introduced is not valid \n" << endl;//tells the user the option he had previously introduced is not valid
			}
			cout << "1: Visualize Data" << endl;
			cout << "2: Manage clients" << endl;
			cout << "3: Add Transactions" << endl;
			cout << "4: Publicity" << endl;
			cout << "5: Leave" << endl;
			cout << "Type the option number: ";
			string option;//option to be chosen by the user
			cin.clear();
			getline(cin, option);
			switch (convint(option))
			{
			case 1:
				visualizemain();
				repeatmenu = false;
				break;
			case 2:
				manageclients();
				repeatmenu = false;
				break;
			case 3:
				addtransactions();
				repeatmenu = false;
				break;
			case 4:
				publicitymenu();
				repeatmenu = false;
				break;
			case 5:
				repeatmenu = false;
				supermarket->setleaveprogram(true);//sets leaveprogram to true so that the program can end when it leaves this function
				break;
			default:
				errormessage = true;//sets errormessage to true to show an error message to the user when this cycle is repeated
			}
		}
	} while (!supermarket->getleaveprogram());
}
//1st level---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This function shows the data related to the supermarket that is available to the user and directs the program to other functions that
allow the user to manipulate such data
*/
void visualizemain(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	bool backflag = false;//When set to true this boolean stop the main cycle in this function and make the program go back
	do{
		bool errormessage = false;//If true will display an error message. It is initially set to false, because the message will not be displayed the first the cycle runs
		bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
		while (repeatmenu){
			system("cls");//clears the screen
			cout << "VISUALIZE INFORMATION - VENDE++\n" << endl;
			if (errormessage){
				cout << "The option you introduced is not valid \n" << endl;//tells the user the option he had previously introduced is not valid
			}
			cout << "1: Clients" << endl;
			cout << "2: Products" << endl;
			cout << "3: Transactions" << endl;
			cout << "4: Back" << endl;
			cout << "5: Leave" << endl;
			cout << "Type the option number: ";
			string option;//option to be chosen by the user
			cin.clear();
			getline(cin, option);
			switch (convint(option)){
			case 1:
				clientdata();
				repeatmenu = false;
				break;
			case 2:
				productdata();
				repeatmenu = false;
				break;
			case 3:
				transactiondata();
				repeatmenu = false;
				break;
			case 4:
				backflag = true;
				repeatmenu = false;
				break;
			case 5:
				supermarket->setleaveprogram(true);
				repeatmenu = false;
				break;
			default:
				errormessage = true;
			}
		}
	} while (!backflag && !supermarket->getleaveprogram());
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This functions asks the user if he wants to add a new client, remove an existent client or change the name of an existing client
*/
void manageclients(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	bool backflag = false;//When set to true this boolean stop the main cycle in this function and make the program go back
	do{
		bool errormessage = false;//If true will display an error message. It is initially set to false, because the message will not be displayed the first the cycle runs
		bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
		while (repeatmenu){
			system("cls");
			cout << "MANAGE CLIENTS - VENDE++\n" << endl;
			if (errormessage){
				cout << "The option you introduced is not valid \n" << endl;
			}
			cout << "1: Add a new client" << endl;
			cout << "2: Remove a client" << endl;
			cout << "3: Change the name of an existing client" << endl;
			cout << "4: Back" << endl;
			cout << "5: Leave" << endl;
			cout << "Type the option number: ";
			string option;//option to be chosen by the user
			cin.clear();
			getline(cin, option);
			switch (convint(option))
			{
			case 1:
				addclient();
				repeatmenu = false;
				break;
			case 2:
				removeclient();
				repeatmenu = false;
				break;
			case 3:
				changenameclient();
				repeatmenu = false;
				break;
			case 4:
				backflag = true;
				repeatmenu = false;
				break;
			case 5:
				repeatmenu = false;
				supermarket->setleaveprogram(true);//sets leaveprogram to true so that the program can end when it leaves this function
				break;
			default:
				errormessage = true;//sets errormessage to true to show an error message to the user when this cycle is repeated
			}
		}
	} while (!backflag && !supermarket->getleaveprogram());
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This function adds a new transactions to the list. 
It asks the user for the client id and the products of the client that performed this transaction
*/
void addtransactions(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	bool errormessage = false;//If true will display an error message. It is initially set to false, because the message will not be displayed the first the cycle runs
	bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
	while (repeatmenu){
		system("cls");
		cout << "ADD TRANSACTION - VENDE++\n" << endl;
		supermarket->showclients();
		if (errormessage){
			cout << "The ID you introduced is not valid" << endl;
		}
		cout << "\nIntroduce the client ID (or press b to go back): ";
		string id;
		cin.clear();
		getline(cin, id);
		if (id[0] == 'b' && id.size()==1){
			repeatmenu = false;
		}
		else{			
			if (!supermarket->valid_id(convint(id))){
				errormessage = true;
			}
			else{
				repeatmenu = false;
				Transaction transaction(convint(id), Date(), {});//creates a transaction with the id chosen above, the current date and an empty list of products
				cout << "\n";
				supermarket->showproducts();//shows products on the screen
				bool repeatquestion = true;//this boolean will be used to control the next loop.When set true it will keep asking the user to choose more products
				vector<Product> vector_products = supermarket->getproducts();//vector with the products
				vector<bool> alreadychosen(vector_products.size(), false); //each entry of this vector will be set to true if the product that is in the same position of that entry was already chosen
				double cost_transaction = 0;//cost of the transaction
				while (repeatquestion)
				{
					cout << "\nType the number of the product you want (or press f if you have already chosen all the products you want): ";
					string product;//product typed by the user
					cin.clear();
					getline(cin, product);
					if (product[0] == 'f' && product.size()==1){
						repeatquestion = false;
					}
					else if (convint(product) <= 0 || unsigned int(convint(product))>vector_products.size()){//checks if it was typed a valid product
						cout << "The product you chose is not valid" << endl;
					}
					else if (alreadychosen[convint(product) - 1]){//checks if the product has already been chosen
						cout << "You have already chosen that product" << endl;
					}
					else{
						transaction.addproduct(vector_products[convint(product) - 1].getname());
						cost_transaction = cost_transaction + vector_products[convint(product) - 1].getcost();
						alreadychosen[convint(product) - 1] = true;
					}
				}
				supermarket->addtransaction(transaction);
				supermarket->raisepurchase_amount(convint(id), cost_transaction);
				cout << "\nThe transaction has been added. Its cost was " <<cost_transaction<<"."<< endl;
				cout << "Press any key to go back: ";
				string keys;//keys to be typed by the user
				cin.clear();
				getline(cin, keys);			
			}
		}
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This functions shows the Publicity menu to the user
*/
void publicitymenu(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	bool backflag = false;//When set to true this boolean stop the main cycle in this function and make the program go back
	do{
		bool errormessage = false;//If true will display an error message. It is initially set to false, because the message will not be displayed the first the cycle runs
		bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
		while (repeatmenu){
			system("cls");
			cout << "PUBLICITY - VENDE++\n" << endl;
			if (errormessage){
				cout << "The option you introduced is not valid \n" << endl;
			}
			cout << "1: Individual Client Publicity" << endl;
			cout << "2: Bottom10 Publicity" << endl;
			cout << "3: Back" << endl;
			cout << "4: Leave" << endl;
			cout << "Type the option number: ";
			string option;//option that is going to be chosen by the user
			cin.clear();
			getline(cin, option);
			switch (convint(option))
			{
			case 1:
				clientpublicity();
				repeatmenu = false;
				break;
			case 2:
				if (supermarket->getclients().size() < 10){
					cout << "\nI am sorry. The supermarket needs to have at least 10 clients for this option."<<endl;
					cout << "Press any key to choose another option: ";
					string keys;//keys that are going to be pressed by the user
					cin.clear();
					getline(cin, keys);
					repeatmenu = true;
				}
				else{
					bottom10publicity();
					repeatmenu = false;
				}
				break;
			case 3:
				backflag = true;
				repeatmenu = false;
				break;
			case 4:
				supermarket->setleaveprogram(true);
				repeatmenu = false;
				break;
			default:
				errormessage = true;//sets errormessage to true to show an error message to the user when this cycle is repeated
			}
		}
	} while (!backflag && !supermarket->getleaveprogram());
}
//2nd level------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This function shows the user information about all the clients and then asks him to type the id of a specific client
*/
void clientdata(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	bool backflag = false;//When set to true this boolean stop the main cycle in this function and make the program go back
	do{
		bool errormessage = false;//If true will display an error message. It is initially set to false, because the message will not be displayed the first the cycle runs
		bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
		while (repeatmenu){
			system("cls");
			supermarket->showclients();
			if (errormessage){
				cout << "\nThe option you introduced is not valid" << endl;//tells the user the option he had previously introduced is not valid;
			}
			cout << "\nType the ID of the Client you are interested in (or press b to go back):";
			string id;//id that is going to be typed by the user;
			cin.clear();
			getline(cin, id);
			if (id[0] == 'b' && id.size()==1){
				backflag = true;
				repeatmenu = false;
			}
			else{
				unsigned int i = 0;
				vector<Client> vector_clients = supermarket->getclients();//vector of clients
				while (i < supermarket->getclients().size() && convint(id) != vector_clients[i].getid()){
					i++;
				}
				if (i == vector_clients.size()){
					errormessage = true;
				}
				else{
					individualclientdata(convint(id), i);
					repeatmenu = false;
				}
			}
		}
	} while (!backflag);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This function shows the user all the available products in a store
*/
void productdata(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	system("cls");
	supermarket->showproducts();
	cout << "\n\nPress any key to go back: ";
	string keys;//keys that are going to be pressed by the user
	cin.clear();
	getline(cin, keys);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This function shows the user all the transactions already made
*/
void transactiondata(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	bool backflag = false;//When set to true this boolean stop the main cycle in this function and make the program go back
	do{
		bool errormessage = false;//If true will display an error message. It is initially set to false, because the message will not be displayed the first the cycle runs
		bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
		while (repeatmenu){
			system("cls");//clears screen
			supermarket->showtransactions();//shows transactions

			if (errormessage){
				cout << "\nThe option you introduced is not valid" << endl;
			}
			if (!errormessage){
				cout << "\n";
			}
			cout << "\n";
			cout << "1: See transactions after a certain date" << endl;
			cout << "2: See transactions between two dates" << endl;
			cout << "3: Back" << endl;
			cout << "Type the option number: ";
			string option;//option that is going to be chosen by the user
			cin.clear();
			getline(cin, option);
			switch (convint(option)){
			case 1:
				transactionsafterdate();
				repeatmenu = false;
				break;
			case 2:
				transactionsbetweendates();
				repeatmenu = false;
				break;
			case 3:
				backflag = true;
				repeatmenu = false;
				break;
			default:
				errormessage = true;
				break;
			}
		}
	} while (!backflag);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This function asks the user to type a name for a new client and then creates a client with that name
*/
void addclient(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	bool errormessage_tooshort = false;//If true it will display an error message saying that the new client name is too short. 
	bool errormessage_alreadyexists = false;//If true it will display an error message saying that the new client name already exists.
	bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
	while (repeatmenu){
		system("cls");
		cout << "Add New Client" << endl;
		if (errormessage_tooshort){
			cout << "\nThe name you introduced is too short" << endl;
		}
		else if (errormessage_alreadyexists){
			cout << "\nThere is already a client with the name you introduced." << endl;
		}
		cout << "\nEnter the name of the client you want to add. It needs to have at least three characters (press b to go back): ";
		string client_name;//name that the user is going to type
		cin.clear();
		getline(cin, client_name);
		if (client_name.size() >= 3 && supermarket->valid_name(client_name)){
			supermarket->addclient(client_name);//adds a client
			cout << "\nA new client was created:" << endl;
			vector<Client> vector_clients = supermarket->getclients();
			cout << "He got assigned the ID: " << vector_clients[vector_clients.size()-1].getid() << "." << " His Purchase Amount is currently 0.00" << endl;
			cout << "Type any key to go back: ";
			string keys;//keys to be typed the user
			cin.clear();
			getline(cin, keys);
			repeatmenu = false;
		}
		else if (client_name.size() == 1 && client_name[0] == 'b'){
			repeatmenu = false;
		}
		else if (client_name.size() < 3){
			errormessage_alreadyexists = false;
			errormessage_tooshort = true;
		}
		else{
			errormessage_alreadyexists = true;
			errormessage_tooshort = false;
		}
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This function asks the user for an id of a client and then removes that client
*/
void removeclient(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();
	bool errormessage = false;//If true will display an error message. It is initially set to false, because the message will not be displayed the first the cycle runs
	bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
	while (repeatmenu){
		system("cls");
		supermarket->showclients();
		if (errormessage){
			cout << "\nThe ID you introduced is not valid";
		}
		cout << "\nType the id of the client you want to remove (or press b to go back): ";
		string id;//id to be typed by the user;
		cin.clear();
		getline(cin, id);
		if (id[0] == 'b' && id.size()==1){
			repeatmenu = false;
		}
		else{
			if (!supermarket->valid_id(convint(id))){
				errormessage = true;
			}
			else{
				supermarket->removeclient(convint(id));
				cout << "\nThe client has been deleted" << endl;
				cout << "Type any key to go back: ";
				string keys;//keys to be typed the user
				cin.clear();
				getline(cin, keys);
				repeatmenu = false;
			}
		}
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This function asks the user for an id of a client and then changes the name of that client for a new name typed by the user
*/
void changenameclient(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	bool errormessage = false;//If true will display an error message. It is initially set to false, because the message will not be displayed the first the cycle runs
	bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
	while (repeatmenu){
		system("cls");
		supermarket->showclients();
		if (errormessage){
			cout << "\nThe ID you introduced is not valid\n" << endl;
		}
		cout << "\nEnter the ID of the client whose name you want to change (or press b to go back): ";
		string id;//name that the user is going to type
		cin.clear();
		getline(cin, id);

		if (id[0] == 'b' && id.size()==1){
			repeatmenu = false;
		}
		else if (!supermarket->valid_id(convint(id))){
			errormessage = true;
		}
			
		else{
				cout << "Introduce a new name for this client (it has to have at least 3 characters):" << endl;
				string new_name;//new name of the client
				cin.clear();
				getline(cin, new_name);
				while ((new_name.size() < 3) || !supermarket->valid_name(new_name)){
					cout << "The name you introduced is invalid" << endl;
					cout << "Introduce a new name for this client: ";
					cin.clear();
					getline(cin, new_name);
				}
				supermarket->changename(convint(id), new_name);
				cout << "\nThe changes have been saved" << endl;
				cout << "Press any key to go back: ";
				string keys;//keys that are going to be pressed by the user;
				cin.clear();
				getline(cin, keys);
				repeatmenu = false;
			}
		}
	}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Asks the user to choose the id of a valid client
*/
void clientpublicity(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	bool backflag = false;//When set to true this boolean stop the main cycle in this function and make the program go back
	do{
		bool errormessage = false;//If true will display an error message. It is initially set to false, because the message will not be displayed the first the cycle runs
		bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
		while (repeatmenu){
			system("cls");
			cout << "PUBLICITY - VENDE++\n" << endl;
			supermarket->showclients();
			if (errormessage){
				cout << "\nThe option you introduced is not valid" << endl;//tells the user the option he had previously introduced is not valid;
			}
			cout << "\nType the ID of the Client you are interested in (or press b to go back):";
			string id;//id to be typed by the user;
			cin.clear();
			getline(cin, id);
			if (id[0] == 'b' && id.size() == 1){
				backflag = true;
				repeatmenu = false;
			}
			else{
				unsigned int i = 0;
				vector<Client> vector_clients = supermarket->getclients();//vector of clients
				while (i < supermarket->getclients().size() && convint(id) != vector_clients[i].getid()){
					i++;
				}
				if (i == vector_clients.size()){
					errormessage = true;
				}
				else{
					individualclientpublicity(convint(id), i);
					repeatmenu = false;
				}
			}
		}
	} while (!backflag);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Recommends a product for all bottom10 clients
*/
void bottom10publicity(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	system("cls");
	vector<Client> vector_clients = supermarket->getclients();//vector with clients
	vector<Product> vector_products = supermarket->getproducts();//vector with products
	vector<Transaction> vector_transactions = supermarket->gettransactions();//vector with transactions
	bool **matrix_publicity = new bool*[vector_clients.size()];//matix publicity is the pointer to the beginning of the 2d array
	for (unsigned int i = 0; i < vector_clients.size(); i++) {
		matrix_publicity[i] = new bool[vector_products.size()];
	}

	//The following loop sets all matrix_publicity entries to false
	for (unsigned int i = 0; i < vector_clients.size(); i++) {
		for (unsigned int j = 0; j < vector_products.size(); j++) {
			matrix_publicity[i][j] = false;
		}
	}

	/*This map associates each client id to the position of the client in an ordered list of clients
	such that each number of a client id corresponds to its position*/
	map <int, int> map_idpos = supermarket->assoaciateidtopos();
	/*This map associates each product to the position of the product in an ordered list of product
	such that each product corresponds to its position*/
	map <Product, int> map_productpos = supermarket->associateproducttopos();
	/*This map associates each name of a product to the product itself*/
	map<string, Product> map_nameproduct = supermarket->associatenametoproduct();

	/*The following loop sets to true each entry of the matrix whose column is a product bought by the client in its line*/
	for (unsigned int i = 0; i < vector_transactions.size(); i++) {
		bool validid = false;//this boolean will be set to true if the client id is part of the clients list
		//the following loop checks if the client id of this transactions exists or not
		for (unsigned int j = 0; j < vector_clients.size(); j++) {
			if (vector_transactions[i].getclient_id() == vector_clients[j].getid()) {
				validid = true;
			}
		}
		if (validid) {
			vector<string> vector_currentproducts = vector_transactions[i].getproducts();//products bought in this current transaction
			for (unsigned int j = 0; j < vector_currentproducts.size(); j++) {
				if (map_nameproduct.find(vector_currentproducts[j]) != map_nameproduct.end()) {//checks if this product still exists in the list or not
					matrix_publicity[map_idpos[vector_transactions[i].getclient_id()]][map_productpos[map_nameproduct[vector_currentproducts[j]]]] = true;
				}
			}
		}
	}

	sort(vector_clients.begin(), vector_clients.end(), purchaseamountorder); //sort clients based on the purchase amount (from lowest to highest)
	
	vector<unsigned> common_products;//vector that contains the positions of the products bought in common by the bottom10 clients
	//The following loop fills the common products vector
	for (unsigned int i = 0; i < vector_products.size(); i++){
		bool bought_by_all = true;//this boolean will be set to true if a product was bought by all bottom10 clients
		for (unsigned int j = 0; (j < 10) && bought_by_all; j++){
			bool bought_this_product = matrix_publicity[map_idpos[vector_clients[j].getid()]][i];//this boolean is set to true if the current client bought this product
			bought_by_all = bought_by_all && bought_this_product;
		}
		if (bought_by_all){
			common_products.push_back(i);
		}
	}

	/*This multimap associates each client to its transactions*/
	multimap<Client, Transaction> multimap_clienttransaction = supermarket->associateclienttotransactions();
	vector<unsigned int> interesting_clients;//this vector contains the id's of the interesting clients
	//each key of the following map corresponds to the position of an interesting product,whereas each value corresponds to the 
	//number of times that product was bought
	map<unsigned int, unsigned int> extra_products;
	//The following loop fills the interesting_clients vector and the extra_products map
	for (unsigned int i = 10; i < vector_clients.size(); i++){
		bool is_interesting_client = true;//this boolean will be set to true if the current client is interesting
		bool bought_extra_product = false;//this boolean will be set to true if the current client bought an extra product
		//The following pair contains iterators to the beginning and end of the transactions of a certains client
		pair<multimap<Client, Transaction>::iterator, multimap<Client, Transaction>::iterator> bounds = multimap_clienttransaction.equal_range(vector_clients[i]);
		for (unsigned int j = 0; (j < vector_products.size())&&is_interesting_client; j++){
			bool bought_this_product = matrix_publicity[map_idpos[vector_clients[i].getid()]][j];//this boolean is set to true if the current client bought this product
			bool is_common_product= (find(common_products.begin(), common_products.end(), j)!=common_products.end());//this boolean is set to true if this product belongs to the list of common products
			if (is_common_product){
				is_interesting_client = bought_this_product;
			}
			else{
				bought_extra_product = (!is_common_product && bought_this_product) || bought_extra_product;
			}
			
		}
		if (is_interesting_client && bought_extra_product){
			interesting_clients.push_back(vector_clients[i].getid());
			//The following pair contains iterators to the beginning and end of the transactions of a certains client
			pair<multimap<Client, Transaction>::iterator, multimap<Client, Transaction>::iterator> bounds = multimap_clienttransaction.equal_range(vector_clients[i]);
			//The following loop adds to the map the number of times that this client bought a certain product
			for (multimap<Client, Transaction>::iterator it = bounds.first; it != bounds.second; it++){
				vector<string> vector_products_bought = it->second.getproducts();//products bought by this client in this transaction
				for (unsigned int j = 0; j < vector_products_bought.size(); j++){
					bool product_exists = map_nameproduct.find(vector_products_bought[j]) != map_nameproduct.end();//true if this product is still in the list of products
					if (product_exists){
						unsigned int pos = map_productpos[map_nameproduct[vector_products_bought[j]]];//position of the current product
						bool is_common_product = (find(common_products.begin(), common_products.end(), pos) != common_products.end());//this boolean is set to true if this product belongs to the list of common products
						if (!is_common_product){
							extra_products[pos]++;
						}
					}
				}
			}
		}
	}

	multimap<unsigned int, unsigned int> reverse_extra_products;//this multimap is simply a copy of extra_products map, but where values and keys are switches
	//The following loop fills reverse_extra_products
	for (map<unsigned int, unsigned int>::iterator it = extra_products.begin(); it != extra_products.end(); it++){
		reverse_extra_products.insert(pair<unsigned int, unsigned int>(it->second, it->first));
	}

	vector<unsigned int> recommended_products;//this vector has the positions of the recommended products
	unsigned int max_product=0;//this vector keeps the highest number of times that a product was bought
	bool break_loop=false;//this boolean is set to true to tell the loop when to stop
	//The following loop finds the list of recommended products in the case that there was an extra product that was not bought by all bottom10 clients
	for (multimap<unsigned int, unsigned int>::reverse_iterator rit = reverse_extra_products.rbegin(); rit != reverse_extra_products.rend() && !break_loop; rit++){
		break_loop = rit->first < max_product;
		bool not_boughtbyany=true;//checks if the current product was not bought by any bottom10 clients
		for (int i = 0; (i < 10) && not_boughtbyany && !break_loop; i++){
			unsigned int pos = map_idpos[vector_clients[i].getid()];//position of the current client in the matrix
			bool bought_this_product = matrix_publicity[pos][rit->second];//this boolean is set to true if the client bought this product
			not_boughtbyany = !bought_this_product && not_boughtbyany;
		}
		if (not_boughtbyany && !break_loop){
			recommended_products.push_back(rit->second);
			max_product = rit->first;
		}
	}

	//In the case that there wasn't found a single recommended product, the following loop finds a new recommended product
	if (recommended_products.size() == 0){
		//The following code dynamically allocates a 2d matrix with 10 lines one column for each product. 
		//Each line contains the number of times that a bottom10 client bought a certain product
		unsigned int **matrix_bottom10 = new unsigned int *[10];
		for (unsigned int i = 0; i < 10; i++){
			matrix_bottom10[i] = new unsigned int[vector_products.size()];
		}
		for (unsigned int i = 0; i < 10; i++){
			for (unsigned int j = 0; j < vector_products.size(); j++){
				matrix_bottom10[i][j] = 0;
			}
		}
		//The following loop sets to each entry of the matrix the number of times that the client i bought the product j
		for (unsigned int i = 0; i < 10; i++){
			//The following pair contains iterators to the beginning and end of the transactions of a certains client
			pair<multimap<Client, Transaction>::iterator, multimap<Client, Transaction>::iterator> bounds = multimap_clienttransaction.equal_range(vector_clients[i]);
			//The following loop adds to the map the number of times that this client bought a certain product
			for (multimap<Client, Transaction>::iterator it = bounds.first; it != bounds.second; it++){
				vector<string> vector_products_bought = it->second.getproducts();//products bought by this client in this transaction
				for (unsigned int j = 0; j < vector_products_bought.size(); j++){
					bool product_exists = map_nameproduct.find(vector_products_bought[j]) != map_nameproduct.end();//true if this product is still in the list of products
					if (product_exists){
						unsigned int pos = map_productpos[map_nameproduct[vector_products_bought[j]]];//position of the current product
						matrix_bottom10[i][pos]++;
					}
				}
			}
		}
		break_loop = false;//will tell when to stop the next loop
		max_product = 0;//keeps the highest number of times that a product was bought
		unsigned int min_count = INT_MAX;//keeps the lowest number of times that a product was bought by all clients
		for (multimap<unsigned int, unsigned int>::reverse_iterator rit = reverse_extra_products.rbegin(); rit != reverse_extra_products.rend() && !break_loop; rit++){
			break_loop = (rit->first < max_product);
			//The following loop counts the number of bottom 10 clients that bought the current product
			unsigned int count=0;//counter
			for (int i = 0; (i < 10) && count<=min_count && !break_loop; i++){
				count = count + matrix_bottom10[i][rit->second];//adds to count the number of times that this product was bought by this client
			}
			if (count==min_count && !break_loop){
				recommended_products.push_back(rit->second);
				max_product = rit->first;
				min_count = count;
			}
			else if (count < min_count && !break_loop){
				recommended_products.clear();
				recommended_products.push_back(rit->second);
				max_product = rit->first;
				min_count = count;
			}
		}
		//The following code deletes matrix_bottom10
		for (unsigned int i = 0; i < 10; ++i) {
			delete[] matrix_bottom10[i];
		}
		delete[] matrix_bottom10;
	}
	
	//shows bottom10 clients
	cout << "Bottom10 clients:\n" << endl;
	cout << "Client ID|" << " Purchase Amount|" << " Accession Date|" << " Name" << endl;
	for (unsigned int i = 0; i < 10; i++){
		vector_clients[i].show();
		cout << "\n";
	}
	//shows recommendations
	cout << "\nRecommendations:" << endl;
	if (recommended_products.size() == 0){
		cout << "I am sorry.Unfortunately we have no suggestions for what bottom10 clients can buy." << endl;
	}
	else{
		cout << "We recommend that bottom10 clients buy the following products:" << endl;
		for (unsigned int i = 0; i < recommended_products.size(); i++){
			cout << vector_products[recommended_products[i]].getname() << endl;
		}
	}

	//The following code deletes publicity_matix
	for (unsigned int i = 0; i < vector_clients.size(); ++i) {
		delete[] matrix_publicity[i];
	}
	delete[] matrix_publicity;
	cout << "\nPress any keys to go back: ";
	string keys;//keys to be typed by the client
	cin.clear();
	getline(cin, keys);
}

//3rd level-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This function shows the user information related to a particular client
*/
void individualclientdata(const int id, const int pos){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	system("cls");
	vector<Client> vector_clients = supermarket->getclients();//vector with the clients
	cout << "ID: " << vector_clients[pos].getid() << endl;
	cout << "Name: " << vector_clients[pos].getname() << endl;
	cout << "Accession Date: ";
	vector_clients[pos].getaccession_date().show();
	cout << "\n";
	cout<< "Purchase Amount: " << setprecision(2) << fixed << vector_clients[pos].getpurchase_amount() << endl;
	cout << "\nTransactions:" << endl;
	cout << "Client|" << "        Date|" << "  Products" << endl;
	vector<Transaction> vector_transactions = supermarket->gettransactions();//vector with the transactions
	//The following loop prints the transactions made by this client
	for (unsigned int i = 0; i < vector_transactions.size(); i++){
		if (vector_transactions[i].getclient_id() == id){
			vector_transactions[i].show();
			cout << "\n";
		}
	}
	cout << "\nPress any key to go back:";
	string keys;//keys that are going to be pressed by the user
	cin.clear();
	getline(cin, keys);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This function shows the user the transactions that happened between two given dates chosen by him
*/
void transactionsafterdate(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	system("cls");//clears the screen
	unsigned int year_date, month_date, day_date;//year month and day of the date
	bool repeat = true;//this boolean will be set to true when the cycles that ask the user for the elements of the dates should be repeated
	//The following loop asks the user for the year of the first date
	while (repeat){
		cout << "Date year: ";
		string year;//year that's going to be typed by the user
		cin.clear();
		getline(cin, year);
		if (isInteger(year) && convint(year) >= 0){
			year_date = convint(year);
			repeat = false;
		}
		else{
			cout << "That year is not valid" << endl;
		}
	}
	repeat = true;
	//The following loop asks the user for the month of the first date
	while (repeat){
		cout << "Date month: ";
		string month;//month that is going to be typed by the user
		cin.clear();
		getline(cin, month);
		if (isInteger(month) && convint(month) >= 1 && convint(month) <= 12){
			month_date = convint(month);
			repeat = false;
		}
		else{
			cout << "That month is not valid" << endl;
		}
	}
	repeat = true;
	//The following loop asks the user for the day of the first date
	while (repeat){
		cout << "Date day: ";
		string day;//day that is going to be typed by the user
		cin.clear();
		getline(cin, day);
		if (isInteger(day) && convint(day) >= 1 && convint(day) <= 31){
			day_date = convint(day);
			repeat = false;
		}
		else{
			cout << "That day is not valid" << endl;
		}
	}
	Date date(year_date, month_date, day_date);	
	cout << "\nTransactions:" << endl;
	cout << "Client|" << "        date|" << "  Products" << endl;
	//The following loop prints all the transactions that occurred between first date and second date
	vector<Transaction> vector_transactions = supermarket->gettransactions();
	for (unsigned int i = 0; i < vector_transactions.size(); i++){
		if (date< vector_transactions[i].getdate()||date==vector_transactions[i].getdate()){
			vector_transactions[i].show();
			cout << "\n";
		}
	}
	cout << "\nType any key to leave: ";
	string keys;//keys that are going to be typed by the user
	cin.clear();
	getline(cin, keys);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This function shows the user the transactions that happened between two given dates chosen by him
*/
void transactionsbetweendates(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	system("cls");//clears the screen
	unsigned int year_date, month_date, day_date;//year month and day of the date
	bool repeat = true;//this boolean will be set to true when the cycles that ask the user for the elements of the dates should be repeated
	//The following loop asks the user for the year of the first date
	while (repeat){
		cout << "First Date year: ";
		string year;//year that's going to be typed by the user
		cin.clear();
		getline(cin, year);
		if (isInteger(year) && convint(year) >= 0){
			year_date = convint(year);
			repeat = false;
		}
		else{
			cout << "That year is not valid" << endl;
		}
	}
	repeat = true;
	//The following loop asks the user for the month of the first date
	while (repeat){
		cout << "First Date month: ";
		string month;//month that is going to be typed by the user
		cin.clear();
		getline(cin, month);
		if (isInteger(month) && convint(month) >= 1 && convint(month) <= 12){
			month_date = convint(month);
			repeat = false;
		}
		else{
			cout << "That month is not valid" << endl;
		}
	}
	repeat = true;
	//The following loop asks the user for the day of the first date
	while (repeat){
		cout << "First Date day: ";
		string day;//day that is going to be typed by the user
		cin.clear();
		getline(cin, day);
		if (isInteger(day) && convint(day) >= 1 && convint(day) <= 31){
			day_date = convint(day);
			repeat = false;
		}
		else{
			cout << "That day is not valid" << endl;
		}
	}
	Date first_date(year_date, month_date, day_date);
	repeat = true;
	//The following loop asks the user for the year of the second date
	while (repeat){
		cout << "\nSecond Date year: ";
		string year;//year that is going to be typed by the user
		cin.clear();
		getline(cin, year);
		if (isInteger(year)){
			year_date = convint(year);
			repeat = false;
		}
		else{
			cout << "That year is not valid" << endl;
		}
	}
	repeat = true;
	//The following loop asks the user for the month of the second date
	while (repeat){
		cout << "Second Date month: ";
		string month;//month that is going to be typed the user
		cin.clear();
		getline(cin, month);
		if (isInteger(month) && convint(month) >= 1 && convint(month) <= 12){
			month_date = convint(month);
			repeat = false;
		}
		else{
			cout << "That month is not valid" << endl;
		}
	}
	repeat = true;
	//The following loop asks the user for the day of the second date
	while (repeat){
		cout << "Second Date day: ";
		string day;//day that is going to be typed by the user
		cin.clear();
		getline(cin, day);
		if (isInteger(day) && convint(day) >= 1 && convint(day) <= 31){
			day_date = convint(day);
			repeat = false;
		}
		else{
			cout << "That day is not valid" << endl;
		}
	}
	Date second_date(year_date, month_date, day_date);
	cout << "\nTransactions:" << endl;
	cout << "Client|" << "        Date|" << "  Products" << endl;
	//The following loop prints all the transactions that occurred between first date and second date
	vector<Transaction> vector_transactions = supermarket->gettransactions();
	for (unsigned int i = 0; i < vector_transactions.size(); i++){
		if ((first_date < vector_transactions[i].getdate() || first_date == vector_transactions[i].getdate()) && (vector_transactions[i].getdate()< second_date || second_date == vector_transactions[i].getdate())){
			vector_transactions[i].show();
			cout << "\n";
		}
	}
	cout << "\nType any key to leave: ";
	string keys;//keys that are going to be typed by the user
	cin.clear();
	getline(cin, keys);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Finds the product most recommended for the chosen user and shows that product on the screen
*/
void individualclientpublicity(const int id_target, const int pos_target){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets intance of class Vendemaismais
	// The following code dynamically allocates a 2d array
	vector<Client> vector_clients = supermarket->getclients();
	vector<Product> vector_products = supermarket->getproducts();
	vector<Transaction> vector_transactions = supermarket->gettransactions();
	bool **matrix_publicity = new bool*[vector_clients.size()];//matix publicity is the pointer to the beginning of the 2d array
	for (unsigned int i = 0; i < vector_clients.size(); i++){
		matrix_publicity[i] = new bool[vector_products.size()];
	}

	//The following loop sets all matrix_publicity entries to false
	for (unsigned int i = 0; i < vector_clients.size(); i++){
		for (unsigned int j = 0; j < vector_products.size(); j++){
			matrix_publicity[i][j] = false;
		}
	}

	/*This map associates each client id to the position of the client in an ordered list of clients
	such that each number of a client id corresponds to its position*/
	map <int, int> map_idpos = supermarket->assoaciateidtopos();

	/*This map associates each product to the position of the product in an ordered list of product
	such that each product corresponds to its position*/
	map <Product, int> map_productpos = supermarket->associateproducttopos();

	/*This map associates each name of a product to the product itself*/
	map<string, Product> map_nameproduct = supermarket->associatenametoproduct();

	/*The following loop sets to true each entry of the matrix whose column is a product bought by the client in its line*/
	for (unsigned int i = 0; i < vector_transactions.size(); i++){
		bool validid = false;//this boolean will be set to true if the client id is part of the clients list
		//the following loop checks if the client id of this transactions exists or not
		for (unsigned int j = 0; j < vector_clients.size(); j++){
			if (vector_transactions[i].getclient_id() == vector_clients[j].getid()){
				validid = true;
			}
		}
		if (validid){
			vector<string> vector_currentproducts = vector_transactions[i].getproducts();//products bought in this current transaction
			for (unsigned int j = 0; j < vector_currentproducts.size(); j++){
				if (map_nameproduct.find(vector_currentproducts[j]) != map_nameproduct.end()){//checks if this product still exists in the list or not
					matrix_publicity[map_idpos[vector_transactions[i].getclient_id()]][map_productpos[map_nameproduct[vector_currentproducts[j]]]] = true;
				}
			}
		}
	}
	int maxcommonproducts = 0;//this variable keeps the maximum number of products bought in common with the target client as the program loops through all clients
	vector<int> clientscommon;//this vector keeps the positions of the clients who bought the maximum number of products in common with the target client
	//The following loop finds the clients with the highest number of products bought in common with the target client
	for (unsigned int i = 0; i < vector_clients.size(); i++){
		if (i != pos_target){
			int commonproducts = 0;//counts the number of common products
			bool extraproduct = false;//this boolean checks if the client bought a product that the target client has not bought
			for (unsigned int j = 0; j < vector_products.size(); j++){
				if (matrix_publicity[i][j] && matrix_publicity[pos_target][j]){
					commonproducts++;
				}
				if (matrix_publicity[i][j] && !matrix_publicity[pos_target][j]){
					extraproduct = true;
				}
			}
			if (commonproducts == maxcommonproducts && extraproduct){//checks if this client has the same number of products in common with the target client
				clientscommon.push_back(i);
			}
			else if (commonproducts > maxcommonproducts && extraproduct){//checks if a client with more products in common with the target client has been found
				clientscommon.clear();
				clientscommon.push_back(i);
				maxcommonproducts = commonproducts;
			}
		}
	}
	/*this vector will create a vector that counts the number of times that a product which
	the target client didn't buy has been bought by clients which bought the most products in common with him*/
	vector<int> counter_extraproducts(vector_products.size(), 0);
	for (unsigned int i = 0; i < clientscommon.size(); i++){
		for (unsigned int j = 0; j < vector_products.size(); j++){
			if (matrix_publicity[clientscommon[i]][j] && !matrix_publicity[pos_target][j]){
				counter_extraproducts[j] = counter_extraproducts[j] + 1;
			}
		}
	}
	int maxextraproducts = 0;//this variable keeps the maximum number times that a product that was not bought by the target client was bought 
	int pos_maxproduct = -1;//keeps the position of the product that was bought the highest number of times
	//The following loop finds the maximum element in counter_extraproducts
	for (unsigned int i = 0; i < counter_extraproducts.size(); i++){
		if (maxextraproducts < counter_extraproducts[i]){
			pos_maxproduct = i;
			maxextraproducts = counter_extraproducts[i];
		}
	}
	if (pos_maxproduct >= 0){
		cout << "\nWe recommend that client " << id_target << " buys " << vector_products[pos_maxproduct].getname() << endl;
	}

	else{
		cout << "I am sorry. Unfortunately we have no suggestions for what client " << id_target << " can buy." << endl;
	}
	//The following code deletes publicity_matix
	for (unsigned int i = 0; i < vector_clients.size(); ++i) {
		delete[] matrix_publicity[i];
	}
	delete[] matrix_publicity;
	cout << "Press any keys to go back: ";
	string keys;//keys to be typed by the client
	cin.clear();
	getline(cin, keys);
}

