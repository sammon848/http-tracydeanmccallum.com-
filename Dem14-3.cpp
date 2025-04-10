//dem14-3.cpp

//This program demonstrates simple file input

#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
  char buffer[81];
  char file_name[81];

  cout << "\nEnter the name of the file you want to display: ";
  cin.getline(file_name, 81);

  ifstream in_file(file_name);

  if (!in_file)
	 {
		cout << "\nERROR: File could not be opened.";
		exit(1);
	 }

  cout << endl;

  while (!in_file.eof())
	 {
		in_file.getline(buffer, 81);
		cout << buffer << endl;
	 }

  in_file.close();

  cout << "\n\nProgram Terminated";

  cout << endl;
  return 0;
}