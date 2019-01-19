#pragma once
#include <iostream>
#include<string>

using namespace std;

class Product{
private:
	string name;//name of the product
	double cost;//cost of the product
public:
	//Methods--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	Product();//default constructor
	Product(const string & name, double cost);//constructor
	string getname() const;//gets name of the product
	double getcost() const;//gets cost of the product
	void show() const;//prints the product on the screen
	//Friend functions--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	friend bool operator<(const Product & product_left,const Product & product_right);//operator<: returns true if product_left costs less than product_right
	friend ostream& operator<<(ostream &out, const Product &product);//operator<<: writes product in an ostream
	friend istream& operator>>(istream &in, Product &product);//operator>>:reads product from an istream
};