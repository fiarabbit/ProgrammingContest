#include <iostream>
#include <array>
#include <boost/range/irange.hpp>

using  namespace std;
using namespace boost;

int main() {
    int N;
    constexpr int N_max {100};
    cin >> N;
    array<int, N_max> d;
    for (int i: irange(0, N)){}
    return 0;
}