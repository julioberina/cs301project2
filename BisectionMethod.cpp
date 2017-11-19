#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float funcA(float x);
float funcB(float x);
bool matchesSign(float a, float b);

int main()
{
  float a, b, c, e = 1, cp = 0; // cp for error purposes
  char errorType;
  
  // Function A

  cout << "Function A" << endl;
  cout << "Enter a:  ";
  cin >> a;
  cout << "Enter b:  ";
  cin >> b;
  cout << "Use (a)pproximate error or (t)rue error?:  ";
  cin >> errorType;
  cout << endl;

  cout << "n\ta\tb\tf(a)\tf(b)\tc\tf(c)\te" << endl;

  for (int n = 0; n < 100; ++n)
  {
    cout << n << "\t" << a << "\t" << b << "\t";
    cout << funcA(a) << "\t" << funcA(b) << "\t";
    c = (a + b) / 2;
    cout << c << "\t" << funcA(c) << "\t";

    if ((errorType == 'a' || errorType == 'A') && n > 0)
      e = (c - cp) / c;

    cout << e << endl;

    if (matchesSign(funcA(a), funcA(c)))
      a = c;
    else if (matchesSign(funcA(b), funcA(c)))
      b = c;

    if (e < 0.01)
    {
      cout << endl << "Root found:  x = " << c << endl;
      break;
    }
  
    else
    {
      if (n == 99)
        cout << endl << "Maximum number of iterations reached.  Divergent" << endl;
    }
    
    cp = c;
  }

  // Function B
  
  cp = 0;
  cout << endl << "Function B" << endl << "Enter a:  ";
  cin >> a;
  cout << "Enter b:  ";
  cin >> b;
  cout << "Use (a)pproximate error or (t)rue error?:  ";
  cin >> errorType;
  cout << endl;

  cout << "n\ta\tb\tf(a)\tf(b)\tc\tf(c)\te" << endl;

  for (int n = 0; n < 100; ++n)
  {
    cout << n << "\t" << a << "\t" << b << "\t";
    cout << funcB(a) << "\t" << funcB(b) << "\t";
    c = (a + b) / 2;
    cout << c << "\t" << funcB(c) << "\t";

    if ((errorType == 'a' || errorType == 'A') && n > 0)
      e = (c - cp) / c;

    cout << e << endl;

    if (matchesSign(funcB(a), funcB(c)))
      a = c;
    else if (matchesSign(funcB(b), funcB(c)))
      b = c;

    if (e < 0.01)
    {
      cout << endl << "Root found:  x = " << c << endl;
      break;
    }
  
    else
    {
      if (n == 99)
        cout << endl << "Maximum number of iterations reached.  Divergent" << endl;
    }
    
    cp = c;
  }

  return 0;
}

float funcA(float x)
{
  return (2*pow(x, 3) - 17.7*pow(x, 2) + 17.7*x - 5);
}

float funcB(float x)
{
  return (x + 10 - x*cosh(50/x));
}

bool matchesSign(float a, float b)
{
  return ((a * b > 0) ? true : false);
}
