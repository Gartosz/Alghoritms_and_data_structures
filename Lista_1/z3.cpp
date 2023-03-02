#include <iostream>

double rec_power(const int &x, const int &n)
{
    if (!n)
        return 1;

    double part_power = rec_power(x, n/2);

    if (n % 2)
    {
        if (n > 0)
            return x * part_power * part_power;
        else
            return 1.0 * part_power * part_power / x;
    }
    else
        return part_power * part_power;
}

double iter_power(const int &x, const int &n)
{
    int current_power = n < 0 ? -1 : 1;
    double current_value = 1;
    
    while(current_power && n != 0)
    {
        if (current_power % 2)
        {
            if (current_power > 0)
                current_value *= x;
            else
                current_value /= x;
        }
        else
            current_value *= current_value;
        
        current_power = current_power == n ? 0 : current_power;

        current_power = (n > 0 ? (current_power * 2 > n) : (current_power * 2 < n)) ? n : current_power * 2;
    }

    return current_value;
}

int main()
{
    std::cout << rec_power(5, -3) << std::endl;
    std::cout << iter_power(5, -3);

}