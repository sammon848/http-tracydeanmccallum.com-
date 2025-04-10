//dem11-14.cpp

//This program illustrates the use of static data members
//and functions

#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>

using namespace std;

class Account
{
  private:
	 char   id_no[5];
	 char * name;
	 double balance;
	 static double rate;
	 static int number_accounts;

  public:
	 Account(char id[], char* n_p, double bal = 0.00);
	 ~Account();
	 const char * Get_Id() const;
	 const char * Get_Name() const;
	 double Calc_Interest();
	 double Get_Balance();
	 void Deposit(double);
	 int Withdraw(double);

	 static int Total_Accounts();
};


//Static data member definitions

double Account::rate = 0.040;
int Account::number_accounts = 0;


Account::Account(char id[], char* n_p, double bal)
{
  strcpy(id_no, id);  //copy first argument into id_no[]

  name = new char[strlen(n_p) + 1]; //create space for the name

  strcpy(name, n_p);  //copy second argument into new space

  balance = bal;

  ++number_accounts;
}

Account::~Account()
{
  cout << "\n\nAccount " << id_no << " terminated.";
  delete [] name;

  --number_accounts;

  cout << "\nNumber Accounts Remaining: " << number_accounts;
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

int Account::Total_Accounts()
{
  return number_accounts;
}


void Display_Account(Account &);    //Function prototypes
Account * Create_Account();

int main()
{
  cout << setprecision(2)
		 << setiosflags(ios::fixed)
		 << setiosflags(ios::showpoint);

  Account * account_table[10];

  int count = 0;
  char response;

  cout << "\nDo you want to create an account?(Y/N): ";
  response = cin.get();
  cin.get();		//Clear the input buffer

  while (toupper(response) == 'Y' && count < 10)
	 {
		account_table[count] = Create_Account();
		account_table[count] -> Calc_Interest();

		++count;

		cout << "\nDo you want to create an account?(Y/N): ";
		response = cin.get();
		cin.get();		//Clear the input buffer
	 }

  //Display the accounts

  for (int i = 0; i < count; ++i)
	 Display_Account(*account_table[i]);

  //Clean up

  for (i = 0; i < count; ++i)
	 delete account_table[i];

  cout << endl;
  return 0;
}

void Display_Account(Account& acc)
{
  cout << "\n\n\nData for Account# " << acc.Get_Id();

  cout << "\n\nOwner's Name: " << acc.Get_Name();

  cout << "\n\nCurrent Account Balance: " << acc.Get_Balance();
}

Account * Create_Account()
{
  char id[5];
  char buffer[81];
  double bal;

  Account * acc_ptr;

  cout << "\nEnter Account ID: ";
  cin.getline(id, 5);

  cin.get();    //Clear the input buffer of newline character

  cout << "\nEnter Account Holder's Name: ";
  cin.getline(buffer, 81);

  cout << "\nEnter Balance: ";
  cin >> bal;

  cin.get();    //Clear the input buffer of newline character

  acc_ptr = new Account (id, buffer, bal);

  cout << "\n\nNumber Existing Accounts: "
		 << Account::Total_Accounts() << endl;

  return acc_ptr;
}
