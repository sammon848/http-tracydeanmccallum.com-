//dem13-7.cpp

//This program demonstrates the use of a virtual function
//in a class hierarchy.

#include <iostream>
#include <iomanip>

using namespace std;

class Shape
{
  protected:
	 const char * figure_type;
  public:
	 Shape(const char * ft = "Default Figure") : figure_type(ft)
		{cout << "\n\nShape Constructor";}
	 const char * Get_Type() {return figure_type;}
	 ~Shape() {cout << "\n\nShape Destructor";}
	 virtual double Area() {return 0.0;}        //virtual function
}; 

class Rectangle : public Shape
{
  protected:
	 double height, width;
  public:
	 Rectangle(double h, double w): Shape("Rectangle"), height(h),width(w)
		{cout << "\nRectangle Constructor";}
	 ~Rectangle() {cout << "\nRectangle Destructor";}
	 double Area() {return height * width;}
};

class Circle : public Shape
{
  protected:
	 double radius;
  public:
	 Circle(double r) : Shape("Circle"), radius(r)
		{cout << "\n\nCircle Constructor";}
	 ~Circle() {cout << "\n\nCircle Destructor";}
	 double Area() {return 3.1416 * radius * radius;}
};

class Trapezoid : public Shape
{
  protected:
	 double base1, base2, height;
  public:
	 Trapezoid(double b1, double b2, double h)
		 : Shape("\n\nTrapezoid"), base1(b1), base2(b2), height(h)
		{cout << "\n\nTrapezoid Constructor";}
	 ~Trapezoid() {cout << "Trapezoid Destructor";}
	 double Area() {return 0.5 * height * (base1 + base2);}
};

int main()
{
  cout << setprecision(4)
       << setiosflags(ios::fixed)
       << setiosflags(ios::showpoint);

  Shape * s_p1;
  Circle * c_p1;

  Circle c1(5);

  s_p1 = &c1;  //Legal pointer assignment

  c_p1 = &c1;

  cout << "\n\nArea() applied through Circle pointer: " << c_p1 -> Area();

  cout << "\n\nArea() applied through Shape pointer: " << s_p1 -> Area();

  cout << endl;
  return 0;
}




