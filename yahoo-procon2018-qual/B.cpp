#include <iostream>
#include <vector>
#include <limits>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

int main() {
    uint X;
    uint K;
    cin >> X >> K;
    uint unit{1};
    for (auto &&i: irange(0U, K)){
        unit *= 10;
    }
    uint base{X/unit+1};
    cout << base * unit;

    return 0;
}