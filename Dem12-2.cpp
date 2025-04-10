//dem12-2.cpp

//This program illustrates the overloading of the addition operator

#include <iostream>

using namespace std;

class Test_Class
{
  friend Test_Class operator + (const Test_Class &, const Test_Class &);
  friend Test_Class operator + (const Test_Class &, const int);

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


int main()
{
  Test_Class tc_object1(4);
  Test_Class tc_object2(7);
  Test_Class tc_object;

  cout << "\n\nPrior to adding the objects, the value of tc_object is "
		 << tc_object.Get_Value();

  tc_object = tc_object1 + tc_object2;

  cout << "\n\nAfter adding the objects, the value of tc_object is "
		 << tc_object.Get_Value();

  tc_object = tc_object1 + 15;

  cout << "\n\nAfter adding 15 to tc_object1, the value of tc_object is "
		 << tc_object.Get_Value();

  cout << endl;
  return 0;
}
