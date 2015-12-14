// Inventory System.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<fstream>
#include<string>		
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <iomanip>
#include <string>

using namespace std;
fstream Inventory_System;
fstream temp;
char path[] = "Inventory_System_Project.txt";
class My_Inventory
{
public:
	string p_id;
	string p_name;
	string price;
	string type_p;
	string p_Amount;
	string shelf_number;
};




int number; //global so ican use the returned valiue without calling the function more than once 
int home()
{
	cout << setw(65) << "<< Welcome to The Inventory Mangment System >>" << endl << endl << setw(65)
		<< "\n1:- Display All Product :- " 
		<< setw(65) << "\n2:- Add new Product :- " 
		<< setw(65) << "\n3:- Find Product :- "
		<< setw(65) << "\n4:- Edit Product :- " 
		<< setw(65) << "\n5:- Delete Product :- " 
		<< setw(65) << "\n0:- Exit" 
		<<endl << "\n\nPLEASE ENTER THE FUNTION NUMBER YOU WISH TO USE :  ";
	cin >> number;
	if (system("CLS")) system("clear");
		return number;
}
void Insert()
{
	
	My_Inventory my_inventory;
	cout << "You are entering a new record  in the Inventory System Now" << endl<<endl;
	cout << "Enter the Product ID :-   "  ;
	cin >> my_inventory.p_id;
	cout << "Enter the Product Name :- " ;
	cin >> my_inventory.p_name;
	cout << "Enter the Product Price :-  " ;
	cin >> my_inventory.price;
	cout << "Enter the Type of Product :-  ";
	cin >> my_inventory.type_p;
	cout << "Enter the Product Amount :-  " ;
	cin >> my_inventory.p_Amount;
	cout << "Enter the Shelf Number :-  " ;
	cin >> my_inventory.shelf_number;
	Inventory_System.open(path, ios::out | ios::app);
	Inventory_System << my_inventory.p_id << setw(11 - my_inventory.p_id.size()) << "|" << my_inventory.p_name
		<< setw(13 - my_inventory.p_name.size()) << "|" << my_inventory.price << setw(14 - my_inventory.price.size())
		<< "|" << my_inventory.type_p << setw(17 - my_inventory.type_p.size()) << "|"
		<< my_inventory.p_Amount << setw(15 - my_inventory.p_Amount.size()) << "|" << my_inventory.shelf_number << endl;
	Inventory_System.close();
	if (system("CLS")) system("clear");
}
void display() {
	Inventory_System.open(path, ios::in | ios::out);
	cout << endl << "Product ID" << "|" << "Product Name" << "|" << "Product Price" << "|"
		<< "Type of Product " << "|" << "Product Amount" << "|" << "Shelf Number" << endl;
	cout << "----------|------------|-------------|----------------|--------------|------------" << endl;
	cout << Inventory_System.rdbuf();
	Inventory_System.close();
	char chr;
	chr = 'y';
	do
	{
		cout << "Home Menu ? (y/n) : ";
		cin >> chr;
	} while (!(chr = 'y'));
	if (system("CLS")) system("clear");
}
void Search() {
	string search;
	string line;
	Inventory_System.open(path, ios::in);
	if (!Inventory_System) {
		cout << "\nUnable to Open File" << endl;
		exit(1);
	}
	cout << "\nEnter Your Search For :- ";
	cin >> search;
	size_t pos;
	if (Inventory_System)
	{
		while (getline(Inventory_System, line))
		{
			// get line from file
			pos = line.find(search);// search
			if (pos != string::npos) // string::npos is returned if string is not found
			{
				cout << "\nFound The record" << endl;
				cout << endl << "Product ID" << "|" << "Product Name" << "|" << "Product Price" << "|"
					<< "Type of Product " << "|" << "Product Amount" << "|" << "Shelf Number" << endl;
				cout << "----------|------------|-------------|----------------|--------------|------------" << endl;
				cout << line << endl << endl;

				//clear screen prompt
				char chr;
				chr = 'y';
				do
				{
					cout << "Home Menu ? (y/n) : ";
					cin >> chr;
				} while (!(chr = 'y'));
				if (system("CLS")) system("clear");
				break;
			}
		}
	}
	else
	{
		cout << "\nRecord Not Found  " << endl;

		char chr;
		chr = 'y';
		do
		{
			cout << "Home Menu ? (y/n) : ";
			cin >> chr;
		} while (!(chr = 'y'));
		if (system("CLS")) system("clear");
	}


	Inventory_System.close();

}
void Edit()
{
	fstream Inventory_System2;
	fstream temp2;

	Inventory_System2.open(path, ios::in | ios::out);
	temp2.open("tmp.txt", ios::in | ios::out);
	string strReplace;
	cout << "Enter product id to edit : ";
	cin >> strReplace;
	string line;
	size_t pos;
	if (!Inventory_System || !temp)
	{
		cout << "Error opening files!" << endl;
	}
	while (getline(Inventory_System, line))
	{
		// get line from file
		pos = line.find(strReplace);// search
		if (pos != string::npos) // string::npos is returned if string is not found
		{
			My_Inventory my_inventory;
			cout << "You are entering data in the Inventory System Now" << endl<<endl;
			cout << "Enter the Product ID :- ";
			cin >> my_inventory.p_id;
			cout << "Enter the Product Name :- " ;
			cin >> my_inventory.p_name;
			cout << "Enter the Product Price :- ";
			cin >> my_inventory.price;
			cout << "Enter the Type of Product :- ";
			cin >> my_inventory.type_p;
			cout << "Enter the Product Amount :- " ;
			cin >> my_inventory.p_Amount;
			cout << "Enter the Shelf Number :- " ;
			cin >> my_inventory.shelf_number;
			temp << my_inventory.p_id << setw(11 - my_inventory.p_id.size()) << "|" << my_inventory.p_name << setw(13 - my_inventory.p_name.size()) << "|" << my_inventory.price << setw(14 - my_inventory.price.size()) << "|" << my_inventory.type_p << setw(17 - my_inventory.type_p.size()) << "|"
				<< my_inventory.p_Amount << setw(15 - my_inventory.p_Amount.size()) << "|" << my_inventory.shelf_number << endl;
			continue;

		}

		temp << line << endl;
	}
	Inventory_System.close();
	temp.close();
	remove("Inventory_System_Project.txt");
	rename("tmp.txt", "Inventory_System_Project.txt");




}
int main()
{
	do
	{

		switch (home())
		{
		case 1:
			display();
			break;
		case 2:
		{

			Insert();
		}
		break;
		case 3:
		{
			Search();
			break;
		}
		case 4:
		{
			Edit();
			break;
		}
		case 5:
		default:
			exit(0);
			break;
		};

	} while (number != 0);
	_getch();
}