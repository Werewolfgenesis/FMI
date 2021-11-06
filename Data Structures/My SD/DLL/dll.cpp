#include <iostream>
#include <cassert>

template<typename T>
struct Node
{
    Node* prev, *next;
    T data;

    Node(Node* prev, Node* next, T data)
    {
        this->prev = prev;
        this->next = next;
        this->data = data;
    }
};
template<typename T>
void push_back(Node<T>*& first, const T& elem)
{
    if (first == nullptr)
    {
        first = new Node<T>{nullptr, nullptr, elem};
        return;
    }
    Node<T>* curr = first;
    while (curr->next)
    {
        curr = curr->next;
    }
    Node<T>* toAdd = new Node<T>{curr,nullptr, elem};
    curr->next = toAdd;
}
template<typename T>
void print(Node<T>* first)
{
    Node<T>* current = first;
    while (current)
    {
        std::cout << current->data << "->";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}
template<typename T>
void makeProgression(Node<T>* first)
{
    if (first == nullptr)
    {
        return;
    }
    int difference = 0;
    if (first && first->next)
    {
        difference += first->next->data - first->data;
    }
    Node<T>* curr = first;
    while (curr->next)
    {
        if (curr->next->data - curr->data != difference)
        {
            Node<T>* toAdd = new Node<T>(curr, curr->next, curr->data + difference);
            curr->next->prev = toAdd;
            curr->next = toAdd;
        }
        curr = curr->next;
    }
}
template<typename T>
void swap(Node<T>*& first, Node<T>*& second)
{
    T temp = first->data;
    first->data = second->data;
    second->data = temp;
}
template<typename T>
Node<T>* last(Node<T>* first)
{
    if (!first)
    {
        return nullptr;
    }
    
    Node<T>* temp = first;
    if (temp && !temp->next)
    {
        return temp;
    }
    
    while (temp->next)
    {
        temp = temp->next;
    }
    return temp;
} 
template<typename T>
void reverse(Node<T>*&first)
{
    if (first == nullptr)
    {
        return;
    }
    Node<T>* current = first;
    Node<T>* temp = last(first);
    while (current != temp && current->prev != temp)
    {
        swap(current, temp);
        temp = temp->prev;
        current = current->next;
    }
}
template<typename T>
void removeFirstDuplicate(Node<T>*& first)
{
    if (!first && !first->next && !first->next->next)
    {
        return;
    }
    Node<T>* curr = first;
    while (curr->next->next)
    {
        if (curr->data == curr->next->data && curr->data == curr->next->next->data)
        {
            Node<T>* save = curr->prev;
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
            delete curr;
            curr = save;
        }
        curr = curr->next;
    }   
}
template<typename T>
void removeAllDuplicates(Node<T>*& first)
{
    Node<T>* temp = first;
    while (temp)
    {
        Node<T>* iter = temp->next;
        while (iter)
        {
            if (iter->data == temp->data)
            {
                Node<T>* prev = iter->prev;
                prev->next = iter->next;
                iter->next->prev = prev;
                delete[] iter;
                iter = prev;
            }
            iter = iter->next;
        }
        temp = temp->next;
    }
}
template<typename T>
void modify(Node<T>* first, Node<T>* second)
{
    while (first->next)
    {
        first = first->next;
    }
    first->next = new Node<T>(last(first), second, '#');
}
template<typename T>
T sum(Node<T>*& first)
{
    Node<T>* current = first;
    T sum = 0; 
    while (current->next)
    {
        sum += current->data;
        current = current->next;
    }
    return sum;
}
template<typename T>
void sumAndReverse(Node<T>*& first)
{
    push_back(first, sum(first));
    reverse(first);
}
template<typename T>
void removeAll(Node<T>*& first, const T& elem)
{
    Node<T>* current = first;
    while (current)
    {
        if (current->data == elem)
        {
            Node<T>* save = current->prev;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            current = save;
        }
        current = current->next;
    }
}
template<typename T>
void removeOnPos(Node<T>*& first, unsigned int index)
{
    unsigned counter = 0;
    Node<T>* current = first;
    if (first && !first->next && index == 0)
    {
        delete first;
        return;
    }
    if (index == 0)
    {
        Node<T>* save = first;
        first = first->next;
        first->prev = nullptr;
        delete save;
    }
    while (current)
    {
        if (counter == index)
        {
            Node<T>* save = current->prev;
            current->next->prev = current->prev;
            current->prev->next = current->next;
            delete current;
            current = save;
            return;
        }
        current = current->next;
        counter += 1;
    }
    
}
int main()
{
    Node<int>* f = new Node<int>(nullptr, nullptr, 1);
    push_back(f, 3);
    push_back(f, 8);
    push_back(f, 10);
    //push_back(f, 'O');

    Node<char>* g = new Node<char>(nullptr, nullptr, 'M');
    push_back(g, 'I');
    push_back(g, 'T');
    push_back(g, 'A');
    push_back(g, 'K');
    //print(f);
    //print(g);
    
    makeProgression(f);
    print(f);
    //reverse(f);
    //removeFirstDuplicate(f);
   // modify(f,g);
 ;
    // sumAndReverse(h);
    // print(h);

        //removeOnPos(h, 2);
    //print(h);
    
    return 0;
}