//dem13-2.cpp

//This program illustrates the copy constructor in a derived class

#include <iostream>

using namespace std;

class Test_Class
{
  protected:
	 int n;

  public:
	 Test_Class(int i = 0);  //One-argument constructor
	 Test_Class(const Test_Class &);  //Copy constructor
	 ~Test_Class();
};

Test_Class::Test_Class(int i) : n(i)
{
	cout << "\nTest_Class Constructor Executed: Data member initialized to "
		  << n << endl;
}

Test_Class::Test_Class(const Test_Class & tc_r) : n(tc_r.n)
{
	 cout << "\n\nTest_Class Copy constructor executed: "
		 << "Data member initialized to " << n;
}

Test_Class::~Test_Class()
{
  cout << "\n\nTest_Class Destructor Executed for object with data member "
		 << n;
}


class Derived_Test_Class : public Test_Class
{
  protected:
	 int m;

  public:
	 Derived_Test_Class(int j = 0);
	 Derived_Test_Class(const Derived_Test_Class &);
	 ~Derived_Test_Class();
};

Derived_Test_Class::Derived_Test_Class(int j) : Test_Class(j+1), m(j)
{
	cout << "\nDerived_Test_Class Constructor Executed: "
		 << "Data member initialized to "
		 << m;
}

Derived_Test_Class::Derived_Test_Class(const Derived_Test_Class & dtc_r)
												  : Test_Class(dtc_r), m(dtc_r.m)
{
	cout << "\n\nDerived_Test_Class Copy constructor executed: "
		 << "Data member initialized to " << m;
}

Derived_Test_Class::~Derived_Test_Class()
{
  cout << "\n\nDerived_Test_Class Destructor Executed "
		 << "for object with data member "
		 << m;
}


int main()
{
  Derived_Test_Class dtc_object1(7);
  Derived_Test_Class dtc_object2 = dtc_object1;

  cout << endl;
  return 0;
}
