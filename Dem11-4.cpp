//dem11-4.cpp

//This program illustrates constant member functions

//Note that the commented statement in main() causes
//an error message in Visual C++ 6.0. Therefore,
//will not compile on that compiler.

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
  const Test_Class tc_object1(4);

  cout << "\nThe value of the object is " << tc_object1.Get_Value();

  tc_object1.Change_Value(7);  //Causes Compiler Warning Message

  cout << "\nThe value of the object is " << tc_object1.Get_Value();

  cout << endl;
  return 0;
}
