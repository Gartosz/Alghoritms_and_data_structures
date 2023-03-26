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