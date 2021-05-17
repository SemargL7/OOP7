#include <iostream>

template <typename T>
class linked_ring
{
    struct node
    {
        T val;
        node* next;
    } *tail;
public:
    linked_ring() :tail(nullptr) {}

    void add_tail(T val)
    {
        if (!tail)
        {
            tail = new node{ val };
            tail->next = tail;
        }
        else
            tail->next = new node{ val, tail->next };
    }

    void delete_el_tail()
    {
        if (!tail) return;
        if (tail == tail->next)
        {
            delete[] tail;
            tail = nullptr;
            return;
        }
        node* to_del = tail->next;
        tail->next = to_del->next;
        delete[] to_del;
    }

    void clear()
    {
        while (tail) delete_el_tail();
    }

    bool empty() const
    {
        return tail;
    }

    ~linked_ring()
    {
        clear();
    }

    void print()
    {
        if (!tail)
        {
            std::cout << "empty\n";
            return;
        }
        node* current = tail->next;
        while (current != tail)
        {
            std::cout << current->val << ' ';
            current = current->next;
        }
        std::cout << tail->val << std::endl;
    }
    void FindBiggestElement()
    {
        if (!tail)
        {
            std::cout << "empty\n";
            return;
        }
        node* p = tail;
        T e = 0;
        while (p->next != tail)
        {
            if (e < p->val) e = p->val;
            p = p->next;
        }
        std::cout << "The Biggest element:" << e << std::endl;
    }

    void FindLowestElement()
    {
        if (!tail)
        {
            std::cout << "empty\n";
            return;
        }
        node* p = tail;
        T e = tail->val;
        while (p->next != tail)
        {
            if (e > p->val) e = p->val;
            p = p->next;
        }
        std::cout << "The Lowest element:" << e << std::endl;
    }
};

int main()
{
    int n = 0;
    bool type = true;
    std::cout << "How many elements do you want enter:";
    std::cin >> n;
    std::cout << "Type of tree(char - 0)(int - 1):";
    std::cin >> type;
    if(type == 0)
    {
        linked_ring<char> list;
        for(int i =0; i < n; i ++)
        {
            char e;
            std::cout << "[" << i + 1 << "]:";
            std::cin >> e;
            list.add_tail(e);
        }
        list.print();
        list.FindBiggestElement(); list.FindLowestElement();
        list.clear(); list.print();
    }
    else
    {
        linked_ring<int> list;
        for (int i = 0; i < n; i++)
        {
            int e;
            std::cout << "[" << i + 1 << "]:";
            std::cin >> e;
            list.add_tail(e);
        }
        list.print();
        list.FindBiggestElement(); list.FindLowestElement();
        list.clear(); list.print();
    }
}
