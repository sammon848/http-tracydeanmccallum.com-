//dem13-5.cpp

//This program illustrates the scope resolution operator

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
	 int Get_Value();
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

inline int Test_Class::Get_Value()
{
  return n;
}


class Derived_Test_Class : public Test_Class
{
  protected:
	 int m;

  public:
	 Derived_Test_Class(int j = 0);
	 Derived_Test_Class(const Derived_Test_Class &);
	 ~Derived_Test_Class();
	 int Get_Value();
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

inline int Derived_Test_Class::Get_Value()
{
  return m;
}

int main()
{
  Test_Class tc_object(3);
  Derived_Test_Class dtc_object(7);

  cout << "\n\nThe n value of the Test_Class object is "
		 << tc_object.Get_Value();

  cout << "\n\nThe m value of the Derived_Test_Class object is "
		 << dtc_object.Get_Value();

  cout << "\n\nThe n value of the Derived_Test_Class object is "
		 << dtc_object.Test_Class::Get_Value();

  cout << endl;
  return 0;
}
