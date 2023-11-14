#include <iostream>
#include <climits>

using namespace std;

const int V = 9; // Number of Vertices

int minDistance (int distance[], bool visited[]) {
    int min = INT_MAX;   // Initialize as infinite
    int min_index;

    for (int v = 0; v < V; v++) {
        if (visited[v] == false && distance[v] <= min) { // checks if vertex is in 'visited' mode
            min = distance[v];  // if yes assign minimum to that
            min_index = v;      // minimum index too
        }
    }
    return min_index;
}

void print (int distance[]) {
    cout << "Vertex\t\tDistance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << distance[i] << endl;
    }
}

void dijkstra (int graph[V][V], int src) {
    int distance[V];  // Will hold the distance from src to i
    bool visited[V];  // Will be true if vertex is included in 'visited' mode

    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;  // Initialize all distances as infinite
        visited[i] = false;     // Initialize 'mode' as false
    }
    
    distance[src] = 0;   // Distance of source vertex from itself is always 0

    for (int i = 0; i < V - 1; i++) {
        int result = minDistance(distance, visited); // Keep result in 'result' variable

        visited[result] = true;  // Mark that Vertex is now in 'visited' mode

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[result][v] && distance[result] != INT_MAX 
                && distance[result] + graph[result][v] < distance[v]) {
                distance[v] = distance[result] + graph[result][v];
            }
        }
    }
    print(distance);
}

int main () {
   int graph[V][V] = {  { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(graph, 0);

    return 0;

}
