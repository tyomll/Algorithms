#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

template <typename T>
class Graph {
private:
    std::map<T, std::vector<T>> list; 

public:
    Graph() {}

    void addEdge(const T& name, const T& edge) {
        list[name].push_back(edge);
        list[edge].push_back(name);
    }

    void deleteVertex(const T& name) {
        list.erase(name);
        for (auto& entry : list) {
            auto& neighbors = entry.second;
            neighbors.erase(std::remove(neighbors.begin(), neighbors.end(), name), neighbors.end());
        }
    }

    void printGraph() const {
        for (const auto& pair : list) {
            std::cout << pair.first << " : [";
            for (size_t i = 0; i < pair.second.size(); ++i) {
                if (i != pair.second.size() - 1) {
                    std::cout << pair.second[i] << ", ";
                } else {
                    std::cout << pair.second[i];
                }
            }
            std::cout << "]\n";
        }
    }

    ~Graph() {}
};

int main() {
    Graph<char> graph;

    graph.addEdge('A', 'B');
    graph.addEdge('A', 'E');
    graph.addEdge('A', 'C');
    graph.addEdge('A', 'D');
    graph.addEdge('B', 'E');
    graph.addEdge('E', 'C');

    graph.printGraph();

    graph.deleteVertex('D');
    std::cout << "\nAfter deleting vertex D:\n\n";
    graph.printGraph();

    return 0;
}
