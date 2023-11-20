#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph {
	private:
		unordered_map<char, int> vertexesVector;
		vector<vector<int>> matrixGraph;

	public:
		Graph(const vector<char>& vertexes) {
			for (int i = 0; i < vertexes.size(); ++i) {
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
		void deleteVertex(char vertex) {
			auto it = vertexesVector.find(vertex);

			if (it != vertexesVector.end()) {
				int vertexIndex = it->second;

				vertexesVector.erase(it);
				matrixGraph.erase(matrixGraph.begin() + vertexIndex);

				for (auto& row : matrixGraph) {
					row.erase(row.begin() + vertexIndex);
				}
			}
			else {
				cout << "Vertex not found: " << vertex << endl;
			}
		}
		void printMatrix() {
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
};

int main() {
	vector<char> vertexes = {'E', 'D', 'C', 'B', 'A'};

	Graph graph(vertexes);

	graph.addEdge('A', 'B', 6);
	graph.addEdge('A', 'D', 1);
	graph.addEdge('B', 'D', 2);
	graph.addEdge('B', 'C', 5);
	graph.addEdge('B', 'E', 2);
	graph.addEdge('D', 'E', 1);
	graph.addEdge('E', 'C', 5);

	graph.printMatrix();

	graph.deleteVertex('A');
	graph.printMatrix();
	return 0;
}

