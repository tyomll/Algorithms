#include <iostream>
#include <vector>
#include <climits>

int minimum_point(std::vector<int>& distance, std::vector<bool>& unvisited, int size) {
    int minimum_distance = INT_MAX, minimum_index;

    for (int i = 0; i < size; i++) {
        if (unvisited[i] && distance[i] <= minimum_distance) {
            minimum_distance = distance[i];
            minimum_index = i;
        }
    }
    return minimum_index;
}

void print_result(std::vector<int>& distance, std::vector<int>& previous, std::vector<char> unvisited, int size, int source) {
    std::cout << "Vertex\tDistance\tPrevious\n";
    for (int i = 0; i < size; i++) {
        std::cout << unvisited[i] << "\t";
        std::cout << distance[i] << "\t\t";

        if (previous[i] != -1)
            std::cout << static_cast<char>('A' + previous[i]);
        else
            std::cout << "--";

        std::cout << "\n";
    }
}

void dijkstras(std::vector<std::vector<int>>& graph, int source) {
    int size = graph.size();
    std::vector<int> distance(size, INT_MAX);
    std::vector<bool> unvisited(size, true); 
    std::vector<int> previous(size, -1);
    std::vector<char> unvisited_list = {'A', 'B', 'C', 'D', 'E'}; 
    distance[source] = 0;

    for (int i = 0; i < size - 1; ++i) {
        int u = minimum_point(distance, unvisited, size);
        unvisited[u] = false; 

        for (int v = 0; v < size; ++v) {
        
            if (unvisited[v] && graph[u][v] != 0 && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                previous[v] = u;
            }
        }
    }
    print_result(distance, previous, unvisited_list, size, source);
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 6, 0, 1, 0},
        {6, 0, 5, 2, 2},
        {0, 5, 0, 0, 5},
        {1, 2, 0, 0, 1},
        {0, 2, 5, 1, 0}
    };
    int source = 0;
    dijkstras(graph, source);

    return 0;
}
