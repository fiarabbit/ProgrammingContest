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
    vector<uint> v{0, 1};
    uint & a = v.at(0);
    a = v.at(1);
    for (auto &&i: v){
        cout << i << endl;
    }

    return 0;
}