#include <iostream>
#include <list>
#include <queue>
#include <string>

template<typename T>
struct Node
{
    T data;
    unsigned id;

    Node(const T& data, const unsigned id)
    {
        this->data = data;
        this->id = id;
    }
    bool operator==(const Node<T>& rhs) const
    {
         return this->id == rhs.id &&
                this->data == rhs.data;
    }
};
template <typename T>
class Graph
{
private:
    std::list<Node<T>>* graphAdj;
    unsigned size;
    unsigned current_id;

public:
    Graph(const unsigned& size)
    {
        this->size = size;
        this->current_id = 0;
        this->graphAdj = new std::list<Node<T>>[size];
    }
    ~Graph()
    {
        delete[] graphAdj;
    }
    void addNode(const T& data)
    {
        Node<T> newNode(data, current_id);
        graphAdj[current_id].push_back(newNode);
        current_id++; 
    }
    void addConnection(const Node<T>& begin, const Node<T>& end)
    {
        graphAdj[begin.id].push_back(end);
    }
    void BFS(const Node<T>& begin)
    {
        bool *visited = new bool[this->size];
        for (size_t i = 0; i < size; i++)
        {
            visited[i] = false;
        }
        std::queue<Node<T>> q;
        q.push(begin);
        visited[begin.id] = true;
        while (!q.empty())
        {
            Node<T> temp = q.front();
            q.pop();
            std::cout << temp.data << "\n";
            for (typename std::list<Node<T>>::iterator it = graphAdj[temp.id].begin(); it != graphAdj[temp.id].end(); ++it)
            {
                if(!visited[it->id])
                {
                    visited[it->id] = true;
                    q.push(*it);
                }
            }
        }
        delete[] visited;
    }
    void DFSHelper(const Node<T>& begin, bool* visited)
    {
        std::cout << begin.data << std::endl;
        visited[begin.id] = true;
        for (typename std::list<Node<T>>::iterator it = graphAdj[begin.id].begin(); it != graphAdj[begin.id].end(); ++it)
        {
            if (!visited[it->id])
            {
                visited[it->id] = true;
                DFSHelper(*it, visited);
            }
        }
    }
    void DFS(const Node<T>& begin)
    {
        bool* visited = new bool[this->size];
        for (size_t i = 0; i < this->size; i++)
        {
            visited[i] = false;
        }
        DFSHelper(begin, visited);
        delete[] visited;
    }
    bool hasWay(const Node<T>& from, const Node<T> end)
    {
        bool* visited = new bool[this->size];
        for (size_t i = 0; i < this->size; i++)
        {
            visited[i] = false;
        }
        std::queue<Node<T>> q;
        q.push(from);
        visited[from.id]  = true;
        while (!q.empty())
        {
            Node<T> tmp = q.front();
            q.pop();
            for(typename std::list<Node<T>>::iterator it = graphAdj[from.id].begin(); it != graphAdj[from.id].end(); ++it)
            {
                if (visited[it->id] == false)
                {
                    visited[it->id] = true;
                }
                if (*it == end)
                {
                    return true;
                }
            }
        }
        delete[] visited;
        return false;
    }
    bool isNotVisited(Node<T>& node, const std::vector<Node<T>>& path)
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
    void shortest_way(const Node<T>& begin, const Node<T>& end)
    {
        std::queue<std::vector<Node<T>>> q;
        std::vector<Node<T>> path;
        path.push_back(begin);
        q.push(path);
        while (!q.empty())
        {
            path = q.front();
            q.pop();
            Node<T> temp = path[path.size() - 1];
            if (temp == end)
            {
                unsigned size = path.size();
                for (size_t i = 0; i < size; i++)
                {
                    std::cout << path[i].data << " ";
                }
                return;
                std::cout << std::endl;
            }
            //in case we look for all paths use this:
            // for (typename std::list<Node<T>>::iterator it = graphAdj[begin.id].begin(); it != graphAdj[begin.id].end(); ++it)
            // {
            //     if(isNotVisited(*it, path))
            //     {
            //         std::vector<Node<T>> newPath(path);7
            //         newPath.push_back(*it);
            //         q.push(newPath);
            //     } 
            // }
            
        }
        
    }
};

int main()
{
    Graph<std::string> gr(4);
    Node<std::string> t1("alo", 0);
    Node<std::string> t2("zdr", 1);
    Node<std::string> t3("bpce", 2);
    Node<std::string> t4("ks", 3);
    gr.addConnection(t1, t3);
    gr.addConnection(t1, t2);

    gr.BFS(t1);
    gr.DFS(t1);
    std::cout << std::boolalpha << gr.hasWay(t1, t3) << std::endl;
    //gr.way(t1, t3);
    return 0;
}