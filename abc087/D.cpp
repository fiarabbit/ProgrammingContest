#include <iostream>
#include <vector>
#include <utility>
#include <boost/range/irange.hpp>
#include <deque>
#include <limits>

using namespace std;
using namespace boost;

int main() {
    using uint = unsigned int;
    uint N, M;
    cin >> N >> M;
    vector<uint> Ls(M, 0);
    vector<uint> Rs(M, 0);
    vector<int> Ds(M, 0);
    for (auto i: irange((uint) 0, M)) {
        uint l;
        uint r;
        int d;
        cin >> l >> r >> d;
        Ls.at(i) = l - 1;
        Rs.at(i) = r - 1;
        Ds.at(i) = d;
    }
    vector<vector<pair<uint, int>>> adjacency_list(N);
    for (auto i: irange((uint) 0, M)) {
        adjacency_list.at(Ls.at(i)).emplace_back(make_pair(Rs.at(i), Ds.at(i)));
        adjacency_list.at(Rs.at(i)).emplace_back(make_pair(Ls.at(i), -Ds.at(i)));
    }
    vector<bool> weight_calculated(N, false);
    deque<uint> to_be_visited{};
    vector<int> weights(N, std::numeric_limits<int>::max());

    for (uint pointer{0};pointer < N; pointer++) {
        if (!weight_calculated.at(pointer)) {
            weights.at(pointer) = 0;
            weight_calculated.at(pointer) = true;
            to_be_visited.emplace_back(pointer);
            while (!to_be_visited.empty()) {
                uint now{to_be_visited.front()};
                to_be_visited.pop_front();
                for (pair<uint, int> next_data:adjacency_list.at(now)) {
                    uint node_index{next_data.first};
                    int weight{next_data.second};
                    if (!weight_calculated.at(node_index)) {
                        to_be_visited.emplace_back(node_index);
                        weights.at(node_index) = weights.at(now) + weight;
                        weight_calculated.at(node_index) = true;
                    }
                }
            }
        }
    }
    for (auto i: irange((uint) 0, M)) {
        if (weights.at(Rs.at(i)) - weights.at(Ls.at(i)) != Ds.at(i)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}