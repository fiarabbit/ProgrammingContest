#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>
#include <limits>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

int main() {
    vector<vector<uint>> cs(3, vector<uint>(3, 0));
    for (auto &&i: irange((unsigned int) 0, (uint) 3)) {
        for (auto &&j: irange((unsigned int) 0, (uint) 3)) {
            cin >> cs.at(i).at(j);
        }
    }
    vector<uint> as(3, numeric_limits<uint>::max());
    vector<uint> bs(3, numeric_limits<uint>::max());
    as.at(0) = 0;
    bs.at(0) = cs.at(0).at(0);
    bs.at(1) = cs.at(0).at(1);
    bs.at(2) = cs.at(0).at(2);
    as.at(1) = cs.at(1).at(0) - bs.at(0);
    as.at(2) = cs.at(2).at(0) - bs.at(0);
    bool b{true};
    if (cs.at(1).at(1) != as.at(1) + bs.at(1)){
        b = false;
    }
    if (cs.at(1).at(2) != as.at(1) + bs.at(2)){
        b = false;
    }
    if (cs.at(2).at(1) != as.at(2) + bs.at(1)){
        b = false;
    }
    if (cs.at(2).at(2) != as.at(2) + bs.at(2)){
        b = false;
    }
    if (b){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}