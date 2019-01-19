#include "menus.h"
#include "Vende++.h"
#include "functions_auxiliary.h"

int main(){
	Vendemaismais *supermarket = Vendemaismais::getinstance();//gets new instance of class Vendemaismais

	readclients();
	if (supermarket->getleaveprogram()){
		return 1;//leaves the program
	}

	readproducts();
	if (supermarket->getleaveprogram()){
		return 1;//leaves the program
	}

	readtransactions();
	if (supermarket->getleaveprogram()){
		return 1;//leaves the program
	}
	
	initialmenu();//calls the initial menu. From there the initial menu directs the flow of the program to other functions menus
	supermarket->writeclients();//writes in clients file
	supermarket->writeproducts();//writes in products file
	supermarket->writetransactions();//writes in transactions file

	return 0;

}