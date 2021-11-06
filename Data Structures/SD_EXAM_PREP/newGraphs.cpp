#include <iostream>
#include <queue>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <unordered_map>

template<typename T>
struct Node{
    T data;
    unsigned id;

    Node(const T& data, const unsigned& id)
    {
        this->data = data;
        this->id = id;
    }
    bool operator==(const Node<T>& node)
    {
        return this->data == node.data && this->id == node.id;
    }
};
template<typename T>
class Graph{
private:
    std::list<Node<T>>* gr;
    unsigned size;
    unsigned current_id;
public:
    Graph(const unsigned& size)
    {
        this->size = size;
        this->current_id = 0;
        this->gr = new std::list<Node<T>>[size];
    }
    ~Graph()
    {
        delete[] gr;
    }
    void add_node(const T& elem)
    {
        Node<T> tmp(elem, current_id);
        gr[current_id].push_back(tmp);
        current_id++;
    }
    void add_connection(const Node<T>& start, const Node<T>& end)
    {
        gr[start.id].push_back(end);
    }
    void BFS(const Node<T>& start)
    {
        bool* visited = new bool[size];
        for(unsigned i = 0; i < size; i++)
        {
            visited[i] = false;
        }
        std::queue<Node<T>> q;
        q.push(start);
        visited[start.id] = true;
        while (!q.empty())
        {
            Node<T> tmp = q.front();
            q.pop();
            std::cout << tmp.data << " ";
            for(typename std::list<Node<T>>::iterator it = gr[tmp.id].begin(); it != gr[tmp.id].end(); ++it)
            {
                if (visited[it->id] == false)
                {
                    visited[it->id] = true;
                    q.push(*it);
                }
            }
        }
        delete[] visited;
    }
    bool hasWay(const Node<T>& start, const Node<T>& end)
    {
        bool* visited = new bool[size];
        for(unsigned i = 0; i < size; i++)
        {
            visited[i] = false;
        }
        std::queue<Node<T>> q;
        q.push(start);
        visited[start.id] = true;
        while (!q.empty())
        {
            Node<T> tmp = q.front();
            q.pop();
            for(typename std::list<Node<T>>::iterator it = gr[tmp.id].begin(); it != gr[tmp.id].end(); ++it)
            {
                if (*it == end)
                {
                    return true;
                }
                if (visited[it->id] == false)
                {
                    visited[it->id] = true;
                    q.push(*it);
                }
            }
        }
        delete[] visited;
        return false;
    }
    void DFS(const Node<T>& start)
    {
        bool* visited = new bool[size];
        for(unsigned i = 0; i < size; i++)
        {
            visited[i] = false;
        }
        help(start, visited);
    }
    void help(const Node<T>& start, bool* visited)
    {
        std::cout << start.data << " ";
        visited[start.id] = true;
        for(typename std::list<Node<T>>::iterator it = gr[start.id].begin(); it != gr[start.id].end(); ++it)
        {
            if (visited[it->id] == false)
            {
                visited[it->id] = true;
                help(*it, visited);
            }
        }
    }

};
void testGraphs()
{
    Graph<std::string> gr(6);
    Node<std::string> t1("alo", 0);
    Node<std::string> t2("zdr", 1);
    Node<std::string> t3("bpce", 2);
    Node<std::string> t4("ks", 3);
    Node<std::string> t5("hsa ibem li", 4);
    Node<std::string> t6("az sum djaro", 5);
    gr.add_connection(t1, t3);
    gr.add_connection(t1, t2);
    gr.add_connection(t2, t4);
    gr.add_connection(t4, t6);
    gr.add_connection(t3, t5);

    gr.BFS(t1);
    std::cout << std::endl;
    gr.DFS(t1);
    std::cout << std::endl;
    std:: cout << gr.hasWay(t1,t5);
    std::cout << std::endl;
}
void compare()
{
    std::stringstream t1("In computing, a hash table (hash map) is a data structure used to implement an associative array, a structure that can map keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the correct value can be found");
    std::stringstream t2("Ideally, the hash function will assign each key to a unique bucket, but this situation is rarely achievable in practice usually some keys will hash to the same bucket");
    
    std::unordered_map<std::string, int> first;
    std::unordered_map<std::string, int> res;
    std::string word;
    while (t1 >> word)
    {
        first[word] = 0;
    }
    unsigned words_matched = 0;
    while (t2 >> word)
    {
        if ((first.find(word) == first.end()))
        {
            words_matched += 1;
            res[word]++;
        }
    }
    for(typename std::unordered_map<std::string, int>::iterator it = res.begin(); it != res.end(); ++it)
    {
        std::cout << it->first << " " << res[it->first] << "\n";
    }
}
template<typename T>
struct Ndde
{
    T data;
    std::vector<Ndde<T>*> children;
};
template<typename T>
Ndde<T>* newNode(const T& elem)
{
    Ndde<T>* tmp = new Ndde<T>;
    tmp->data = elem;
    return tmp;
}
template<typename T>
unsigned depth(Ndde<T>*& root)
{
    if (root == nullptr)
    {
        return 0;
    }
    unsigned max = 0;
    for(typename std::vector<Ndde<T>*>::iterator it = root->children.begin(); it != root->children.end(); ++it)
    {
        max = __max(max, depth(*it));
    }
    return max + 1;
}
void testNtree()
{
    Ndde<int>* n = newNode(3);
    Ndde<int>* m = newNode(4);
    Ndde<int>* p = newNode(5);
    Ndde<int>* q = newNode(8);
    n->children.push_back(m);
    n->children.push_back(p);
    n->children[0]->children.push_back(q);
    std::cout << depth(n);
}
int main()
{
     testGraphs();
     compare();
     testNtree();
}