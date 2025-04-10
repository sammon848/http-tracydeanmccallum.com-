//dem14-2.cpp

//This program demonstrates simple file output
//The program checks the file open for errors

#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
  char buffer[81];
  char file_name[81];

  cout << "\nEnter the name of the file you want to write to: ";
  cin.getline(file_name, 81);

  ofstream out_file(file_name);

  if (!out_file)
	 {
		cout << "\nERROR: File could not be opened.";
		exit(1);
	 }

  cout << "\nEnter your name: ";
  cin.getline(buffer, 81);

  out_file << buffer << endl;

  cout << "\nEnter the first line of your address: ";
  cin.getline(buffer, 81);

  out_file << buffer << endl;

  out_file.close();
	 
  cout << "\nProgram Terminated";

  cout << endl;
  return 0;
}
