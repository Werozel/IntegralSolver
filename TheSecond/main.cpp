#include <iostream>
#include <iomanip>

using namespace std;

double f(double x)
{
    return x*x + 3;
}

double abs(double a)
{
    return a > 0 ? a : -a;
}

int main()
{
    double a, b, e;
    int i = 0;
    cin >> a;
    cin >> b;
    cin >> e;

    double delt = (b - a);
    double s0 = delt*(f(b) + f(a))/2;
    delt = delt / 2;

    double sn = s0/2 + delt*f((a + b)/2);
    delt = delt / 2;

    i = 2;
    while(abs(s0 - sn) >= 2*e)
    {
        s0 = sn;
        sn = s0/2;
        for(double x = a; x <= b; x += 2*delt)
        {
            sn += delt*f(x);
        }
        delt = delt / 2;
        i++;
    }

    cout << setprecision(4) << fixed << "Area = " << sn << "  Steps = " << i << endl;

    return 0;
}

