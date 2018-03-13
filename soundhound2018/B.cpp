#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

int main() {
    uint N, L, R;
    cin >> N >> L >> R;
    vector<uint> as(N, 0);
    for (auto &&i: irange((unsigned int) 0, N)){
        cin >> as.at(i);
    }
    vector<uint> bs(N, 0);
    for (auto &&i: irange((unsigned int) 0, N)){
        uint target{as.at(i)};
        if (target < L){
            bs.at(i) = L;
        } else if (target > R) {
            bs.at(i) = R;
        } else {
            bs.at(i) = as.at(i);
        }
    }
    for (auto &&i: irange((unsigned int) 0, N-1)){
        cout << bs.at(i) << " ";
    }
    cout << bs.back();
    return 0;
}