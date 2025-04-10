//dem13-11.cpp

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;


class Loan
{
  protected:
	 double principal;
	 double yearly_rate;     //rate as a percent
	 int    term_in_years;
	 double payment;
	 const char * loan_type;
  public:
	 Loan (double prin, double rt, int term, const char * lt) :
			principal(prin), yearly_rate(rt),term_in_years(term),
			loan_type(lt), payment(0.0) {};
	 virtual ~Loan() {}
	 virtual void Payment() = 0;   //pure virtual function
	 void Display_Loan_Info();
};

void Loan::Display_Loan_Info()
{
  cout << "\n\nLoan Type: " << loan_type;
  cout << "\nPrinciple: " << principal;
  cout << "\nYearly Rate: " << yearly_rate;
  cout << "\nNumber of Years: " << term_in_years;
  cout << "\n\nMonthly Payment: " << payment;
}

//End of Class Loan 			*******************************************

class Simple_Loan : public Loan
{
  public:
	 Simple_Loan(double prin, double rt, int term)
		: Loan(prin, rt, term, "Simple Loan") {}
	 ~Simple_Loan() {}
	 void Payment();
};

void Simple_Loan::Payment()
{
  double interest = principal *  term_in_years * (yearly_rate / 100);
  double loan_amount = principal + interest;

  payment = loan_amount / (term_in_years * 12);
}

//End of Class Simple_Loan 		*********************************************

class Amortized_Loan : public Loan
{
  public:
	 Amortized_Loan(double prin, double rt, int term)
		: Loan(prin, rt, term, "Amortized Loan") {}
	 ~Amortized_Loan() {}
	 void Payment();

};

void Amortized_Loan::Payment()
{
  double monthly_rate = yearly_rate / 12 / 100;
  int term_in_months = term_in_years * 12;

  double power = pow(1 + monthly_rate, term_in_months);

  payment = (principal * monthly_rate * power) / (power - 1);
}

//End of Class Amortized_Loan 	*********************************************



Loan * Get_Loan_Data(); 	//Prototype for function used by main()

int main()
{
  cout << setprecision(2)
		 << setiosflags(ios::fixed)
		 << setiosflags(ios::showpoint);

  const int num_loans = 3;

  Loan * loans[num_loans];

  for (int i = 0; i < num_loans; ++i)
	 loans[i] = Get_Loan_Data();

  for (i = 0; i < num_loans; ++i)
	 loans[i] -> Payment();

  for (i = 0; i < num_loans; ++i)
	 loans[i] -> Display_Loan_Info();

  for (i = 0; i < num_loans; ++i)
	 delete loans[i];

  cout << endl;
  return 0;
} //End of main()

Loan * Get_Loan_Data()
{
  double principal;
  double rate;
  int term_in_years;

  Loan * l_p;

  cout << "\n\nEnter the first letter of the loan type.";
  cout << "\n\n(S)imple";
  cout << "\n(C)ompound";
  cout << "\n\nEnter your choice: ";
  char response = cin.get();

  cout << "\n\nPrincipal: ";
  cin >> principal;
  cout << "\nYearly Rate as a Percent: ";
  cin >> rate;
  cout << "\nTerm in Years: ";
  cin >> term_in_years;

  cin.get();			//clear the input buffer

  switch (response)
  {
	 case 'S': case 's':
		l_p = new Simple_Loan(principal, rate, term_in_years);
		break;
	 case 'C': case 'c':
		l_p = new Amortized_Loan(principal, rate, term_in_years);
		break;
  }

  return l_p;
}   //End of Get_Loan_Data()
	 
