//dem14-4.cpp

//This program demonstrates simple file input and output
//The file is opened in in out and app modes

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

  fstream file(file_name, ios::out);

  if (!file)
	 {
		cout << "\nERROR: File could not be opened.";
		exit(1);
	 }

  cout << "\nEnter your name: ";
  cin.getline(buffer, 81);

  file << buffer << endl;

  cout << "\nEnter the first line of your address: ";
  cin.getline(buffer, 81);

  file << buffer << endl;

  file.close();

  cout << "\nThe file you created is the following:"
		 << endl << endl;

  file.open(file_name, ios::in);

  if (!file)
	 {
		cout << "\nERROR: File could not be opened.";
		exit(1);
	 }

  while (!file.eof())
	 {
		file.getline(buffer, 81);
		cout << buffer << endl;
	 }

  file.close();

  cout << "\nEnter the city, state, and zip in which you live: ";
  cin.getline(buffer, 81);

  cout << "\nThe information will be appended to your file." << endl;

  file.open(file_name, ios::app);

  if (!file)
	 {
		cout << "\nERROR: File could not be opened.";
		exit(1);
	 }

  file << buffer << endl;

  file.close();

  cout << "\nYour complete name and address is the following:"
		 << endl << endl;

  file.open(file_name, ios::in);

  if (!file)
	 {
		cout << "\nERROR: File could not be opened.";
		exit(1);
	 }

  while (!file.eof())
	 {
		file.getline(buffer, 81);
		cout << buffer << endl;
	 }

  file.close();


  cout << "\nProgram Terminated";

  cout << endl;
  return 0;
}
