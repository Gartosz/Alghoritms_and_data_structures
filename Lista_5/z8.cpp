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

void counting_sort(lnode *&lista, int m)
{
    std::vector<lnode*> count_vector(m, nullptr);
    while (lista)
    {
        if(count_vector[lista->key])
        {
            lnode** current_head = &count_vector[lista->key];
            while(*current_head)
                current_head = &((*current_head)->next);
            *current_head = lista;
            lista = lista->next;
            (*current_head)->next = nullptr;
        }
        else
        {
            std::size_t key = lista->key;
            count_vector[key] = lista;
            lista = lista->next;
            count_vector[key]->next = nullptr;
        }
    }
    }
}

int main()
{
    lnode* test_list = new lnode({11,15,0,3,4,8,12,17,11,0,4});
    print(test_list);
    counting_sort(test_list, 18);
    print(test_list);
}