#include "orderedtree.cpp"

int main() {
    OrderedTree<int> tree;
    tree.insertOrdered(15);
    tree.insertOrdered(7);
    tree.insertOrdered(143555);
    tree.insertOrdered(2);
    tree.insertOrdered(5);
    tree.insertOrdered(543534);

    tree.print();
    return 0;
}