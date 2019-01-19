#pragma once
#include "Vende++.h"
#include "functions_auxiliary.h"
#include<fstream>
#include<algorithm>
//read functions
void readclients();//asks the user for the clients file path and then reads it
void readproducts();//asks the user for the products file path and then reads it
void readtransactions();//asks the user for the transactions file path and then reads it
//Main program functions - The level has to do with the flow of the program
//0 level
void initialmenu();//displays initial menu
//1st level
void visualizemain();//displays the visualization menu
void manageclients();//displays the manage clients menu
void addtransactions();//displays the menu that allows to add transactions
void publicitymenu();//displays the menu that makes the products recommendations
//2nd level
void clientdata();//displays data related to the clients
void productdata();//displays data related to the products
void transactiondata();//displays data related to the transactions
void addclient();//adds a new client
void removeclient();//removes a client
void changenameclient();//changes the name of a client
void clientpublicity();//asks the user to type the id of the client that is gonna be the target of the publicity campaign
void bottom10publicity();//makes publicity specifically targeted for the bottom10 clients
//3rd level
void individualclientdata(const int id, const int pos);//shows the user information related to a particular client
void transactionsafterdate();//shows transactions after a certain date
void transactionsbetweendates();//shows transactions between two dates
void individualclientpublicity(const int id_target, const int pos_target);//shows recommendations for a specific client