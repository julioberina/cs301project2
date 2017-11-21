#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float funcA(float x);
float funcB(float x);

int main()
{
  float xp = 0.0; // previous 
  float xn = 0.0; // next
  float delta = 0.01; // delta
  float e = 0.0; // error
  char errorType = ' ';

  // Function A

  cout << "Function A" << endl;
  cout << "Enter initial guess:  ";
  cin >> xp;
  cout << "Use (a)pproximate error or (t)rue error:  ";
  cin >> errorType;
  cout << endl << "n\txp\txp*delta\tf(xp)\tf(xp+d*xp)\txn\terr" << endl;

  for (int n = 0; n < 100; ++n)
  {
    cout << n << "\t";
    cout << setprecision(3) << xp << "\t";
    cout << setprecision(3) << xp*delta << "\t";
    cout << setprecision(3) << funcA(xp) << "\t";
    cout << setprecision(3) << funcA(xp + xp*delta) << "\t";

    xn = xp - ((delta*xp*funcA(xp)) / (funcA(xp + delta*xp) - funcA(xp)));
    cout << setprecision(3) << xn << "\t";

    if (errorType == 'a' || errorType == 'A')
      e = (xn - xp) / xn;

    cout << abs(e) << endl;

    if (abs(e) < 0.01)
    {
      cout << endl << "Root found at x = " << setprecision(3) << xn << endl;
      break;
    }
    else if (abs(e) >= 0.01 && n == 99)
      cout << endl << "Reached max number of iterations.  Divergent" << endl;

    xp = xn;
  }

  cout << endl;

  // Function B

  cout << "Function B" << endl;
  cout << "Enter initial guess:  ";
  cin >> xp;
  cout << "Use (a)pproximate error or (t)rue error:  ";
  cin >> errorType;
  cout << endl << "n\txp\txp*delta\tf(xp)\tf(xp+d)\txn\terr" << endl;

  for (int n = 0; n < 100; ++n)
  {
    cout << n << "\t";
    cout << setprecision(3) << xp << "\t";
    cout << setprecision(3) << xp*delta << "\t";
    cout << setprecision(3) << funcB(xp) << "\t";
    cout << setprecision(3) << funcB(xp + xp*delta) << "\t";

    xn = xp - ((delta*xp*funcB(xp)) / (funcB(xp + delta*xp) - funcB(xp)));
    cout << setprecision(3) << xn << "\t";

    if (errorType == 'a' || errorType == 'A')
      e = (xn - xp) / xn;
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

    xp = xn;
  }

  return 0;
}

float funcA(float x)
{
  return (2*pow(x, 3) - 11.7*pow(x, 2) + 17.7*x - 5);
}

float funcB(float x)
{
  return (x + 10 - x*cosh(50 / x));
}