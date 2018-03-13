#include <iostream>
#include <vector>
#include <limits>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>
#include <queue>
#include <utility>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

constexpr uint INF = numeric_limits<uint>::max();


struct Edge{
    uint node_1;
    uint node_2;
    uint cost;
    Edge(uint node_1, uint node_2, uint cost);
};


struct Node{
    uint id;
    uint shortest_path;
    uint prev;
    vector<Edge*> edge_ptrs;

    Node(uint id, uint shortest_path);
    explicit Node(uint id);
    bool operator < (Node n) const;
};



Node::Node(uint id, uint shortest_path):
        id(id),
        shortest_path(shortest_path),
        prev(INF),
        edge_ptrs({})
{}

Node::Node(uint id):
        id(id),
        prev(INF),
        shortest_path(INF),
        edge_ptrs({})
{}

bool Node::operator<(const Node n) const {
    return shortest_path < n.shortest_path;
}


Edge::Edge(uint node_1, uint node_2, uint cost):
        node_1(node_1),
        node_2(node_2),
        cost(cost)
{}

int main() {
    uint N, M;
    cin >> N >> M;
    vector<Node> nodes_original{};
    for (auto &&i: irange(0U, N)){
        nodes_original.emplace_back(Node(i));
    }
    vector<Edge*> edge_ptrs{};
    for (auto &&i: irange(0U, M)){
        uint a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        auto edge_ptr = new Edge(a, b, c);
        nodes_original.at(a).edge_ptrs.push_back(edge_ptr);
        nodes_original.at(b).edge_ptrs.push_back(edge_ptr);
        edge_ptrs.emplace_back(edge_ptr);
    }

    vector<vector<bool>> is_used(N, vector<bool>(N, false));
    for (auto &&i: irange(0U, N)){
        vector<Node> nodes_tmp = nodes_original;
        auto start_node = i;
        priority_queue<Node> pq{};
        nodes_tmp.at(start_node).shortest_path = 0U;
        pq.push(nodes_tmp.at(start_node));
        while(!pq.empty()){
            Node src = pq.top();
            pq.pop();
            for (auto &&edge_ptr: src.edge_ptrs){
                uint dest_id = edge_ptr->node_1==src.id ? edge_ptr->node_2 : edge_ptr->node_1;
                Node dest = nodes_tmp.at(dest_id);
                if (dest.shortest_path > src.shortest_path + edge_ptr->cost){
                    dest.shortest_path = src.shortest_path + edge_ptr->cost;
                    nodes_tmp.at(dest.id).shortest_path = dest.shortest_path;
                    nodes_tmp.at(dest.id).prev = src.id;
                    pq.push(dest);
                }
            }
        }
        for (auto &&j: irange(0U, N)){
            if (nodes_tmp.at(j).prev != INF){
                is_used.at(j).at(nodes_tmp.at(j).prev) = true;
                is_used.at(nodes_tmp.at(j).prev).at(j) = true;
            }
        }
    }
    uint count{0};
    for (auto &&i: irange(0U, N)){
        for (auto &&j: irange(0U, N)){
            if (is_used.at(i).at(j)){
                count++;
            }
        }
    }
    cout << M-(count/2) << endl;
    return 0;
}