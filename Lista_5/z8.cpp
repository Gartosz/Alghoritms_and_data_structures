#include <iostream>
#include <vector>
#include <cassert>

struct lnode
{ 
    int key;
    lnode *next;
    lnode(int k,lnode* n=nullptr):key(k),next(n){}
    lnode(std::vector<int> list, lnode* n=nullptr)
    {
        if (list.empty())
            std::logic_error("Vector cannot be empty.");
        key = list[0];
        lnode* last_lnode = this;
        for (auto element = list.begin() + 1; element < list.end(); ++element)
        {
            last_lnode->next = new lnode(*element);
            last_lnode = last_lnode->next;
        }
    }
};

void print (lnode* L)
{
    std::cout << "[ ";
    while (L != nullptr)
    {
        std::cout << L->key << ", "; 
        L = L->next;
    }
    std::cout << "]\n";
}

void insert(lnode* &L, int x)
{
    L = new lnode(x, L);
}

int main()
{
    lnode* test_list = new lnode({11,15,0,3,4,8,12,17,11,0,4});
    print(test_list);
}