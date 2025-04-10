//prb14-2.cpp

//This program demonstrates reading a text file of records
//whose data are space separated.

#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main()
{
  char file_name[81];

  int    id_no;
  int    qoh;
  double price;
  double total;

  cout << setprecision(2)
		 << setiosflags(ios::fixed)
       << setiosflags(ios::showpoint);

  cout << "\nEnter the name of the inventory file: ";
  cin.getline(file_name, 81);

  ifstream inventory_file(file_name);

  if (!inventory_file)
	 {
		cout << "\nERROR: File could not be opened.";
		exit(1);
	 }

  cout << endl << endl;
  cout << setw(8) << "ID No." << setw(10) << "Quantity"
		 << setw(10) << "Price" << setw(12) << "Total"
		 << endl << endl;

  //Obtain the first inventory record

  inventory_file >> id_no >> qoh >> price;

  while (!inventory_file.eof())
  {
	 total = qoh * price;

	 if (total > 3000.00)
		{
		  cout << setw(8) << id_no << setw(10) << qoh
				 << setw(10) << price << setw(12)<< total
				 << endl;
		}

	 //obtain the next inventory record

    inventory_file >> id_no >> qoh >> price;
  }

  inventory_file.close();

  cout << endl;
  return 0;
}