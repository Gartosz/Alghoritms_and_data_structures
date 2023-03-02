#include <cmath>
#include <iostream>

double bisect(double function(double), double const &epsilon, double a, double b, double const &approximation = 0)
{
    double root = (approximation ? approximation : (a + b) / 2);
    do
    {
        if (function(root) * function(b) < 0)
            a = root;
        else
            b = root;
        root = (a + b) / 2;
    }while (std::abs(function(root)) > epsilon);
   return root;
}

int main()
{
    std::cout << bisect([](double x){return sin(x)-0.1;}, 0.000000002, -5, 5);
}