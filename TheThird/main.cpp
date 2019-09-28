#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <climits>

using namespace std;

double f(double x)
{
    return x*x;
}

double abs(double a)
{
    return a > 0 ? a : -a;
}

double rnd(double a, double b)
{
    return ((double)rand()*(b - a))/(double)RAND_MAX + a;
}

double inFunction(double x, double y, double a, double b, double maxY)
{

    return (y <= f(x) && y >= 0 && x >= a && x <= b);

}

double findMaxY(double a, double b)
{
    double maxY = f(a);
    for(double i = a; i < b + 0.1; i+= 0.1)
    {
        if(f(i) > maxY) maxY = f(i);
    }
    return maxY;
}

int main()
{
    srand(time(NULL));
    double a, b, maxi;
    cin >> a;
    cin >> b;
    cin >> maxi;

    double maxY = findMaxY(a, b);
    double x, y;
    int n = 0;
    for(int i = 0; i < maxi; i++)
    {
        x = rnd(a, b);
        y = rnd(f(a), f(b));
        if(inFunction(x, y, a, b, maxY)) n++;
    }

    cout << setprecision(4) << fixed << "Area = " << (b - a)* maxY *(n/maxi) << " Points in function = " << n << endl;

    return 0;
}
