#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>

template <typename Node>
class Graph {
private:
    std::unordered_map<Node, std::unordered_map<Node, int>> edges;

public:
    void add_edge(const Node& src, const Node& dest, int weight) {
        edges[src][dest] = weight;
    }

    std::unordered_map<Node, int> dijkstra(const Node& start) {
        std::unordered_map<Node, int> dist;
        std::priority_queue<std::pair<int, Node>, std::vector<std::pair<int, Node>>, std::greater<>> pq;

        for (const auto& node : edges) {
            dist[node.first] = std::numeric_limits<int>::max();
        }

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            Node curr = pq.top().second;
            int curr_dist = pq.top().first;
            pq.pop();

            if (curr_dist > dist[curr]) {
                continue;
            }

            for (const auto& neighbor : edges[curr]) {
                int new_dist = curr_dist + neighbor.second;
                if (new_dist < dist[neighbor.first]) {
                    dist[neighbor.first] = new_dist;
                    pq.push({new_dist, neighbor.first});
                }
            }
        }

        return dist;
    }
};

int main() {
    Graph<char> graph;
    graph.add_edge('A', 'B', 1);
    graph.add_edge('A', 'C', 4);
    graph.add_edge('A', 'D', 2);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('C', 'D', 5);

    std::unordered_map<char, int> shortest_distances = graph.dijkstra('A');

    std::cout << "Shortest distances from 'A':\n";
    for (const auto& pair : shortest_distances) {
        std::cout << "Distance to " << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
