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
		}

		void printMatrix () {
			for (int i = 0; i < matrixGraph.size(); ++i) {
				for (int j = 0; j < matrixGraph[i].size(); ++j) {
					cout << matrixGraph[i][j] << " ";
				}
				cout << endl;
			}
		}
};

int main() {
	vector <char> vertexes = {'A', 'B', 'C', 'D', 'E'};

	Graph graph(vertexes);

	graph.addEdge('A', 'B', 6);
	graph.addEdge('A', 'D', 1);
	graph.addEdge('B', 'D', 2);
	graph.addEdge('B', 'C', 5);
	graph.addEdge('B', 'E', 2);
	graph.addEdge('D', 'E', 1);
	graph.addEdge('E', 'C', 5);

	cout << "Matrix:\n";
	graph.printMatrix();

	return 0;
}

