#ifndef __ORDEREDTREE_H
#define __ORDEREDTREE_H

#include <iostream>

template <typename T>
class OrderedTree {
public:
    OrderedTree();

    void insert (const T&, const char*);
    T get (const char*) const;
    void toDotty(std::ostream&);
    T& operator[](const char*);

    void insertOrdered(const T& x);
    void print() const;
private:
    struct Node {
        T data;
        Node* left, *right;
    };

    void toDottyHelper(std::ostream&, Node*);
    void insertOrderedHelper(const T& x, Node*&);
    Node* locate(const char*) const;
    void printLKD(Node*) const;

    Node* root;
};

#endif  