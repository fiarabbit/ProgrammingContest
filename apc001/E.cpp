#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>
#include <unordered_set>

using  namespace std;
using namespace boost;

using uint = unsigned int;

struct Node{
    unordered_set<Node> adjacent_nodes{};

    explicit Node();
    bool is_sole();
    bool is_leaf();
    uint get_number_of_adjacent_leafs();
    void connect(Node &n);
    void disconnect(Node &n);
};

Node::Node() = default;

bool Node::is_sole() {
    return adjacent_nodes.empty();
}
bool Node::is_leaf() {
    return adjacent_nodes.size() == 1;
}
uint Node::get_number_of_adjacent_leafs() {
    uint i{0};
    for (Node n: adjacent_nodes){
        i += n.is_leaf();
    }
    return i;
}

void Node::connect(Node &n) {
    adjacent_nodes.insert(n);
    n.adjacent_nodes.insert(*this);
}
void Node::disconnect(Node &n) {
    adjacent_nodes.erase(n);
    n.adjacent_nodes.erase(*this);
}
int main() {
    return 0;
}