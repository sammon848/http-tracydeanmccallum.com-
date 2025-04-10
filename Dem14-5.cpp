//dem14-5.cpp

//This program copies one file to another using get() and put()

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

  cout << "\nEnter the name of the target file: ";
  cin.getline(file_name, 81);

  ofstream target_file(file_name);

  if (!target_file)
    {
		cout << "\nERROR: File cannot be opened.";
		exit(1);
    }

  while ( (ch = source_file.get()) != EOF)
    target_file.put(ch);

  source_file.close();
  target_file.close();

  cout << "\n\nProgram Terminated.";

  cout << endl;
  return 0;
}

