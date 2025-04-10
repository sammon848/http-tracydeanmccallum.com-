//prb14-1.cpp

//This program demonstrates the creation of a simple text data
//inventory file in which the data items are space separated.

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
  char file_name[81];

  int    id_no;
  int    qoh;
  double price;

  int response;

  cout << "\nEnter the name of the new inventory file: ";
  cin.getline(file_name, 81);

  ofstream inventory_file(file_name);

  if (!inventory_file)
	 {
		cout << "\nERROR: File could not be opened.";
		exit(1);
	 }

  inventory_file << setprecision(2)
					  << setiosflags(ios::fixed)
		           << setiosflags(ios::showpoint);

  cout << "\nCreate an inventory record? (1 for Yes/0 for No): ";
  cin >> response;

  while (response)
  {
	 // Get data for inventory record

	 cout << "\nID Number: ";
	 cin >> id_no;

	 cout << "\nQuantity On Hand: ";
	 cin >> qoh;

	 cout << "\nPrice: ";
	 cin >> price;

	 //Write inventory record

	 inventory_file << id_no << " " << qoh << " " << price << endl;

    cout << "\nCreate an inventory record? (1 for Yes/0 for No): ";
	 cin >> response;
  }

  cout << "\n\nInventory File " << file_name << " created.";

  inventory_file.close();

  cout << endl;
  return 0;
}

