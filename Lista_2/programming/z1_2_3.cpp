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

void remove(Node *&t, int x)
{
    Node **current_node = &t;
    while(*current_node && (*current_node)->x != x)
        current_node = x < (*current_node)->x ? &((*current_node)->left) : &((*current_node)->right);
    if (*current_node)
    {
        if ((*current_node)->left && (*current_node)->right)
        {
            Node *replacement_node = (*current_node)->right;
            while(replacement_node->left)
                replacement_node = replacement_node->left;
            (*current_node)->x = replacement_node->x;
            current_node = &replacement_node;
        }
        
        Node *child_node = (*current_node)->right ? (*current_node)->right : (*current_node)->left;
        if (child_node)
            child_node->parent = (*current_node)->parent;
        delete *current_node;
        *current_node = child_node;
    }
    else
        std::cout << "Key not found.\n";
}

void inorder_do_rec(Node *t, void f(Node*))
{
    if (!t)
        return;
    inorder_do_rec(t->left, f);
    f(t);
    inorder_do_rec(t->right, f);
}

void inorder_do(Node *t, void f(Node*))
{
    Node *current_node = t;
    
    while(current_node)
    {
        while (current_node->left) 
            current_node = current_node->left;
        f(current_node);
        if (current_node->right)
            current_node = current_node->right;
        else
        {
            Node *child = current_node;
            current_node = current_node->parent;
            while(current_node && (!current_node->right || current_node->right == child))
            {
                if (current_node->right != child)
                    f(current_node);
                child = current_node;
                current_node = current_node->parent;
            }
            if (current_node)
            {
                f(current_node);
                current_node = !current_node->right || current_node->right == child ? current_node->parent : current_node->right;
            }
        }
    }
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
    remove(bst, 24);
    inorder_do_rec(bst, [](Node *t) {std::cout << t->x << std::endl;});
    remove(bst, 24);
    // remove(bst, 10);
    inorder_do(bst, [](Node *t) {std::cout << t->x << std::endl;});
}