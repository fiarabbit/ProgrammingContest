#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>
#include <boost/heap/pairing_heap.hpp>

using namespace std;
using namespace boost;
using namespace boost::heap;

using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

struct Edge{
    uint node_to;
    uint cost;
    explicit Edge(uint n, uint c): node_to(n), cost(c){};
};

struct Node{
    uint id;
    vector<Edge> adjacent_node{};
    uint distance_from_start{numeric_limits<uint>::max()};
    uint distance_from_terminate{numeric_limits<uint>::max()};
    uint count_from_start{0};
    uint count_from_terminate{0};
    explicit Node(uint _id): id(_id){};
};

auto greater_than_start = [] (const Node & n1, const Node & n2) -> bool{return n1.distance_from_start > n2.distance_from_start;};
using ph_start = pairing_heap<Node, compare<decltype(greater_than_start)>>;

auto greater_than_terminate = [](const Node & n1, const Node & n2) -> bool {return n1.distance_from_terminate > n2.distance_from_terminate;};
using ph_terminate = pairing_heap<Node, compare<decltype(greater_than_terminate)>>;

int main() {
    uint N, M;
    cin >> N >> M;
    uint start_node_index, terminate_node_index;
    cin >> start_node_index >> terminate_node_index;

//    数え上げダイクストラ法
    ph_start heap_start(greater_than_start);
    ph_terminate heap_terminate(greater_than_terminate);
    vector<ph_start::handle_type> node_handles_start{};
    vector<ph_terminate::handle_type> node_handles_terminate{};
    for (auto &&i: irange((unsigned int) 0, N)){
        node_handles_start.emplace_back(heap_start.push(Node(i)));
    }
    for (auto &&i: irange((unsigned int) 0, N)){
        node_handles_terminate.emplace_back(heap_terminate.push(Node(i)));
    }
    for (auto &&i: irange((unsigned int) 0, M)){
        uint node_index_1, node_index_2, distance;
        cin >> node_index_1 >> node_index_2 >> distance;
        node_index_1--;
        node_index_2--;
        (*node_handles_start.at(node_index_1)).adjacent_node.emplace_back(Edge(node_index_2, distance));
        (*node_handles_start.at(node_index_2)).adjacent_node.emplace_back(Edge(node_index_1, distance));
        (*node_handles_terminate.at(node_index_1)).adjacent_node.emplace_back(Edge(node_index_2, distance));
        (*node_handles_terminate.at(node_index_2)).adjacent_node.emplace_back(Edge(node_index_1, distance));
    }

    (*node_handles_start.at(start_node_index)).distance_from_start = 0;
    (*node_handles_start.at(start_node_index)).count_from_start = 1;
    heap_start.update(node_handles_start.at(start_node_index));
    while (!heap_start.empty()){
        Node n = heap_start.top();
        heap_start.pop();
        for (auto &&e: n.adjacent_node){
            Node adj = *node_handles_start.at(e.node_to);
            uint distance_from_n = n.distance_from_start + e.cost;
            if (adj.distance_from_start > distance_from_n){
                adj.distance_from_start = n.distance_from_start + e.cost;
                adj.count_from_start = n.count_from_start;
                heap_start.update(node_handles_start.at(e.node_to));
            } else if (adj.distance_from_start == distance_from_n) {
                adj.count_from_start += n.count_from_start;
            }
        }
    }
    (*node_handles_terminate.at(terminate_node_index)).distance_from_terminate = 0;
    (*node_handles_terminate.at(terminate_node_index)).count_from_terminate = 1;
    heap_terminate.update(node_handles_terminate.at(terminate_node_index));


    return 0;
}