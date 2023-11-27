#include <iostream>
#include <list>

class Graph {
    struct Node {
        int data;
        std::list<int> neighbours;
    };

    std::list<Node> nodes;

public:
    void insertNode(int value) {
        Node newNode;
        newNode.data = value;
        nodes.push_back(newNode);
    }

    void insertEdge(int a, int b) {
        for (auto& node : nodes) {
            if (node.data == a) {
                node.neighbours.push_back(b);
            }             
            else if (node.data == b) {
                node.neighbours.push_back(a);
            }
        }
    }
    void delateNode(int value) {
        for (auto it = nodes.begin(); it != nodes.end(); it++){
            if (value == it->data) {
                it = nodes.erase(it);          
                break; 
            }
        }
        for (auto& node : nodes){
            node.neighbours.remove(value);
        }
    }
    void printGraph() {
        for (const auto& node : nodes) {
            std::cout << "Node " << node.data << " has neighbours: ";
            for (const auto& neighbour : node.neighbours) {
                std::cout << neighbour << " ";
            }
            std::cout << std::endl;
        }
    }
    
};

int main() {
    Graph graph;
    graph.insertNode(1);
    graph.insertNode(2);
    graph.insertNode(3);
    graph.insertNode(4);

    graph.insertEdge(1, 2);
    graph.insertEdge(1, 3);
    graph.insertEdge(2, 3);
    graph.insertEdge(3, 4);

    graph.printGraph();

    graph.delateNode(3);
    std::cout << "Graph after delating a node : ";
    std::cout << std::endl; 
    graph.printGraph();

    return 0;
}
