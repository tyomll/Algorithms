#include <iostream>
#include <list>
#include <map>
#include <algorithm>

template <typename T>
class graph {
    std::map<T, std::list<T>> adj_list;

public:
    graph() {}

    void add_vertex(const T& vertex, const T& edge){
        adj_list[vertex].push_back(edge);
        adj_list[edge].push_back(vertex);
    }

    void delete_vertex(const T& vertex){
        auto erasable = adj_list.find(vertex);
        if (erasable != adj_list.end()){
            for (auto& current : adj_list) {
                current.second.remove(vertex);
            }

            adj_list.erase(erasable);

            for (auto current = adj_list.begin(); current != adj_list.end();) {
                if (current->second.empty()){
                    current = adj_list.erase(current);
                } else {
                    ++current;
                }
            }
        }
    }

    void print_graph() {
        for (auto& entry : adj_list) {
            std::cout << entry.first << " : [";
            auto& neighbors = entry.second;
            for (auto current = neighbors.begin(); current != neighbors.end(); ++current) {
                std::cout << *current;
                if (std::next(current) != neighbors.end()) {
                    std::cout << ", ";
                }
            }

            std::cout << "]\n";
        }
    }

    ~graph() {}
};

int main() {
    graph<char> my_graph;
    my_graph.add_vertex('A', 'B');
    my_graph.add_vertex('A', 'C');
    my_graph.add_vertex('A', 'D');
    my_graph.add_vertex('C', 'D');

    my_graph.print_graph();

    my_graph.delete_vertex('A');

    std::cout << "After deleting vertex A:\n";
    my_graph.print_graph();

    return 0;
}
