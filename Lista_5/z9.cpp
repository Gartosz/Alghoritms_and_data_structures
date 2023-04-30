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

}

int main()
{

}