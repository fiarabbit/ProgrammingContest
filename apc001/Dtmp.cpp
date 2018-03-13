#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>
#include <boost/heap/binomial_heap.hpp>
#include <functional>
#include <unordered_set>

using namespace std;
using namespace boost;
using uint = unsigned int;

struct Node{
    static vector<reference_wrapper<heap::binomial_heap<Node, heap::compare<greater<>>>>> heaps;
    static vector<uint> heap_references;
    static uint id_generator;

    uint id;
    uint value;
    heap::binomial_heap<Node, heap::compare<greater<>>> & heap;
    explicit Node(uint _value);
    bool operator > (Node n) const;
    bool operator < (Node n) const;
    void merge (Node n);
};

static unordered_set<heap::binomial_heap<Node, heap::compare<greater<>>>> heaps;

Node::id_generator = 0;

Node::Node(uint _value): value(_value), heap(*new heap::binomial_heap<Node, heap::compare<greater<>>>) {
    heaps.push_back(heap);
    id = id_generator;
    heap_references.push_back(id);
    id_generator += 1;
}
bool Node::operator>(const Node n) const {return value > n.value;}
bool Node::operator<(const Node n) const {return value < n.value;}
void Node::merge(Node n) {
    if(heap.size() > n.heap.size()){
        heap.merge(n.heap);
        n.heap = heap;
    }else{
        heaps.erase(heap);
        n.heap.merge(heap);
        heap = n.heap;
    }
}




int main() {
    uint N, M;
    cin >> N >> M;
    vector <Node> nodes(N, Node(0));
    for (auto i: irange((uint)0, N)){
        cin >> nodes.at(i).value;
    }
    for (auto i: irange((uint)0, M)){
        uint x, y;
        cin >> x >> y;
        nodes.at(x).merge(nodes.at(y));
    }

    return 0;
}