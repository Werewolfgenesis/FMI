#include <iostream>
#include "Node.h"

template <typename T>
class DLlist
{
private:
    Node<T>* first;
    Node<T>* last;

    void copy(const DLlist<T>& other)
    {
        Node<T>* other_iter = other.first;
        this->first = new Node<T>(nullptr, nullptr, other.first->data);
        Node<T>* current = this->first;
        Node<T>* next_box = nullptr;
        while (other_iter->next != nullptr)
        {
            other_iter= other_iter->next;
            next_box = new Node<T>(current, nullptr, other_iter->data);
            current->next = next_box;
            current = current->next;
        }
    }
    void destroy()
    {
        Node<T>* current = this->first;
        while (current)
        {
            this->first = this->first->next;
            delete current;
            current = this->first;
        }
        
    }
public:
    DLlist()
    {
        this->first = nullptr;
        this->last = nullptr;
    }
    DLlist(const DLlist<T>& other)
    {
        this->copy(other);
    }
    DLlist<T>& operator=(const DLlist<T>& other)
    {
        if(this != &other)
        {
            this->destroy();
            this->copy(other);
        }  
    }
   
    ~DLlist()
    {
        this->destroy();
    }

    void push_back(const T& data)
    {
        if(this->first == nullptr)
        {
            this->first = new Node<T>(nullptr, nullptr, data);
            this->last = this->first;
            return;
        }
        Node<T>* new_box = new Node<T>(last, nullptr,data);
        this->last->next = new_box;
        this->last = new_box;
    }
    void push_front(const T& data)
    {
        if (this->first == nullptr)
        {
            this->first = new Node<T>(nullptr, nullptr, data);
            this->last = this->first;
            return;
        }
        Node<T>* new_box = new Node<T>(nullptr, this->first, data);
        this->first->prev = new_box;
        this->first = new_box;
    }
    void pop_back()
    {
        if(this->first == nullptr)
        {
            throw std::out_of_range("List is empty be tapak");
        }
        else if(this->first->next == nullptr)
        {
            delete this->first;
            this->first = nullptr;
            this->last = nullptr;
            return;
        }
        Node<T>* save = this->last->prev;
        delete this->last;
        this->last = save;
        this->last->next = nullptr;
    }

    void removeElement(Node<T>*& element){
        Node<T>* current = element;

        if(element){
            return;
        } 

        element->prev->next = element->next;
        if(!element->next)
        element->next->prev = element->prev;
        delete element;
        element = current->next;
    }

    unsigned int size()
    {
        Node<T>* current = this->first;
        unsigned int counter = 0;
        while (current)
        {
            counter += 1;
            current = current->next;
        }
        return counter;
    }
    void print()
    {
        Node<T>* current = this->first;
        while (current)
        {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }
    Node<T>* createList(size_t n)
    {
        int element = 0;
        Node<T>* current = this->first;
        while (element <= n)
        {
            current = new Node<T>(nullptr, nullptr, element);
            std::cout << "Kur";
            current = current->next;
            element += 1;
        }
        return this->first;
    }
    Node<T>* firstPtr()
    {
        return this->first;
    }
    //tasks from book
    //16.1
    size_t count(T elem)
    {
        Node<T>* current = this->first;
        size_t counter = 0;
        while (current)
        {
            if (current->data == elem)
            {
                counter += 1;
            }
            current = current->next;
        }
        return counter;
    }
    //16.2
    DLlist<T>* range(int x, int y)
    {
        DLlist<T> *list = new DLlist<T>();
        while (x <= y)
        {
            list->push_back(x);
            x+=1;
        }
        return list->firstPtr();
    }
    //16.3 -> remove all elems same as elem
    void removeAll(T elem)
    {
        Node<T>* current = this->first;
        while (current != nullptr)
        {
            if (current->data == elem)
            {
                if(current->prev == nullptr)
                {
                    Node<T>* save = current;
                    current = current->next;
                    current->prev = nullptr;
                    delete save;
                }
                else if(current->next == nullptr)
                {
                    current->prev->next = nullptr;
                    delete current;
                }
                else
                {
                    Node<T>* save = current;
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete save;
                }
            }
            current = current->next;
        }
    }
    //16.4 -> concatenates two lists
    void append(const DLlist<T>& other)
    {
        Node<T>* other_iter= other.first;
        while (other_iter)
        {
            this->push_back(other_iter->data);
            other_iter = other_iter->next;
        }
    }
    //16.8 - deleting an element
    void removeElem(size_t i)
    {
        size_t counter = 0;
        if (i < 0)
        {
            throw std::out_of_range("Negative index input be lud!");
        }
        Node<T> * cur = this->first;
        if(i == 0)
        {
            this->first = first->next;
            first->prev = nullptr;
            delete cur;
            return;       
        }
        while(cur != nullptr && i>0)
        {
            i--;
            cur=cur->next;
        }
        if(cur==nullptr && i)
        {
            throw std::out_of_range("Index out of bounds");
        }

        Node<T>* toDel = cur;

        (cur->prev)->next = cur->next;
        (cur->next)->prev = cur->prev;
        delete toDel;
        return ;//*this;
    }
    bool hasElem(Node<T>* start, T elem)
    {
        while (start)
        {
            if (start->data == elem)
            {
                return true;
            }
            start = start->next;
        }
        return false;
    }
    void sort()
    {
        Node<T>* current = first;
        T temp;
        if (current == nullptr)
        {
            return;
        }
        while (current)
        {
            Node<T>* index = current->next; 
            while (index)
            {
                if(current->data > index->data) {  
                    temp = current->data;  
                    current->data = index->data;  
                    index->data = temp;  
                }  
                index = index->next;
            }
            current = current->next;
        }
    }
    void removeDuplicates()
    {
        Node<T> * current = this->first;
        DLlist<T> newList;
        int counter = 0;
        while (current)
        {
            Node<T>* temp = current->next;
            while (temp)
            {
                this->removeAll(temp->data);
                temp = temp->next;
            }
            counter += 1;
            current = current->next;
        }
    }
    void reverse()
    {
        Node<T>* current = this->first;
        DLlist<T> newList;
        while (current)
        {
            newList.push_front(current->data);
            current = current->next;
        }
        this->destroy();
        this->copy(newList);
    }
   
};

//16.5 -> operator +=
template <typename T>
typename DLlist<T>::DLlist operator+=(DLlist<T> list1, const DLlist<T> list2)
{
    list1.append(list2);
    return list1;
}

//16.6 ->operator +
template<typename T>
typename DLlist<T>::DLlist operator+(const DLlist<T> list1, const DLlist<T> list2)
{
    DLlist<T> newList;
    newList.append(list1);
    newList.append(list2);
    return newList;
}
template<typename T>
void merge(DLlist<T>& list, DLlist<T>& list2)
{
    list.append(list2);
    list.sort();
}
template <typename T>
void makeProgression(Node<T>* current)
{
    T difference = current->next->data - current->data;
    while (current)
    {
        if(current->next->data != current->data + difference)
        {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            current->next->next->prev = current;
            delete temp;
        }
        current = current->next;
    }
}
template <typename T>
void removeAll(DLlist<T>& list, T x)
{
    Node<T>* current = list.firstPtr();
        while (current != nullptr)
        {
            if (current->data == x)
            {
                if(current->prev == nullptr)
                {
                    Node<T>* save = current;
                    current = current->next;
                    current->prev = nullptr;
                    delete save;
                }
                else if(current->next == nullptr)
                {
                    current->prev->next = nullptr;
                    delete current;
                }
                else
                {
                    Node<T>* save = current;
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete save;
                }
            }
            current = current->next;
        }
}
int main()
{
    DLlist<int> *list = new DLlist<int>();
    list->push_back(2);
    list->push_back(3);
    list->push_back(4);
    list->push_back(2);
    list->push_back(5);

    list->removeAll(2);
    list->print();
    return 0;
}


