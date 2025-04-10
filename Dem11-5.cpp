// dem11-5.cpp

// This program shows how find the average of the elements
// in an array.  It finds the average by passing the array
// to a function that computes the average.

#include <iostream>
#include <iomanip>

using namespace std;

#define NUM_QUIZZES 10

double Avg(const int [], int);

int main()
{
  int    grade[NUM_QUIZZES]; /* The array to store the quiz grades */
  int    quiz;               /* The array subscript */
  double grade_avg;

  cout << setiosflags(ios::fixed)
       << setiosflags(ios::showpoint)
       << setprecision(1);


  cout << "\nPlease enter " << NUM_QUIZZES << " integer quiz grades.\n\n";

  for (quiz = 0; quiz < NUM_QUIZZES; ++quiz)
    {
		cout << "\nEnter grade for quiz " << quiz + 1 << ": ";
      cin >> grade[quiz];
	 }

  grade_avg = Avg(grade, NUM_QUIZZES);

  cout << "\nThe average quiz grade is " << grade_avg;

  cout << endl;
  return 0;
 
}   // End of main()


double Avg(const int arr[], int size)
{
  int    i,			// The array subscript
         sum = 0; 	// The accumulator
  double avg;   		// The array average

  for (i = 0; i < size; ++i)
    sum += arr[i];

  avg = double(sum) / size;

  return avg;
}   // End of Avg()
