#include <iostream>
#include <boost/heap/pairing_heap.hpp>
#include <boost/range/irange.hpp>
#include <limits>

using namespace std;
using namespace boost;
using namespace boost::heap;

using uint = unsigned int;


struct Node {
    uint id;
    pairing_heap<Node, compare<greater<>>>::handle_type heap_handle;
    uint cost{numeric_limits<int>::max()};

    explicit Node(uint _id): id(_id){};
    bool operator > (const Node n) const{
        return cost > n.cost;
    }
    bool operator < (const Node n) const{
        return cost < n.cost;
    }
};
int main() {
    uint H, W;
    cin >> H >> W;
    vector<vector<uint>> costs(H, vector<uint>(W, 0));
    for (auto &&i: irange((unsigned int) 0, H)) {
        for (auto &&j: irange((unsigned int) 0, W)) {
            cin >> costs.at(i).at(j);
        }
    }
    vector<Node> nodes;
    pairing_heap<Node, compare<greater<>>> heap;
    for (auto &&i: irange((unsigned int) 0, (uint) 10)){
        nodes.emplace_back(Node(i));
        nodes.at(i).heap_handle = heap.push(nodes.at(i));
    }
//    dijekstra-search from 1
    nodes.at(1).cost = 0;
    heap.update(nodes.at(1).heap_handle, nodes.at(2));

    nodes.at(3).cost = 7;
    heap.update(nodes.at(3).heap_handle, nodes.at(3));

    nodes.at(4).cost = 10;
    heap.update(nodes.at(4).heap_handle, nodes.at(4));
    for (auto i = heap.ordered_begin(); i!=heap.ordered_end(); i++){
        cout << i->cost << " " << i->id << endl;
    }
}