#include <iostream>
#include <vector>
#include <limits>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>
#include <unordered_set>
#include <deque>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

struct Edge{
    uint node_to;
    int weight;
    explicit Edge(uint _node_to, int _weight): node_to(_node_to), weight(_weight){};
};


struct Node{
    bool visited{false};
    uint value{numeric_limits<uint>::max()};
    uint position{numeric_limits<uint>::max()};
    vector<Edge> adjacent_node{};
    explicit Node() = default;;
};



int main() {
    uint N, M;
    cin >> N >> M;
    vector<uint> lefts(M, 0);
    vector<uint> rights(M, 0);
    vector<uint> distances(M, 0);
    for (auto &&i: irange((unsigned int) 0, M)){
        uint l, r;
        cin >> l >> r;
        lefts.at(i) = l - 1;
        rights.at(i) = r - 1;
        cin  >> distances.at(i);
    }

    vector<Node> nodes(N, Node());
    for (auto &&i: irange((unsigned int) 0, N)){
        nodes.at(i).value = i;
    }

    for (auto &&i: irange((unsigned int) 0, M)){
        nodes.at(lefts.at(i)).adjacent_node.emplace_back(Edge(rights.at(i), distances.at(i)));
        nodes.at(rights.at(i)).adjacent_node.emplace_back(Edge(lefts.at(i), -distances.at(i)));
    }

    unordered_set<uint> unsettled;
    for (auto &&i: irange((unsigned int) 0, N)){
        unsettled.insert(i);
    }

    while (!unsettled.empty()){
        uint first_index = *unsettled.begin();

        nodes.at(first_index).visited = true;
        nodes.at(first_index).position = 0;

        deque<uint> stack{first_index};
        while (!stack.empty()){
            uint visiting = stack.back();
            stack.pop_back();
            unsettled.erase(visiting);
            for (auto &&edge: nodes.at(visiting).adjacent_node){
                if (!nodes.at(edge.node_to).visited){
                    nodes.at(edge.node_to).visited = true;
                    nodes.at(edge.node_to).position = nodes.at(visiting).position + edge.weight;
                    stack.push_back(edge.node_to);
                }
            }
        }
    }

    for (auto &&i: irange((unsigned int) 0, M)){
        if (nodes.at(rights.at(i)).position - nodes.at(lefts.at(i)).position != distances.at(i)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}