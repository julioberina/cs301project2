#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float funcA(float x);
float dfuncA(float x); // derivative of function a)
float funcB(float x);
float dfuncB(float x); // derivative of function b)

int main()
{
  float xp = 0.0; // previous
  float xn = 0.0; // next
  float e = 0.0; // error
  char errorType = ' ';

  // Function A

  cout << "Function A" << endl;
  cout << "Enter initial guess (x0):  ";
  cin >> xp;
  cout << "Use (a)pproximate error or (t)rue error:  ";
  cin >> errorType;
  cout << endl << "n\txn\tf(x)\tf'(x)\txn+1\terr\t" << endl;

  for (int n = 0; n < 100; ++n)
  {
    cout << n << "\t";
    cout << setprecision(3) << xp << "\t";
    cout << setprecision(3) << funcA(xp) << "\t";
    cout << setprecision(3) << dfuncA(xp) << "\t";

    xn = xp - (funcA(xp) / dfuncA(xp));
    cout << setprecision(3) << xn << "\t";

    if (errorType == 'a' || errorType == 'A')
      e = (xn - xp) / xn;

    cout << abs(e) << endl;
    xp = xn;

    if (abs(e) < 0.01)
    {
      cout << endl << "Root found at x = " << setprecision(3) << xn << endl;
      break;
    }
    else if (abs(e) >= 0.01 && n == 99)
      cout << endl << "Reached max number of iterations.  Divergent" << endl;
  }

  cout << endl;

  // Function B

  cout << "Function B" << endl;
  cout << "Enter initial guess (x0):  ";
  cin >> xp;
  cout << "Use (a)pproximate error or (t)rue error:  ";
  cin >> errorType;
  cout << endl << "n\txn\tf(x)\tf'(x)\txn+1\terr\t" << endl;

  for (int n = 0; n < 100; ++n)
  {
    cout << n << "\t";
    cout << setprecision(3) << xp << "\t";
    cout << setprecision(3) << funcB(xp) << "\t";
    cout << setprecision(3) << dfuncB(xp) << "\t";

    xn = xp - (funcB(xp) / dfuncB(xp));
    cout << setprecision(3) << xn << "\t";

    if (errorType == 'a' || errorType == 'A')
      e = (xn - xp) / xn;
    else if (errorType == 't' || errorType == 'T')
      e = (126.632 - xn) / 126.632;

    cout << abs(e) << endl;
    xp = xn;

    if (abs(e) < 0.01)
    {
      cout << endl << "Root found at x = " << setprecision(3) << xn << endl;
      break;
    }
    else if (abs(e) >= 0.01 && n == 99)
      cout << endl << "Reached max number of iterations.  Divergent" << endl;
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