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

    void add_node(const T& source, const T& destination) {
        create_node(source, destination);
        create_node(destination, source);
    }

    void create_node(const T& data, const T& value) {
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
        for (auto it = nodes.begin(); it != nodes.end(); it++) {
            if (it->data == target) {
                it = nodes.erase(it);
                break;
            }
        }
        for (auto& entry : nodes) {
            entry.friends.remove(target);
        }
    }


    void print() {
        for (const auto& element : nodes) {
            std::cout << "Vertex " << element.data << ": { ";
            for (const T& value : element.friends) {
                std::cout << value << ", ";
            }
            std::cout << "\b\b } \n";
        }
    }
    private:
};

int main() {
    Graph<char> obj;
    obj.add_node('A', 'B');
    obj.add_node('A', 'C');
    obj.add_node('A', 'D');
    obj.add_node('B', 'E');
    obj.print();
    obj.delete_node('E');
    std::cout << std::endl;
    obj.print();

    return 0;
}
