#include <iostream>

struct Node
{
    int data;
    Node* right;
    Node* left;

    Node(int _data, Node* _right, Node* _left)
    {
        this->data = _data;
        this->right = _right;
        this->left = _left;
    }
};
int sumParentsHelper(Node* current, int x)
{
    if (current == nullptr)
    {
        return 0;
    }
    if ((current->left && current->left->data == x) || (current->right && current->right->data == x))
    {
        return current->data + sumParentsHelper(current->right, x) + sumParentsHelper(current->left, x);
    }
    return 0 + sumParentsHelper(current->right, x) + sumParentsHelper(current->left, x);
}
bool fullBinaryH(Node*root)
{
    if (root == nullptr)
    {
        /* code */
        return true;
    }
    if (!root->left && !root->right)
    {
        /* code */
        return true;
    }
    if (root->right && root->left)
    {
        /* code */
        return fullBinaryH(root->right) && fullBinaryH(root->left);
    }
    return false;
}
bool isMirrorH(Node* root)
{
    if(root == nullptr)
    {
        return true;
    }
    if (!root->right && !root->right)
    {
        return true;
    }
    if (root->right && !root->left)
    {
        return false;
    }
    if (root->left && !root->right)
    {
        return false;
    }
    return (root->left->data == root->right->data) && 
    isMirrorH(root->right) && 
    isMirrorH(root->left);
}
bool isBSTH(Node* root)
{
    if(root == nullptr)
    {
        return true;
    }
    if (root->right && !root->left)
    {
        return false;
    }
    if (root->left && !root->right)
    {
        /* code */
        return false;
    }
    
    return root->data <= root->left->data &&
    root->data > root->right->data &&
    isBSTH(root->right) &&
    isBSTH(root->left);
    
}






//TASK4
bool isBST(Node* root)
{
    return isBSTH(root);
}
//task3
bool isMirror(Node* root)
{
    return isMirrorH(root);
}
//task2
int sumParents(Node* root, int x)
{
    return sumParentsHelper(root, x);
}
//task1
bool fullBinary(Node*root)
{
    return fullBinaryH(root);
}

///////////////////
//////PRINT///////
/////////////////
void print(Node* root)
{
    if (root == nullptr)
    {
        std::cout << "() ";
        return;
    }
    std::cout << root->data << " ";
    print(root->left);
    print(root->right);
    
}
int main()
{
    Node* tree = new Node{5, 
                            new Node{2,nullptr, nullptr},
                            new Node{6,nullptr, nullptr}};
    print(tree);
    std::cout << std::endl;
    std::cout << sumParents(tree, 3) << std::endl;
    std::cout << fullBinary(tree) << std::endl;
    std::cout << isMirror(tree) << std::endl;
    std::cout << isBST(tree) << std::endl;
}