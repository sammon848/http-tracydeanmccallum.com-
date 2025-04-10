//dem11-13.cpp

//This program illustrates the use of dynamically allocated
//objects

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

void Display_Account(Account &acc)
{
  cout << "\n\n\nData for Account# " << acc.Get_Id();

  cout << "\n\nOwner's Name: " << acc.Get_Name();

  cout << "\n\nAccount Balance: " << acc.Get_Balance();
}

Account * Create_Account()
{
  char id[5];
  char buffer[81];
  double bal;
  double rt;

  Account * acc_ptr;

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

  acc_ptr = new Account (id, buffer, bal, rt);

  return acc_ptr;
}
