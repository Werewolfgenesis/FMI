#include <iostream>
#include <vector>

template<typename T>
struct Node
{
    T data;
    std::vector<Node<T>*> children;
};
template<typename T>
Node<T>* newNode(const T& elem)
{
    Node<T>* tmp = new Node<T>;
    tmp->data = elem;
    return tmp; 
}
template<typename T>
unsigned depth(Node<T>*& root)
{
    if(root == nullptr)
    {
        return 0;
    }
    unsigned max = 0;
    for(typename std::vector<Node<T>*>::iterator it = root->children.begin(); it != root->children.end(); ++it)
    {
        max = __max(max, depth(*it));
    }
    return max + 1;
}
int main()
{
    Node<int>* n = newNode(3);
    Node<int>* m = newNode(4);
    Node<int>* p = newNode(5);
    Node<int>* q = newNode(8);
    n->children.push_back(m);
    n->children.push_back(p);
    n->children[0]->children.push_back(q);
    std::cout << depth(n);
    return 0;
}