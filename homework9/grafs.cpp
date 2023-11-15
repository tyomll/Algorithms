#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

class Graf
{
public:
    std::vector<std::string> unvisited;
    std::vector<std::pair<std::string, std::pair<int, std::string>>> table;

    struct Node
    {
        std::string name;
        std::vector<std::pair<std::string, int>> friends;
    };

    std::vector<Node> nodes;

public:
    bool check(std::string name)
    {
        for (int j = 0; j < nodes.size(); j++)
        {
            if (name == nodes[j].name)
            {
                return false;
            }
        }
        return true;
    }

    void create_node(const std::string &name, const std::vector<std::pair<std::string, int>> &friends)
    {
        Node node;
        node.name = name;
        node.friends = friends;
        nodes.push_back(node);
    }

    void addNode(const std::string &name, const std::vector<std::pair<std::string, int>> &friends)
    {
        if (check(name))
        {
            create_node(name, friends);
        }
        else
        {
            addEdge(name, friends);
        }

        for (int i = 0; i < friends.size(); i++)
        {
            if (check(friends[i].first))
            {
                create_node(friends[i].first, {{name, friends[i].second}});
            }
            else
            {
                addEdge(friends[i].first, {{name, friends[i].second}});
            }
        }
    }

    int find_index(std::string name)
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

    void addEdge(std::string name, const std::vector<std::pair<std::string, int>> &friends)
    {
        int index = find_index(name);
        for (int i = 0; i < friends.size(); i++)
        {
            nodes[index].friends.push_back(friends[i]);
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
                std::cout << nodes[i].friends[j].first << " ";
            }
            std::cout << "\n";

            std::cout << "--> Lengths: ";
            for (int k = 0; k < nodes[i].friends.size(); k++)
            {
                std::cout << nodes[i].friends[k].second << " ";
            }
            std::cout << "\n\n";
        }
        std::cout << "\n";
    }

    void calculate(std::string start_vertex)
    {
        int start_index = find_index(start_vertex);
        table.resize(nodes.size());

        for (const auto &node : nodes)
        {
            unvisited.push_back(node.name);
        }

        for (int i = 0; i < unvisited.size(); ++i)
        {
            table[i].first = unvisited[i];
            if (unvisited[i] == start_vertex)
            {
                table[i].second.first = 0;
            }
            else
            {
                table[i].second.first = std::numeric_limits<int>::max();
            }
        }

        while (!unvisited.empty())
        {
            int min_distance = std::numeric_limits<int>::max();
            int min_index = -1;

            for (int i = 0; i < table.size(); ++i)
            {
                if (std::find(unvisited.begin(), unvisited.end(), table[i].first) != unvisited.end() &&
                    table[i].second.first < min_distance)
                {
                    min_distance = table[i].second.first;
                    min_index = i;
                }
            }

            if (min_index == -1)
            {
                break;
            }

            std::string current_vertex = table[min_index].first;
            unvisited.erase(std::remove(unvisited.begin(), unvisited.end(), current_vertex), unvisited.end());

            for (const auto &friendNode : nodes[find_index(current_vertex)].friends)
            {
                int friend_index = find_index(friendNode.first);
                int new_distance = table[min_index].second.first + friendNode.second;
                if (new_distance < table[friend_index].second.first)
                {
                    table[friend_index].second.first = new_distance;
                    table[friend_index].second.second = current_vertex;
                }
            }
            print_matrix();
        }
    }

    void print_matrix()
    {
        for (int i = 0; i < table.size(); i++)
        {
            std::cout << table[i].first << " " << table[i].second.first << " " << table[i].second.second << "\n";
        }
        std::cout << "\n";
    }
};

int main()
{
    Graf graph;

    graph.addNode("A", {{"B", 6}, {"D", 1}});
    graph.addNode("B", {{"C", 5}, {"E", 2}, {"D", 2}});
    graph.addNode("D", {{"E", 1}});
    graph.addEdge("C", {{"E", 5}});
    graph.addEdge("E", {{"C", 5}});

    graph.print_nodes();

    graph.calculate("A");
    graph.print_matrix();
}
