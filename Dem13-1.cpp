//dem13-1.cpp

//This program illustrates how a function is inherited

#include <iostream>

using namespace std;

class Test_Class
{
  protected:
    int n;

  public:
	 Test_Class(int i = 0);  //One-argument constructor
	 ~Test_Class();
	 int Get_Value();
};

Test_Class::Test_Class(int i) : n(i)
{
	cout << "\nTest_Class Constructor Executed: Data member initialized to "
		  << n << endl << endl;
}

Test_Class::~Test_Class()
{
  cout << "\n\nTest_Class Destructor Executed for object with data member "
		 << n;
}

int Test_Class::Get_Value()
{
  return n;
}


class Derived_Test_Class : public Test_Class
{
  protected:
	 int m;

  public:
	 Derived_Test_Class(int j = 0);
	 ~Derived_Test_Class();
};

Derived_Test_Class::Derived_Test_Class(int j) : Test_Class(j+1), m(j)
{
	cout << "\n\nDerived_Test_Class Constructor Executed: "
		 << "Data member initialized to "
		 << m;
}


Derived_Test_Class::~Derived_Test_Class()
{
  cout << "\n\n\nDerived_Test_Class Destructor Executed "
		 << "for object with data member "
		 << m;
}


int main()
{
  Derived_Test_Class dtc_object1(7);

  cout << "\nThe value returned by Get_Value() is " << dtc_object1.Get_Value();

  cout << endl;
  return 0;
}
