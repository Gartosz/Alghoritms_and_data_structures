#include <iostream>

int max_iter(int *t, int n)
{
    int x = t[--n];
    while (n--)
        if (t[n] > x)
            x = t[n];
    return x;
}

int max_rec(int *t, int n)
{
    --n;
    if (n == 0)
        return t[0];
    int prev_element = max_rec(t, n);
    return prev_element > t[n] ? prev_element : t[n];
}

int max_divide(int *t, int n)
{
    --n;
    if (n == 0)
        return t[0];
    int left_part = max_divide(t, n % 2 ? n/2 : n/2 + 1);
    int right_part = max_divide(t + (n % 2 ? n/2 : n/2 + 1), n/2);
    return left_part > right_part ? left_part : right_part;
}

int main()
{
    int array[10] = {2, 5, 6, 12, 54, 37, 25, 11, 9, 1};
    std::cout << max_iter(array, sizeof(array) / sizeof(*array)) << std::endl;
    std::cout << max_rec(array, sizeof(array) / sizeof(*array)) << std::endl;
    std::cout << max_divide(array, sizeof(array) / sizeof(*array));
    return 0;
}