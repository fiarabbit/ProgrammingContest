#include <iostream>
#include <vector>
#include <limits>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>
#include <utility>
#include <cstdlib>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

struct Coordinate{
    uint x;
    uint y;
    explicit Coordinate(uint x, uint y): x(x), y(y){};
    uint operator - (const Coordinate c){
        return (uint)(abs((int)x-(int)c.x) + abs((int)y-(int)c.y));
    };
};

int main() {
    uint H, W, D;
    cin >> H >> W >> D;
    vector<vector<uint>> As(H, vector<uint>(W, 0));
    for (auto &&i: irange(0U, H)){
        for (auto &&j: irange(0U, W)){
            uint written_value;
            cin >> written_value;
            As.at(i).at(j) = written_value - 1;
        }
    }
    uint Q;
    cin >> Q;
    vector<uint> Ls(Q, 0);
    vector<uint> Rs(Q, 0);
    for (auto &&i: irange(0U, Q)){
        uint written_value_l, written_value_r;
        cin >> written_value_l >> written_value_r;
        Ls.at(i) = written_value_l - 1;
        Rs.at(i) = written_value_r - 1;
    }

    vector<Coordinate> reverse_dict(H*W, Coordinate(numeric_limits<uint>::max(), numeric_limits<uint>::max()));
    for (auto &&i: irange(0U, H)){
        for (auto &&j: irange(0U, W)){
            reverse_dict.at(As.at(i).at(j)).x = j;
            reverse_dict.at(As.at(i).at(j)).y = i;
        }
    }
    vector<uint> accumulated_costs(H*W, numeric_limits<uint>::max());
    for (auto &&init_value: irange(0U, D)){
        for (unsigned int j = init_value; j < H*W; j+=D) {
            if (j < D){
                accumulated_costs.at(j) = 0;
            } else {
                accumulated_costs.at(j) = accumulated_costs.at(j-D) + (reverse_dict.at(j)-reverse_dict.at(j-D));
            }
        }
    }
    for (auto &&i: irange(0U, Q)){
        cout <<  accumulated_costs.at(Rs.at(i)) - accumulated_costs.at(Ls.at(i)) << endl;
    }
    return 0;
}