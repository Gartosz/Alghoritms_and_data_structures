struct Node
{
    int x; 
    Node *left; 
    Node *right; 
    Node *parent;

    Node(int key, Node *_parent = nullptr) : x(key), parent(_parent), right(nullptr), left(nullptr) {} 
};

int main()
{
    Node *bst = new Node(30);
}