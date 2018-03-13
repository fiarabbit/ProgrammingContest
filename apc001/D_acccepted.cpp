#include <iostream>
#include <boost/heap/binomial_heap.hpp>
#include <vector>
#include <boost/range/irange.hpp>
#include <experimental/optional>
#include <unordered_set>
#include <algorithm>

using namespace std;
using namespace std::experimental;
using namespace boost;

using uint = unsigned int;

struct Node {
    uint id;
    uint value;
    optional<uint> heap_idx;
    bool is_top;

    explicit Node(uint _value) : value(_value), heap_idx(nullopt), is_top(false) {
        static uint _id = 0;
        id = _id;
        _id++;
    }

    bool operator>(const Node n) const {
        return value > n.value;
    }

    bool operator<(const Node n) const {
        return value < n.value;
    }
};

using bh = heap::binomial_heap<Node, heap::compare<greater<>>>;

int main() {
    uint N, M;
    cin >> N >> M;
    vector<bh> heaps;
    unordered_set<uint> valid_heap_indexes;
    vector<Node> nodes;
    for (auto i: irange((uint) 0, N)) {
        uint a;
        cin >> a;
        nodes.emplace_back(a);
    }
    for (auto i: irange((uint) 0, M)) {
        uint x, y;
        cin >> x >> y;
        auto heap_idx_x = nodes.at(x).heap_idx;
        auto heap_idx_y = nodes.at(y).heap_idx;
        if (heap_idx_x && heap_idx_y) {
            if (heap_idx_x == heap_idx_y) {
                cout << "somthing going wrong" << endl;
                exit(1);
            } else {
                if (heaps.at(heap_idx_x.value()).size() > heaps.at(heap_idx_y.value()).size()) {
                    cout << "heap" << heap_idx_x.value() << " included heap " << heap_idx_y.value() << endl;
                    heaps.at(heap_idx_x.value()).merge(heaps.at(heap_idx_y.value()));
                    nodes.at(y).heap_idx = nodes.at(x).heap_idx;
                    valid_heap_indexes.erase(heap_idx_y.value());

                } else {
                    cout << "heap" << heap_idx_y.value() << " included heap " << heap_idx_x.value() << endl;
                    heaps.at(heap_idx_y.value()).merge(heaps.at(heap_idx_x.value()));
                    nodes.at(x).heap_idx = nodes.at(y).heap_idx;
                    valid_heap_indexes.erase(heap_idx_x.value());
                }
            }
        } else if (heap_idx_x) {
            cout << "heap" << heap_idx_x.value() << " included node " << y << endl;
            heaps.at(heap_idx_x.value()).push(nodes.at(y));
            nodes.at(y).heap_idx = nodes.at(x).heap_idx;
        } else if (heap_idx_y) {
            cout << "heap" << heap_idx_y.value() << " included node " << x << endl;
            heaps.at(heap_idx_y.value()).push(nodes.at(x));
            nodes.at(x).heap_idx = nodes.at(y).heap_idx;
        } else {
            cout << "new heap: " << heaps.size() << " contains " << x << " and " << y << endl;
            uint heap_idx = heaps.size();
            heaps.emplace_back(bh());
            heaps.back().push(nodes.at(x));
            heaps.back().push(nodes.at(y));
            valid_heap_indexes.insert(heap_idx);
            nodes.at(x).heap_idx = heap_idx;
            nodes.at(y).heap_idx = heap_idx;
        }
    }
    for (auto i: valid_heap_indexes) {
        cout << "heap index: " << i << endl;
        cout << "node id: ";
        for (auto n: heaps.at(i)) {
            cout << n.id << " ";
        }
        cout << endl;
    }
    vector<bool> is_tops(N, false);
    for (auto i: valid_heap_indexes) {
        auto n = heaps.at(i).top();
        is_tops.at(n.id) = true;
    }
    for (auto i: irange((uint) 0, N)) {
        nodes.at(i).is_top = is_tops.at(i);
    }
    sort(nodes.begin(), nodes.end());
    if (valid_heap_indexes.size() * 2 - 2 > N){
        cout << "Impossible" << endl;
        return 0;
    }

    uint top_counter{0};
    uint non_top_counter{0};
    uint sum{0};
    for (auto n: nodes) {
        if (n.is_top && top_counter < valid_heap_indexes.size()) {
            sum += n.value;
            top_counter += 1;
        } else if (non_top_counter < valid_heap_indexes.size() - 2) {
            sum += n.value;
            non_top_counter += 1;
        }
    }
    cout << sum << endl;

    return 0;

}