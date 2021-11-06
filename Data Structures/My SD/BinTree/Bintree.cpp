#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
template <typename T>
class Bintree
{
private:
    struct Node
    {
        T data;
        Node* right;
        Node* left;

        Node(T data, Node* right, Node* left)
        {
            this->data = data;
            this->right = right;
            this->left = left;
        }
    };

    Node* root;
public:
    Bintree()
    {
        this->root = nullptr;
    }
    void add(const T& x, const char* trace)
    {
        if (this->root == nullptr)
        {
            this->root = new Node(x, nullptr, nullptr);
            return;
        }
        else
        {
            Node* current = this->root;

            while (*trace != '\0')
            {
                if (*trace == 'L')
                {
                    if (current->left == nullptr)
                    {
                        current->left = new Node(x,nullptr,nullptr);
                    }
                     current = current->left;
                }
                else
                {
                    if (current->right == nullptr)
                    {
                        current->right = new Node(x,nullptr,nullptr);
                    }
                    
                    current = current->right;
                }
                trace++;
            }
        }
    }

    
    bool isMember(const T& x)
    {
        return isMemberHelper(x,root);
    }
    bool isMemberHelper(const T& x, Node* curr)
    {
        if (curr == nullptr)
        {
            return false;
        }
        return x == curr->data ||
               isMemberHelper(x, curr->right) ||
               isMemberHelper(x, curr->left);
    }
    int sum()
    {
        return sumHelper(root);
    }
    int sumHelper(Node* curr)
    {
        if (curr == nullptr)
        {
            return 0;
        }
        else
        {
            return curr->data + sumHelper(curr->right) + sumHelper(curr->left);
        }
    }
    //19.1 - nr of all elems in a tree
    int nrElems()
    {
        return nrElemsHelper(root);
    }
    int nrElemsHelper(Node* curr)
    {
        if(curr == nullptr)
        {
            return 0;
        }
        return 1 + nrElemsHelper(curr->right) + nrElemsHelper(curr->left);
    }
    //19.2 - nr of even elements in a tree
    int nrEvens()
    {
        return nrEvensHelper(root);
    }
    int nrEvensHelper(Node* curr)
    {
        if (curr == nullptr)
        {
            return 0;
        }
        else if (curr->data % 2 == 0)
        {
            return 1 + nrEvensHelper(curr->right) + nrEvensHelper(curr->left);
        }
        else
        {
            return nrEvensHelper(curr->right) + nrEvensHelper(curr->left);
        }
    }
    //19.4 - nr of levels
    int height()
    {
        return heightHelper(root);
    }
    int heightHelper(Node* current)
    {
        if(current == nullptr)
        {
            return 1;
        }
        return __max((1+heightHelper(current->right)),((1+heightHelper(current->right))));
    }
    //19.5 - nr of leaves
    int countLeaves()
    {
        return countLeavesHelper(root);
    }
    int countLeavesHelper(Node* current)
    {
        if(current == nullptr)
        {
            return 0;
        }
        else if (current->right == nullptr && current->left == nullptr)
        {
            return 1 + countLeavesHelper(current->right) + countLeavesHelper(current->left);
        }
        else
        {
            return countLeavesHelper(current->right) + countLeavesHelper(current->left);
        }
    }
    //19.6 - leaf with biggest value
    int maxLeaf()
    {
        return maxLeafHelper(root);
    }
    int max = 0;
    int maxLeafHelper(Node* current)
    {
        if(current == nullptr)
        {
            return max;
        }
        else if (current->right == nullptr && current->left == nullptr)//isLeaf
        {
            if (current->data >= max)
            {
                max = current->data;
            }
        }
        maxLeafHelper(current->right);
        maxLeafHelper(current->left);
    }
    void print()
    {
        printHelper(root);
    }
    void printHelper(Node *current)
    {
        if (current == nullptr)
        {
            std::cout << "()";
            return;
        }
        std::cout << '(' << current->data << " ";
        printHelper(current->left);
        std::cout << " ";
        printHelper(current->right);
        std::cout << ")" << std::endl;
    }
    //task to add a number to each element of binary tree
    void increment_by(int nr)
    {
        increment_by_helper(nr, root);
    }
    void increment_by_helper(int nr, Node* current)
    {
        if (current == nullptr)
        {
            return;
        }
        current->data += nr;
        increment_by_helper(nr,current->right);
        increment_by_helper(nr,current->left);
    }
    //func to check whether the tree is a mirror tree
    bool is_mirror()
    {
        return is_mirror_helper(root);
    }
    bool is_mirror_helper(Node* current)
    {
        if(current == nullptr)
        {
            return true;
        }
        if (current->left == nullptr && current->right == nullptr)
        {
            return true;
        }
        if(current->left == nullptr || current->right == nullptr)
        {
            return false;
        }
        return  current->left->data == current->right->data && 
                is_mirror_helper(current->right) &&
                is_mirror_helper(current->left);
    }
    //FUNC TO chck whether a tree on a given level is a palindrome - todo
    bool is_palindrome(int level)
    {
        is_palindrome_helper(root, level);
        return pal(my);
    }
    std::vector<int> my;
    bool pal(std::vector<int> x)
    {
        std::vector<int> n;
        for (size_t i = my.size() - 1; i >= 0; i--)
        {
            n.push_back(my[i]);
        }
        return n == x;
    }
    void is_palindrome_helper(Node* current, size_t level)
    {
        if (level == 0 && current == nullptr)
        {
            return;
        }
        if (level == 0 && current != nullptr)
        {
            my.push_back(current->data);
            std::cout << "kur" << std::endl;
        }
        
        is_palindrome_helper(current->left, --level);
        is_palindrome_helper(current->right, --level);
    }
    
    //todo
    bool isBST()
    {
        return isBST_helper(root,INT_MAX, INT_MIN);
    }
    bool isBST_helper(Node* curr, int max, int min)
    {
        if(curr == nullptr)
        {
            return true;
        }
        if (curr->data < min || curr->data > max)
        {
            return false;
         }
    return isBST_helper(curr->left, min, curr->data) &&
           isBST_helper(curr->right, curr->data, max);
         }
};
int main()
{
    Bintree<int> *tree= new Bintree<int>();
    tree->add(3,"");
    tree->add(2,"L");
    tree->add(2, "R");  
    tree->add(1, "LL");
    std::cout << tree->is_palindrome(1);
        //tree->print();  
    //std::cout << tree->countLeaves();//2
    //std::cout << tree->is_mirror(); //0
    //std::cout << tree->isBST() << std::endl;//1
    /*tree->add(2, "LL");
    tree->add(2, "R");
    tree->add(2, "RL");
    tree->add(2, "RR");
    tree->add(2, "RRL");*/

    /*std::cout << tree->isMember(3) << std::endl;//1
    std::cout << tree->nrElems() << std::endl;//8
    std::cout << tree->sum() << std::endl;//22
    std::cout << tree->nrEvens() << std::endl;//6
    std::cout << tree->height() << std::endl;//4
    std::cout << tree->countLeaves() << std::endl;//4
    std::cout << tree->maxLeaf() << std::endl;//5
    return 0;*/
}