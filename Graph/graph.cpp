#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class Graph {
private:
    unordered_map<int, list<int>> adjList;

public:
    void addEdge (int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void deleteVertex (int vertex) {
        for (auto& entry : adjList) {
            entry.second.remove(vertex);    // Removes from the adjList
        }

        adjList.erase(vertex);       // Removes entire entry
    }

    void printGraph () {
        for (auto& entry : adjList) {
            cout << "Vertex " << entry.first << ": ";
            for (int neighbour : entry.second) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }

};

int main () {
    Graph graph;

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);

    cout << "Graph: " << endl;
    graph.printGraph();

    graph.deleteVertex(2);

    cout << "Graph after deleting Vertex 2: " << endl;
    graph.printGraph();

    return 0;

}
