#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

template <typename T>
class Graph {
   private:
    std::map<T, std::vector<T>> graph;

   public:
    Graph() {}

    void addEdge(const T& firstNode, const T& secondNode) {
        graph[firstNode].push_back(secondNode);
        graph[secondNode].push_back(firstNode);
    }

    void deleteNode(const T& node) {
        auto itStart = graph.begin();
        auto itEnd = graph.end();

        graph.erase(node);

        while (itStart != itEnd) {
            auto nodeIterator =
                std::find(itStart->second.begin(), itStart->second.end(), node);
            if (nodeIterator != itStart->second.end()) {
                itStart->second.erase(nodeIterator);
            }
            itStart++;
        }
    }
    friend std::ostream& operator<<(std::ostream& cout, const Graph& graph) {
        auto it = graph.graph.begin();

        while (it != graph.graph.end()) {
            std::cout << it->first << " - [ ";
            for (size_t i = 0; i < it->second.size(); i++) {
                std::cout << it->second[i]
                          << (it->second.size() - 1 == i ? " " : ", ");
            }
            std::cout << "]" << std::endl;
            it++;
        }
        return cout;
    }
};

int main() {
    Graph<char> graph;

    graph.addEdge('A', 'B');
    graph.addEdge('B', 'C');
    graph.addEdge('A', 'C');
    graph.addEdge('A', 'D');
    graph.deleteNode('C');

    std::cout << graph << std::endl;
    return 0;
}