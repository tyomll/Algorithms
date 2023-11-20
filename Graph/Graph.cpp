#include <iostream>
#include <list>
#include <unordered_map>

class Graph {
private:
    std::unordered_map<int, std::list<std::pair<int, int>>> adjacencyList;

public:
    void addEdge(int source, int destination, int weight) {
        adjacencyList[source].push_back(std::make_pair(destination, weight));
        adjacencyList[destination].push_back(std::make_pair(source, weight));
    }

    void deleteEdge(int source, int destination) {
        adjacencyList[source].remove_if([destination](const std::pair<int, int>& edge) {
            return edge.first == destination;
        });

        adjacencyList[destination].remove_if([source](const std::pair<int, int>& edge) {
            return edge.first == source;
        });
    }

    void deleteNode(int node) {
        adjacencyList.erase(node);

        for (auto& pair : adjacencyList) {
            pair.second.remove_if([node](const std::pair<int, int>& edge) {
                return edge.first == node;
            });
        }
    }

    void displayGraph() {
        for (const auto& pair : adjacencyList) {
            std::cout << "Node " << pair.first << " connects to: ";
            for (const auto& edge : pair.second) {
                std::cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph graph;

    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 4);
    graph.addEdge(2, 3, 1);
    graph.addEdge(3, 4, 2);

    std::cout << "Original Graph:" << std::endl;
    graph.displayGraph();

    graph.deleteEdge(2, 3);

    std::cout << "\nGraph after deleting edge (2, 3):" << std::endl;
    graph.displayGraph();

    graph.deleteNode(1);

    std::cout << "\nGraph after deleting node 1:" << std::endl;
    graph.displayGraph();

    return 0;
}
