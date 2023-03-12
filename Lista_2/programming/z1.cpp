#include <iostream>

struct Node
{
    int x; 
    Node *left; 
    Node *right; 
    Node *parent;

    Node(int key, Node *_parent = nullptr) : x(key), parent(_parent), right(nullptr), left(nullptr) {} 
};

void insert(Node *&t, int x)
{
    Node **current_node = &t;
    Node **parent_node = nullptr;
    while(*current_node)
    {
        parent_node = current_node;
        if (x < (*current_node)->x)
            current_node = &((*current_node)->left);
        else
            current_node = &((*current_node)->right);
    }
    *current_node = new Node(x, *parent_node);
}

int main()
{
    Node *bst = new Node(30);
    insert(bst, 10);
    std::cout << bst->x << " " << bst->left->x << std::endl;
}