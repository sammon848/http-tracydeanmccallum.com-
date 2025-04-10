//dem11-10.cpp

//This program demonstrates the use of pointers to objects
//and the use of the -> operator to call member functions

#include <iostream>

using namespace std;

class Test_Class
{
  private:
	 int n;

  public:
	 Test_Class(int i = 0);    //One-argument constructor with default value
	 int Get_Value() const;
	 void Change_Value(int);
};


Test_Class::Test_Class(int i)
{
  n = i;

  cout << "\n\nConstructor Executed: Data member initialized to " << n;
}

inline int Test_Class::Get_Value() const
{
  return n;
}

void Test_Class::Change_Value(int i)
{
  n = i;
}

int main()
{
  Test_Class tc_object(5);
  Test_Class * tc_p = &tc_object;

  cout << "\nThe value of the object is " << tc_p -> Get_Value();
  
  tc_p -> Change_Value(7);    //Change the value of the pointer's target
  
  cout << "\nThe new value of the object is " << tc_p -> Get_Value();

  cout << endl;
  return 0;
}
