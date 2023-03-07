#include <iostream>
#include <vector>

double oblicz(std::vector<double> a, double x)
{
    double result = 0;
    for (auto coeff_iter = a.rbegin(); coeff_iter != a.rend(); ++coeff_iter )
        result = *coeff_iter + result * x;
        
    return result;
}

int main()
{
    std::cout << oblicz({4,5,3,0,0,18}, 10) << std::endl;
}

