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

    void print_friends(Node node)
    {
        std::cout << "--> friends: ";

        for (int i = 0; i < node.friends.size(); i++)
        {
            std::cout << node.friends[i] << " ";
        }

        std::cout << "\n";
    }

    void print_nodes()
    {
        std::cout << "This is list of all nodes \n \n";

        for (int i = 0; i < nodes.size(); i++)
        {
            std::cout << "node[" << i << "] "
                      << " Vertex: " << nodes[i].name;
            print_friends(nodes[i]);
        }

        std::cout << "\n";
    }

 
};

int main()
{
    Graf graph;

    graph.addNode("Aram", {"Jon", "Ani"});
    graph.print_nodes();
    graph.addEdge("Ani", {"Nare"});
    graph.print_nodes();

    // graph.addNode("John", ["John"]);
    // graph.addNode("Alice", ["John"]);
    // graph.addNode("Bob", ["John"]);
}