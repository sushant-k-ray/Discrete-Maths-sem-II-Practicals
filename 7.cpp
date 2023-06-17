#include <iostream>
#include <vector>
#include <algorithm>

//this class is for simple undirected graphs
class graph{
    int num_nodes;
    std::vector<std::vector<int>> connections;

public:
    graph(int numNodes = 0)
        : num_nodes(numNodes)
        {
            for(int i = 0; i < num_nodes; i++)
                connections.push_back({});
        }

    void connect(int a, int b)
    {
        if(a == b)
            return;

        if(a < 0 || a >= num_nodes || b < 0 || b >= num_nodes)
            throw std::out_of_range("Out of Range Arguments Provided");

        if(std::count(connections[a].begin(), connections[a].end(), b))
            return;

        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    bool isComplete()
    {
        if(!num_nodes)
            return false;

        for(int i = 0; i < num_nodes; i++)
            if(connections[i].size() != num_nodes - 1)
                return false;

        return true;
    }

    friend std::ostream& operator<<(std::ostream&, const graph&);
};

//to signify adjacency list representation
std::ostream& operator<<(std::ostream& out, const graph& g)
{
    for(int i = 0; i < g.num_nodes; i++){
        auto& c = g.connections[i];
        if(!c.size())
            continue;

        out << i << "\t";
        for(int j = 0; j < c.size(); j++)
            out << c[j] << ", ";

        out << "\n";
    }

    return out;
}

int main()
{
    graph g(5);
    g.connect(3,2);
    g.connect(4,3);

    std::cout << "The graph is :\n" << g << std::endl;
    std::cout << std::boolalpha;
    std::cout << "Graph is Complete : " << g.isComplete() << std::endl;

    g.connect(0,1);
    g.connect(0,2);
    g.connect(0,3);
    g.connect(0,4);
    g.connect(1,2);
    g.connect(1,3);
    g.connect(1,4);
    g.connect(2,4);

    std::cout << "\nThe graph is :\n" << g << std::endl;
    std::cout << "Graph is Complete : " << g.isComplete() << std::endl;
    return 0;
}

