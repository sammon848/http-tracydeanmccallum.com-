//dem12-5.cpp

//This program illustrates the overloading of the extraction operator

#include <iostream>

using namespace std;

class Test_Class
{
  friend Test_Class operator + (const Test_Class &, const Test_Class &);
  friend Test_Class operator + (const Test_Class &, const int);
  friend istream & operator >> (istream &, Test_Class &);

  private:
	 int n;

  public:
	 Test_Class(int i = 0);  //One-argument constructor
	 Test_Class(Test_Class &);  //Copy constructor
	 ~Test_Class();
	 int Get_Value();
};

Test_Class::Test_Class(int i)
{
  n = i;

  //cout << "\nConstructor Executed: Data member initialized to " << n;
}

Test_Class::Test_Class(Test_Class & tc_r)
{
  n = tc_r.n;

  //cout << "\n\nCopy constructor executed: "
  //		<< "Data member initialized to " << n;
}

Test_Class::~Test_Class()
{
  //cout << "\n\nDestructor Executed for object with data member " << n;
}

inline int Test_Class::Get_Value()
{
  return n;
}


Test_Class operator + (const Test_Class & left_op, const Test_Class & right_op)
{
  Test_Class temp_obj;

  temp_obj.n = left_op.n + right_op.n;

  return temp_obj;
}

Test_Class operator + (const Test_Class & left_op, const int right_op)
{
  Test_Class temp_obj;

  temp_obj.n = left_op.n + right_op;

  return temp_obj;
}

istream & operator >> (istream & is, Test_Class & right_op)
{
  is >> right_op.n;

  return is;
}


int main()
{
  Test_Class tc_object1;
  Test_Class tc_object2;
  Test_Class tc_object3;

  cout << "\nEnter a value for the first object: ";
  cin >> tc_object1;

  cout << "\nEnter two values for the next two objects: ";
  cin >> tc_object2 >> tc_object3;

  cout << "\nThe data values for the three objects are: " << endl;
  cout << tc_object1.Get_Value() << endl;
  cout << tc_object2.Get_Value() << endl;
  cout << tc_object3.Get_Value() << endl;

  cout << endl;
  return 0;
}
