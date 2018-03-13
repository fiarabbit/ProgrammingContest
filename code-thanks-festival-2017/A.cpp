#include <iostream>
#include <vector>
#include <limits>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>
#include <algorithm>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

int main() {
    vector<uint> v(8, 0U);
    for(auto&&i: irange(0U, 8U)){
        cin >> v.at(i);
    }
    cout << *max_element(v.begin(), v.end());
    return 0;
}