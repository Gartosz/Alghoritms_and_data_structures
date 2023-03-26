#include <iostream>

class Node
{
    public:
    int x;
    int nL;
    Node *parent;
    Node *left;
    Node *right;
    
    Node(int key, int left_nodes = 0, Node *_parent = nullptr) : x(key), parent(_parent), right(nullptr), left(nullptr), nL(left_nodes) {} 
    
    void insert(int x)
    {
        Node *parent_node = this;
        Node **current_node = &parent_node;
        while(*current_node)
        {
            parent_node = *current_node;
            current_node = x < (*current_node)->x ? &((*current_node)->left) : &((*current_node)->right);
        }
        *current_node = new Node(x, parent_node);
    }


};

int main ()
{
    Node tree(41);
    int nodes[11] = {16, 3, 4, 9, 56, 18, 37, 65, 58, 2, 1};
    for (int i = 0; i < sizeof(nodes)/sizeof(*nodes); ++i)
        tree.insert(nodes[i]);
}