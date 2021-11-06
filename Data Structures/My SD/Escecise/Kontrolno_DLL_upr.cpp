#include <iostream>
/*
struct Node
{
    
    int data;
    Node* prev, *next;

    Node(int data, Node* prev, Node* next)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};
void push_back(Node*& list,const int& el)
{
    if (list == nullptr)
    {
        list = new Node{el, nullptr, nullptr};
        return;
    }
    Node* current = list;
    while (current->next)
    {
        current = current->next;
    }
    current->next = new Node{el,current, nullptr};
}
void push_front(Node*& list, const int& el)
{
    if (list == nullptr)
    {
        list = new Node{el, nullptr, nullptr};
        return;
    }
    Node* newB = new Node{el,nullptr, list};
    list->prev = newB;
    list = newB;
    return;
}
void sort(Node*& list)
{
    int temp;
    while (list)
    {
        Node* save = list->next;
        while (save)
        {
            if (save->data < list->data)
            {
                temp = list->data;
                list->data = save->data;
                save->data = temp;
            }
            save = save->next;
        }
        list = list->next;
    }
}


void removeElPos(Node*& list, size_t pos)
{
    Node* current = list;
    if (pos < 0)
    {
        throw std::out_of_range("Kakva e taq posiciq e manqk");
    }
    
    if (pos == 0)
    {
        list = list->next;
        list->prev = nullptr;
        delete current;
        return;
    }
    
    while (current && pos)
    {
        current = current->next;
        pos -= 1;
    }
    if (current->next == nullptr && pos == 0)
    {
        current->prev->next = nullptr;
        delete current;
        return;
    }
    
    if (pos == 0)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
    else
    {
        throw std::out_of_range("Kakva e taq posiciq e manqk");
    }
}
bool hasElems(Node*& list, int elem)
{
    Node* current = list;
    while (current)
    {
        
        if (current->data == elem)
        {
            
            return true;
        }
        current = current->next;
    }
    return false;
}
void print(Node*& list)
{
    Node* current = list;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
void removeAll(Node*& list, const int& elem)
{
    Node* current = list;
    Node* newL = nullptr;
    while (current)
    {
        if (current->data != elem)
        {
            push_back(newL, current->data);
        }
        current = current->next;
    }
    delete list;
    list = newL;
}
void removeDuplicates(Node*& list)
{
    Node* newL = nullptr;
    while (list)
    {
        if (!hasElems(newL, list->data) && !hasElems(list->next, list->data))
        {
            push_back(newL, list->data);
        }
        list = list->next;
    }
    delete list;
    list = newL;
}
void removeDup(Node*& list)//not workin
{
    while (list)
    {
        Node* current = list;
        while (current)
        {
            if (current->data == list->data)
            {
                removeAll(list, current->data);
            }
            current = current->next;
        } 
        list = list->next;
    }
    
}
Node* append(Node*& list, Node* clist)
{
    while (clist)
    {
        push_back(list, clist->data);
        clist = clist->next;
    } 
    return list;
}

bool areSame(Node*& l1, Node*& l2)
{
    while (l1 && l2)
    {
        if (l1->data != l2->data)
        {
            return false;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return true;
}
//check if a list is a palindrome
bool is_palindrome(Node*& list)
{
    Node* current = list;
    Node* newL = nullptr;
    while(current)
    {
        push_front(newL, current->data);
        current = current->next;
    }
    return areSame(list, newL);
}
//sort 2 lists together 
Node* sort_list(Node*& l1, Node*& l2)
{
    Node* newL = append(l1, l2);
    Node* current = newL;
    int tempor;
    while (current)
    {
        Node* temp = current->next;
        while (temp)
        {
            if (current->data > temp->data)
            {
                tempor = current->data;
                current->data = temp->data;
                temp->data = tempor;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return newL;
}

/////////////////////////////
//DATA STRUCTURES EXAM 2018//
////////////////////////////

//reverse first n elements of a list
void reverseBy(Node*& list, size_t pos)
{
    Node* current = list;
    Node* newL = nullptr;
    if(pos == 0)
    {
        return;
    }
    while (current && pos)
    {
       push_front(newL, current->data);
       current = current->next;
       pos -= 1;
        
    }
    while (current)
    {
        push_back(newL, current->data);
        current = current->next;
    }
    
    delete list;
    list = newL;
}
//create a list with nr elements with values 0..nr
Node* createList(size_t nr)
{
    int element = 0;
    Node* list = nullptr;
    while (nr)
    {
        push_back(list, element);
        element += 1;
        nr -= 1;
    }
    return list;
}
//modify a list so that its elements are in arithmetical progression with each other
void makePr(Node*& list)
{
    Node*current = list;
    int counter = 0;
    int diff = list->next->data - list->data;
    std::cout << diff << std::endl;
    while (list->next)
    {
        if (list->next->data != list->data + diff)
        {
           removeElPos(list, counter );
        }
        counter += 1;
        list = list->next;
    }
    list = current;
}*/
struct Node
{
    int data;
    Node* next;
};

Node* range(Node*& fst)
{
    if (!fst->next)
    {
        return nullptr;
    }
    Node* current = fst;
    while (current->next)
    {
        if (current->next->data - current->data != 1)
        {
            Node* newB = new Node{current->data + 1,  current->next};
            current->next = newB;
        }
        current = current->next;
    }
    current = fst;
    return current;
}
void push_back(Node*& list,const int& el)
{
    if (list == nullptr)
    {
        list = new Node{el, nullptr};
        return;
    }
    Node* current = list;
    while (current->next)
    {
        current = current->next;
    }
    current->next = new Node{el, nullptr};
}
void print(Node*& list)
{
    Node* current = list;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
int main()
{
    Node *list = new Node{1,nullptr};
    push_back(list, 3);
    push_back(list, 4);
    push_back(list, 8);
    Node* newL = range(list);
    print(list);
    

    
    //std::cout << std::boolalpha << is_palindrome(list);
    return 0;
}