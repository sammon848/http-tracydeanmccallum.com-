//dem14-7.cpp

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>

using namespace std;

int main()
{
  char file_name [51];
  char ch;

  cout << "\nEnter the file you want to uppercase: ";
  cin.getline(file_name, 51);

  fstream file(file_name, ios::in | ios::out | ios::binary);

  if (!file)
	 {
		cout << "\nERROR: Could not open file.";
		exit(1);
	 }

  while ( (ch = file.get()) != EOF)
  {
    ch = toupper(ch);
	 file.seekg(-1L, ios::cur);
	 file.put(ch);
    cout << file.tellg() << setw(6) << ch << endl;
  }

  cout << "\nCharacters processed: " << file.tellg();

  file.close();

  cout << endl;
  return 0;
}

