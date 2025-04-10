//dem14-6.cpp

//This program prints the contents of a file, double spaced, on a printer

#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
  char file_name[81];
  char ch;

  cout << "\nEnter the name of the source file: ";
  cin.getline(file_name, 81);

  ifstream source_file(file_name);

  if (!source_file)
    {
		cout << "\nERROR: File cannot be opened.";
	   exit(1);
	 }

  ofstream printer_file("prn");

  if (!printer_file)
	 {
		cout << "\nERROR: Printer could not be opened.";
		exit(1);
	 }


  printer_file << "Contents of the Source File - Double Spaced."
	       << endl << endl;

  while ((ch = source_file.get()) != EOF)
	 {
		printer_file.put(ch);
		if (ch == '\n')
		  printer_file.put(ch);
	 }

  source_file.close();
  printer_file.close();

  cout << "\n\nProgram Terminated.";

  cout << endl;
  return 0;
}

