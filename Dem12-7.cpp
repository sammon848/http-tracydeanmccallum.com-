//dem12-7.cpp

//This program illustrates overloading the == operator

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Account
{
  friend int Transfer(Account &, Account &, double);
  friend ostream& operator << (ostream &, const Account &);
  friend int operator == (Account &, Account &);

  private:
	 char   id_no[5];
	 char * name;
	 double balance;
	 double rate;

  public:
	 Account(char id[], char* n_p, double bal = 0.00, double rt = 0.04);
	 ~Account();
	 const char * Get_Id() const;
	 const char * Get_Name() const;
	 double Calc_Interest();
	 double Get_Balance() const;
	 Account & operator += (const double);
	 Account & operator -= (const double);

	 Account & operator = (const Account &);
};


Account::Account(char id[], char* n_p, double bal, double rt)
{
  strcpy(id_no, id);  //copy first argument into id_no[]

  name = new char[strlen(n_p) + 1]; //create space for the name

  strcpy(name, n_p);  //copy second argument into new space

  balance = bal;
  rate    = rt;
}

Account::~Account()
{
  delete [] name;
}

inline const char * Account::Get_Id() const
{
  return id_no;
}

inline const char * Account::Get_Name() const
{
  return name;
}


inline double Account::Get_Balance() const
{
  return balance;
}

double Account::Calc_Interest()
{
  double interest;

  interest = balance * rate;
  balance += interest;

  return interest;
}

Account & Account::operator += (const double right_op)
{
  balance += right_op;

  return *this;
}

Account & Account::operator -= (const double right_op)
{
  balance -= right_op;

  return *this;
}

ostream& operator << (ostream & os, const Account & right_op)
{
  os << "\nData for Account# " << right_op.id_no;

  os << "\n\nOwner's Name: " << right_op.name;

  os << "\n\nAccount Balance: " << right_op.balance << endl;

  return os;
}


Account & Account::operator = (const Account & right_op)
{
  if (&right_op == this)
	 ;                   //Self assignment - do nothing
  else
	 {
		strcpy(id_no, right_op.id_no);  //copy id of right_op into id_no[]

		delete [] name;

		name = new char[strlen(right_op.name) + 1]; //create space for the name

		strcpy(name, right_op.name);  //copy second argument into new space

		balance = right_op.balance;
		rate    = right_op.rate;
	 }

  return *this;
}

int Transfer(Account & acc_r1, Account & acc_r2, double amount)
{
  //If amount exceeds acc_r2's balance, do nothing and return 0

  if (amount > acc_r2.balance)
	 return 0;

  //Otherwise, make the transfer and return 1

  acc_r2.balance -= amount;  //decrease acc_r2's balance by amount
  acc_r1.balance += amount;  //increase acc_r1's balance by amount

  return 1;
}

int operator == (Account & acc_left, Account & acc_right)
{
  if (strcmp(acc_left.id_no, acc_right.id_no))
	 return 0;

  if (strcmp(acc_left.name, acc_right.name))
	 return 0;

  if (acc_left.balance != acc_right.balance)
	 return 0;

  if (acc_left.rate != acc_right.rate)
	 return 0;

  return 1;
}


Account Get_Account();              //Function prototype

int main()
{
  cout << setprecision(2)
		 << setiosflags(ios::fixed)
		 << setiosflags(ios::showpoint);

 
  Account acc1 = Get_Account();

  cout << acc1;

  Account acc2 = acc1;

  cout << "\nInitializing acc2 to the value of acc1.";

  if (acc1 == acc2)
	 cout << "\n\nThe accounts are equal";
  else
	 cout << "\n\nThe accounts are not equal";

  cout << "\n\nAdding $50.00 to Account 2" << endl;

  acc2 += 50.00;

  cout << acc2;

  if (acc1 == acc2)
	 cout << "\nThe accounts are equal";
  else
	 cout << "\nThe accounts are not equal";

  cout << endl;
  return 0;

}


Account Get_Account()
{
  char id[5];
  char buffer[81];
  double bal;
  double rt;

  cout << "\nEnter Account ID: ";
  cin.getline(id, 5);

  cin.get();    //Clear the input buffer of newline character

  cout << "\nEnter Account Holder's Name: ";
  cin.getline(buffer, 81);

  cout << "\nEnter Balance: ";
  cin >> bal;

  cout << "\nEnter Interest Rate: ";
  cin >> rt;

  cin.get();    //Clear the input buffer of newline character

  Account acc(id, buffer, bal, rt);

  return acc;
}
