#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

template <typename T>
class graph {
    std::map<T, std::vector<T>> list;

public:
    graph() {}

    void add_vertex(const T& vertex, const T& edge){
        list[vertex].push_back(edge);
        list[edge].push_back(vertex);
    }

    void delete_vertex(const T& vertex){
        auto obj = list.find(vertex);
        if (obj != list.end()){
            for (auto& pair: list) {
                pair.second.erase(std::remove(pair.second.begin(), pair.second.end(), vertex), pair.second.end());
            }

            list.erase(obj);

            for (auto pair = list.begin(); pair != list.end();) {
                if (pair->second.empty()){
                    pair = list.erase(pair);
                } else {
                    ++pair;
                }
            }
        }
    }

    void print_graph() const {
        for (const auto& pair : list) {
            std::cout << pair.first << " : [";
            for (int i = 0; i < pair.second.size(); ++i) {
                if (i != pair.second.size() - 1) {
                    std::cout << pair.second[i] << ", ";
                } else {
                    std::cout << pair.second[i];
                }
            }
            std::cout << "]\n";
        }
    }

    ~graph() {}
};

int main() {
    graph<int> graph;
    graph.add_vertex(1, 2);
    graph.add_vertex(1, 3);
    graph.add_vertex(1, 4);
    graph.add_vertex(3, 4);

    graph.print_graph();

    graph.delete_vertex(1);

    std::cout << "After deleting vertex 1:\n";
    graph.print_graph();

    return 0;
}
