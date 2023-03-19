#include <iostream>

class Node
{
    public:
    int x;
    Node *parent;
    Node *left;
    Node *right;

    Node(int key, Node *_parent = nullptr) : x(key), parent(_parent), right(nullptr), left(nullptr) {} 

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

    struct BSTiter 
    {
        BSTiter(Node *_current) : current(_current) {}

        int &operator*() const { return current->x; }
        Node* operator->() { return current; }

    private:
        Node *current;
    };

int main()
{
    Node tree(41);
    tree.insert(16);
    std::cout << tree.x << " " << (*tree.left).x;
    return 0;
}