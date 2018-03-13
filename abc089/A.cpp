#include <iostream>
#include <vector>
#include <limits>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>
#include <queue>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

enum EdgeType {
    same, add, remove_edge, modify, None
};

struct Edge {
    EdgeType edge_type;
    uint dest_x;
    uint dest_y;
    uint cost;

    explicit Edge(EdgeType edge_type, uint dest_x, uint dest_y);

};

struct Node {
    uint x;
    uint y;
    uint shortest_path;

    explicit Node();
    bool operator < (Node n) const;

    uint prev_x;
    uint prev_y;
    EdgeType prev_edge_type;
    vector<Edge> adjacent_edges;
};

Edge::Edge(EdgeType edge_type, uint dest_x, uint dest_y) : edge_type(edge_type), dest_x(dest_x), dest_y(dest_y) {
    switch (edge_type) {
        case same:
            cost = 0U;
            break;
        default:
            cost = 1U;
            break;
    }
};

Node::Node() : x(numeric_limits<uint>::max()), y(numeric_limits<uint>::max()),
               shortest_path(numeric_limits<uint>::max()), prev_x(numeric_limits<uint>::max()),
               prev_y(numeric_limits<uint>::max()), prev_edge_type(None), adjacent_edges({}) {}

bool Node::operator < (const Node n) const{
    return (shortest_path < n.shortest_path);
}

int main() {
    uint N;
    cin >> N;
    for (auto &&i: irange(0U, N)) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        vector<vector<Node>> nodes(s1.size() + 1, vector<Node>(s2.size() + 1, Node()));
        // edit graph from s1 to s2
        // edit graph size = s1.size()+1, s2.size()+1 for BOS
        for (auto &&x: irange(0U, s1.size() + 1)) {
            for (auto &&y: irange(0U, s2.size() + 1)) {
                nodes.at(x).at(y).x = x;
                nodes.at(x).at(y).y = y;
                if (x < s1.size()) {
                    nodes.at(x).at(y).adjacent_edges.emplace_back(Edge(remove_edge, x + 1, y));
                }
                if (y < s2.size()) {
                    nodes.at(x).at(y).adjacent_edges.emplace_back(Edge(add, x, y + 1));
                }
                if (x < s1.size() && y < s2.size()) {
                    if (s1.at(x) == s2.at(y)) {
                        nodes.at(x).at(y).adjacent_edges.emplace_back(Edge(same, x + 1, y + 1));
                    } else {
                        nodes.at(x).at(y).adjacent_edges.emplace_back(Edge(modify, x + 1, y + 1));
                    }
                }
            }
        }
        nodes.at(0U).at(0U).shortest_path = 0U;
        priority_queue<Node> pq{};
        pq.push(nodes.at(0U).at(0U));
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            for (auto &&edge: node.adjacent_edges){
                auto& target_node = nodes.at(edge.dest_x).at(edge.dest_y);
                auto alternative_shortest_path = node.shortest_path + edge.cost;
                if (alternative_shortest_path < target_node.shortest_path){
                    target_node.shortest_path = alternative_shortest_path;
                    target_node.prev_x = node.x;
                    target_node.prev_y = node.y;
                    target_node.prev_edge_type = edge.edge_type;
                    pq.push(target_node);
                }
            }
        }
        uint current_x{s1.size()};
        uint current_y{s2.size()};
        uint count{0};
        while (true){
            auto & current_node = nodes.at(current_x).at(current_y);
            if (current_node.prev_edge_type == None){
                break;
            } else if (current_node.prev_edge_type == same){
                count++;
            }
            auto & prev_node = nodes.at(current_node.prev_x).at(current_node.prev_y);
            current_x = prev_node.x;
            current_y = prev_node.y;
        }
        cout << count << endl;
    }
    return 0;
}