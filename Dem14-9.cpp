//dem14-9.cpp

//This program shows how to read a sequential file of structures.
//It ises the member function read() to read records from the file
//and uses << to print records to a disk text file in a form
//suitable for later printing. The program assumes that the input file
//has been previously created by the program dem14-8.cpp

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Part_Record
{
  char   id_no[3];
  int    qoh;
  double price;
};

int main()
{
  Part_Record part;

  char input_file_name[51];
  char output_file_name[51];

  int record_count = 0;

  cout << "\nEnter the name of the printable file: ";
  cin.getline(output_file_name, 51);

  ofstream output_file(output_file_name);

  if (!output_file)
	 {
		cout << "ERROR: Could not open printable file.";
		exit(1);
	 }

  output_file << setw(15) << "Part Number" << setw(15) << "Quan on Hand"
				  << setw(15) << "Price" << endl << endl;


  cout << "\nEnter the name of the sequential file: ";
  cin.getline(input_file_name, 51);

  ifstream input_file(input_file_name, ios::binary);

  if (!input_file)
	 {
		cout << "\nERROR: Could not open sequential file.";
		exit(1);
	 }

  input_file.read( (char *) &part, sizeof(Part_Record) );

  while (!input_file.eof())
	 {
		++record_count;
		output_file << setw(15) << part.id_no << setw(15) << part.qoh
						<< setw(15) << part.price << endl;

		input_file.read( (char *) &part, sizeof(Part_Record) );
	 }

  cout << endl << endl << record_count << " records read.";

  input_file.close();
  output_file.close();

  cout << endl;
  return 0;
}







  