#include <iostream>
#include <vector>

class DirectedGraph{
    int num_nodes;
    std::vector<std::vector<bool>> connections;

public:
    DirectedGraph(int numNodes = 0)
        : num_nodes(numNodes)
        {
            for(int i = 0; i < num_nodes; i++)
            {
                connections.push_back({});

                for(int j = 0; j < num_nodes; j++)
                    connections[i].push_back(false);
            }
        }

    //edge from a to b
    void connect(int a, int b)
    {
        if(a == b)
            return;

        if(a < 0 || a >= num_nodes || b < 0 || b >= num_nodes)
            throw std::out_of_range("Out of Range Arguments Provided");

        connections[a][b] = true;
    }

    int inDegree(int node)
    {
        if(node < 0 || node >= num_nodes)
            throw std::out_of_range("Out of Range Arguments Provided");

        int in_degree = 0;

        for(int i = 0; i < num_nodes; i++)
            in_degree += connections[i][node] ? 1 : 0;

        return in_degree;
    }

    int outDegree(int node)
    {
        if(node < 0 || node >= num_nodes)
            throw std::out_of_range("Out of Range Arguments Provided");

        int out_degree = 0;

        for(int j = 0; j < num_nodes; j++)
            out_degree += connections[node][j] ? 1 : 0;

        return out_degree;
    }

    friend std::ostream& operator<<(std::ostream&, const DirectedGraph&);
};

std::ostream& operator<<(std::ostream& out, const DirectedGraph& g)
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
    DirectedGraph g(5);
    g.connect(3,2);
    g.connect(4,3);
    g.connect(4,1);

    std::cout << "The given directed graph is : \n"
              << g << std::endl;

    std::cout << "Node\t" "in\t" "out\n";

    for(int i = 0; i < 5; i++)
        std::cout << i << "\t"
                  << g.inDegree(i) << "\t"
                  << g.outDegree(i) << "\n";

    return 0;
}
