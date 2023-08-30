#include <iostream>
using namespace std;
class RationalNumber
{
private:
  int numerator;
  int denominator;
public:
  void assign(int a, int b)
  {
    numerator = a;
    if(b > 0)
      denominator = b;
    else
      cout << "ERROR" << endl;
  }
  double convert()
  {
      double a = (double) numerator;
      double b = (double) denominator;
      if(b > 0) return a/b;
      else cout << "ERROR" << endl;
      return 0.0;
  }
  void invert()
  {
    if(denominator > 0)
      swap(numerator, denominator);
  }
  void print()
  {
      if(denominator > 0)
      {
        cout << "The Rational Number is: ";
        cout << numerator << "/" << denominator << endl;
      }
  }
};

int main()
{
  RationalNumber object1;
  int a, b;
  cin >> a >> b;
  object1.assign(a,b);
  object1.print();
  object1.invert();
  object1.print();
  cout << object1.convert() << endl;
 
  return 0;
}
