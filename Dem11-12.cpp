//dem11-12.cpp

//This program uses an expanded version of the Account.
//The program uses a constructor with default arguments.
//The ID number is stored as an array and the name of the
//account holder is a character pointer. The constructor uses
//dynamic memory allocation.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Account
{
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
    double Get_Balance();
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


inline double Account::Get_Balance()
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


void Display_Account(Account &);    //Function prototype

int main()
{
  cout << setprecision(2)
	 << setiosflags(ios::fixed)
	 << setiosflags(ios::showpoint);

  char id[5];
  char buffer[81];  //Temporarily stores the name
  double bal;
  double rt;
  double amount;

  cout << "\nEnter Account ID: ";
  cin.getline(id, 5);

  cin.get();    //Clear the input buffer of newline character

  cout << "\nEnter Account Holder's Name: ";
  cin.getline(buffer, 81);

  cout << "\nEnter Balance: ";
  cin >> bal;

  cout << "\nEnter Interest Rate: ";
  cin >> rt;


  Account acc1(id, buffer, bal, rt);

  Display_Account(acc1);

  cout << "\n\nEnter an amount to deposit: ";
  cin >> amount;

  acc1.Deposit(amount);

  cout << "\n\nA deposit of " << amount << " was made.";

  Display_Account(acc1);

  acc1.Calc_Interest();

  cout << "\n\nInterest was applied to the account.";

  Display_Account(acc1);

  cout << "\n\nName: " << acc1.Get_Name();

  cout << "\n\nEnter an amount to withdraw: ";
  cin >> amount;



  if (acc1.Withdraw(amount))
	 cout << "\n\nA withdrawal of " << amount << " was made.";
  else
	 cout << "\n\nWITHDRAWAL NOT MADE: Insufficient funds.";

	 cout << "\n\nName: " << acc1.Get_Name();

  Display_Account(acc1);

  cout << endl;
  return 0;
}

void Display_Account(Account &acc)
{
  cout << "\nData for Account# " << acc.Get_Id();

  cout << "\n\nOwner's Name: " << acc.Get_Name();

  cout << "\n\nAccount Balance: " << acc.Get_Balance();
}
