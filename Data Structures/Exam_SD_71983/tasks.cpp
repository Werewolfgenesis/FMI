#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

template<typename T>
struct Node
{
    T data;
    unsigned id;
    
    bool is_wall;

    Node(const T& data, const unsigned& id)
    {
        this->data = data;
        this->id = id;
        is_wall = false;
    }
    bool operator==(const Node<T>& other)
    {
        return this->data == other.data && this->id == other.id && this->is_wall == other.is_wall;
    }
};
template<typename T>
class Graph
{
private:
    std::list<Node<T>>* gr;
    unsigned size;
    unsigned current_id;
public:
    Graph(const unsigned& size, const unsigned& nr_walls)
    {
        this->size =size;
        this->current_id = 0;
        this->gr = new std::list<Node<T>>[size];
        unsigned counter = 0;
        for (typename std::list<Node<T>>::iterator it = gr[current_id].begin(); it != gr[current_id].end(); ++it)
        {
            while (counter < nr_walls)
            {
                it->is_wall = true;
            }
            
        }
        
        
    }
    ~Graph()
    {
        delete[] gr;
    }
    void addNode(const T& elem)
    {
        Node<T> tmp(elem, current_id);
        this->gr[current_id].push_back(tmp);
        current_id++;
    }
    void addConnection(const Node<T>& first, const Node<T>& sec)
    {
        this->gr[first.id].push_back(sec);
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
        for (typename std::list<Node<T>>::iterator it = this->gr[start.id].begin(); it != gr[start.id].end(); ++it)
        {
            if (visited[it->id] == false)
            {
                visited[it->id] = true;
                help(*it, visited);
            }
        }
    }
    bool safepPath(const Node<T>& from, const Node<T>& to)
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
                if (it->is_wall == true && ++it->is_wall == true)
                {
                    return false;
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
    bool isNotVisited(const Node<T>& node, const std::vector<Node<T>>& path)
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
    void shortest_way(const Node<T>& first, const Node<T>& sec, unsigned number_walls)
    {
        std::queue<std::vector<Node<T>>> q;
        std::vector<Node<T>> path;
        std::vector<std::vector<Node<T>>> all_paths;
        path.push_back(first);
        q.push(path);
        while (!q.empty())
        {
            path = q.front();
            q.pop();
            Node<T> tmp = path[path.size() - 1];
            if (tmp == sec)//path found
            {
                unsigned counter = 0;
                for (size_t i = 0; i < path.size(); i++)
                {
                    if (path[i].is_wall == true)
                    {
                        counter += 1;
                    }
                }
                if (counter < number_walls / 2)
                {
                    all_paths.push_back(path);
                }
            }
            for (typename std::list<Node<T>>::iterator it = gr[tmp.id].begin(); it != gr[tmp.id].end(); ++it)
            {
                if (isNotVisited(*it, path))
                {
                    std::vector<Node<T>> current(path);
                    current.push_back(*it);
                    q.push(current);
                }
            }
        }
        unsigned min_index;
        unsigned min_size = all_paths[0].size();
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
struct WordNode{
    std::string data;
    std::vector<WordNode*> children;
    unsigned nrChildren = children.size();
};
void printWordNode(WordNode*& root)
{
    std::queue<WordNode*> q;
    q.push(root);
    while (!q.empty())
    {
        WordNode* tmp = q.front();
        q.pop();
        std::cout << tmp->data << " ";
        for (typename std::vector<WordNode*>::iterator it = tmp->children.begin(); it != tmp->children.end(); ++it)
        {
            q.push(*it);
        }
    }
}
WordNode* readTree(const char* str)
{
    unsigned current_index = 0;
    WordNode* root = new WordNode;
    root->data = str[0];
    current_index++;
    while (str[current_index] != '\0')
    {
        if(str[current_index + 1] != ' ')
        {
            std::string word;
            while (str[current_index] != ' ')
            {
                word += str[current_index];
                current_index++;
            }
            WordNode* newNode = new WordNode;
            newNode->data = word;
            root->children.push_back(newNode);
        }
    }
    return root;
}
unsigned depth(WordNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    unsigned maxLevel = 0;
    for (typename std::vector<WordNode*>::iterator it = root->children.begin(); it != root->children.end(); ++it)
    {
        maxLevel = __max(maxLevel, depth(*it));
    }
    return maxLevel + 1;
}
void printFirstLevel(WordNode* root)
{
    unsigned size = root->children.size();
    for (size_t i = 0; i < size; i++)
    {
        std::cout << root->children[i];
    }
    
}
void task3A(std::stringstream t1, std::stringstream t2)
{   
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
        if (first.find(word) == first.end())
        {
            res[word]++;
            matches++;
        }
    }
    std::cout << "We have " << matches << " matching words." << "\n";
    std::cout << "Generating list of all matching words..." << "\n";
    for (typename std::unordered_map<std::string, int>::iterator it = res.begin(); it != res.end(); ++it)
    {
        std::cout << it->first << "\n";
    }
}
int main()
{
    return 0;
}