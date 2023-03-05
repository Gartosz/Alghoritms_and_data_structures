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
    std::cout << "]\n";
}

int nty(int n, lnode *L)
{
    for (int i = 0; i < n; ++i)
    {
        if (L == nullptr)
            return 0;
        else
            L = L->next;
    }
    return L != nullptr ? L->key : 0;
}

void insert(lnode* &L, int x)
{
    L = new lnode(x, L);
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

void insert_after_smaller(lnode *&L, int x)
{
    if (L == nullptr || L->key > x)
            insert(L, x);
    else
        insert_after_smaller(L->next, x);
}

void remove(lnode* &L, int x)
{
    lnode* node = L;
    lnode* prev_node = nullptr;
    while(node != nullptr)
    {
        if (node->key == x)
        {
            lnode* node_to_remove = node;
            if (L == node)
                node = L->next;
            node = node->next;
            if (prev_node != nullptr)
            prev_node->next = node;
            delete node_to_remove;
        }
        else
        {
            prev_node = node;
            node = node->next;
        }
    }
}

int main()
{
    lnode* test_list = new lnode({10, 2,4,5,9});
    wypisz(test_list);
    std::cout << suma(test_list) << std::endl;
    insert(test_list, 11);
    wypisz(test_list);
    std::cout << nty(3, test_list) << std::endl;
    insert_after_smaller(test_list, 13);
    wypisz(test_list);
    remove(test_list, 4);
    wypisz(test_list);
}