#include <iostream>
#include <fstream>

int fib(int const &n, int &sum_counter)
{
    long long fib_number = 0, n_1 = 0, n_2 = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (i < 2)
            fib_number = i;
        else
        {
            fib_number = n_2 + n_1;
            ++sum_counter;
        }
        
            n_2 = n_1;
            n_1 = fib_number;
    }

    return fib_number;
}

int main()
{
    int sum_count = 0;
    for (int i = 0; i <= 100; ++i)
    {
        std::cout << "Dla n = " << i << ": " << fib(i, sum_count) << " " << sum_count << std::endl;
    }
    sum_count = 0;
    std::cout << "\nDla n = 20: "<< fib(20, sum_count) << " " << sum_count << std::endl;
}

