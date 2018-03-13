#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>
#include <boost/heap/binomial_heap.hpp>
#include <unordered_set>

using namespace std;
using namespace boost;

using uint = unsigned int;

struct Node {
    using bh_node =  heap::binomial_heap<Node, heap::compare<greater<>>>;
    uint value;
    bh_node *p_heap;

    explicit Node(uint _value);

    void merge_heap(Node &n);

    bool operator>(const Node &n) const;

    bool operator<(const Node &n) const;
};

using bh_node = heap::binomial_heap<Node, heap::compare<greater<>>>;

static unordered_set<bh_node*> p_heaps;

Node::Node(uint _value) : value(_value), p_heap(new bh_node()) {
    (*p_heap).push(*this);
    p_heaps.insert(p_heap);
}

void Node::merge_heap(Node &n) {
    uint size_self = p_heap->size();
    uint size_n = n.p_heap->size();
    bh_node * p_larger_heap, * p_smaller_heap;
    if (size_self >= size_n) {
        p_larger_heap = p_heap;
        p_smaller_heap = n.p_heap;
    } else {
        p_larger_heap = n.p_heap;
        p_smaller_heap = p_heap;
    }
    p_larger_heap->merge(*p_smaller_heap);
    p_heaps.erase(p_smaller_heap);
    p_heap = p_larger_heap;
    n.p_heap = p_larger_heap;
}

bool Node::operator>(const Node &n) const {
    return value > n.value;
}

bool Node::operator<(const Node &n) const {
    return n.value > value;
}

int main() {
    uint N, M;
    cin >> N >> M;
    vector<Node> nodes;
    for (auto i: irange((unsigned int) 0, N)) {
        uint a;
        cin >> a;
        nodes.emplace_back(Node(a));
    }
    for (auto i: irange((unsigned int) 0, M)){
        uint x, y;
        cin >> x >> y;
        nodes.at(x).merge_heap(nodes.at(y));
    }

    uint sum{0};
    uint forest_size{p_heaps.size()};

    if (nodes.size() < 2 * forest_size - 2){
        cout << "Impossible" << endl;
    }else if (forest_size == 1) {
        cout << "0" << endl;
    }else{
        bh_node base;
        for (auto i: p_heaps){
            sum += (*i).top().value;
            (*i).pop();
            base.merge(*i);
        }
        for (auto i: irange((unsigned int) 0, forest_size-2)){
            sum += base.top().value;
            base.pop();
        }
    }
    cout << sum << endl;
    return 0;
}