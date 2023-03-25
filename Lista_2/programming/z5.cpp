#include <iostream>
#include <stack>

template <typename key_type>
class Node
{
    public:
    key_type x;
    Node *left;
    Node *right;
    
    Node(key_type key) : x(key), right(nullptr), left(nullptr) {} 
    
    void insert(key_type x)
    {
        Node *parent_node = this;
        Node **current_node = &parent_node;
        while(*current_node)
            current_node = x < (*current_node)->x ? &((*current_node)->left) : &((*current_node)->right);
        *current_node = new Node(x);
    }

    struct BSTiter 
    {
        BSTiter(Node *current) : current_node(current) 
        {
            while (current_node && current_node->left)
            {
                stack.push(current_node);
                current_node = current_node->left;
            }
        }

        key_type &operator*() const { return current_node->x; }
        Node* operator->() { return current_node; }
        BSTiter& operator++() 
        {  
            if (current_node->right)
            {
                current_node = current_node->right;
                while (current_node->left)
                {
                    stack.push(current_node);
                    current_node = current_node->left;
                }
            }
            else
            {
                if (stack.empty())
                    current_node = nullptr;
                else
                {
                    current_node = stack.top();
                    stack.pop();
                }
            }
            return *this;
        }  

        bool operator!= (const BSTiter& second_iterator) { return current_node != second_iterator.current_node; };  

    private:
        Node *current_node;
        std::stack<Node*> stack;
    };

    BSTiter begin() 
    {   
        return BSTiter(this);
    }

    static BSTiter end()
    {
        return BSTiter(nullptr);
    }

};

int main()
{
    Node<float> tree(41);
    tree.insert(16);
    std::cout << tree.x << " " << (*tree.left).x << std::endl;
    float nodes[8] = {3, 4.5, 9, 56.31, 18, 37, 2.0, 1.2};
    for (int i = 0; i < sizeof(nodes)/sizeof(*nodes); ++i)
        tree.insert(nodes[i]);
    for (Node<float>::BSTiter i = tree.begin(); i != tree.end(); ++i)
        std::cout<< *i <<std::endl;   
    std::cout << std::endl;
    for (auto &node: tree)
        std::cout << node << std::endl;
    return 0;
}