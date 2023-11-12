#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class graph {
private:
    std::map<char, std::vector<char>> data;

public:
    graph() {}

    void add_vertex(char key, char value) {
        data[key].push_back(value);
        data[value].push_back(key);
    }   

    void print_graph() {
        for (const auto& pair : data) {
            std::cout << "Key: " << pair.first << ", Values: ";
            for (const auto& value : pair.second) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }

        void deleteValueForKey(char key) {
        for (auto& pair : data) {
            pair.second.erase(std::remove(pair.second.begin(), pair.second.end(), key), pair.second.end());
        }
        data.erase(key);
    }
};

int main() {
    graph Graph;

    Graph.add_vertex('A', 'B');
    Graph.add_vertex('A', 'E');
    Graph.add_vertex('A', 'C');
    Graph.add_vertex('A', 'D');
    Graph.add_vertex('B', 'E');
    Graph.add_vertex('E', 'C');

    std::cout << "Graph before deletion:\n";
    Graph.print_graph();

    Graph.deleteValueForKey('A');

    std::cout << "\nGraph after deletion:\n";
    Graph.print_graph();

    return 0;
}
