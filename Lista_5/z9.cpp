#include <iostream>


int partition (int t[], int n)
{
    int k = -1;
    double x = t[n / 2];
    for(;;)
    {
        do ++k; 
        while (t[k] < x);
        do --n; 
        while (t[n] > x);

        if (k < n) 
            std::swap(t[k],t[n]);
        else       
            return k;
    }
}

int kth(int t[], int n, int k)
{
    int pivot = partition(t, n);
    if (pivot == k)
        return t[pivot];
    else if (pivot < k)
        kth(t + pivot + 1, n - pivot - 1, k - pivot - 1);
    else
        kth(t, pivot, k);
}

int main()
{
    int t1[5] = {3, 54, 21, 7, 16};
    int t2[10] = {1, 2, 3, 5, 8, 10, 11, 13, 17, 19};
    std::cout << kth(t1, 5, 2) << "\n";
    std::cout << kth(t2, 10, 5);
}