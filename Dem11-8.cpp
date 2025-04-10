//dem11-8.cpp

//This program illustrates the use of the copy constructor
//in a class that has a pointer as a data member

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
	 Account(const Account &);
    ~Account();
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

  cout << "\n\nConstructor executed.";
}

Account::Account(const Account & acc_r)
{
  strcpy(id_no, acc_r.id_no);  //copy first argument into id_no[]

  name = new char[strlen(acc_r.name) + 1]; //create space for the name

  strcpy(name, acc_r.name);  //copy second argument into new space

  balance = acc_r.balance;
  rate    = acc_r.rate;

  cout << "\n\nCopy constructor executed.";
}

Account::~Account()
{
  cout << "\n\nAccount " << id_no << " terminated.";
  delete [] name;
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

Account Get_Account();

int main()
{
  cout << setprecision(2)
	 << setiosflags(ios::fixed)
	 << setiosflags(ios::showpoint);

  cout << "\n\nAccount now being created.";

  Account acc1 = Get_Account();

  cout << "\n\nAccount now being created by initialization.";
  
  Account acc2 = acc1;

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
