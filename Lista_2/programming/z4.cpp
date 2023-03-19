#include <iostream>

class BSTiter
{
    public:
    int x;
    BSTiter *parent;
    BSTiter *left;
    BSTiter *right;

    BSTiter(int key, BSTiter *_parent = nullptr) : x(key), parent(_parent), right(nullptr), left(nullptr), current(this) {} 

    private:
    BSTiter *current;

};

int main()
{
    return 0;
}