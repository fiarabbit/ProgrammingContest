#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>
#include <cstdlib>
#include <limits>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

int main() {
    uint N, Z, W;
    cin >> N >> Z >> W;
    vector<uint> as(N, 0);
    for (auto &&i: irange((unsigned int) 0, N)){
        cin >> as.at(i);
    }
    auto an_w = (uint)abs((int)as.at(N-1) - (int) W);
    vector<uint> abss(N-1, 0);
    for (auto &&i: irange((unsigned int) 0, N-1)){
        abss.at(i) = (uint)abs((int)as.at(N-1) - (int) as.at(i));
    }

    uint maximum{an_w};
    for (auto &&k: irange((unsigned int) 0, N-1)){
        uint minimum{abss.at(k)};
        for (auto &&l: irange((unsigned int) k+1, N-1)){
            minimum = min(minimum, abss.at(l));
        }
        maximum = max(maximum, minimum);
    }
    cout << max(an_w, maximum);
    return 0;
}