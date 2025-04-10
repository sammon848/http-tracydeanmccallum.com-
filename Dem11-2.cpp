//dem11-2.cpp

//This program illustrates the use of a copy constructor

#include <iostream>

using namespace std;

class Test_Class
{
  private:
    int n;

  public:
	 Test_Class(int);  //One-argument constructor
	 Test_Class(Test_Class &);  //Copy constructor
    ~Test_Class();
    int Get_Value();
};

Test_Class::Test_Class(int i)
{
  n = i;
  
  cout << "\nConstructor Executed: Data member initialized to " << n;
}

Test_Class::Test_Class(Test_Class & tc_r)
{
  n = tc_r.n;

  cout << "\n\nCopy constructor executed: "
		 << "Data member initialized to " << n;
}

Test_Class::~Test_Class()
{
  cout << "\n\nDestructor Executed for object with data member " << n;
}

inline int Test_Class::Get_Value()
{
  return n;
}

int main()
{
  Test_Class tc_object1(4);
  Test_Class tc_object2(0);

  cout << "\n\nAfter object creation:";
  cout << "\n\nObject 1: " << tc_object1.Get_Value();
  cout << "\nObject 2: " << tc_object2.Get_Value();

  tc_object2 = tc_object1;

  cout << "\n\nAfter object assignment:";
  cout << "\n\nObject 1: " << tc_object1.Get_Value();
  cout << "\nObject 2: " << tc_object2.Get_Value();

  Test_Class tc_object3 = tc_object1;

  cout << "\n\nAfter initializing object 3:";
  cout << "\n\nObject 3: " << tc_object3.Get_Value();

  cout << endl;
  return 0;
}
