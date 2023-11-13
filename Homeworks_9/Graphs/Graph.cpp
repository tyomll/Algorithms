#include <iostream>
#include <list>

template <typename T>
class Graph {
private:
    struct Node {
        T data;
        std::list<T> friends;
    };
    std::list<Node> nodes;
public:
    Graph() {}

    void add_node(const T& data, const T& value) {
        auto it = std::find_if(nodes.begin(), nodes.end(),
                               [&](const Node& node) { return node.data == data; });

        if (it == nodes.end()) {
            Node newNode;
            newNode.data = data;
            newNode.friends.push_back(value);
            nodes.push_back(newNode);
        } else {
            it->friends.push_back(value);
        }
    }

    void delete_node(const T& target) {
        for (auto it = nodes.begin(); it != nodes.end();) {
            if (it->data == target) {
                it = nodes.erase(it);
                break;
            }
            ++it;
        }
        for (auto& entry : nodes) {
            entry.friends.remove(target);
        }
    }


    void print() {
        for (const auto& node : nodes) {
            std::cout << "Vertex " << node.data << ": { ";
            for (const T& friendData : node.friends) {
                std::cout << friendData << ", ";
            }
            std::cout << "\b\b } \n";
        }
    }
};

int main() {
    Graph<char> obj;
    obj.add_node('A', 'B');
    obj.add_node('A', 'E');
    obj.add_node('B', 'D');
    obj.add_node('B', 'E');
    obj.add_node('B', 'C');
    obj.add_node('C', 'D');
    obj.add_node('C', 'A');
    obj.add_node('E', 'A');
    obj.print();
    obj.delete_node('E');
    std::cout << std::endl;
    obj.print();

    return 0;
}
