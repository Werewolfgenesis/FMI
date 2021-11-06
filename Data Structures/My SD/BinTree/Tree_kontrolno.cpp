#include <iostream>
#include <vector>
struct Node
{
    Node *right, *left;
    int data;
};
void add(Node*& root, const char * trace, const int& elem)
{
    if(root == nullptr)
    {
        root = new Node{nullptr, nullptr, elem};
        return;
    }
    Node* curr = root;
    while (*trace)
    {
        if (*trace == 'L')
        {
            if (curr->left == nullptr)
            {
                curr->left = new Node{nullptr, nullptr, elem};
            }
            curr = curr->left;
        }
        else
        {
            if(curr->right == nullptr)
            {
                curr->right = new Node{nullptr, nullptr, elem};
            }
            curr = curr->right;
        }
        trace++;
    }
}
void helper(Node* root, int lvl, std::vector<int>& v)
{
    if (root == nullptr)
    {
        return;
    }
    if (lvl == 1)
    {
        if (root->left)
        {
            v.push_back(root->left->data);
        }
        if (root->right)
        {
            v.push_back(root->right->data);
        }
    }
    helper(root->left, lvl - 1, v);
    helper(root->right, lvl - 1, v);

}
 std::vector<int> elems_on_level(Node* root, int lvl)
{
    std::vector<int> v;
    helper(root, lvl, v);
    return v;
}
int main()
{
    Node* tree = new Node{nullptr, nullptr, 1};
    add(tree, "L", 2);
    add(tree, "LL", 3);
    add(tree, "R", 1);
    add(tree, "RR", 8);
    add(tree, "RL", 9);

    std::vector<int> m;
    m = elems_on_level(tree, 2);
    for (size_t i = 0; i < m.size(); i++)
    {
        std::cout << m[i];
    }
    
    return 0;
}