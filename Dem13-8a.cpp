//dem13-8a.cpp

//This program illustrates the use of virtual destructors
//in a class hierarchy

#include <iostream>

using namespace std;

class Test_Class
{
  protected:
	 int n;

  public:
	 Test_Class(int i = 0);  //One-argument constructor
	 Test_Class(Test_Class &);  //Copy constructor
	 virtual ~Test_Class();
	 virtual int Get_Value();
};

Test_Class::Test_Class(int i) : n(i)
{
	cout << "\nTest_Class Constructor Executed: Data member initialized to "
		  << n << endl;
}

Test_Class::Test_Class(Test_Class & tc_r) : n(tc_r.n)
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
	 Derived_Test_Class(Derived_Test_Class &);
	 virtual ~Derived_Test_Class();
	 int Get_Value();
};

Derived_Test_Class::Derived_Test_Class(int j) : Test_Class(j+1), m(j)
{
	cout << "\nDerived_Test_Class Constructor Executed: "
		 << "Data member initialized to "
		 << m;
}

Derived_Test_Class::Derived_Test_Class(Derived_Test_Class & dtc_r)
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
  Test_Class * tc_p1 = new Test_Class (7);
  Test_Class * tc_p2 = new Derived_Test_Class (4);

  cout << "\n\nThe value of the object is " << tc_p1 -> Get_Value();
  cout << "\nThe value of the object is " << tc_p2 -> Get_Value();

  delete tc_p1;
  delete tc_p2;

  cout << endl;
  return 0;
}
