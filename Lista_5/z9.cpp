#include <iostream>


int partition (double t[], int n)
{
  int k = -1;
  double x = t[n / 2]; // pivot bierzemy posrodku
  for(;;)
  {
     do ++k; while (t[k] < x);
     do --n; while (t[n] > x);
     if (k < n) std::swap(t[k],t[n]);
     else       return k;
  }
}

int main()
{
    
}