//dem12-8.cpp

//This program illustrates overloading the ++ operator

#include <iostream>

using namespace std;

class Test_Class
{
  friend Test_Class operator + (const Test_Class &, const Test_Class &);
  friend Test_Class operator + (const Test_Class &, const int);
  friend istream & operator >> (istream &, Test_Class &);
  friend ostream & operator << (ostream &, Test_Class &);

  private:
	 int n;

  public:
	 Test_Class(int i = 0);  //One-argument constructor
	 Test_Class(Test_Class &);  //Copy constructor
	 ~Test_Class();
	 Test_Class & operator ++();	//Prefix overload
	 Test_Class & operator ++(int);	//Postfix overload
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

ostream & operator << (ostream & os, Test_Class & right_op)
{
  os << right_op.n;

  return os;
}

Test_Class & Test_Class::operator ++ ()			//Preincrement overload
{
  ++n;

  return *this;
}

Test_Class & Test_Class::operator ++ (int)		//Postincrement overload
{
  n++;

  return *this;
}


int main()
{
  Test_Class tc_object(5);

  cout << "\nThe current value of the object is " << tc_object;

  ++tc_object;

  cout << "\n\nAfter a preincrement the value of the object is "
		 << tc_object;

  tc_object++;

  cout << "\n\nAfter a postincrement the value of the object is "
		 << tc_object;

  cout << endl;
  return 0;
}

