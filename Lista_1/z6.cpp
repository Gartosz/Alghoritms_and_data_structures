#include <iostream>
#include <vector>

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


void wypisz (lnode* L)
{
    std::cout << "[ ";
    while (L != nullptr)
    {
        std::cout << L->key << ", "; 
        L = L->next;
    }
    std::cout << " ]";
}

int suma (lnode* L)
{
    int sum = 0;
    while (L != nullptr)
    {
        sum += L->key;
        L = L->next;
    }
    return sum;
}

int main()
{
    lnode* test_list = new lnode({10, 2,4,5,9});
    wypisz(test_list);
    std::cout << std::endl << suma(test_list) << std::endl;
}