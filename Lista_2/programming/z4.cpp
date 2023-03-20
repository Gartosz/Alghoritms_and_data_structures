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

    struct BSTiter 
    {
        BSTiter(Node *current) : current_node(current) {}

        int &operator*() const { return current_node->x; }
        Node* operator->() { return current_node; }
        BSTiter& operator++() 
        {  
            if (current_node->right)
                current_node = current_node->right;
            else
            {
                Node *child = current_node;
                current_node = current_node->parent;
                while(current_node && (!current_node->right || current_node->right == child))
                {
                    if (current_node->right != child)
                        return *this;
                    child = current_node;
                    current_node = current_node->parent;
                }
                if (current_node)
                {
                    return *this;
                    current_node = !current_node->right || current_node->right == child ? current_node->parent : current_node->right;
                }
            }
            return *this;
        }  

        bool operator!= (const BSTiter& second_iterator) { return current_node != second_iterator.current_node; };  

    private:
        Node *current_node;
    };

    BSTiter begin() 
        {           
        Node *bst = this;
            while (bst->left) 
                bst = bst->left;
            return BSTiter(bst);
        }

        static BSTiter end()
        {
        return BSTiter(nullptr);
        }

    };

int main()
{
    Node tree(41);
    tree.insert(16);
    std::cout << tree.x << " " << (*tree.left).x << std::endl;
    int nodes[6] = {3, 4, 9, 56, 18, 37};
    for (int i = 0; i < sizeof(nodes)/sizeof(*nodes); ++i)
        tree.insert(nodes[i]);
    for (Node::BSTiter i = tree.begin(); i!=  tree.end(); ++i)
        std::cout<< *i <<std::endl;   
    for (auto &node: tree)
        std::cout << node << std::endl;
    return 0;
}