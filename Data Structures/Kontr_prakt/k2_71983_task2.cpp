#include<iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cassert>
struct Node
{
    Node* prev, *next;
    std::string data;
};
void push_back(Node*& first, std::string elem)
{
    if (first == nullptr)
    {
        first = new Node{nullptr, nullptr, elem};
        return;
    }
    Node* current = first;
    while (current->next)
    {
        current = current->next;
    }
    current->next = new Node{current, nullptr, elem};
}
void print(Node*& first)
{
    if (first == nullptr)
    {
        std::cout << "null"; 
    }
    
    Node* current = first;
    while (current)
    {
        std::cout << current->data << "->";
        current = current->next;
    }
    std::cout << "nullptr";
}
void modify(Node*& first)
{
    while(first->next->data[0] == first->data[(strlen(first->data.c_str())) - 1])
    {
        Node* save = first->next;
                first->next->prev = nullptr;
                delete first;
                first = save;
    }
    
    Node* current = first->next;
    while (current->next)
    {
        if (current->next == nullptr && current->prev)//last elem
        {
            if ( current->prev->data[strlen(current->prev->data.c_str()) - 1] == current->data[0])
            {
                Node* save = current->prev;
                save->next = nullptr;
                delete current;
                current = save;
                return; //it is last elem, so we no longer need to iterate through the list
            }
        }
        if (current->prev->data[strlen(current->prev->data.c_str()) - 1] == current->data[0] && 
            current->next->data[0] == current->data[strlen(current->data.c_str()) - 1])
        {
            Node* save = current->prev;
            current->next->prev = current->prev;
            current->prev->next = current->next;
            delete current;
            current = save;
        }
        current = current->next;
    }
}
void testTask2()
{
    
    Node* str = new Node{nullptr, nullptr, "radar"};
    //push_back(str, "cat");
    push_back(str, "razer");
    push_back(str, "raper");
    push_back(str, "racer");
    //push_back(str, "lemon");

    modify(str);
    print(str);
}
int main()
{
    testTask2();
    return 0;
}