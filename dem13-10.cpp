//dem13-10.cpp

//This program demonstrates the use of polymorphism

#include <iostream>
#include <iomanip>

using namespace std;

class Shape
{
  protected:
	 const char * figure_type;
  public:
	 Shape(const char * ft = "Default Figure") : figure_type(ft) {}
	 const char * Get_Type() {return figure_type;}
	 virtual ~Shape() {}
	 virtual double Area() {return 0.0;}
};

class Rectangle : public Shape
{
  protected:
	 double height, width;
  public:
	 Rectangle(double h, double w) : Shape("Rectangle"), height(h), width(w){}
	 virtual ~Rectangle() {}
	 double Area() {return height * width;}
};

class Circle : public Shape
{
  protected:
	 double radius;
  public:
	 Circle(double r) : Shape("Circle"), radius(r){}
	 virtual ~Circle() {}
	 double Area() {return 3.1416 * radius * radius;}
};

class Trapezoid : public Shape
{
  protected:
	 double base1, base2, height;
  public:
	 Trapezoid(double b1, double b2, double h)
			: Shape("Trapezoid"), base1(b1), base2(b2), height(h){}
	 virtual ~Trapezoid() {}
	 double Area() {return 0.5 * height * (base1 + base2);}
};


Shape * Get_Shape();

int main()
{
  cout << setprecision(4)
       << setiosflags(ios::fixed)
       << setiosflags(ios::showpoint);

  const int num_shapes = 5;

  Shape * shapes[num_shapes];

  for (int i = 0; i < num_shapes; ++i)
	 shapes[i] = Get_Shape();

  cout << endl;

  for (i = 0; i < num_shapes; ++i)
	 cout << "\nThe area of the " << shapes[i] -> Get_Type() << " is "
			<< shapes[i] -> Area();

  for (i = 0; i < num_shapes; ++i)
	 delete shapes[i];

  cout << endl;
  return 0;
}

Shape * Get_Shape()
{
  Shape * s_p;    //To be returned by the function

  double height,
			width,
			radius,
			base1,
			base2;

  cout << "\n\nEnter the number of the shape you want to create:";
  cout << "\n\nFor a Rectangle, enter 1";
  cout << "\nFor a Circle, enter 2";
  cout << "\nFor a Trapezoid, enter 3";

  cout << "\n\nPlease make your selection: ";

  int response;

  cin >> response;

  switch (response)
  {
	 case 1:
		cout << "\n\nEnter the height of the rectangle: ";
		cin >> height;
		cout << "\n\nEnter the width of the rectangle: ";
		cin >> width;

		s_p = new Rectangle(height, width);

		break;

	 case 2:
		cout << "\n\nEnter the radius of the circle: ";
		cin >> radius;

		s_p = new Circle(radius);

		break;

	 case 3:
		cout << "\n\nEnter the first base of the trapezoid: ";
		cin >> base1;
		cout << "\n\nEnter the second base of the trapezoid: ";
		cin >> base2;
		cout << "\n\nEnter the height of the trapezoid: ";
		cin >> height;

		s_p = new Trapezoid(base1, base2, height);

		break;

	 default:
		cout << "\n\nInvalid selection. Creating default object.";

		s_p = new Shape();

      break;
  }

  return s_p;
}


