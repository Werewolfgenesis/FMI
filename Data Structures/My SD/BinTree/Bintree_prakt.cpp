#include <iostream>
#include <vector>
using namespace std;
class BTree
{
private:
    struct Node
    {
        Node* right;
        Node* left;
        int data;

        Node(Node* _right, Node* _left, int _data)
        {
            this->right = _right;
            this->left = _left;
            this->data = _data;
        }

    };
    Node* root;
public:
    BTree()
    {
        this->root = nullptr;
    }
    ~BTree()
    {
        delete this->root;
    }
    void add(const int& x, const char* trace)
    {
        if (this->root == nullptr)
        {
            this->root = new Node(nullptr, nullptr, x);
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
                        current->left = new Node(nullptr,nullptr,x);
                    }
                     current = current->left;
                }
                else
                {
                    if (current->right == nullptr)
                    {
                        current->right = new Node(nullptr,nullptr,x);
                    }
                    
                    current = current->right;
                }
                trace++;
            }
        }
    }
    bool isMemberHelper(Node* root, const int& elem)
    {
        if (root == nullptr)
        {
            return false;
        }
        return root->data == elem || isMemberHelper(root->right, elem) || isMemberHelper(root->left, elem);
    }
    bool isMember(const int& elem)
    {
        return isMemberHelper(root, elem);
    }
    int sum()
    {
        return sumHelper(this->root);
    }
    int sumHelper(Node* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return root->data + sumHelper(root->right) + sumHelper(root->left);
    }
    int nrElems()
    {
        return nrElemsHelper(root);
    }
    int nrElemsHelper(Node* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        return 1 + nrElemsHelper(root->left) + nrElemsHelper(root->right);
    }
    int nrEvens()
    {
        return nrEvensH(root);
    }
    int nrEvensH(Node* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->data % 2 == 0)
        {
            return 1 + nrEvensH(root->right) + nrEvensH(root->left);
        }
        return nrEvensH(root->left) + nrEvensH(root->right);
    }
    int height()
    {
        return heightH(root);
    }
    int heightH(Node* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return __max((1+heightH(root->left)), 1+heightH(root->right));
    }
    int nrLeaves()
    {
        return nrLeavesH(root);
    }
    int nrLeavesH(Node* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        return nrLeavesH(root->left) + nrLeavesH(root->right);
    }
    int maxLeaf()
    {
        return maxLeafH(root);
    }
    int max = INT_MIN;
    int maxLeafH(Node* root)
    {
        if (root == nullptr)
        {
            return max;
        }
        if (root->data > max)
        {
            max = root->data;
        }
        maxLeafH(root->right);
        maxLeafH(root->left);
    }
    int getElement(const char* trace)
    {
        return getElementH(root, trace);
    }
    int getElementH(Node* root, const char *trace)
    {
        if (root == nullptr)
        {
            return 0;
        }
        while (*trace)
        {
            if(*trace == 'L')
            {
                if (root->left == nullptr)
                {
                    return 0;
                }
                
                root = root->left;
            }
            else
            {
                if (root->right == nullptr)
                {
                    return 0;
                }
                
                root = root->right;
            }
            trace++;
        }
        return root->data;
    }
    void printScheme()
    {
        printSchemeH(root);
    }
    void printSchemeH(Node* root)
    {
        if (root == nullptr)
        {
            std::cout << "() ";
            return;
        }
        cout << root->data << " ";
        printSchemeH(root->left);
        printSchemeH(root->right);
    }
    void printHaskell()
    {
        printHaskellH(root);
    }
    void printHaskellH(Node* root)
    {
        if (root == nullptr)
        {
            cout << "Empty ";
            return;
        }
        cout << root->data << " ";
        printHaskellH(root->left);
        printHaskellH(root->right);
    }
    std::vector<int> my;
    std::vector<int> listLeaves()
    {
        return listLeavesHelper(root);
    }
    std::vector<int> listLeavesHelper(Node* root)
    {
        if (root == nullptr)
        {
            return my;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            my.push_back(root->data);
            listLeavesHelper(root->right);
            listLeavesHelper(root->left);
        }
        else
        {
            listLeavesHelper(root->right);
            listLeavesHelper(root->left);
        }
        return my;
    }
    std::string res;
    std::string findTrace(int elem)
    {
        return findTraceH(root, elem);
    }
    std::string findTraceH(Node* root, int elem)
    {
        if (root == nullptr)
        {
            return res;
        }
        else if (root->data == elem)
        {

            return res;
        }
        if(isMemberHelper(root->right,elem))
        {
            res+='R';
        }
        if(isMemberHelper(root->left,elem))
        {
            res+='L';
        }
        findTraceH(root->right,elem);
        findTraceH(root->left,elem);
        return res;
    }
    int getAt(int i)
    {
        int result = 0;
        int current_index = 0;
        getAtH(root, i, result, current_index);
        return result;
    }
    void getAtH(Node* root, int i, int& result, int c_index)
    {
        if (root == nullptr)
        {
            return;
        }
        if(c_index == i)
        {
            result = root->data;
            return;
        }
        getAtH(root->left, i, result, ++c_index);
        getAtH(root->right, i, result, ++c_index);
    }
    void increment(int nr)
    {
        incrementH(root, nr);
    }
    void incrementH(Node* root, int nr)
    {
        if (root == nullptr)
        {
            return;
        }
        root->data += nr;
        incrementH(root->left, nr);
        incrementH(root->right, nr);
    }
    bool isMirror()
    {
        return isMirrorH(root);
    }
    bool isMirrorH(Node* root)
    {
        if(root == nullptr)
        {
            return true;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return true;
        }
        if (root->left == nullptr || root->right == nullptr)
        {
            return false;
        }
        return  root->left->data == root->right->data &&
            	isMirrorH(root->right) &&
                isMirrorH(root->left);
    }
    bool isBST()
    {
        return isBSTH(root);
    }
    bool isBSTH(Node* root)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->right == nullptr || root->left == nullptr)
        {
            return true;
        }
        if (root->data > root->right->data || root->data < root->left->data) 
        {
            return false;
        }
        return isBSTH(root->left) && isBSTH(root->right);
    }
    std::vector<int> m;
    bool isPalindrome(int level)
    {
        isPalindromeH(root, level, 0);
        return pal(m);
    }
    bool pal(std::vector<int> x)
    {
        std::vector<int> n;
        for (size_t i = m.size() - 1; i >= 0; i--)
        {
            n.push_back(m[i]);
        }
        return n == x;
    }
    void isPalindromeH(Node* root, int level, int start)
    {
        if (root == nullptr)
        {
            return;
        }
        if (start == level - 1)
        {
            
        }
        
        if (start == level - 1)
        {
            m.push_back(root->left->data);
            m.push_back(root->right->data);
        }
        isPalindromeH(root->right, level, ++start);
        isPalindromeH(root->left, level, ++start);
    }
    int getOnLvl(int level)//only lefts
    {
       getOnLvlH(root, level, 0);
       return 0;
    }
    
    void getOnLvlH(Node* root, int level,int curr)
    {
        if(root == nullptr)
        {
            return;
        }
        if (curr == level - 1)
        {
            cout << root->left->data;
            //return;
        }
        getOnLvlH(root->left, level, ++curr);
        getOnLvlH(root->right, level, curr);
    }
    
};
int main()
{
    BTree *t = new BTree();
    t->add(5, "");
    t->add(7, "L");
    t->add(7, "R");
    t->add(1, "LL");
    t->add(4, "RL");

    // cout << t->sum() << endl;
    // cout <<t->nrElems() << endl;
    // cout << t->nrEvens() << endl;
    // cout << t->height() << endl;
    // cout << t->nrLeaves() << endl;
    // cout << t->maxLeaf() << endl;
    // cout << t->getElement("LLR") << endl;
    // t->printScheme();
    // cout << endl;
    // t->printHaskell();
    // cout << endl;
    // std::vector<int> m = t->listLeaves();
    // cout << "[";
    // for (size_t i = 0; i < m.size(); i++)
    // {
    //     cout << m[i] << " ";
    // }
    // cout << "]" << endl;
    //cout << t->findTrace(2) << endl;
    // cout << t->getAt(2) << endl;
    // //cout << t->isMirror() << endl;
    // cout << t->isBST() << endl;
    // cout << t->isPalindrome(1);
    t->getOnLvl(2);
}
