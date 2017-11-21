#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float funcA(float x);
float funcB(float x);

int main()
{
  float xp1 = 0.0; // previous 1
  float xp2 = 0.0; // previous 2
  float xn = 0.0; // next
  float e = 0.0; // error
  char errorType = ' ';

  // Function A

  cout << "Function A" << endl;
  cout << "Enter first guess:  ";
  cin >> xp1;
  cout << "Enter second guess:  ";
  cin >> xp2;
  cout << endl << "n\txp1\txp2\tf(xp1)\tf(xp2)\txn\terr" << endl;

  for (int n = 0; n < 100; ++n)
  {
    cout << n << "\t";
    cout << setprecision(3) << xp1 << "\t";
    cout << setprecision(3) << xp2 << "\t";
    cout << setprecision(3) << funcA(xp1) << "\t";
    cout << setprecision(3) << funcA(xp2) << "\t";

    xn = xp2 - (funcA(xp2) / ((funcA(xp2) - funcA(xp1)) / xp2 - xp1));
    cout << setprecision(3) << xn << "\t";

    e = (xn - xp2) / xn;

    cout << abs(e) << endl;

    if (abs(e) < 0.01)
    {
      cout << endl << "Root found at x = " << setprecision(3) << xn << endl;
      break;
    }
    else if (abs(e) >= 0.01 && n == 99)
      cout << endl << "Reached max number of iterations.  Divergent" << endl;

    xp1 = xp2;
    xp2 = xn;
  }

  cout << endl;

  // Function B

  cout << "Function B" << endl;
  cout << "Enter first guess:  ";
  cin >> xp1;
  cout << "Enter second guess:  ";
  cin >> xp2;
  cout << "Use (a)pproximate error or (t)rue error:  ";
  cin >> errorType;
  cout << endl << "n\txp1\txp2\tf(xp1)\tf(xp2)\txn\terr" << endl;

  for (int n = 0; n < 100; ++n)
  {
    cout << n << "\t";
    cout << setprecision(3) << xp1 << "\t";
    cout << setprecision(3) << xp2 << "\t";
    cout << setprecision(3) << funcB(xp1) << "\t";
    cout << setprecision(3) << funcB(xp2) << "\t";

    xn = xp2 - (funcB(xp2) / ((funcB(xp2) - funcB(xp1)) / xp2 - xp1));
    cout << setprecision(3) << xn << "\t";

    if (errorType == 'a' || errorType == 'A')
      e = (xn - xp2) / xn;
    else if (errorType == 't' || errorType == 'T')
      e = (126.632 - xn) / 126.632;

    cout << abs(e) << endl;

    if (abs(e) < 0.01)
    {
      cout << endl << "Root found at x = " << setprecision(3) << xn << endl;
      break;
    }
    else if (abs(e) >= 0.01 && n == 99)
      cout << endl << "Reached max number of iterations.  Divergent" << endl;

    xp1 = xp2;
    xp2 = xn;
  }

  return 0;
}

float funcA(float x)
{
  return (2*pow(x, 3) - 11.7*pow(x, 2) + 17.7*x - 5);
}

float dfuncA(float x)
{
  return (6*pow(x, 2) - 23.4*x + 17.7);
}

float funcB(float x)
{
  return (x + 10 - x*cosh(50 / x));
}

float dfuncB(float x)
{
  return (1 - cosh(50 / x) + (50 * sinh(50/x) / x));
}