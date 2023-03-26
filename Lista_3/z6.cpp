#include <iostream>

class Node
{
    public:
    int x;
    int nL;
    Node *parent;
    Node *left;
    Node *right;
    
    Node(int key, Node *_parent = nullptr, int left_nodes = 0) : x(key), parent(_parent), right(nullptr), left(nullptr), nL(left_nodes) {} 
    
    void insert(int key)
    {
        if (x > key)
        {
            ++nL;
            if(left)
                left->insert(key);
                
            else
                left = new Node(key, this);;
        }
        else
        {
            if (right)
                right->insert(key);
            else
                right = new Node(key, this);
        }
    }
            }
            else if(right)
                right->insert(key);
        }
    }

};

int main ()
{
    Node tree(41);
    std::cout << tree.nL << " ";
    tree.insert(16);
    std::cout << tree.nL << "\n";
    int nodes[10] = {3, 4, 9, 56, 18, 37, 65, 58, 2, 1};
    for (int i = 0; i < sizeof(nodes)/sizeof(*nodes); ++i)
        tree.insert(nodes[i]);
}