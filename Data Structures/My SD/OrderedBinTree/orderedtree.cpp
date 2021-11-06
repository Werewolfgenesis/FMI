#ifndef __ORDEREDTREE_CPP
#define __ORDEREDTREE_CPP

#include "orderedtree.h"
#include <cassert>

////////////////////// helpers 
template <typename T>
typename OrderedTree<T>::Node* OrderedTree<T>::locate(const char* trace) const {
    OrderedTree<T>::Node* curr = root;

    while(trace[0] != 0) {
        assert(curr != nullptr);
        assert(trace[0] == 'L' || trace[0] == 'R');
        
        if (trace[0] == 'L') {
            curr = curr->left;
        } else {
            curr = curr->next;
        } 
        
        trace++;
    }

    assert (curr != nullptr);
    return curr;
}

template <typename T>
void OrderedTree<T>::toDottyHelper(std::ostream& out, Node* curr) {
    if (curr == nullptr) return;

    out << &curr << "[label=\"" << curr->data << "\"];\n";

    if (curr->left != nullptr) {
        out << &curr << "->" << &curr->left << "[color=red];\n";
    }

    if (curr->right != nullptr) {
        out << &curr << "->" << &curr->right << "\n";
    }

    toDottyHelper(out, curr->left);
    toDottyHelper(out, curr->right);
}

template <typename T>
void OrderedTree<T>::insertOrderedHelper(const T& x, Node*& curr) {
    if (curr == nullptr) {
        curr = new Node{x, nullptr, nullptr};
        return;
    }

    if (x < curr->data)
        insertOrderedHelper(x, curr->left);
    else 
        insertOrderedHelper(x, curr->right);
}

template <typename T>
void OrderedTree<T>::printLKD(Node* curr) const {
    if (curr == nullptr) return;

    printLKD(curr->left);
    std::cout << curr->data << " ";
    printLKD(curr->right);
}

//////////////////////////////

template <typename T>
OrderedTree<T>::OrderedTree():root(nullptr){}

template <typename T>
void OrderedTree<T>::insert (const T& x, const char* trace) {
    if (root == nullptr) {
        assert(trace[0] == 0);
        root = new Node{x, nullptr, nullptr};
        return;
    }

    assert (trace[0] != 0);

    OrderedTree<T>::Node* crr = root;

    while (trace[1] != 0) {
        assert(trace[0] == 'L' || trace[0] == 'R');

        if (trace[0] == 'L') 
            crr = crr->left;
        else 
            crr = crr->right;

        assert(crr!=nullptr);
        trace++;
    }
    
    if (trace[0] == 'L') {
        crr->left = new Node{x, nullptr,nullptr};
    } else if (trace[0] == 'R')
        crr->right = new Node{x,nullptr,nullptr};
    else 
        assert(false);
}

template <typename T>
T OrderedTree<T>::get (const char* path) const {
    OrderedTree<T>::Node* result = locate(path);
    assert(result != nullptr);
    return result->data;
}

template <typename T>
T& OrderedTree<T>::operator[](const char* trace) {
    OrderedTree<T>::Node* element = locate(trace);
    assert(element != nullptr);
    return element->data;
}

template <typename T>
void OrderedTree<T>::toDotty(std::ostream& out) {
    out << "digraph G{\n";
    toDottyHelper(out, root);
    out << "}";
}

template <typename T>
void OrderedTree<T>::insertOrdered(const T& x) {
    insertOrderedHelper(x, root);
}

template <typename T>
void OrderedTree<T>::print() const {
    printLKD(root);
}

#endif