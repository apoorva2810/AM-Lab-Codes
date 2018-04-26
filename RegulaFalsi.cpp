/**
Similarities with Bisection Method:

Same Assumptions: This method also assumes that function is continuous in [a, b] and given two numbers 'a' and 'b' are such that f(a) * f(b) < 0.
Always Converges: like Bisection, it always converges, usually considerably faster than Bisection--but sometimes very much more slowly than Bisection.
Differences with Bisection Method:
It differs in the fact that we make a chord joining the two points [a, f(a)] and [b, f(b)]. We consider the point at which the chord touches the x axis and named it as c.



Steps:

Write equation of the line connecting the two points.
y – f(a) =  ( (f(b)-f(a))/(b-a) )*(x-a)

Now we have to find the point which touches x axis.
For that we put y = 0.

so x = a - (f(a)/(f(b)-f(a))) * (b-a)
   x = (a*f(b) - b*f(a)) / (f(b)-f(a))

This will be our c that is c = x.
If f(c) == 0, then c is the root of the solution.
Else f(c) != 0
If value f(a)*f(c) < 0 then root lies between a and c. So we recur for a and c
Else If f(b)*f(c) < 0 then root lies between b and c. So we recur b and c.
Else given function doesn't follow one of assumptions.
*/

// C++ program for implementation of Bisection Method for
// solving equations
#include<bits/stdc++.h>
using namespace std;
#define MAX_ITER 1000000

// An example function whose solution is determined using
// Bisection Method. The function is x^3 - x^2  + 2
double func(double x)
{
    return x*x*x - x*x + 2;
}

// Prints root of func(x) in interval [a, b]
void regulaFalsi(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return;
    }

    double c = a;  // Initialize result

    for (int i=0; i < MAX_ITER; i++)
    {
        // Find the point that touches x axis
        c = (a*func(b) - b*func(a))/ (func(b) - func(a));

        // Check if the above found point is root
        if (func(c)==0)
            break;

        // Decide the side to repeat the steps
        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "The value of root is : " << c;
}

// Driver program to test above function
int main()
{
    // Initial values assumed
    double a =-200, b = 300;
    regulaFalsi(a, b);
    return 0;
}


///Output->  The value of root is : -1
