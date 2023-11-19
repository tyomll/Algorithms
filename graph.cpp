#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

template <typename T>
class graph {
private:
    std::unordered_map<T, std::vector<T>> edgeMap; 

public:
    void add_vertex(const T& source, const T& destination) {
        edgeMap[source].push_back(destination);
    }

    void delete_vertex(const T& vertex) {
        edgeMap.erase(vertex);

        for (size_t i = 0; i < edgeMap.size(); ++i) {
            auto& pair = edgeMap[i];
            auto& neighbors = pair.second;
            neighbors.erase(std::remove(neighbors.begin(), neighbors.end(), vertex), neighbors.end());
        }
    }

    void print_graph() {
        for (size_t i = 0; i < edgeMap.size(); ++i) {
            auto& pair = edgeMap[i];
            std::cout << pair.first << " : ";
            for (size_t j = 0; j < pair.second.size(); ++j) {
                std::cout << pair.second[j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    graph<char> my_graph;
    my_graph.add_vertex('A', 'B');
    my_graph.add_vertex('A', 'C');
    my_graph.add_vertex('A', 'D');
    my_graph.add_vertex('B', 'A');
    my_graph.add_vertex('C', 'A');
    my_graph.add_vertex('C', 'D');
    my_graph.add_vertex('D', 'A');
    my_graph.add_vertex('D', 'C');
    
    my_graph.print_graph();

    my_graph.delete_vertex('D');

    std::cout << "After deleting vertex D:\n";
    my_graph.print_graph();

    return 0;
}

