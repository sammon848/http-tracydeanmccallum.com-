//dem12-1.cpp

//This program illustrates the use of a friend function

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Account
{
  friend int Transfer(Account &, Account &, double);

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
	 void Deposit(double);
	 int Withdraw(double);
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
  cout << "\n\nAccount " << id_no << " terminated.";
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

void Account::Deposit(double amount)
{
  balance += amount;
}



int Account::Withdraw(double amount)
{
  int result;

  if (amount <= balance)
	 {
		balance -= amount;
		result = 1;
	 }
  else
	 result = 0;

  return result;
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



void Display_Account(Account &);    //Function prototype
Account Get_Account();              //Function prototype

int main()
{
  cout << setprecision(2)
	 << setiosflags(ios::fixed)
	 << setiosflags(ios::showpoint);

  double amount;

  Account acc1 = Get_Account();

  Display_Account(acc1);

  Account acc2 = Get_Account();

  Display_Account(acc2);

  cout << "\n\nEnter an amount to transfer from "
		 << "the second account to the first: ";

  cin >> amount;

  if (Transfer(acc1, acc2, amount))
	 {
		cout << "\nTransfer made. Updated Account Information:" << endl;
		Display_Account(acc1);
		Display_Account(acc2);
	 }
  else
	 cout << "\nTransfer could not be made.";

  cout << endl;
  return 0;
}

void Display_Account(Account & acc_r)
{
  cout << "\nData for Account# " << acc_r.Get_Id();

  cout << "\n\nOwner's Name: " << acc_r.Get_Name();

  cout << "\n\nAccount Balance: " << acc_r.Get_Balance() << endl;
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
