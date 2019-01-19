-----------
Objectives
-----------
All the objectives proposed for this project were fullfilled.

------------------------
Structure of the Program
------------------------
The program starts by asking the user for the names of the files with the clients, products and transactions.
Then, the program calls a function that shows an initial menu to the user.From there he can choose if he wants to visualize information, change clients data or add new transactions.
From the function initial menu, other functions that perform other tasks are called, so the program only returns to main at the end of the program.
At the end, the program writes information back to the clients and transactions files. The file with the products can't be changed.

------------
Files Format
------------
The files used in this program should have exactly the same format as the ones shown as example in the project guide, although there can be
extra blanks spaces between words.

------------------
Bottom10 Publicity
------------------
In the case that there are two or more products bought with the same frequency by the group of interesting clients, but none of them
was bought by any bottom10 clients, the program recommends both products.
In the case that there weren't any products bought by the intersting clients that were not bought by any bottom10 clients, the program does the following:
If there is a product that was, at the same time, the most bought product between the interesting clients and the least bought product by the bottom10 clients,
the program will recommend it, as it was asked in the project guide. If, however, the most bought product between the interesting clients is not,at the same time, the least 
bought product by the bottom10 clients the program will recommend between the most bought products by the interesting clients, the ones that were the least bought by the bottom10
clients.


------------
Improvements
------------
The handling of invalid inputs typed by the user was substantially improved, compared to what was proposed in the project guide. 
The program was designed so that no input can cause the program to crash or to stop working properly.


