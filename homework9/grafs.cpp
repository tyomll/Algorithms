#include <iostream>
#include <string>
#include <vector>

class Graf
{
public:
    struct Node
    {
        std::string name;
        std::vector<std::string> friends;
        std::vector<int> length;
    };

    std::vector<Node> nodes;

public:
    bool check(std::string name)
    // checkes if there is already node with that name?
    {
        bool find = false;
        for (int j = 0; j < nodes.size(); j++)
        {
            if (name == nodes[j].name)
            {
                find == true;
                return true;
            }
        }

        return false;
    }

    void addNode(const std::string &name, const std::vector<std::string> &friends)
    // add new nodes with thait friensd, by using check function for friends

    {
        Node node;
        node.name = name;
        node.friends = friends;
        nodes.push_back(node);

        for (int i = 0; i < friends.size(); i++)
        {
            if (!check(friends[i]))
            {
                addNode(friends[i], {name});
            }
        }
    }

    int find_index(std::string name)
    // we need this function for getting index of some Name of node
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i].name == name)
            {
                return i;
            }
        }
        throw std::invalid_argument("Invalid node");
    }

    void addEdge(std::string name1, std::vector<std::string> names)
    // we need this function to add friends to node which is already in list og nodes
    {
        int index = find_index(name1);
        for (int i = 0; i < names.size(); i++)
        {
            nodes[index].friends.push_back(names[i]);
        }

        for (int i = 0; i < names.size(); i++)
        {
            if (!check(names[i]))
            {
                addNode(names[i], {name1});
            }
        }
    }

    void print_nodes()
    {
        std::cout << "This is a list of all nodes \n\n";

        for (int i = 0; i < nodes.size(); i++)
        {
            std::cout << "node[" << i << "] Vertex: " << nodes[i].name << "\n";
            std::cout << "--> Friends: ";
            for (int j = 0; j < nodes[i].friends.size(); j++)
            {
                std::cout << nodes[i].friends[j] << " ";
            }
            std::cout << "\n";

            std::cout << "--> Lengths: ";
            for (int k = 0; k < nodes[i].length.size(); k++)
            {
                std::cout << nodes[i].length[k] << " ";
            }
            std::cout << "\n\n";
        }

        std::cout << "\n";
    }
};

void shortest_way(Graf graph, std::string vertex)
{
    std::vector<std::string> unvisited;
    for (const auto &node : graph.nodes)
    {
        unvisited.push_back(node.name);
    }
 
    for (const auto &node : unvisited)
    {
        std::cout << node << " ";
    }
}

int main()
{
    Graf graph;

    graph.addNode("A", {"B", "D"});
    graph.addEdge("B", {"C", "E", "D"});
    graph.addEdge("D", {"E", "B"});
    graph.addEdge("C", {"E"});
    graph.addEdge("E", {"C", "D"});

    graph.nodes[0].length = {6, 1};
    graph.nodes[1].length = {5, 5, 2, 2};
    graph.nodes[2].length = {1, 1, 2};
    graph.nodes[3].length = {5, 5};
    graph.nodes[4].length = {2, 5, 1};

    std::vector<std::string> unvisited;

    graph.print_nodes();

    shortest_way(graph, "A");

    // graph.addNode("John", ["John"]);
    // graph.addNode("Alice", ["John"]);
    // graph.addNode("Bob", ["John"]);
}