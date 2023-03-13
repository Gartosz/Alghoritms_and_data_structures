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
        current_node = x < (*current_node)->x ? &((*current_node)->left) : &((*current_node)->right);
    }
    *current_node = new Node(x, *parent_node);
}

void inorder_do_rec(Node *t, void f(Node*))
{
    if (!t)
        return;
    inorder_do_rec(t->left, f);
    f(t);
    inorder_do_rec(t->right, f);
}

int main()
{
    Node *bst = new Node(30);
    insert(bst, 10);
    std::cout << bst->x << " " << bst->left->x << std::endl;
    int nodes[6] = {1, 5, 7, 24, 73, 39};
    for (int i = 0; i < sizeof(nodes)/sizeof(*nodes); ++i)
        insert(bst, nodes[i]);
    inorder_do_rec(bst, [](Node *t) {std::cout << t->x << std::endl;});
}