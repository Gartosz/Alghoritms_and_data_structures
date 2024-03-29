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

void filter(lnode* &L, bool(*cond)(int))
{
    lnode* node = L;
    lnode* prev_node = nullptr;
    while(node != nullptr)
    {
        if (!cond(node->key))
        {
            lnode* node_to_remove = node;
            if (L == node)
                L = node->next;
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

void destroy(lnode* &L)
{
    while(L != nullptr)
    {
        lnode* to_destroy = L;
        L = L->next;
        delete to_destroy;
    }
}

void reverse(lnode* &L)
{
    lnode* next_node = nullptr;
    do
    {
        lnode* prev_node = L->next;
        L->next = next_node;
        next_node = L;
        L = prev_node;
    }while(L != nullptr);
    L = next_node;
}

lnode* merge(lnode* L1, lnode* L2)
{
    lnode* merged_list = nullptr;
    if (L1->key < L2->key)
    {
        merged_list = L1;
        L1 = L1->next;
    }
    else
    {
        merged_list = L2;
        L2 = L2->next;
    }
    lnode* next_node = merged_list;
    
    while(L1 != nullptr)
    {
        if(L2 != nullptr && L1->key > L2->key)
        {
            next_node = L2;
            L2 = L2->next;
        }
        else
        {
            next_node = L1;
            L1 = L1->next;
        }
    }
    if (L2 != nullptr)
        next_node->next = L2;
    return merged_list;
}

void insertion_sort(lnode*& L)
{
    lnode *sorted = nullptr;
    lnode *current_node = L;
    while (current_node)
    {
        lnode **node = &sorted;
        while (*node && current_node->key <= (*node)->key)
            node = &((*node)->next);

        lnode *next_node = current_node->next;
        if (*node)
        {
            lnode *found_node = *node;
            *node = current_node;
            (*node)->next = found_node;
        }
        else
        {
            *node = current_node;
            (*node)->next = nullptr;
        }
        current_node = next_node;
    }
    reverse(sorted);
    L = sorted;
}

int main()
{
    lnode* test_list = new lnode({11, 13, 2, 7, 1, 20, 24});
    print(test_list);
    insertion_sort(test_list);
    print(test_list);
}