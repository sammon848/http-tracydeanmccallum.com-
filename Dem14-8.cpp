//dem14-8.cpp

//This program creates a sequential file of structures from a text
//data file. It uses >> to obtain data from the text file
//and uses the write() member function to write structures
//onto the output file.

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Part_Record
{
  char   id_no[3];
  int    qoh;
  double price;
};

void Read_Part_Record(ifstream&, Part_Record&);

int main()
{
  int record_count = 0;

  char input_file_name[51];
  char output_file_name[51];

  Part_Record part;

  cout << "\nEnter the name of the text file: ";
  cin.getline(input_file_name, 51);

  ifstream input_file(input_file_name);

  if (!input_file)
	 {
		cout << "\nERROR: Could not open text file.";
		exit(1);
	 }

  cout << "\nEnter the name of the sequential file: ";
  cin.getline(output_file_name, 51);

  ofstream output_file(output_file_name, ios::binary);

  if (!output_file)
	 {
		cout << "\nERROR: Could not open sequential file: ";
		exit(1);
	 }


  //Read the first record

  Read_Part_Record(input_file, part);


  while (!input_file.eof())
	 {
		output_file.write( (char *)&part, sizeof(Part_Record) );

		++record_count;

		Read_Part_Record(input_file, part);
	 }

  cout << endl << endl << record_count << " records written.";

  input_file.close();
  output_file.close();

  cout << endl;
  return 0;
}

void Read_Part_Record(ifstream& ifs, Part_Record& pr)
{
  ifs >> pr.id_no;
  ifs >> pr.qoh;
  ifs >> pr.price;
}


