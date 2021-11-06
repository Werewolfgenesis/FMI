#include <iostream>
#include <queue>
#include <vector>
#include <list>
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
        this->id = id;
    }
    bool operator==(const Node<T>& other)
    {
        return this->data == other.data && this->id == other.id;
    }
};
template<typename T>
class Graph{
private:
    std::list<Node<T>>* gr;
    unsigned current_id;
    unsigned size;
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
    void addNode(const T& elem)
    {
        Node<T> tmp(elem, current_id);
        gr[current_id].push_back(tmp);
        current_id++;
    }
    void addConnection(const Node<T>& first, const Node<T>& sec)
    {
        gr[first.id].push_back(sec);
    }
    void DFS(const Node<T>& start)
    {
        bool* visited = new bool[size];
        for (size_t i = 0; i < size; i++)
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
    void BFS(const Node<T>& start)
    {
        bool* visited = new bool[size];
        for (size_t i = 0; i < size; i++)
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
            for (typename std::list<Node<T>>::iterator it = gr[tmp.id].begin(); it != gr[tmp.id].end(); ++it)
            {
                if(visited[it->id] == false)
                {
                    visited[it->id] = true;
                    q.push(*it);
                }
            }
        }
        delete[] visited;
    }
    bool hasWay(const Node<T>& from, const Node<T>& to)
    {
        bool* visited = new bool[size];
        for (size_t i = 0; i < size; i++)
        {
            visited[i] = false;
        }
        std::queue<Node<T>> q;
        q.push(from);
        visited[from.id] = true;
        while (!q.empty())
        {
            Node<T> tmp = q.front();
            q.pop();
            for (typename std::list<Node<T>>::iterator it = gr[tmp.id].begin(); it != gr[tmp.id].end(); ++it)
            {
                if (visited[it->id] == false)
                {
                    visited[it->id] = true;
                    q.push(*it);
                }
                if (*it == to)
                {
                    return true;
                }
            }
        }
        delete[] visited;
        return false;
    }
    bool isNotVisited(const Node<T>& node, const std::vector<Node<T>>& path )
    {
        unsigned size = path.size();
        for (size_t i = 0; i < size; i++)
        {
            if (path[i] == node)
            {
                return false;
            }
        }
        return true;
    }
    void shortest(const Node<T>& from, const Node<T>& to)
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
            if (tmp == to)
            {
                all_paths.push_back(path);
            }
            for (typename std::list<Node<T>>::iterator it = gr[tmp.id].begin(); it != gr[tmp.id].end(); ++it)
            {
                if (isNotVisited(*it, path))
                {
                    std::vector<Node<T>> newVec(path);
                    newVec.push_back(*it);
                    q.push(newVec);
                }
            }
        }
        unsigned min_size = all_paths[0].size();
        unsigned min_index;
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
    unsigned matches = 0;
    while (t2 >> word)
    {
        if (first.find(word) != first.end())
        {
            res[word]++;
            matches++;
        }
    }
    for (typename std::unordered_map<std::string, int>::iterator it = res.begin(); it != res.end(); ++it)
    {
        std::cout << it->first << " " << it->second << "\n";
    }
    
}
int main()
{
    compare();
    return 0;
}