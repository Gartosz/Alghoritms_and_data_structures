struct node
{
    int x; 
    node *left; 
    node *right; 
    node *parent;

    node(int key, node *_parent = nullptr) : x(key), parent(_parent), right(nullptr), left(nullptr) {} 
};
