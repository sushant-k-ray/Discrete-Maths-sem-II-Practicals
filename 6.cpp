#include <iostream>
#include <vector>

//this class is for simple undirected graphs
class graph{
    int num_nodes;
    std::vector<std::vector<bool>> connections;

public:
    graph(int numNodes = 0)
        : num_nodes(numNodes)
        {
            for(int i = 0; i < num_nodes; i++)
            {
                connections.push_back({});

                for(int j = 0; j < num_nodes; j++)
                    connections[i].push_back(false);
            }
        }

    void connect(int a, int b)
    {
        if(a == b)
            return;

        if(a < 0 || a >= num_nodes || b < 0 || b >= num_nodes)
            throw std::out_of_range("Out of Range Arguments Provided");

        connections[a][b] = true;
        connections[b][a] = true;
    }

    bool isComplete()
    {
        if(!num_nodes)
            return false;

        for(int i = 0; i < num_nodes; i++)
            //Symmetry ensures that other half would be same
            for(int j = i + 1; j < num_nodes; j++)
                if(!connections[i][j])
                    return false;

        return true;
    }

    friend std::ostream& operator<<(std::ostream&, const graph&);
};

//to signify adjacency matrix representation
std::ostream& operator<<(std::ostream& out, const graph& g)
{
    for(int i = 0; i < g.num_nodes; i++){
            for(int j = 0; j < g.num_nodes; j++)
                out << (g.connections[i][j] ? 1 : 0) << "\t";

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
