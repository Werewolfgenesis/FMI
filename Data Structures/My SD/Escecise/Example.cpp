#include <iostream>
#include <functional>
#include <stack>


//task 1
template <typename T>
struct Node{
    Node* next;
    T data;
};
template <typename T>
int average(Node<std::stack<T>>* list)
{
    Node<std::stack<T>>* cur = list;
    int nrNodes = 0;
    int nrEls = 0;
    while (cur)
    {
        while (!(cur->data.empty()))
        {
            nrEls += 1;
            cur->data.pop();
        }
        cur = cur -> next;
        nrNodes += 1;
    }
    return nrEls / nrNodes;
}
template<typename T>
int count(std::stack<T> stack)
{
    int counter = 0;
    while (!stack.empty())
    {
        counter += 1;
        stack.pop();
    }
    return counter;
}
/*
template<typename T>
Node<std::stack<T>>* equalise(Node<std::stack<T>>*& list)
{
    Node<std::stack<T>>* cur = list;
    Node<std::stack<T>>* save = list;
    int cnt = average(list);
    while (cur->next)
    {
        if (count(cur->data) > cnt)
        {
            while (count(cur->data) >= cnt)
            {
                if (!cur->next )
                {
                    cur->next = save;
                }
                
                cur->next->data.push(cur->data.top());
                cur->data.pop();
            }
        }
        cur = cur->next;
    }
    while (count(cur->next->data) == cnt)
    {
        cur->next->data.push(cur->data.top());
        cur->data.pop();
    }
}
*/
template<typename T>
Node<std::stack<T>>* equaliseVesko(Node<std::stack<T>>*& vesko)
{
    int cnt = average(vesko);
    Node<std::stack<T>>* cur = vesko, *save = nullptr;
    while (cur->next)
    {
        if(cur->data.size() == cnt)
        {
            cur = cur->next;
            continue;
        }
        save = cur->next;
        while(save)
        {
            if (save->data.size() == cnt)
            {
                save = save->next;
                continue;
            }
            while (save->data.size() != cnt && save->data.size() != cnt + 1)
            {
                if (cur->data.size() == cnt)
                {
                    break;
                }
                save->data.push(cur->data.top());
                cur->data.pop();
            }
            
            save = save->next;
        }
        cur = cur->next;
    }
}






int multiply(const int& x1, const int& x2)
{
    return x1*x2;
}
template<typename T>
T reduce(Node<T>*& list, std::function<T (const T&, const T&)> f)
{
    if(list == nullptr)
    {
        throw std::out_of_range("saf");
    }
    else if(list->next == nullptr)
    {
        return list->data;
    }
    T res = f(list->data, list->next->data);
    list = list->next->next;
    while (list)
    {
        res = f(res, list->data);
        list = list->next;
    }
    return res;
}

template<typename T>
struct NodeT{
    T data;
    NodeT* next, *prev;
};
void print(NodeT<int>* list)
{
    NodeT<int>* cur = list;
    while (cur)
    {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}
void reverse(NodeT<int>*& list)
{
    NodeT<int>* temp = nullptr, *cur = list;
    while (cur)
    {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;

        cur = cur->prev;
    }
    if(temp)
    {
        list = temp->prev;
    }
}


//task 3
size_t count(NodeT<int>*& first)
{
    size_t counter = 0;
    NodeT<int>* cur = first;
    while (cur)
    {
        counter += 1;
        cur = cur->next;
    }
    return counter;
}
void shuffle(NodeT<int>*& list)
{
    NodeT<int>* cur = list;
    int temp = count(list);
    if(temp % 2 == 1)
    {
        for(int i = 0; i < temp/2+1; i++)
        {
            cur= cur->next;
        }
        
    }
    else
    {
        for(int i = 0; i < temp/2;i++)
        {
            cur= cur->next;
        }
    }

    NodeT<int>* sec = cur->prev;
    sec->next = nullptr;
    cur->prev = nullptr;
    reverse(cur);

    sec = cur;
    while (sec->next)
    {
        sec = sec->next;
    }
    sec->next = list;
    list = cur;
}


//////////////////////////////
//////////EXAM 2018//////////
/////////////////////////////

//TASK 0
//crate  a list

struct NodeL{
    int data;
    NodeL* next, *nextEven;
};

void push_front(NodeL*& list, const int& el)
{
    if (list == nullptr)
    {
        list = new NodeL{el, nullptr, nullptr};
        return;
    }
    if (list->next)
    {
        NodeL* newB = new NodeL{el, list, list->next};
        list = newB;
        return;
    }
    else
    {
        NodeL* newB = new NodeL{el, list, nullptr};
        list = newB;
        return;
    }
}
NodeL* createList(size_t size)
{
    int value = size;
    NodeL* newL = nullptr;
    while (size)
    {
        push_front(newL, value);
        size-= 1;
        value -= 1;
    }
    return newL;
}
void print(NodeL* list)
{
    NodeL* cur = list;
    while (cur)
    {
        std::cout << cur->data << " ";
        cur = cur->next; 
    }
    std::cout << std::endl;
}
template<typename T>
void push_back(NodeT<T>*& first, const T& el)
{
    if (first == nullptr)
    {
        first = new NodeT<T>{el, nullptr, nullptr};
        return;
    }
    NodeT<T>* cur = first;
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = new NodeT<T>{el, nullptr, cur};
    return;
}


void test()
{
    NodeL* m = createList(5);
    NodeT<int>* n = nullptr;
    push_back(n, 1);
    push_back(n, 2);
    push_back(n, 3);
    push_back(n, 4);
    push_back(n, 5);
    
}




































void test1()
{
    NodeT<int>* l1 = nullptr;
    push_back(l1, 2);
    push_back(l1, 8);
    push_back(l1, 4);
    push_back(l1, 11);
    push_back(l1, 1);
    print(l1);
    shuffle(l1);
    print(l1);
   // std::cout << reduce<int>(l1, multiply);

}
int main()
{
    test();
    return 0;
}