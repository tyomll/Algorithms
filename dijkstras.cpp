#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#include <limits>
#include <vector>

template <typename T>
class graph {
    std::map<T, std::list<std::pair<T, int>>> adj_list;

public:
    graph() {}

    void add_vertex(const T& vertex, const T& edge, int weight) {
        adj_list[vertex].push_back({edge, weight});
        adj_list[edge].push_back({vertex, weight});
    }

    void delete_vertex(const T& vertex) {
        auto erasable = adj_list.find(vertex);
        if (erasable != adj_list.end()) {
            for (auto& current : adj_list) {
                current.second.remove_if([vertex](const std::pair<T, int>& p) { return p.first == vertex; });
            }

            adj_list.erase(erasable);

            for (auto current = adj_list.begin(); current != adj_list.end();) {
                if (current->second.empty()) {
                    current = adj_list.erase(current);
                } else {
                    ++current;
                }
            }
        }
    }

    void print_graph() const {
        for (const auto& entry : adj_list) {
            std::cout << entry.first << " : [";
            const auto& neighbors = entry.second;
            for (auto current = neighbors.begin(); current != neighbors.end(); ++current) {
                std::cout << "(" << current->first << ", " << current->second << ")";
                if (std::next(current) != neighbors.end()) {
                    std::cout << ", ";
                }
            }

            std::cout << "]\n";
        }
    }

    const std::map<T, std::list<std::pair<T, int>>>& get_adj_list() const {
        return adj_list;
    }

    ~graph() {}
};

template <typename T>
void dijkstra(const graph<T>& graph, const T& start) {
    std::map<T, std::pair<int, T>> distances;
    std::vector<T> visited;
    std::vector<T> unvisited;

    const auto& adj_list = graph.get_adj_list();

    for (const auto& vertex : adj_list) {
        distances[vertex.first] = {std::numeric_limits<int>::max(), T()};
        unvisited.push_back(vertex.first);
    }
    distances[start] = {0, start};

    std::vector<std::pair<int, T>> priority;  
    priority .push_back({0, start});

    std::cout << "\nShortest Distances from vertex " << start << ":\n";
    std::cout << "Vertex\tDistance\tPrevious\n";

    while (!priority .empty()) {
        auto current = std::min_element(priority .begin(), priority.end());
        T current_vertex = current->second;
        int current_distance = current->first;
        priority .erase(current);

        visited.push_back(current_vertex);
        unvisited.erase(std::remove(unvisited.begin(), unvisited.end(), current_vertex), unvisited.end());

        std::cout << " " << current_vertex << "\t" << current_distance;

        if (distances[current_vertex].first != 0) {
            std::cout << "\t\t" << distances[current_vertex].second;
        } else {
            std::cout << "\t\t-";
        }

        std::cout << "\n";

        for (const auto& neighbor : adj_list.at(current_vertex)) {
            T neighbor_vertex = neighbor.first;
            int edge_weight = neighbor.second;

            if (std::find(visited.begin(), visited.end(), neighbor_vertex) == visited.end()) {
                int new_distance = current_distance + edge_weight;
                if (new_distance < distances[neighbor_vertex].first) {
                    distances[neighbor_vertex] = {new_distance, current_vertex};
                    priority.push_back({new_distance, neighbor_vertex});
                }
            }
        }
    }
}

int main() {
    graph<char> my_graph;

    my_graph.add_vertex('A', 'B', 6);
    my_graph.add_vertex('A', 'D', 1);
    my_graph.add_vertex('B', 'E', 2);
    my_graph.add_vertex('B', 'D', 2);
    my_graph.add_vertex('B', 'C', 5);
    my_graph.add_vertex('D', 'E', 1);
    my_graph.add_vertex('C', 'E', 5);

    std::cout << "Original Graph:\n";
    my_graph.print_graph();

    char start_vertex = 'A';
    dijkstra(my_graph, start_vertex);

    return 0;
}
