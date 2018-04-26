/**
The formula:
Starting from initial guess x1, the Newton Raphson method uses below formula to find next value of x, i.e., xn+1 from previous value xn.
newtonraphson formula

    Xn+1= Xn - f(Xn)/f'(Xn)


Algorithm:
Input: initial x, func(x), derivFunc(x)
Output: Root of Func()

Compute values of func(x) and derivFunc(x) for given initial x
Compute h: h = func(x) / derivFunc(x)
While h is greater than allowed error ε
h = func(x) / derivFunc(x)
x = x – h

*/
// C++ program for implementation of Newton Raphson Method for
// solving equations
#include<bits/stdc++.h>
#define EPSILON 0.001
using namespace std;

// An example function whose solution is determined using
// Bisection Method. The function is x^3 - x^2  + 2
double func(double x)
{
    return x*x*x - x*x + 2;
}

// Derivative of the above function which is 3*x^x - 2*x
double derivFunc(double x)
{
    return 3*x*x - 2*x;
}

// Function to find the root
void newtonRaphson(double x)
{
    double h = func(x) / derivFunc(x);
    while (abs(h) >= EPSILON)
    {
        h = func(x)/derivFunc(x);

        // x(i+1) = x(i) - f(x) / f'(x)
        x = x - h;
    }

    cout << "The value of the root is : " << x;
}

// Driver program to test above
int main()
{
    double x0 = -20; // Initial values assumed
    newtonRaphson(x0);
    return 0;
}
