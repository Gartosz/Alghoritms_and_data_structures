#include <iostream>

class BSTiter
{
    public:
    int x;
    BSTiter *parent;
    BSTiter *left;
    BSTiter *right;

    BSTiter(int key, BSTiter *_parent = nullptr) : x(key), parent(_parent), right(nullptr), left(nullptr) {} 

    struct Iterator 
    {
    private:
        BSTiter *current;
    };

    
    void insert(int x)
    {
        BSTiter *parent_node = this;
        BSTiter **current_node = &parent_node;
        while(*current_node)
        {
            parent_node = *current_node;
            current_node = x < (*current_node)->x ? &((*current_node)->left) : &((*current_node)->right);
        }
        *current_node = new BSTiter(x, parent_node);
    }

};

int main()
{
    BSTiter tree(41);
    tree.insert(16);
    std::cout << tree.x << " " << (*tree.left).x;
    return 0;
}