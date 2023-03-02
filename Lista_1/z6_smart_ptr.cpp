#include <iostream>
#include <vector>
#include <memory>

class lnode
{ 
    public:
    int key = 0;
    std::shared_ptr<lnode> next = nullptr;
    std::shared_ptr<lnode> last = nullptr;
    lnode(int k = 0, std::shared_ptr<lnode> n=nullptr):key(k),next(n), last(n){}
    lnode(std::vector<int> list)
    {
        if (list.empty())
            std::logic_error("Vector cannot be empty.");
        key = list[0];
        for (auto element = list.begin() + 1; element < list.end(); ++element)
        {
            back_insert(*element);
        }
    }


    void wypisz ()
    {
        std::cout << "[ " << key << ", ";
        std::shared_ptr<lnode> list_element = next;
        while (list_element->next != nullptr)
        {
            std::cout << list_element->key << ", "; 
            list_element = list_element->next;
        }
        if (next != nullptr)
            std::cout << list_element->key;
        std::cout << " ]";
    }

    int nty(int n)
    {
        std::shared_ptr head = next;
        for (int i = 1; i < n; ++i)
        {
            if (head->next == nullptr)
                return 0;
            else
                head = head->next;
        }
        return n == 0 ? key : ((head == nullptr) ? 0 : head->key);
    }

    void back_insert(int x)
    {
        if (next != nullptr)
        {
            last->next = std::make_shared<lnode>(x);
            last = last->next;
        }
        else
        {
            next = std::make_shared<lnode>(x);
            last = next;
        }
    }

    void insert(int x)
    {
        next = std::make_shared<lnode>(key, next);
        key = x;
    }

    int suma ()
    {
        int sum = key;
        std::shared_ptr<lnode> list_element = next;
        while (list_element->next != nullptr)
        {
            sum += list_element->key;
            list_element = list_element->next;
        }
        sum += list_element->key;
        return sum;
    }

};

int main()
{
    lnode test_list(std::vector<int>{10, 2,4,5,9});
    test_list.wypisz();
    std::cout << std::endl << test_list.suma() << std::endl;
    test_list.insert(11);
    test_list.wypisz();
    std::cout << std::endl << test_list.nty(3) << std::endl;
}