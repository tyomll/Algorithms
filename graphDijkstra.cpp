#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>

using namespace std;

class Graph {
private:
    unordered_map<char, int> vertexesVector;
    vector<vector<int>> matrixGraph;

public:
    Graph(const vector<char>& vertexes) {
        for (int i = vertexes.size() - 1; i > 0; i--) {

            vertexesVector[vertexes[i]] = i;
        }

        matrixGraph.resize(vertexes.size(), vector<int>(vertexes.size(), 0));
    }

    void addEdge(char from, char to, int weight) {
        int fromIndex = vertexesVector[from];
        int toIndex = vertexesVector[to];
        matrixGraph[fromIndex][toIndex] = weight;
        matrixGraph[toIndex][fromIndex] = weight;
    }
	void print() {
            cout << "  ";
            for (const auto& vertex : vertexesVector) {
                cout << vertex.first << " ";
            }
            cout << endl;

            for (const auto& vertexRow : vertexesVector) {
                char vertexLabel = vertexRow.first;
                int rowIndex = vertexRow.second;

                cout << vertexLabel << " ";
                for (const auto& col : vertexesVector) {
                    char colLabel = col.first;
                    int colIndex = col.second;
                    cout << matrixGraph[rowIndex][colIndex] << " ";
                }
                cout << endl;
            }
        }

    void dijkstra(char startVertex) {
        int numVertexes = vertexesVector.size();
        vector<int> distance(numVertexes, numeric_limits<int>::max());
        vector<bool> visited(numVertexes, false);

        int startIndex = vertexesVector[startVertex];
        distance[startIndex] = 0;

        for (int count = 0; count < numVertexes - 1; ++count) {
            int minDistance = numeric_limits<int>::max();
            int minIndex = -1;

            for (int i = 0; i < numVertexes; ++i) {
                if (!visited[i] && distance[i] < minDistance) {
                    minDistance = distance[i];
                    minIndex = i;
                }
            }

            if (minIndex == -1) {
                break;
            }

            visited[minIndex] = true;

            for (int i = 0; i < numVertexes; ++i) {
                if (!visited[i] && matrixGraph[minIndex][i] && distance[minIndex] != numeric_limits<int>::max() && distance[minIndex] + matrixGraph[minIndex][i] < distance[i]) {
                    distance[i] = distance[minIndex] + matrixGraph[minIndex][i];
                }
            }
        }

        cout << "Shortest distances from vertex " << startVertex << endl;
        for (const auto& vertex : vertexesVector) {
            char vertexLabel = vertex.first;
            int vertexIndex = vertex.second;

            cout << "To " << vertexLabel << ": " << distance[vertexIndex] << endl;
        }
    }
};

int main() {
    vector<char> vertices = {'A', 'B', 'C', 'D', 'E'};
    Graph graph(vertices);

    graph.addEdge('A', 'B', 6);
    graph.addEdge('A', 'D', 1);
    graph.addEdge('B', 'D', 2);
    graph.addEdge('B', 'C', 5);
    graph.addEdge('B', 'E', 2);
    graph.addEdge('D', 'E', 1);
    graph.addEdge('E', 'C', 5);
	
	graph.print();

    graph.dijkstra('A');

    return 0;
}

