#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

struct Edge {
    char dest;
    int weight;
};

struct Node {
    char id;
    int distance;
    char previous;
};

struct CompareNode {
    bool operator()(const Node& a, const Node& b) {
        return a.distance > b.distance;
    }
};

void dijkstra(std::vector<std::vector<Edge>>& graph, char start) {
    int numNodes = graph.size();

    std::priority_queue<Node, std::vector<Node>, CompareNode> pq;

    std::vector<int> distance(numNodes, INT_MAX);
    std::unordered_map<char, char> previous;

    distance[start - 'A'] = 0;
    pq.push({start, 0, start});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        for (const Edge& edge : graph[current.id - 'A']) {
            int newDist = distance[current.id - 'A'] + edge.weight;

             if (newDist < distance[edge.dest - 'A']) {
                distance[edge.dest - 'A'] = newDist;
                previous[edge.dest] = current.id;
                pq.push({edge.dest, newDist, current.id});
            }
        }
    }

    std::cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < numNodes; ++i) {
        char currentNode = char('A' + i);
        std::cout << "To node " << currentNode << ": " << distance[i];
        if (previous.find(currentNode) != previous.end()) {
            std::cout << " | Previous: " << previous[currentNode];
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<Edge>> graph = {
        {{'B', 6}, {'D', 1}},
        {{'A', 6}, {'C', 5}, {'D', 2}, {'E', 2}},
        {{'B', 5}, {'E', 5}},
        {{'A', 1}, {'B', 2}, {'E', 1}},
        {{'D', 1}, {'B', 2}, {'C', 5}}
    };

    char startNode = 'A';

    dijkstra(graph, startNode);

    return 0;
}