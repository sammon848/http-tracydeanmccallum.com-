//dem14-1.cpp

//This program demonstrates simple file output

#include <fstream>
#include <iostream>

using namespace std;



int main()
{
  char buffer[81];

  ofstream out_file("outdata.dat");

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
