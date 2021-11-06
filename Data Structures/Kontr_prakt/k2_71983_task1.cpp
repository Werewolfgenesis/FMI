#include <iostream>
#include <vector>

struct Node
{
    Node* left, *right;
    int data;
};
void add(Node*& root, const char* trace, const int& elem)
{
    if (root == nullptr)
    {
        root = new Node{nullptr, nullptr, elem};
        return;
    }
    Node* current = root;
    while (*trace)
    {
        if (*trace == 'L')
        {
            if (current->left == nullptr)
            {
                current->left = new Node{nullptr, nullptr, elem};
            }
            current = current->left;
        }
        else
        {
            if (current->right == nullptr)
            {
                current->right = new Node{nullptr, nullptr, elem};
            }
            current = current->right;
        }
        trace++;
    }
    
}
int helper(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return __max(1+helper(root->left), 1+helper(root->right));
}
int height(Node* root)
{
    return helper(root);
}
void helper2(Node* root, int lvl, std::vector<int>& res)
{
    if (root == nullptr)
    {
        return;
    }
    if (lvl == 1)
    {
        if (root->left)
        {
            res.push_back(root->left->data);
        }
        if (root->right)
        {
            res.push_back(root->right->data);
        }
    }
    helper2(root->left, lvl - 1, res);
    helper2(root->right, lvl - 1, res);
}
std::vector<int> create_vector_on_level(Node*& root, int lvl)
{
    std::vector<int> result;
    helper2(root, lvl, result);
    return result;
}
std::vector<int> create_vector_on_max_level(Node*& root)//max_level = height
{
    std::vector<int> result;
    result = create_vector_on_level(root, height(root) - 1);
    return result;
}
void testTask1()
{
    Node* tree = new Node{nullptr, nullptr, 1};
    add(tree, "R" , 3);
    add(tree, "L" , 2);
    add(tree, "LR" , 5);
    add(tree, "LL" , 4);
    add(tree, "RL" , 6);
    add(tree, "RR" , 7);
    add(tree, "RLR" , 8);

    std::vector<int> res;
    res = create_vector_on_max_level(tree);
    for (size_t i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << " ";
    }
}
int main()
{      
    testTask1();
    return 0;
}