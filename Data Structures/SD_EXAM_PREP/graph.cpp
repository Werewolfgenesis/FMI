//1 graph
//2 ntree
//3 hash map

#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

template<typename T>
struct Node{
    T data;
    unsigned id;

    Node(const T& data, const unsigned& id)
    {
        this->data = data;
        this->id= id;
    }
    bool operator==(const Node<T>& elem)
    {
        return this->data == elem.data && this->id == elem.id;
    }
};
template<typename T>
class Graph{
private:
    std::list<Node<T>>* graph;
    unsigned current_id;
    unsigned size;
public:
    Graph(const unsigned& size)
    {
        this->size = size;
        this->current_id = 0;
        this->graph = new std::list<Node<T>>[size];
    }
    ~Graph()
    {
        delete[] this->graph;
    }
    void add_elem(const T& elem)
    {
        Node<T> tmp(elem, current_id);
        this->graph[current_id].push_back(tmp);
        current_id++;
    }
    void add_connection(const Node<T>& first, const Node<T>& second)
    {
        this->graph[first.id].push_back(second);
    }
    void BFS(const Node<T>& start)
    {
        bool* visited = new bool[this->size];
        for(unsigned i = 0; i < size; i++)
        {
            visited[i] = false;
        }
        std::queue<Node<T>> q;
        q.push(start);
        visited[start.id] = true;
        while (q.empty() == false)
        {
            Node<T> tmp = q.front();
            q.pop();
            std::cout << tmp.data << " ";
            for(typename std::list<Node<T>>::iterator it = graph[tmp.id].begin(); it != graph[tmp.id].end(); ++it)
            {
                if (visited[it->id] == false)
                {
                    visited[it->id] = true;
                    q.push(*it);
                }
            }
        }
        std::cout << "\n";
        delete[] visited;
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
        for(typename std::list<Node<T>>::iterator it = graph[start.id].begin(); it != graph[start.id].end(); ++it)
        {
            if (visited[it->id] == false)
            {
                visited[it->id] = true;
                help(*it, visited);
            }
        }
    }
    bool has_way(const Node<T>& start, const Node<T>& end)
    {
        bool* visited = new bool[size];
        for(unsigned i = 0; i < size; i++)
        {
            visited[i] = false;
        }
        std::queue<Node<T>> q;
        q.push(start);
        visited[start.id] = true;
        while (q.empty() == false)
        {
            Node<T> tmp = q.front();
            q.pop();
            for(typename std::list<Node<T>>::iterator it = graph[tmp.id].begin(); it != graph[tmp.id].end(); ++it)
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
    bool isNotVisited(const Node<T>& node, std::vector<Node<T>>& path)
    {
        unsigned size = path.size();
        for(unsigned i = 0; i < size; i++)
        {
            if (path[i] == node)
            {
                return false;
            }
            
        }
        return true;
    }
    void shortest(const Node<T>& first, const Node<T>& second)
    {
        std::queue<std::vector<Node<T>>> q;
        std::vector<Node<T>> path;
        path.push_back(first);
        std::vector<std::vector<Node<T>>> all_paths;
        q.push(path);
        while (!q.empty())
        {
            path = q.front();
            q.pop();
            Node<T> end = path[path.size()-1];
            //if path is found
            if (end == second && end.data % 2 == 0)
            {
                all_paths.push_back(path);
            }
            for(typename std::list<Node<T>>::iterator it = graph[end.id].begin(); it != graph[end.id].end(); ++it)
            {
                if (isNotVisited(*it, path))
                {
                    std::vector<Node<T>> current(path);
                    current.push_back(*it);
                    q.push(current);
                }
            }
        }
        unsigned min_index = 0;
        unsigned min_size = all_paths[0].size();
        for(unsigned i =0; i < all_paths.size(); i++)
        {
            if (all_paths[i].size() < min_size)
            {
                min_size = all_paths[i].size();
                min_index = i;
            }
        }
        for(unsigned i = 0; i < min_size; i++)
        {
            std::cout << all_paths[min_index][i].data << " ";
        }
    }
    void sh(const Node<T>& start, const Node<T>& end)
    {
        std::queue<std::vector<Node<T>>> q;
        std::vector<std::vector<Node<T>>> all_paths;
        std::vector<Node<T>> path;
        path.push_back(start);
        q.push(path);
        while (!q.empty())
        {
            path = q.front();
            q.pop();
            Node<T> tmp = path[path.size() - 1];
            if (tmp == end)
            {
                all_paths.push_back(path);
            }
            for(typename std::list<Node<T>>::iterator it = graph[tmp.id].begin(); it != graph[tmp.id].end(); ++it)
            {
                if (isNotVisited(*it, path))
                {
                    std::vector<Node<T>> curr(path);
                    curr.push_back(*it);
                    q.push(curr);
                }
            }
        }
        
            unsigned min_index = 0, min_size;
            min_size = all_paths[0].size();
            unsigned curr_size = all_paths.size();
            for(unsigned i = 0; i < curr_size; i++)
            {
                if (all_paths[i].size() < min_size)
                {
                    min_size = all_paths[i].size();
                    min_index = i;
                }
            }
            for(unsigned i = 0; i < min_size; i++)
            {
                std::cout << all_paths[min_index][i].data << " ";
            }
    }
    void shortesst(Node<T>& from, Node<T>& end)
    {
        std::queue<std::vector<Node<T>>> q;
        std::vector<Node<T>> path;
        std::vector<std::vector<Node<T>>> all_paths;
        path.push_back(from);
        q.push(path);
        while (!q.empty())
        {
            path = q.front();
            q.pop();
            Node<T> tmp = path[path.size() - 1];
            if (tmp == end)
            {   
                all_paths.push_back(path);
            }
            for (typename std::list<Node<T>>::iterator it = graph[tmp.id].begin(); it != graph[tmp.id].end(); ++it)
            {
                if (isNotVisited(*it, path))
                {
                    std::vector<Node<T>> curr(path);
                    curr.push_back(*it);
                    q.push(curr);
                }
            }
        }
        unsigned min_index = 0, min_size = all_paths[0].size();
        for (size_t i = 0; i < all_paths.size(); i++)
        {
            if (all_paths[i].size() < min_size)
            {
                min_size = all_paths[i].size();
                min_index = i;
            }
        }
        for (size_t i = 0; i < min_size; i++)
        {
            std::cout << all_paths[min_index][i].data << " ";
        }
        
    }
};
void testGraphs()
{
    Graph<int> gr(4);
    Node<int> n(2,0);
    Node<int> m(4,1);
    Node<int> o(6,2);
    Node<int> p(6,3);

    gr.add_connection(n,m);
    gr.add_connection(n,m);
    gr.add_connection(n,o);
    gr.add_connection(m,p);
    gr.add_connection(m,o);
    std::cout << gr.has_way(n, p) << "\n";
    gr.shortesst(n,o);
}
void comparStrings()
{
    std::stringstream t1("mitaka e losh");
    std::stringstream t2("madafaka e mitaka");
    
    std::unordered_map<std::string, int> first;
    std::unordered_map<std::string, int> result;

    std::string word;
    while (t1 >> word)
    {
        first[word] = 0;
    }
    unsigned matches = 0;
    while (t2 >> word)
    {
        if (first.find(word) == first.end())
        {
            result[word]++;
            matches += 1;
        }
    }
    std::cout << "We have " << matches << " matching words!" << std::endl;
    for (typename std::unordered_map<std::string,int>::iterator it = result.begin(); it != result.end(); ++it)
    {
        std::cout << it->first << ":" << it->second << "\n";
    }
}
struct Node2
{
    int data;
    std::vector<Node2*> children;
};
Node2* newNode(const int& elem)
{
    Node2* tmp = new Node2;
    tmp->data = elem;
    return tmp;
}
unsigned depth(Node2* start)
{
    if (start == nullptr)
    {
        return 0;
    }
    unsigned max = 0;
    for (typename std::vector<Node2*>::iterator it = start->children.begin(); it != start->children.end();++it)
    {
        max = __max(max, depth(*it));
    }
    return max + 1;
}
void BFSprint(Node2*& root)
{
    std::queue<Node2*> q;
    q.push(root);
    while (!q.empty())
    {
        Node2* tmp = q.front();
        q.pop();
        std::cout << tmp->data << "\n";
        for(typename std::vector<Node2*>::iterator it = tmp->children.begin(); it != tmp->children.end(); ++it)
        {
            q.push(*it);
        }
    }
}
//[1([2][3([5][6])][4([7])])]
//1 2 3 4 5 6 7
Node2* make_from_string(Node2*& root, const char*& str)
{
    int data = *str - '0';
    root->data = data;
    ++str;
    if (*str == '(')
    {
        ++str;
        while (*str != ')')
        {
            if(*str == '[')
            {
                Node2* tmp = new Node2;
                ++str;
                make_from_string(tmp, str);
                root->children.push_back(tmp);
            }
            ++str;
        }
        ++str;
    }
}
int main()
{
    testGraphs();
    comparStrings();
    return 0;
}